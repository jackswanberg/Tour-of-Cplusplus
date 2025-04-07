#include<iostream>

class complex{
    double re, im;
public:
    complex(double r, double i):re(r), im(i) {}     //Construct from two scalars
    complex(double r): re(r), im(0) {}              //Construct from one scalar
    complex(): re(0), im(0) {}                      //default complex of (0,0)

    //Functions for setting and getting values of re and im
    double real() const{return re;}
    void real(double d) {re=d;}
    double imag() const {return im;}
    void imag(double d) {im=d;}

    //Defining operators
    complex& operator+=(complex z)
    {
        re+=z.re;
        im+=z.im;
        return *this;
    }

    complex& operator-=(complex z)
    {
        re-=z.re;
        im-=z.im;
        return *this;
    }
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

int main()
{
    std::cout << "Hi there" << std::endl;
}
