#include <string>
#include <map>
#include <unordered_map>
#include <iostream>

#include "entry.h"

map<string, int> book = {
    {"Alice", 12345},
    {"Bob", 67890},
    {"Charlie", 11223}
};

unordered_map<string, int> book_unordered = {
    {"Adam", 9465},
    {"Becca", 34896},
    {"Candice", 64824}
};

int get_number(const string& s)
{
    return book[s]; // Returns 0 if s is not found
}

int get_number_unordered(const string& s)
{
    return book_unordered[s]; // Returns 0 if s is not found
}

int main(){
    std::cout << get_number("Alice") << "\n"; // Should print 12345
    std::cout << get_number("Bob") << "\n";   // Should print 67890
    std::cout << get_number_unordered("Adam") << "\n"; // Should print 9465
    std::cout << get_number_unordered("Becca") << "\n"; // Should print 34896
    std::cout << get_number_unordered("Unknown") << "\n"; // Should print 0 (not found)
    return 0;
}