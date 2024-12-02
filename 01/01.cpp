//
// Created by hank on 12/1/24.
//
#ifndef PUZZLE01

#include <fstream>
#include <string>
#include <vector>

namespace puzzle01 {
    bool comp(int a, int b) {
        return a >= b;
    }

    int puzzleA(const std::string &path) {
        int total = 0;
        std::vector<int> a, b, c;

        std::ifstream inputFile(path);

        if (!inputFile.is_open()) {
            std::cerr << "Error opening file" << std::endl;
        }

        if (inputFile.is_open()) {
            int in;
            while (inputFile >> in) {
                //std::cout << in << std::endl;
                a.emplace_back(in);
                inputFile >> in;
                //std::cout << in << std::endl;
                b.emplace_back(in);
            }
        }
        inputFile.close();

        std::sort(a.begin(), a.end(), comp);
        std::sort(b.begin(), b.end(), comp);

        for (int i = 0; i < a.size(); i++) {
            c.emplace_back(a[i] < b[i] ? b[i] - a[i] : a[i] - b[i]);
        }

        for (int num : c)
            total += num;

        return total;
    }

    int puzzleB(const std::string &path) {
        int total = 0;

        std::vector<int> a, b;

        std::ifstream inputFile(path);

        if (!inputFile.is_open()) {
            std::cerr << "Error opening file" << std::endl;
        }

        if (inputFile.is_open()) {
            int in;
            while (inputFile >> in) {
                //std::cout << in << std::endl;
                a.emplace_back(in);
                inputFile >> in;
                //std::cout << in << std::endl;
                b.emplace_back(in);
            }
        }
        inputFile.close();

        for (int i : a) {
            int count = 0;
            for (int j : b) {
                if (i == j)
                    count++;
            }
            total += count * i;
        }

        return total;
    }
}

#endif
