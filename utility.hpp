//
// Created by hank on 12/2/24.
//
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace util {

  std::vector<std::string> GetInputByLine(std::string path) {
    std::vector<std::string> input;

    std::ifstream file(path);
    if(!file.is_open()) {
      std::cerr << "File " << path << " not found" << std::endl;
      return input;
    }

    std::string line;
    while(std::getline(file, line)) {
      input.emplace_back(line);
    }

    return input;
  }

}

#endif //UTILITY_H
