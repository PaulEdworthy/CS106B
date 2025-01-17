/* 1. Mirror
Write a function mirror that accepts a reference to a grid of integers as a parameter and flips the
grid along its diagonal, so that each index [i][j] contains what was previously at index [j][i]
in the grid. You may assume the grid is square, that is, it has the same number of rows as columns.
For example, the grid below at left would be altered to give it the new grid state at right:
{{ 6, 1, 9, 4},       {{6, -2, 14, 21},
{-2, 5, 8, 12},       {1, 5, 39, 55},
{14, 39, -6, 18}, --> {9, 8, -6, 73},
{21, 55, 73, -3}}     {4, 12, 18, -3}} */

// Just swap i and j

#include <iostream>
#include <vector>

void print(const std::vector<std::vector<int>>& grid);

void mirror(std::vector<std::vector<int>>& grid) {
    for(int i = 0; i < grid.size(); i++){
        for(int j = i + 1; j < grid.size(); j++){
            int temp = grid[i][j];
            grid[i][j] = grid[j][i];
            grid[j][i] = temp;
        }
    }
}

void print(const std::vector<std::vector<int>>& grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid.size(); j ++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> grid = {
        { 6, 1, 9, 4},
        {-2, 5, 8, 12},
        {14, 39, -6, 18},
        {21, 55, 73, -3}
    };
    mirror(grid);
    std::cout << "\nMirrored grid: \n";
    print(grid);
    return 0;
}