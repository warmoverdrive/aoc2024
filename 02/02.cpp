//
// Created by hank on 12/2/24.
//
#ifndef PUZZLE02
#define PUZZLE02
#include <sstream>

namespace puzzle02 {
    int puzzleA(std::vector<std::string> input) {
        int result = 0;

        // parse input into 2d vector
        std::vector<std::vector<int>> data;
        std::stringstream ss;
        std::string temp_string;
        int temp_int;

        for (std::string line: input) {
            std::vector<int> page;
            ss << line;

            while (!ss.eof()) {
                ss >> temp_string;
                if (std::stringstream(temp_string) >> temp_int) {
                    page.emplace_back(temp_int);
                }
            }
            data.emplace_back(page);
            ss.clear();
        }

        // for each vector check if it is strictly increasing or decreasing, increment result.
        for (std::vector<int> page: data) {
            int last = -1;
            int dir = 0;
            bool safe = true;
            for (int x: page) {
                // std::cout << x << " ";
                if (last == -1) {
                    last = x;
                    continue;
                }
                if (last == x)
                    safe = false;
                if (last < x) {
                    if (dir == -1) {
                        safe = x - last <= 3;
                        last = x;
                    } else if (dir == 0) {
                        safe = x - last <= 3;
                        last = x;
                        dir = -1;
                    } else
                        safe = false;
                } else if (last > x) {
                    if (dir == 1) {
                        safe = last - x <= 3;
                        last = x;
                    } else if (dir == 0) {
                        safe = last - x <= 3;
                        last = x;
                        dir = 1;
                    } else
                        safe = false;
                }
                if (!safe)
                    break;
            }
            // std::cout << "\t\t" << safe << std::endl;
            result += safe ? 1 : 0;
        }

        return result;
    }

    void process_page_bad(int &result, std::vector<int> page) {
        int last = -1;
        int dir = 0;
        int chances = 1;
        bool safe = true;
        for (int x: page) {
            std::cout << x << " ";
            if (last == -1) {
                last = x;
                continue;
            }
            if (last == x) {
                safe = false;
            }
            if (last < x) {
                if (dir == -1) {
                    safe = x - last <= 3;
                    last = safe ? x : last;
                } else if (dir == 0) {
                    safe = x - last <= 3;
                    last = safe ? x : last;
                    dir = -1;
                } else
                    safe = false;
            } else if (last > x) {
                if (dir == 1) {
                    safe = last - x <= 3;
                    last = safe ? x : last;
                } else if (dir == 0) {
                    safe = last - x <= 3;
                    last = safe ? x : last;
                    dir = 1;
                } else
                    safe = false;
            }
            if (!safe) {
                chances--;
                if (chances < 0)
                    break;
                safe = true;
            }
        }
        std::cout << "\t\t" << safe << std::endl;
        result += safe ? 1 : 0;
    }

    int puzzleB(std::vector<std::string> input) {
        int result = 0;

        // parse input into 2d vector
        std::vector<std::vector<int>> data;
        std::stringstream ss;
        std::string temp_string;
        int temp_int;

        for (std::string line : input) {
            std::vector<int> page;
            ss << line;

            while (!ss.eof()) {
                ss >> temp_string;
                if (std::stringstream(temp_string) >> temp_int) {
                    page.emplace_back(temp_int);
                }
            }
            data.emplace_back(page);
            ss.clear();
        }

        // for each vector check if it is strictly increasing or decreasing, increment result.
        for (std::vector<int> page : data) {
            // process_page_bad(result, page); // faulty implementation for part B

            bool safe = true;

            for (int x = 0; x < page.size(); x++) {
                safe = true;
                int dir = 0;
                int last = -1;

                for (int i = 0; i < page.size(); i++) {
                    if (i == x)
                        continue;
                    if (last == -1)
                        last = page[i];
                    else if (last == page[i])
                        safe = false;
                    else if (last < page[i]) {
                        if (dir == 0)
                            dir = -1;
                        if (dir == -1) {
                            safe = page[i] - last <= 3;
                            last = page[i];
                        } else
                            safe = false;
                    } else {
                        if (dir == 0)
                            dir = 1;
                        if (dir == 1) {
                            safe = last - page[i] <= 3;
                            last = page[i];
                        } else
                            safe = false;
                    }
                    if (!safe)
                        break;

                }
                //std::cout << "\t  x: " << x << " || safe: " << safe << '\t';
                if (safe)
                    break;
            }
            //std::cout << "\t\t" << safe << std::endl;
            result += safe ? 1 : 0;
        }


        return result;
    }
}
#endif