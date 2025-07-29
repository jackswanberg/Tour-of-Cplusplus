#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <bitset>
#include <utility> // for std::pair

#include "entry.h"

using namespace std;

// void f(int n)
// {
//     array<int a0> = {1,2,3}; // error: size not specified
//     array<string, n> a1 = {"Hello", "World"}; // error: n is not a constant expression
//     array<string,0> a2; //error: size must be positive
//     array<2> a3 = {"Hello", "World"}; // error: eleemnt type not specified, need both type and size
// }

enum class Error_code { success, not_found };

// Define entry_table globally
vector<Entry> entry_table = {
    {"Alice", 123},
    {"Bob", 456},
    {"Carol", 789}
};

pair<Entry*, Error_code> complex_search(vector<Entry>& v, const string& s)
{
    Entry* found = nullptr;
    Error_code err = Error_code::not_found;
    for(auto& e : v){
        if(e.name == s){
            found = &e;
            err = Error_code::success;
            break;
        }
    }
    return make_pair(found, err);
}

void user(const string& s)
{
    auto r = complex_search(entry_table, s);
    if(r.second != Error_code::success){
        //Handle error
        cout << "Error: Entry not found.\n";
        return;
    }
    cout << "Found entry: " << *(r.first) << endl;
}

int main()
{
    array<int,3> arr = {1, 2, 3};

    bitset<9> bs1 {"110001111"};
    bitset<9> bs2 {0b1'1000'1111};
    bitset<9> bs5 = bs1 << 2;

    cout << bs1 << endl;

    bitset<9> bs_flip = bs1.flip();
    cout << bs_flip << endl;

    user("Alice");
    user("Patrice");

    return 0;
}