#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

std::vector<std::vector<char>> stack1 = {
    {'G','T','R','W'},
    {'G','C','H','P','M','S','V','W'},
    {'C','L','T','S','G','M'},
    {'J','H','D','M','W','R','F'},
    {'P','Q','L','H','S','W','F','J'},
    {'P','J','D','N','F','M','S'},
    {'Z','B','D','F','G','C','S','J'},
    {'R','T','B'},
    {'H','N','W','L','C'}
};

std::vector<std::vector<char>> stack2 = {
    {'G','T','R','W'},
    {'G','C','H','P','M','S','V','W'},
    {'C','L','T','S','G','M'},
    {'J','H','D','M','W','R','F'},
    {'P','Q','L','H','S','W','F','J'},
    {'P','J','D','N','F','M','S'},
    {'Z','B','D','F','G','C','S','J'},
    {'R','T','B'},
    {'H','N','W','L','C'}
};

int main() {
    int num = 0;
    int src = 0;
    int dest = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::sscanf(line.c_str(), "move %d from %d to %d", &num, &src, &dest);

        std::vector<char> tmpv = {};
        for (int i = 0; i < num; i++) {
            stack1[dest - 1].push_back(stack1[src - 1].back());
            stack1[src - 1].pop_back();

            tmpv.push_back(stack2[src - 1].back());
            stack2[src - 1].pop_back();
        }
        while (!tmpv.empty()) {
            stack2[dest - 1].push_back(tmpv.back());
            tmpv.pop_back();
        }
    }

    for (auto v : stack1) {
       std::cout << v.back();
    }
    std::cout << std::endl;

    for (auto v : stack2) {
       std::cout << v.back();
    }
    std::cout << std::endl;
}
