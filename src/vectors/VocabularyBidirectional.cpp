//
// Created by m1martin on 25-04-2024
//

#include "VocabularyBidirectional.h"

namespace mar {
VocabularyBidirectional::VocabularyBidirectional(int           capacity,
                                                 std::istream &input)
    : Vocabulary(capacity, input) {
    cursor = rbegin();
}

void VocabularyBidirectional::ShowBack(int n) {
    for (int i = 0; i < n && cursor != rend(); i++) {
        std::cout << *cursor++ << std::endl;
    }
}

void VocabularyBidirectional::SearchBack(const std::string &s) {
    cursor = std::vector<std::string>::reverse_iterator(
        std::upper_bound(begin(), end(), s));
}
} // namespace mar