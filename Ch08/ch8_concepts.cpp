#include<iostream>
#include<iterator>
#include<concepts>
#include<ranges>

using namespace std;

template<typename Sequence, typename Value>  // Least constrained template we can do, typename just specifies value must be a type
//template<Sequence Seq, Number Num> //Need to define what a Sequence and Number are for this to work
Value sum(const Sequence& s, Value v)
{
    for(const auto& x: s)
    {
        v+=x;
    } 
    return v;
}

// Need to digest this more
// template<Sequence Seq, Number Num>
//     requires Arithmetic<range_value_t<Seq>,Num>
// Num sum(const Seq& s, Num n);

//Important to have meaningful constraints on template arguments
// template<typename Sequence, typename Number>
    // // requires Arithmetic<range_value_t<Sequence>,Number>
// Number sum(const Sequence& s, Number n);

template<forward_iterator Iter>
void advance(Iter p, int n)
{
    while(n--)
        ++p;    // forward iterator has ++, but not + or +=
}

template<random_access_iterator Iter>
void advance(Iter p, int n)
{
    p+=n;   //Random access iterator has +=
}

template<forward_iterator Iter>
    requires requires(Iter p, int i) {p[i];p+i;}
void advance(Iter p, int n)
{
    p+=n;
}

// ****************************** Concepts ******************************
template<typename B>
concept Boolean = 
    requires(B x, B y){
        {x = true};
        {x = false};
        {x = (x==y)};
        {x = (x!=y)};
        {x = !x};
        {x = (x = y)};
    };

// template<typename T>
// concept Equality_comparable = 
//     requires(T a,T b){
//         {a == b} -> Boolean;
//         {a != b} -> Boolean;
//     };

template<typename T, typename T2 = T>
concept Equality_comparable = 
    requires(T a,T2 b){
        {a == b} -> Boolean;
        {a != b} -> Boolean;
        {b == a} -> Boolean;
        {b != a} -> Boolean;
    };

// If just given one argument type, checks whether x has properties of a number, if given two checks whether the two types can be ..
// used together for the given operations
template<typename T, typename U = T>
concept Number = 
    requires(T x, U y){
        x+y;x-y;x*y;x/y;
        x+=y;x-=y;x*=y,x/=y;
        x=x;
        x=0;
    };

// Can use the above concept of a number to define an Arithmetic concept
template<typename T, typename U = T>
concept Arithmetic = Number<T,U> && Number<U,T>; // Checks whether type 1 and 2 can perform arithmetic operations defined in Number concept

//More complex example
template<typename S>
concept Sequence = requires(S a){
    typename ranges::range_value_t<S>;
    typename ranges::iterator_t<S>;

    {a.begin()} -> same_as<ranges::iterator_t<S> >;  //iterator_t is part of ranges, not std
    {a.end()} -> same_as<ranges::iterator_t<S> >;

    requires input_iterator<ranges::iterator_t<S> >;
    requires same_as<ranges::range_value_t<S>, iter_value_t<S> >;

};

int main()
{
    static_assert(Equality_comparable<int>);
    // static_assert(Equality_comparable<int, string>); // Fails, can't compare int with string
    cout << "howdy" << endl;
    
}

