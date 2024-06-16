#include <AddingNum.h>
#include <algorithm>
#include <iostream>


std::string Parcer::trimQuotes(const std::string& str) {
    if (str.size() >= 2 && str.front() == '"' && str.back() == '"') {
        return str.substr(1, str.size() - 2);
    }
    return str;
}

void Parcer::writeToFile(int base, const std::string& number, const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    outputFile << base << ": \"" << number << "\"" << std::endl;
}

Elements Parcer::parceNumbers(const std::string& inputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file");
    }

    std::string line;
    Elements nums;

    while (std::getline(inputFile, line)) {
        if (line.empty()) continue;
        size_t colonPos = line.find(':');
        if (colonPos != std::string::npos) {
            int base = std::stoi(line.substr(0, colonPos));
            std::string number = line.substr(colonPos + 2);

            if (nums.A.number.empty()) {
                nums.A.base = base;
                nums.A.number = trimQuotes(number);
                std::cout << "Found A: base=" << nums.A.base << ", number=" << nums.A.number << std::endl;
            }
            else if (nums.B.number.empty()) {
                nums.B.base = base;
                nums.B.number = trimQuotes(number);
                std::cout << "Found B: base=" << nums.B.base << ", number=" << nums.B.number << std::endl;
            }
        }
        else {
            nums.C = std::stoi(line);
            std::cout << "Found C: base=" << nums.C << std::endl;
        }
    }
    if (nums.A.number.empty() || nums.B.number.empty() || nums.C == 0) {
        throw std::runtime_error("Input file does not contain valid data for A, B, and C");
    }
    return nums;
}

bigint Adder::convertToDecimal(const std::string& number, int base) {
    bigint result(0);
    for (char c : number) {
        int value = charToValue(c);
        if (value >= base) throw std::invalid_argument("Invalid digit in number for the given base");
        result = result * base + value;
    }
    return result;
}

std::string Adder::convertFromDecimal(bigint number, int base) {
    if (number == 0) return "0";
    std::string result;
    while (number > 0) {
        result.push_back(valueToChar(number % base));
        number /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int Adder::charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    throw std::invalid_argument("Invalid character in number string");
}

char Adder::valueToChar(long long v) {
    if (v >= 0 && v <= 9) return '0' + v;
    if (v >= 10 && v <= 35) return 'A' + (v - 10);
    throw std::invalid_argument("Invalid value to convert to char");
}

bool Adder::isValidBase(int base) {
    return base >= 2 && base <= 36;
}

void processFile(const std::string& inputFilename, const std::string& outputFilename) {
    Elements elems = Parcer::parceNumbers(inputFilename);
    std::string add = Adder::add(elems);
    Parcer::writeToFile(elems.C, add, outputFilename);
}
