#include <vector>
#include <iostream>

void printBoard(std::vector<std::vector<int>>& board){
    std::cout << "Howdy" << "\n";
}

int main(){
    std::vector<std::vector<int>> board = {{1,0},{2,3}};
    std::vector<int> test = {1,2,3};

    for(auto row: board){
        for(auto val: row){
            std::cout << val << "\n";
        }
    }

    for(auto row: board){
        for(auto val: row){
            val >>= 1;
        }
    }

    for(auto row: board){
        for(auto val: row){
            std::cout << val << "\n";
        }
    }
}