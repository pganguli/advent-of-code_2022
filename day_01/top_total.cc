#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

int main(int argc, char* argv[]) {
    int largest_n = 1;
    if (argc > 1) {
        largest_n = std::max(std::stoi(argv[1]), 0);
    }
    const int LARGEST_N = largest_n;

    std::vector<int> calories;
    int cur_sum = 0;

    while (std::cin) {
        std::string line;
        std::getline(std::cin, line);

        if (line.empty()) {
            calories.push_back(cur_sum);
            cur_sum = 0;
        } else {
            cur_sum += std::stoi(line);
        }
    }

    std::sort(calories.begin(), calories.end(), std::greater<int>());
    std::cout << std::accumulate(calories.cbegin(), calories.cbegin() + LARGEST_N, 0) << std::endl;
}
