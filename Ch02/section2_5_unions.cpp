#include <iostream>

using namespace std;

enum class Type {ptr,num}; // Type can hold ptr and num
struct Node{
    int a=0;
};

struct Entry{
    string name;
    Type t;
    Node* p;
    int i;
};

struct Entry2{
    string name;
    variant<Node*,int> v;
};

union Value{
    Node* p;
    int i;
};

void f(Entry* pe)
{
    if (pe->t==Type::num)
        cout << pe->i;
}

void f2(Entry2* pe)
{
    if (holds_alternative<int>(pe->v))
        cout << get<int>(pe->v);
}

int main()
{

}