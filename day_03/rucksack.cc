#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

std::pair<std::string, std::string> compartmentalize(const std::string& contents) {
    auto len = contents.length();
    return {contents.substr(0, len / 2), contents.substr(len / 2)};
}

std::string find_common(std::string compartment_a, std::string compartment_b) {
    std::sort(compartment_a.begin(), compartment_a.end());
    std::sort(compartment_b.begin(), compartment_b.end());

    std::string common;
    std::set_intersection(compartment_a.cbegin(), compartment_a.cend(),
                          compartment_b.cbegin(), compartment_b.cend(),
                          std::back_inserter(common));
    return common;
}

int char_priority(char ch) {
    auto u_ch = static_cast<unsigned char>(ch);
    if (std::islower(u_ch)) {
        return (ch - 'a' + 1);
    }
    if (std::isupper(u_ch)) {
        return (ch - 'A' + 27);
    }
    return 0;
}


int main() {
    std::string group[3];

    std::string line;
    int indiv_sum = 0;
    int group_sum = 0;
    int i = 0;
    while (std::cin >> line) {
        group[i] = line;
        if (++i == 3) {
            i = 0;
            auto common = find_common(group[0], group[1]);
                 common = find_common(group[2], common);
            if (common.length() > 0) {
                group_sum += char_priority(common[0]);
            }
        }

        auto compartments = compartmentalize(line);
        auto common = find_common(compartments.first, compartments.second);
        if (common.length() > 0) {
            indiv_sum += char_priority(common[0]);
        }
    }

    std::cout << indiv_sum << std::endl;
    std::cout << group_sum << std::endl;
}
