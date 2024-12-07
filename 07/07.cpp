//
// Created by hank on 12/7/24.
//

#include <cmath>
#ifndef PUZZLE07
#define PUZZLE07

#include <vector>
#include <string>
#include <sstream>

namespace puzzle07 {
    u_int32_t puzzleA(std::vector<std::string> &input) {
        u_int32_t result = 0;
        std::stringstream ss;
        std::string temp_str;
        int temp_int;
        for (const std::string& line : input) {
            ss << line;
            ss >> temp_str;
            int ans;
            std::vector<int> nums;
            std::stringstream(temp_str) >> ans;
            while (!ss.eof()) {
                ss >> temp_str;
                std::stringstream(temp_str) >> temp_int;
                nums.push_back(temp_int);
            }
            ss.clear();
            u_int16_t permutations = std::pow(2, nums.size()-1);
            // do work on the stuff
            for (u_int16_t i = 0; i <= permutations; i++) {
                int res = nums[0];
                for (int n = 1; n < nums.size(); n++) {
                    if (((i >> (n-1)) & 1) == 0)
                        res += nums[n];
                    else
                        res *= nums[n];
                    if (res > ans)
                        break;
                }
                if (ans == res) {
                    result += ans;
                    break;
                }
            }
        }
        return result;
    }
    u_int32_t puzzleB(std::vector<std::string> &input) {return 0;}
}
#endif