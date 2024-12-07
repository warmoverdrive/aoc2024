#include <iostream>
#include "utility.hpp"
#include "01/01.cpp"
#include "02/02.cpp"
#include "03/03.cpp"
#include "04/04.cpp"
#include "05/05.cpp"

int main(int argc, char* argv[])
{
    const std::string num = argv[1];
    const std::string path = num + "/input.txt";
    std::vector<std::string> input = util::GetInputByLine((path));

    const int resultA = puzzle05::puzzleA(input);
    std::cout << "Result Part A: " << resultA << std::endl;
    const int resultB = puzzle05::puzzleB(input);
    std::cout << "Result Part B: " << resultB << std::endl;

    return 0;
}
