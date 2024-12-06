//
// Created by hank on 12/6/24.
//

#ifndef PUZZLE04
#define PUZZLE04

#include <vector>
#include <string>

namespace puzzle04 {
    int searchA(int x, int y, std::vector<std::string> &input) {
        int count = 0;

        // mapping: U | UR | R | DR | D | DL | L | UL
        int8_t dir_flags = 0b11111111;
        const std::string word = "XMAS";

        for (int i = 1; i <= 3; i++) {
            // up
            if ((dir_flags & 0b10000000) == 0b10000000) {
                if (y - i < 0 || input[y-i][x] != word[i])
                    dir_flags &= 0b01111111;
            }
            // up-right
            if ((dir_flags & 0b01000000) == 0b01000000) {
                if (y - i < 0 || x + i >= input[y].size() || input[y-i][x+i] != word[i])
                    dir_flags &= 0b10111111;
            }
            // right
            if ((dir_flags & 0b00100000) == 0b00100000) {
                if (x + i >= input[y].size() || input[y][x+i] != word[i])
                    dir_flags &= 0b11011111;
            }
            // down-right
            if ((dir_flags & 0b00010000) == 0b00010000) {
                if (y + i >= input.size() || x + i >= input[y].size() || input[y+i][x+i] != word[i])
                    dir_flags &= 0b11101111;
            }
            // down
            if ((dir_flags & 0b00001000) == 0b00001000) {
                if (y + i >= input.size() || input[y+i][x] != word[i])
                    dir_flags &= 0b11110111;
            }
            // down-left
            if ((dir_flags & 0b00000100) == 0b00000100) {
                if (y + i >= input.size() || x - i < 0 || input[y+i][x-i] != word[i])
                    dir_flags &= 0b11111011;
            }
            // left
            if ((dir_flags & 0b00000010) == 0b00000010) {
                if ( x - i < 0 || input[y][x-i] != word[i])
                    dir_flags &= 0b11111101;
            }
            // up-left
            if ((dir_flags & 0b00000001) == 0b00000001) {
                if (y - i < 0 || x - i < 0 || input[y-i][x-i] != word[i])
                    dir_flags &= 0b11111110;
            }
        }

        // count bits not flipped
        for (count = 0; dir_flags; count++) {
            dir_flags &= (dir_flags - 1);
        }

        return count;
    }

    int puzzleA(std::vector<std::string> &input) {
        int result = 0;

        const char target = 'X';

        for (int y = 0; y < input.size(); y++)
            for (int x = 0; x < input[y].size(); x++)
                if (input[y][x] == target)
                    result += searchA(x, y, input);

        return result;
    }

    bool searchB(int x, int y, std::vector<std::string> &input) {
        bool valid;

        if (x - 1 < 0 || x + 1 >= input[y].size() || y - 1 < 0 || y + 1 >= input.size())
            valid = false;
        else {
            if (((input[y-1][x-1] == 'M' && input[y+1][x+1] == 'S') ||
                (input[y-1][x-1] == 'S' && input[y+1][x+1] == 'M')) &&
                ((input[y-1][x+1] == 'M' && input[y+1][x-1] == 'S') ||
                (input[y-1][x+1] == 'S' && input[y+1][x-1] == 'M')))
                valid = true;
            else
                valid = false;
        }
        return valid;
    }

    int puzzleB(std::vector<std::string> &input) {
        int result = 0;

        const char target = 'A';

        for (int y = 0; y < input.size(); y++)
            for (int x = 0; x < input[y].size(); x++)
                if (input[y][x] == target)
                    result += searchB(x, y, input) ? 1 : 0;

        return result;
    }
}

#endif