#include <iostream>
#include <string>
#include <set>

template<typename Iterator>
bool unique(Iterator first, Iterator last, size_t n) {
    std::set<typename Iterator::value_type> s;

    for (auto it = first; it != last; it++) {
        s.insert(*it);
    }

    return (s.size() == n);
}

int main() {
    const int NUM1 = 4;
    const int NUM2 = 14;

    std::string line;
    std::cin >> line;

    for (size_t i = 0; i < line.size(); i++) {
        if (unique(line.cbegin()+i, line.cbegin()+i+NUM1, NUM1)) {
            std::cout << i + NUM1 << std::endl;
            break;
        }
    }

    for (size_t i = 0; i < line.size(); i++) {
        if (unique(line.cbegin()+i, line.cbegin()+i+NUM2, NUM2)) {
            std::cout << i + NUM2 << std::endl;
            break;
        }
    }
}
