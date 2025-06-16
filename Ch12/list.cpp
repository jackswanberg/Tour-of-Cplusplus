#include <list>
#include <string>
#include <iostream>

#include "entry.h"


list<Entry> book = {
    {"Alice", 12345},
    {"Bob", 67890},
    {"Charlie", 11223}
};

// Using for-range loop to find the number associated with a name
int get_number(const string& s)
{
    for(const auto& x : book){
        if(x.name == s) return x.number;
    }
    return 0; // Return 0 if not found
}

//Using iterators explicitly to rewrite get_number
int get_number_iter(const string& s)
{
    for(auto p = book.begin(); p != book.end(); ++p){
        if(p->name == s) 
            return p->number;
    }
    return 0; // Return 0 if not found
}

int main(){
    std::cout << get_number_iter("Alice") << "\n"; // Should print 12345
    return 0;
}