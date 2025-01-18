/* 2. PlusSum
Write a function named plusSum that accepts three parameters - a reference to a Grid of
integers, and two integers for a row and column - and returns the sum of all numbers in the
“plus” pattern with sides of length 1 centered at that row and column. For example, if a grid
named g stores the following integers:
{{1, 2, 3},
{4, 5, 6},
{7, 8, 9}}
Then the call of crossSum(g, 1, 1) should return 25 (4+5+6+2+8):
 */

#include <iostream>
#include <vector>

void plusSum(std::vector<std::vector<int>> &grid, int row, int column)
{
    int sum = 0;
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid.size(); j++){
            if (grid[i][j] == grid[row][j]){
                sum += grid[i][j];
            }
            else if (grid[i][j] == grid[i][column]) {
                sum += grid[i][j];
            }
        }
    }
    std::cout << sum << "\n";
}

int main()
{
    std::vector<std::vector<int>> grid{
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}}
    };
    plusSum(grid, 1, 1); // 25
    plusSum(grid, 2, 2); // 33
    
    return 0;
}