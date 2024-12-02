#include <iostream>
#include "utility.hpp"
#include "01/01.cpp"
#include "02/02.cpp"

int main()
{
    std::vector<std::string> input = util::GetInputByLine("02/input.txt");

    int resultA = puzzle02::puzzleA(input);
    int resultB = puzzle02::puzzleB(input);

    std::cout << "Result Part A: " << resultA << std::endl;
    std::cout << "Result Part B: " << resultB << std::endl;
    return 0;
}
