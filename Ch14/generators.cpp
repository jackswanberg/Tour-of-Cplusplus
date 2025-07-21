#include <iostream>
#include <vector>
#include <ranges>
#include <complex>

int main()
{
    for (int x : std::ranges::iota_view(1, 10)) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // for(auto x : std::ranges::istream_view<std::complex<double>>(std::cin)) {
    //     std::cout << x << ' ';
    // }
    // std::cout << '\n';

    auto cplx = std::ranges::istream_view<double>(std::cin);
    for (auto x : std::ranges::transform_view(cplx, [](auto z){ return z*z;}))
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';


}