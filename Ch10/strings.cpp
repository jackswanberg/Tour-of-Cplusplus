#include <string>
#include <iostream>

using namespace std;

string cat(string_view sv1, string_view sv2)
{
    string res {sv1};
    return res +=sv2;
}

int main(){
    auto mouse = "Mouse"sv;
    auto dog = "Dog";

    std::cout << mouse << std::endl;
    std::cout << cat(mouse,dog) << std::endl;

    std::cout << mouse.substr(1,3) << std::endl;
    std::cout << cat({&mouse[2],3},dog) << std::endl;

    return 0;
}