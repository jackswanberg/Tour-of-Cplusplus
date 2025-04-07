#include <iostream>

enum class Color{red,blue,green};
enum class Traffic_light {green,yellow,red};

int main()
{
    Color x1 = Color::red;
    auto x2 = Color::red;
    Color x = Color(5);
    int i = int(Color::blue);
    std::cout << i << std::endl;
}