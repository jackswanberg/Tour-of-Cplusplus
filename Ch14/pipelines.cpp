#include <iostream>
#include <string>
#include <vector>
#include <ranges>

void user(std::ranges::forward_range auto& r)
{
    auto odd = [](int x){return x%2;};

    for(int x:r | std::views::filter(odd) | std::views::take(5)){
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

int main()
{
    auto r = std::ranges::iota_view(1, 1000);
    user(r);
}