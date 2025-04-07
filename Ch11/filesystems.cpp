#include <filesystem>
#include <cassert>
#include <iostream>
#include <fstream>
#include <format>
#include <ios>
#include <chrono>


// Can use path to open a file
void use(std::filesystem::path p)
{
    std::ofstream f {p};
    if (!f) std::cerr << "Bad file name: " << p << std::endl;
    f << "Hello, file!";
}

void print_directory(std::filesystem::path p)
try
{
    if(std::filesystem::is_directory(p)){
        std::cout << p << ":\n:";
        for(const std::filesystem::directory_entry& x: std::filesystem::directory_iterator{p})
            std::cout << "  " << x.path() << "\n";
    }
}
catch (const std::filesystem::filesystem_error& ex){
    std::cerr << ex.what() << '\n';
}

void use2()
{
    print_directory(".");
    print_directory("..");
    print_directory("/");
    print_directory("c:");
}

int main(){

    using namespace std::filesystem;
    path f = "test2.txt";
    
    // assert(exists(f));

    std::cout << f << " " << exists(f) << std::endl;
    use(f);

    auto start_time = std::chrono::high_resolution_clock::now();
    use2();
    auto stop_time = std::chrono::high_resolution_clock::now();
    std::string result = format("Total time without sync turned off was: {}", stop_time-start_time); 
    
    std::ios_base::sync_with_stdio(false);

    start_time = std::chrono::high_resolution_clock::now();
    use2();
    stop_time = std::chrono::high_resolution_clock::now();
    std::string result2 = format("Total time with sync turned off was: {}", stop_time-start_time); 

    std::cout << result << "\n";
    std::cout << result2 << "\n";
    // std::cout << std::filesystem::current_path() << "\n";
}