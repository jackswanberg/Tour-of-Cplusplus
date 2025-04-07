#include<iostream>
//Abstract class
class Container{
public:
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

class Vector_container : public Container{
public:
    Vector_container(int s) : v(s) {}
    ~Vector_container() {}

    double& operator[](int i) override {return v[i];}
    int size() const override { return v.size();}
private:
    Vector v;
};

class Vector{
public:
    Vector(int s): elem(new double[s]), sz(s) {
        for (int i=0;i!=s;++i)
            elem[i]=0;
    }
    Vector();
    Vector(std::initializer_list<double>);

    ~Vector(){ delete[] elem;} //Desctructor: releases resources 
private:
    double* elem;
    int sz;
};

void use(Container& c)
{
    const int sz = c.size();

    for(int i=0;i!=sz;++i)
        std::cout << c[i] << std::endl;
}