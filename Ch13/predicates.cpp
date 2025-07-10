#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <map>
#include <string>

// using namespace std;

template<typename T>
class Greater_than {
    const T val;
public:
    Greater_than(const T& v) : val(v) {}
    bool operator()(const std::pair<std::string,int>& x) const {return x.second > val;}
};

void f(std::map<std::string,int>& m){
    auto p = std::find_if(m.begin(), m.end(),Greater_than<int>(10));
    if (p != m.end()) {
        std::cout << "Found: " << p->first << " with value " << p->second << std::endl;
    } else {
        std::cout << "No element found with value greater than 10" << std::endl;
    }
}

int main(){
    using namespace std;
    map<string,int> m = {{"apple", 5}, {"banana", 15}, {"cherry", 20}};
    f(m);
    return 0;
}