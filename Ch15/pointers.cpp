#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <span>

using namespace std;

struct S{
    int i;
    string s;
    double d;
};

void fpn(int* p, int n)
{
    for(int i =0;i<n;++i)
        p[i] = 0;
}

void use_nospan(int x)
{
    int a[100];
    fpn(a,100); // OK
    fpn(a,1000); //range error in fpn
    fpn(a+10,100); //range error in fpn
    fpn(a,x); //suspect, but OK if x <= 100, however won't fully initialize a to 0's
}

void fs(span<int> p)
{
    for(int& x : p)
        x = 0;
}

void use_span(int x)
{
    int a[100];
    fs(a); //Implicitly creates a span<int>(a,100)
    //fs(a,1000); //error: span expected
    fs({a+10,100}); //range error in fs
    fs({a,x}); //suspect, but OK if x <= 100, however
}

int main(){
    auto p1 = make_shared<S>(1, "Hello", 3.14);
    auto p2 = make_unique<S>(2, "World", 2.71);

    return 0;
}