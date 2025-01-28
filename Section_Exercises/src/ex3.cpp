#include <iostream>
#include <vector>

void stretch(std::vector<int>);

int main() {
    std::vector<int> grid = {18, 7, 4, 24, 11};
    stretch(grid);
    return 0;
}

void stretch(std::vector<int> grid) {
    int len = grid.size();
    for (int i = len - 1; i >= 0; i--){
        grid.insert(grid.begin() + i + 1, grid[i] / 2);

        if (grid[i] % 2 == 0){
            grid[i] = grid[i] / 2;
        } else {
            grid[i] = (grid[i] / 2) + 1;
        }
    }
    for (int i = 0; i < grid.size(); i++) {
        std::cout << grid[i] << " ";
    }
    std::cout << "\n";
}