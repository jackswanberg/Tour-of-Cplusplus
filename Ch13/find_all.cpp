#include <iostream>
#include <vector>

template<typename C, typename V>
std::vector<V> find_all(C& container, V v){
    std::vector<V> result;
    for (auto& item : container){
        if(item == v){
            result.push_back(item);
        }
    }
     return result;
}

int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 2, 5, 2};
    int value_to_find = 2;

    std::vector<int> found_numbers = find_all(numbers, value_to_find);

    std::cout << "Found " << found_numbers.size() << " occurrences of " << value_to_find << ": ";
    for (const auto& num : found_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

