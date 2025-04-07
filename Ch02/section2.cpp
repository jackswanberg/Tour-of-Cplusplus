#include <iostream>

struct Vector{
    double* elem; //point to elements
    int sz; //number of elements
};

void vector_init(Vector& v, int s)
{
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s)
{
    Vector v;
    vector_init(v,s);

    for (int i=0;i!=s;++i)
        std::cin >> v.elem[i];

    double sum = 0;
    for (int i=0;i!=s;++i)
        sum+=v.elem[i];
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