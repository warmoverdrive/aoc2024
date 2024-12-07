//
// Created by hank on 12/6/24.
//

#ifndef PUZZLE05
#define PUZZLE05

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace puzzle05 {
    struct Page {
        int number = 0;
        std::unordered_map<int, std::shared_ptr<Page>> children;
        std::unordered_map<int, std::shared_ptr<Page>> parents;
    };

    void parse_input(std::vector<std::string> &input, std::unordered_map<int, std::shared_ptr<Page>> &pages, std::vector<std::vector<int>> &updates) {
        for (std::string &line : input) {
            if (line[2] == '|') {
                int num = std::stoi(line.substr(0,2));
                int next = std::stoi(line.substr(3));
                std::shared_ptr<Page> parent;
                std::shared_ptr<Page> child;
                try {
                    parent = pages.at(num);
                } catch (std::out_of_range &e) {
                    parent = std::make_shared<Page>();
                    parent->number = num;
                    pages.insert(std::make_pair(num, parent));
                }
                try {
                    child = pages.at(next);
                } catch (std::out_of_range &e) {
                    child = std::make_shared<Page>();
                    child->number = next;
                    pages.insert(std::make_pair(next, child));
                }

                parent->children.insert(std::make_pair(next, child));
                child->parents.insert(std::make_pair(num, parent));
            }
            else if (line[2] == ',') {
                std::vector<int> update;
                for(int i = 0; i < line.size(); i+=3)
                    update.push_back(std::stoi(line.substr(i,2)));
                updates.push_back(update);
            }
        }
    }

    int puzzleA(std::vector<std::string> &input) {
        std::unordered_map<int, std::shared_ptr<Page>> pages;
        std::vector<std::vector<int>> updates;
        int result = 0;

        parse_input(input, pages, updates);

        for (std::vector<int> update : updates) {
            bool valid = true;

            for (int i = 0; i < update.size(); i++) {
                for (int j = 0; j < update.size(); j++) {
                    if (update[i] != update[j]) {
                        if (i < j) {
                            // children
                            valid = pages.at(update[i])->children.contains(update[j]);
                        } else if (i > j) {
                            // parents
                            valid = pages.at(update[i])->parents.contains(update[j]);
                        }
                    }
                    if (!valid)
                        break;
                }
                if (!valid)
                    break;
            }

            if (valid) {
                result += update[update.size()/2];
            }
        }

        return result;
    }

    void sort_update(std::vector<int> &update, std::unordered_map<int, std::shared_ptr<Page>> &pages) {
        bool valid = false;
        while (!valid) {
            for (int i = 0; i < update.size(); i++) {
                for (int j = 0; j < update.size(); j++) {
                    if (update[i] != update[j]) {
                        if (i < j) {
                            // children
                            valid = pages.at(update[i])->children.contains(update[j]);
                        } else if (i > j) {
                            // parents
                            valid = pages.at(update[i])->parents.contains(update[j]);
                        }
                    }
                    if (!valid) {
                        int temp = update[i];
                        update[i] = update[j];
                        update[j] = temp;
                    }
                }
            }
        }
    }

    int puzzleB(std::vector<std::string> &input) {
        std::unordered_map<int, std::shared_ptr<Page>> pages;
        std::vector<std::vector<int>> updates;
        std::vector<std::vector<int>> bad_updates;
        int result = 0;

        parse_input(input, pages, updates);

        for (std::vector<int> update : updates) {
            bool valid = true;

            for (int i = 0; i < update.size(); i++) {
                for (int j = 0; j < update.size(); j++) {
                    if (update[i] != update[j]) {
                        if (i < j) {
                            // children
                            valid = pages.at(update[i])->children.contains(update[j]);
                        } else if (i > j) {
                            // parents
                            valid = pages.at(update[i])->parents.contains(update[j]);
                        }
                    }
                    if (!valid)
                        break;
                }
                if (!valid)
                    break;
            }
            if (!valid) {
                bad_updates.push_back(update);
            }
        }

        for (std::vector<int> update : bad_updates) {
            sort_update(update, pages);
            result += update[update.size()/2];
        }

        return result;
    }
} // namespace puzzle05
#endif
