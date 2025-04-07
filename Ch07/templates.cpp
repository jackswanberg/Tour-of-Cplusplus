#include<iostream>
#include<list>

using namespace std;

template<typename T> //Older code often used template<class T>
class Vector{
private:
    T* elem;
    int sz;
public:
    explicit Vector(int s);
    Vector(initializer_list<T>);
    ~Vector() {delete[] elem; }

    // copy and move operations

    T& operator[](int i)
    {
        if(i<0 || size()<=i)
            throw out_of_range("Vector::operator[]");
        return elem[i];
    }
    const T& operator[](int i) const
    {
        if(i<0 || size()<=i)
            throw out_of_range("Vector::operator[]");
        return elem[i];
    }
    int size() const {return sz;}
};

template<typename T>
Vector<T>::Vector(int s)
{
    if (s<0)
        throw length_error("Vector constructor: negative size");
    elem = new T[s];
    sz=s;
}


// template<typename T>
// const T& Vector<T>::operator[](int i) const
// {
//     if(i<0 || size()<=i)
//         throw out_of_range("Vector::operator[]");
//     return elem[i];
// }

void write(const Vector<string>& vs)
{
    for (int i=0;i!=vs.size();++i)
        cout << vs[i] << '\n';
}

// In order to utilize the range-for loop we need to define begin() and end() functions

template<typename T>
T* begin(Vector<T>& x)
{
    return &x[0]; //pointer to the first element
}

template<typename T>
T* end(Vector<T>& x)
{
    return &x[0]+x.size(); //pointer to one beyond the last element
}

//implementing these allows us to use the "cleaner" for loop in a new write function

void write2(Vector<string>& vs)
{
    for(auto& s: vs)
        cout << s << '\n';
}

//Function object
template<typename T>
class Less_than {
    const T val;
public:
    Less_than(const T& v): val(v) {}
    bool operator()(const T& x) const {return x<val;}
};

template<typename C, typename P>
int count(const C& c, P pred)
{
    int cnt=0;
    for (const auto& x: c)
        if(pred(x))
            ++cnt;
    return cnt;
}



int main(){
    Vector<char> vc(200); //vector of 200 char
    Vector<string> vs(2); //vector of 17 strings
    Vector<list<int> > vli(45);
    Vector<int> vi {4,67,2,4,7,6,57,89};
    // write2(vs);

    Less_than lti {42};
    cout << boolalpha;
    cout << lti(35) << endl;
    cout << typeid(lti(35)).name() << endl;
    cout << lti(47) << endl;
}