#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter a file name: ";
    std::cin >> filename;

    std::ifstream file("../res/" + filename);
    std::string line;

    if(!file){
        std::cerr << "Unable to open file" << "\n";
        return 1;
    }

    while (line, file){
        std::cout << line << "\n";
    }
    file.close();
    return 0;
}
