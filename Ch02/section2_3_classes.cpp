#include <iostream>

class Vector {
public:
    // Written out construcotor
    // Vector(int s) {
    //     elem = new double[s];    
    //     sz=s;
    // }

    //Constructor list with same output as "full" constructor above
    Vector(int s) : elem(new double[s]), sz(s) {}
    double& operator[](int i) {return elem[i]; }
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

int main()
{
    // 2.2 Structures
    int num = 4;
    double sum = 0;
    sum = read_and_sum(num);
    std::cout << sum << std::endl;
}

