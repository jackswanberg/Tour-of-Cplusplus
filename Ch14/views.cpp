#include <iostream>
#include <vector>
#include <ranges>
#include <forward_list>

void user(std::ranges::forward_range auto& r)
{
    std::ranges::filter_view v {r, [](int x) {return x%2; } };

    std::cout << "odd numbers: ";
    for (auto x : v) {
        std::cout << x << ' '; 
    }
}

// view for taking only a few values, in this case it is the first 100 odd numbers
// this is a view that can be used to limit the number of elements processed
// in a range, without copying the elements into a new container
void user2(std::ranges::forward_range auto& r)
{
    std::ranges::filter_view v{r, [](int x) {return x%2; } };
    std::ranges::take_view t{v,100};

    std::cout << "odd numbers: ";
    for (auto x : t) {
        std::cout << x << ' ';
    }
}

int main()
{
    std::vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> v2;

    for (int i = 0; i <500; ++i) {
        v2.push_back(i);
    }

    user2(v2);

    // Output: odd numbers: 1 3 5 7 9
}

