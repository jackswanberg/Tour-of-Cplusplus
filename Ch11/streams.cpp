#include <fstream>
#include <iostream>


using namespace std;
int main(){
    string filename = "test.txt";
    ofstream ofs{filename};
    if (!ofs)
        cout << "Couldn't open 'target' for writing, creating it" << endl;
        // ofstream file(filename);
    ofs.write("Hallo\n",6);
}