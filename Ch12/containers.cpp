#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Entry{
    string name;
    int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
    return os << "{\"" << e.name << "\", " << e.number << "}";
}

istream& operator>>(istream& is, Entry& e)
{
    // read {"NAME", NUMBER} pair. formatted with {"", and }
    char c, c2;
    if(is>>c && c=='{' && is>>c2 && c2=='"'){
        string name;
        while(is.get(c)&&c!='"')
            name+=c;

        if(is>>c && c==','){
            int number = 0;
            if(is>>number>>c && c=='}'){
                e={name,number};
                return is;
            }
        }
    }
    is.setstate(ios_base::failbit);
    return is;
}

void print_book(const vector<Entry>& book)
{
    // Const means we will not be changing the value
    // auto lets the compiler determine what type it is
    // & Means we want a reference of the item, not a copy
    for(const auto& item : book){
        std::cout << item << "\n";
    }
}

//Need to have the reference in order for it to affect the values in main
void input_entry(vector<Entry>& book){
    for(Entry e; cin>>e;){
        book.push_back(e);
    }
}

int main(){
    vector<Entry> phone_book = {
        {"David Hume",1234},
        {"Lionel Messi",10},
        {"Betty",93}
    };

    input_entry(phone_book);
    

    print_book(phone_book);

    return 0;

}