//
// Created by hank on 12/6/24.
//

#ifndef PUZZLE06
#define PUZZLE06

#include <vector>
#include <string>

namespace puzzle06 {
    struct Guard {
        char direction;
        int x, y;
    };

    Guard find_pos(std::vector<std::string> &input) {
        for (int y = 0; y < input.size(); y++)
            for (int x = 0; x < input[y].size(); x++)
                if (input[y][x] == '^')
                    return Guard{'^', x, y};
    }

    void step(std::vector<std::string> &input, Guard &guard) {
        input[guard.y][guard.x] = 'X';
        if(guard.direction == '^') {
            if(guard.y > 0 && input[guard.y-1][guard.x] == '#')
                guard.direction = '>';
            else
                guard.y--;
        } else if (guard.direction == '>') {
            if (guard.x < input[guard.y].size()-1 && input[guard.y][guard.x+1] == '#')
                guard.direction = 'v';
            else
                guard.x++;
        }
        else if (guard.direction == 'v') {
            if (guard.y < input.size()-1 && input[guard.y+1][guard.x] == '#')
                guard.direction = '<';
            else
                guard.y++;
        }
        else if (guard.direction == '<') {
            if (guard.x > 0 && input[guard.y][guard.x-1] == '#')
                guard.direction = '^';
            else
                guard.x--;
        }
    }

    int count(std::vector<std::string> &input) {
        int count = 0;
        for (std::string & y : input)
            for (const char x : y)
                if (x == 'X')
                    count++;
        return count;
    }

    int puzzleA(std::vector<std::string> input) {
        Guard guard = find_pos(input);
        bool valid = true;

        while(valid) {
            step(input, guard);
            valid = guard.x >= 0 && guard.x < input[0].size() && guard.y > 0 && guard.y < input.size();
        }

        return count(input);
    }

    int puzzleB(std::vector<std::string> input) {
        // create a list of each obstacle hit, and the direction from hit.
        // if the obstacle paired with direction is hit again, then we are in a loop
        // iterate over every possible object placement to generate a list of valid objects
        // count those objects.
        return 0;
    }
}

#endif