#include <iostream>
#include <vector>
#include <chrono>
#include <format>

using namespace std;
void print(auto in){
    cout << in << endl;
}

vector<int> read_ints(istream& is)
{
    vector<int> res;
    for (int i;is>>i;)
        res.push_back(i);
    return res;
}

struct Entry{
    string name;
    int number;
};

ostream& operator<<(ostream& os,const Entry& e){
    return os << "{\"" << e.name << "\"," << e.number << "}";
}

int main(){
    int b = 'b';
    char c = 'c';
    print(b);
    print(c);

    Entry ent {"Jack Johnson",187};
    cout << ent << endl;

    int num = 15;
    cout << hex << num << endl;
    using namespace std::chrono;
    cout << "zt:" << zoned_time{current_zone(),system_clock::now()} << endl;

    using namespace std;
    string name = "Bob";
    string s = format("Howdy, {}, have a nice day!",name);
    cout << s << endl;
    using namespace std::chrono;
    auto ymd = 2021y/March/30;
    
    cout << format("ymd: {0:%A}, {1:%B} {2:}. {3:}\n",weekday(ymd), ymd.month(), ymd.day(), ymd.year());
    // double test;
    // cin >> test;
    // cout << test << endl;

    // auto v = read_ints(cin);
    // for (const auto& val : v){
    //     cout << val << endl;
    // }
}