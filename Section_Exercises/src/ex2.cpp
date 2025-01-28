#include <iostream>
#include <vector>

void plusSum(std::vector<std::vector<int>>, int, int);

int main() {
    std::vector<std::vector<int>> grid = {
        {{1, 2, 3},
        {4, 5, 6,},
        {7, 8, 9}}
    };
    
    plusSum(grid, 1, 1);
    return 0;
}

void plusSum(std::vector<std::vector<int>> grid, int x, int y){
    int sum = 0;
    int len = grid.size();
    for (int i = 0; i < len; i++){
       sum += grid[i][y];
    }
    for (int j = 0; j < len; j++){
        sum += grid[x][j];
    }
    sum -= grid[x][y];
    std::cout << sum << "\n";
};