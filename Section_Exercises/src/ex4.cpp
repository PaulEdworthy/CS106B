#include <iostream>
#include <vector>

void removeConsecutiveDuplicates(std::vector<int>& grid);
void printGrid(std::vector<int>& grid);

int main() {
    std::vector<int> grid = {1, 2, 2, 3, 4, 5, 5};
    removeConsecutiveDuplicates(grid);
    return 0;
}

void removeConsecutiveDuplicates(std::vector<int>& grid) {
    for (int i = 0; i < grid.size() - 1; i++) {
        if (grid[i] == grid[i + 1]) {
            grid.erase(grid.begin() + i);
        }
    } 
    printGrid(grid);
}

void printGrid(std::vector<int>& grid) {
    for (int i = 0; i < grid.size(); i++) {
        std::cout << grid[i] << " ";
    }
    std::cout << "\n";
}