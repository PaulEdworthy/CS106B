#include <iostream>
#include <vector>

std::vector<std::vector<int>> grid = {
    {6, 1, 9, 4},
    {-2, 5, 8, 12},
    {14, 39, -6, 18},
    {21, 55, 73, -3}
};

void mirror(std::vector<std::vector<int>>);

int main() {
    mirror(grid);
    return 0;
}

void mirror(std::vector<std::vector<int>> grid) {
    int len = grid.size();
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i < j) {
                int temp = grid[i][j];
                grid[i][j] = grid[j][i];
                grid[j][i] = temp;
            }
        }
    }

        // print the new grid
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}