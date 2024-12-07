//
// Created by hank on 12/6/24.
//

#ifndef PUZZLE06
#define PUZZLE06

#include <vector>
#include <string>
#include <map>

namespace puzzle06 {
    struct Guard {
        char direction;
        int x, y;
    };

    struct Obstacle {
        bool up = false, down = false, right = false, left = false;
    };

    Guard find_pos(std::vector<std::string> &input) {
        for (int y = 0; y < input.size(); y++)
            for (int x = 0; x < input[y].size(); x++)
                if (input[y][x] == '^')
                    return Guard{'^', x, y};
    }

    void stepA(std::vector<std::string> &input, Guard &guard) {
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
            stepA(input, guard);
            valid = guard.x >= 0 && guard.x < input[0].size() && guard.y > 0 && guard.y < input.size();
        }

        return count(input);
    }

    bool check_loop(int x, int y, char dir, std::map<std::pair<int,int>,Obstacle> &obstacles) {
        Obstacle ob;
        try {
            ob = obstacles.at(std::make_pair(x,y));
            if (dir == '^') {
                if (ob.up)
                    return true;
                ob.up = true;
            } else if (dir == 'v') {
                if (ob.down)
                    return true;
                ob.down = true;
            } else if (dir == '<') {
                if (ob.left)
                    return true;
                ob.left = true;
            } else if (dir == '>') {
                if (ob.right)
                    return true;
                ob.right = true;
            }
        } catch (std::out_of_range &e) {
            if (dir == '^')
                ob.up = true;
            else if (dir == 'v')
                ob.down = true;
            else if (dir == '<')
                ob.left = true;
            else
                ob.right = true;
            obstacles.emplace(std::make_pair(x,y), ob);
            return false;
        }
    }

    bool stepB(std::vector<std::string> &input, Guard &guard, std::map<std::pair<int,int>,Obstacle> &obstacles) {
        bool is_loop =false;
        input[guard.y][guard.x] = 'X';
        if(guard.direction == '^') {
            if(guard.y > 0 && (input[guard.y-1][guard.x] == '#' || input[guard.y-1][guard.x] == 'O')) {
                is_loop = check_loop(guard.y-1, guard.x, '^', obstacles);
                guard.direction = '>';
            } else
                guard.y--;
        } else if (guard.direction == '>') {
            if (guard.x < input[guard.y].size()-1 && (input[guard.y][guard.x+1] == '#' || input[guard.y][guard.x+1] == 'O')) {
                is_loop = check_loop(guard.y, guard.x+1, '>', obstacles);
                guard.direction = 'v';
            } else
                guard.x++;
        }
        else if (guard.direction == 'v') {
            if (guard.y < input.size()-1 && (input[guard.y+1][guard.x] == '#' || input[guard.y+1][guard.x] == 'O')) {
                is_loop = check_loop(guard.y+1, guard.x, 'v', obstacles);
                guard.direction = '<';
            } else
                guard.y++;
        }
        else if (guard.direction == '<') {
            if (guard.x > 0 && (input[guard.y][guard.x-1] == '#' || input[guard.y][guard.x-1] == 'O')) {
                is_loop = check_loop(guard.y, guard.x-1, '<', obstacles);
                guard.direction = '^';
            }
            else
                guard.x--;
        }
        return is_loop;
    }

    int puzzleB(std::vector<std::string> input) {
        int count = 0;

        for (int y = 0; y < input[0].size(); y++)
            for (int x = 0; x < input[y].size(); x++) {
                if (input[y][x] != '#' || input[y][x] != '^') {
                    Guard guard = find_pos(input);
                    std::vector<std::string> new_board = input;
                    std::map<std::pair<int,int>, Obstacle> obstacles;
                    new_board[y][x] = 'O';
                    bool valid = true;
                    bool loop = false;
                    while(valid) {
                        loop = stepB(new_board, guard, obstacles);
                        valid = guard.x >= 0 && guard.x < new_board[0].size() && guard.y > 0 && guard.y < new_board.size();
                        if (loop) {
                            count++;
                            break;
                        }
                    }
                }
            }
        return count;
    }
}

#endif