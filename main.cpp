#include <iostream>
#include "utility.hpp"
#include "01/01.cpp"
#include "02/02.cpp"
#include "03/03.cpp"
#include "04/04.cpp"
#include "05/05.cpp"
#include "06/06.cpp"
#include "07/07.cpp"

int main(int argc, char* argv[])
{
    const std::string num = argv[1];
    const std::string path = num + "/input.txt";
    std::vector<std::string> input = util::GetInputByLine((path));

    const u_int32_t resultA = puzzle07::puzzleA(input);
    std::cout << "Result Part A: " << resultA << std::endl;
    const u_int32_t resultB = puzzle07::puzzleB(input);
    std::cout << "Result Part B: " << resultB << std::endl;

    return 0;
}
