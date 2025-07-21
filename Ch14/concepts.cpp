#include <iostream>
#include <string>
#include <vector>
#include <concepts>
#include <ranges>
#include <iterator>
#include <algorithm>

template<typename B>
concept Boolean=
    requires(B x, B y) {
        {x = true};
        {x = false};
        {x = (x==y)};
        {x = (x!=y)};
        {x = !x};
        {x = (x = y)};
    };


template<class Iter>
class Sentinel{
public:
    Sentinel(int ee) : end(ee) {}
    Sentinel() : end(0) {}

    friend bool operator==(const Iter& p, Sentinel s) {return (*p == s.end); }
    friend bool operator!=(const Iter& p, Sentinel s) {return (*p != s.end); }
private:
    std::iter_value_t<const char*> end;
};

int main()
{
    static_assert(std::sentinel_for<Sentinel<const char*>, const char*>);

    const char aa[] = "Hello, World!\nBye for now\n";
    std::ranges::for_each(aa, Sentinel<const char*>('\n'), [](const char x) {std::cout << x; });

    return 0;
}