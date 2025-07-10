#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

ostream_iterator<string> oo {cout};
istream_iterator<string> ii {cin};

int main(){
    *oo = "Hello ";
    ++oo; // Move to the next position in the output stream
    *oo = "World";
    ++oo; // Move to the next position in the output stream
    *oo = "!\n";
    
    return 0;
}