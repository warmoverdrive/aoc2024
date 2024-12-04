#include <iostream>
#include "utility.hpp"
#include "01/01.cpp"
#include "02/02.cpp"
#include "03/03.cpp"

int main()
{
    std::vector<std::string> input = util::GetInputByLine("03/input.txt");

    const int resultA = puzzle03::puzzleA(input);
    std::cout << "Result Part A: " << resultA << std::endl;
    const int resultB = puzzle03::puzzleB(input);
    std::cout << "Result Part B: " << resultB << std::endl;

    return 0;
}
