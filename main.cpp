#include <iostream>
#include <AddingNum.h>


int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";
    try {
        processFile(inputFilename, outputFilename);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
