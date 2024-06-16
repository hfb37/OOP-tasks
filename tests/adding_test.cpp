#include <gtest/gtest.h>
#include <AddingNum.h>
#include <fstream>

void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }
    outFile << content;
    outFile.close();
}

std::string readFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Failed to open file for reading: " + filename);
    }
    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    inFile.close();
    return content;
}

TEST(adding_test, 16FFplus36HELLO) {
    const std::string inputContent = "16: \"FF\"\n36: \"HELLO\"\n2";
    const std::string expectedOutput = "2: \"1101111100001011011011011\"\n";

    writeFile("input.txt", inputContent);
    processFile("input.txt", "output.txt");
    std::string actualOutput = readFile("output.txt");

    EXPECT_EQ(actualOutput, expectedOutput);
}

TEST(adding_test, EmptyLines) {
    const std::string inputContent = "\n\n16: \"FF\"\n\n36: \"HELLO\"\n\n2";
    const std::string expectedOutput = "2: \"1101111100001011011011011\"\n";

    writeFile("input.txt", inputContent);
    processFile("input.txt", "output.txt");
    std::string actualOutput = readFile("output.txt");

    EXPECT_EQ(actualOutput, expectedOutput);
}

TEST(adding_test, LowerCaseLetters) {
    const std::string inputContent = "16: \"ff\"\n36: \"hello\"\n2";
    const std::string expectedOutput = "2: \"1101111100001011011011011\"\n";

    writeFile("input.txt", inputContent);
    processFile("input.txt", "output.txt");
    std::string actualOutput = readFile("output.txt");

    EXPECT_EQ(actualOutput, expectedOutput);
}

TEST(adding_test, BigNumber) {
    const std::string inputContent = "16: \"1\"\n36: \"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\"\n10";
    const std::string expectedOutput = "10: \"37711171281396032013366321198900157303750656\"\n";

    writeFile("input.txt", inputContent);
    processFile("input.txt", "output.txt");
    std::string actualOutput = readFile("output.txt");

    EXPECT_EQ(actualOutput, expectedOutput);
}
