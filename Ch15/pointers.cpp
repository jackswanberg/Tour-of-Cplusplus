#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    vector<string> msg = {"Hello","C++","World","from","VS Code","and the C++ Extension!"};
    for (const auto& word : msg)
    {
        cout << word << " ";
    }
    cout << "\n";
    
}