#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string from, to;
    cin >> from >> to;
    if (from.empty()){
        cerr << "Input file name is empty, using default input file 'input.txt'." << "\n";
        from = "input.txt";
    }
    if (to.empty()){
        cerr << "Output file name is empty, using default output file 'output.txt'." << "\n";
        to = "output.txt";
    }

    ifstream is{from};
    istream_iterator<string> ii{is};
    istream_iterator<string> eos;

    ofstream os{to};
    ostream_iterator<string> oi{os, "\n"};

    vector<string> words{ii, eos};
    sort(words.begin(), words.end());

    unique_copy(words.begin(), words.end(), oi);

    return !is.eof() || !os;

}
