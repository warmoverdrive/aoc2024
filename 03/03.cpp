//
// Created by hank on 12/3/24.
//

#ifndef PUZZLE03
#define PUZZLE03

#include <sstream>
#include <vector>

namespace puzzle03 {

    int puzzleA(const std::vector<std::string>& input) {
        int result = 0;
        std::stringstream ss;
        int lhs = 0;
        int rhs = 0;

        for (const std::string& line : input) {
            ss << line;
            while (!ss.eof()) {
                if(ss.get() == 'm')
                    if(ss.get() == 'u')
                        if(ss.get() == 'l')
                            if(ss.get() == '(') {
                                if (std::isdigit(ss.peek())) {
                                    ss >> lhs;
                                    if (ss.get() == ',')
                                        if(std::isdigit(ss.peek())) {
                                            ss >> rhs;
                                            if (ss.get() == ')')
                                                result += lhs * rhs;
                                        }
                                }
                            }
            }
            ss.clear();
        }

        return result;
    }

    int puzzleB(const std::vector<std::string> input) {
        int result = 0;

        std::stringstream ss;
        char c;
        bool enabled = true;
        int lhs = 0;
        int rhs = 0;

        for (const std::string& line : input) {
            ss << line;
            while (!ss.eof()) {
                ss >> c;
                if(c == 'm' && enabled) {
                    if(ss.get() == 'u')
                        if(ss.get() == 'l')
                            if(ss.get() == '(') {
                                if (std::isdigit(ss.peek())) {
                                    ss >> lhs;
                                    if (ss.get() == ',')
                                        if(std::isdigit(ss.peek())) {
                                            ss >> rhs;
                                            if (ss.get() == ')')
                                                result += lhs * rhs;
                                        }
                                }
                            }
                } else if (c == 'd') {
                    if (ss.get() == 'o') {
                        ss >> c;
                        if (c == 'n') {
                            if (ss.get() == '\'')
                                if(ss.get() == 't')
                                    if(ss.get() == '(')
                                        if (ss.get() == ')')
                                            enabled = false;
                        } else if (c == '(')
                            if (ss.get() == ')')
                                enabled = true;
                    }
                }
            }
            ss.clear();
        }
        return result;
    }

} // namespace puzzle03

#endif
