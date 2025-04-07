#include <regex>
#include <iostream>
using namespace std;

bool is_identifier(const string& s)
{
    // regex pat{"[_[:alpha:]]\\w*"};
    regex pat{R"([_[:alpha:]]\w*)"};
    return regex_match(s,pat);
}

void test()
{
    string input = "as ae kdl: e_e1 ^dj ido ja";
    regex pat{R"(\s+(\w+))"};
    for(sregex_iterator p(input.begin(),input.end(),pat);p!=sregex_iterator{};++p)
        cout << (*p)[1] << "\n";
}

int main(){
    
    regex pat(R"(\w{2}\d{3})");

    using namespace std; 
    int lineno = 0;
    // for (string line; getline(cin,line);){
    //     ++lineno;
    //     smatch matches;
    //     if(regex_search(line,matches,pat))
    //         cout << lineno << ":" << matches[0] << "\n";
    // }
    test();
}