#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void printGameRules();
void getFile();
void printGrid(vector<vector<char>>, int row, int col);
bool gridWrap();
char printOptions();
bool quit(char option);
void runSimulation(vector<vector<char>> grid, int cycle);

vector<vector<char>> grid;  // game board grid
string fileName;                 // read in from ifstream
int counter = 0;

int main() {
  printGameRules();
  getFile();
  bool wrap = gridWrap();
  char option = printOptions();

  if (quit(option)) {
    std::cout << "Have a nice Life!\n";
    exit(0);
  } else if (option == 't') {
    runSimulation(grid, 1);
  } else if (option == 'a') {
    runSimulation(grid, grid.size());
  }
  return 0;
}

void printGameRules() {
  cout << "Welcome to the CS 106B Game of Life,\n"
               "a simulation of the lifecycle of a bacteria colony.\n"
               "Cells (X) live and die by the following rules:\n"
               "- A cell with 1 or fewer neighbors dies.\n"
               "- Locations with 2 neighbors remain stable.\n"
               "- Locations with 3 neighbors will create life.\n"
               "- A cell with 4 or more neighbors dies.\n";
}

void getFile() {
  // Get the file name from the user
  cout << "Choose an input file: ";
  getline(cin, fileName);

  // Open the file
  ifstream infile("../res/" + fileName);

  // Get the grid dimensions
  string row_c;
  string col_c;
  getline(infile, row_c);  // gets the first line and puts it in row variable
  getline(infile, col_c);  // gets the 2nd line and puts it in col variable

  // convert to int
  int row = stoi(row_c);
  int col = stoi(col_c);

  grid.resize(row, vector<char>(col));

  string line;
  for (int i = 0; i < row; i++) {
    getline(infile, line);
    for (int j = 0; j < col; j++) {
      grid[i][j] = line[j];
    }
  }
  infile.close();

  printGrid(grid, row, col);
}

void printGrid(vector<vector<char>> grid, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << grid[i][j];
    }
    cout << "\n";
  }
}

// TODO ensure input is a single char, y or n (case insensitive)
bool gridWrap() {
  cout << "Should the simulation wrap around the grid? (y/n) ";
  char answer;
  cin >> answer;
  return (answer = tolower(answer)) == 'y';
}

// TODO error check input is single char and only a, t or q (case insensitive)
char printOptions() {
  char option;
  char frames;
  cout << "a)nimate, t)ick, q)uit? ";
  cin >> option;
  option = tolower(option);
  return option;
}

bool quit(char op) {
  if (op == 'q') {
    return true;
  }
  return false;
}

void runSimulation(std::vector<std::vector<char>> grid, int cycle) {
  int numRows = grid.size();
  int numCols = grid[0].size();

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {

    }
  }
  printGrid(grid, numRows, numCols);
}