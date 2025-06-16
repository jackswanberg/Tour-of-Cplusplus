#include <vector>
#include <string>
#include <iostream>

#include "Checked_iter.h"
#include "entry.h"

using namespace std;

template<typename T>
struct Vec : std::vector<T> {
    using vector<T>::vector; // Inherit constructors

    T& operator[](int i) { return vector<T>::at(i); }
    //     if (i >= this->size()) {
    //         throw std::out_of_range("Index out of range");
    //     }
    //     return std::vector<T>::operator[](i);
    // }

    const T& operator[](int i) const { return vector<T>::at(i); }
    //     if (i >= this->size()) {
    //         throw std::out_of_range("Index out of range");
    //     }
    //     return std::vector<T>::operator[](i);
    // }

    auto begin() {return Checked_iter<vector<T>>{*this};}
    auto end() {return Checked_iter<vector<T>>{*this, vector<T>::end()};}
};

void checked(Vec<Entry>& book)
{
    try{
        book[book.size()] = Entry{"John Doe", 48135}; // Out of range access
    }
    catch(out_of_range&){
        cerr << "range error: Index out of range" << "\n";
    }
}
int main(){
    cout << "Compiled" << "\n";
    Vec<Entry> book;
    book.push_back({"Alice", 12345});
    book.push_back({"Bob", 67890});
    checked(book);
    cout << "Keep on going" << "\n";
    return 0;
}