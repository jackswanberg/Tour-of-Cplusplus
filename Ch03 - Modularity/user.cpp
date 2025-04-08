#include "Vector.h"
#include <cmath>

double sqrt_sum(const Vector& v){
    double sum = 0;
    for(int i=0;i!=v.size();++i){
        sum+=std::sqrt(v[i]);
    }
    return sum;
}

int main(){
    Vector test = Vector(4);
    
    return 0;
}