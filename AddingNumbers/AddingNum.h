#include <fstream>
#include <vector>
#include <BigInt.h>

struct Number {
    std::string number;
    int base;
};

struct Elements {
    Number A, B;
    int C = 0;
};

class Parcer {
private:
    inline static std::string trimQuotes(const std::string& str);

public:
    static void writeToFile(int base, const std::string& number, const std::string& outputFileName);

    static Elements parceNumbers(const std::string& inputFileName);
};

class Adder {
private:
    static bigint convertToDecimal(const std::string& number, int base);

    static std::string convertFromDecimal(bigint number, int base);

    static int charToValue(char c);

    static char valueToChar(long long v);

    static bool isValidBase(int base);

public:
    static std::string add(const Elements& elem){
        if (!isValidBase(elem.A.base) || !isValidBase(elem.B.base) || !isValidBase(elem.C)) {
            throw std::invalid_argument("Error: One or more bases are invalid. They must be between 2 and 36.");
        }
        bigint decimalA = convertToDecimal(elem.A.number, elem.A.base);
        bigint decimalB = convertToDecimal(elem.B.number, elem.B.base);
        bigint sum = decimalA + decimalB;
        return convertFromDecimal(sum, elem.C);
    }

};

void processFile(const std::string& inputFilename, const std::string& outputFilename);
