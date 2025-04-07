#include <iostream>

using namespace std;


class Vector {
public:
    // Written out construcotor
    // Vector(int s) {
    //     elem = new double[s];    
    //     sz=s;
    // }

    //Constructor list with same output as "full" constructor above
    Vector(int s) : elem(new double[s]), sz(s) {}
    double& operator[](int i) 
    {
        if (!(0<=i && i<size()))
            throw out_of_range{"Vector::operator[]"};
        return elem[i]; 
    }
    int size() {return sz; }
private:
    double* elem;
    int sz;
};

double read_and_sum(int s)
{
    Vector v(s);

    for (int i=0;i!=v.size();++i)
        std::cin >> v[i];

    double sum = 0;
    for (int i=0;i!=v.size();++i)
        sum+=v[i];
    return sum;
}

void f(Vector& v)
{
    try{
        auto x = v[100];
    }
    catch(const out_of_range& err){
        cerr << err.what() << '\n';
    }
}

int main()
{
    // 2.2 Structures
    int num = 4;
    double sum = 0;
    sum = read_and_sum(num);
    Vector v(num);
    f(v);
    std::cout << sum << std::endl;
}