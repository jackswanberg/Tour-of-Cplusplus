#include "Vector.h"

Vector::Vector(int s)
    :elem{new double[s]}, sz{s}
{
}

double& Vector::operator[](int i) const
{
    return elem[i];
}

int Vector::size() const
{
    return sz;
}