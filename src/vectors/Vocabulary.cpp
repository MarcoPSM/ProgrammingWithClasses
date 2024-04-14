//
// Created by m1martin on 14-04-2024
//

#include "Vocabulary.h"
#include <algorithm>

namespace mar {
Vocabulary::Vocabulary(int capacity, std::istream &input)
    : std::vector<std::string>() {
    reserve(capacity);
    Read(input);
    std::cout << static_cast<unsigned>(size()) << " "
              << static_cast<unsigned>(this->capacity()) << std::endl;
    std::sort(begin(), end());
    erase(std::unique(begin(), end()), end());
    cursor = begin();
    std::cout << static_cast<unsigned>(size()) << " "
              << static_cast<unsigned>(this->capacity()) << std::endl;
}

Vocabulary::~Vocabulary() {}

void Vocabulary::Show(int n) {
    for (int i = 0; i < n && cursor != end(); i++) {
        std::cout << *cursor++ << std::endl;
    }
}

void Vocabulary::Search(const std::string &s) {
    cursor = std::lower_bound(begin(), end(), s);
}

void Vocabulary::Read(std::istream &input) {
    std::string s;
    for (;;) {
        std::getline(input, s);
        if (!input) {
            break;
        }
        push_back(s);
    }
}
} // namespace mar