#include <iostream>
#include <cstdio>
#include <string>

bool between(const int x, const int low, const int high) {
    return ((x - high) * (x - low) <= 0);
}

bool between(const int al, const int ah, const int bl, const int bh) {
    return ((between(al, bl, bh) && between(ah, bl, bh))
         || (between(bl, al, ah) && between(bh, al, ah)));
}

bool overlap(const int al, const int ah, const int bl, const int bh) {
    return (between(al, bl, bh) || between(ah, bl, bh) || between(al, ah, bl, bh));
}

int main() {
    int count_between = 0;
    int count_overlap = 0;
    std::string line;
    while (std::cin >> line) {
        int al, ah;
        int bl, bh;
        std::sscanf(line.c_str(), "%d-%d,%d-%d", &al, &ah, &bl, &bh);
        if (between(al, ah, bl, bh)) {
            count_between++;
        }
        if (overlap(al, ah, bl, bh)) {
            count_overlap++;
        }
    }

    std::cout << count_between << std::endl;
    std::cout << count_overlap << std::endl;
}
