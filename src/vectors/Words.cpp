//
// Created by m1martin on 28-04-2024
//

#include "Words.h"

namespace mar {
Words::Words(int capacity, std::istream &input) : std::vector<StringBasic>() {
    reserve(capacity);
    Read(input);
    std::sort(begin(), end());
    std::unique(begin(), end());
}
Words::~Words() {}

void Words::Read(std::istream &input) {
    StringBasic s(256);
    for (;;) {
        if (!input) {
            break;
        }
        push_back(s);
    }
}

void Words::WriteWordsEndingBy(const StringBasic &s,
                               std::ostream      &output) const {
    for (std::vector<StringBasic>::const_iterator i = begin(); i != end();
         i++) {
        if (i->EndsBy(s)) {
            i->WriteLine(output);
        }
    }
}

void Words::WriteWordsStartingBy(const StringBasic &s,
                                 std::ostream      &output) const {
    for (std::vector<StringBasic>::const_iterator i = begin(); i != end();
         i++) {
        if (i->StartsBy(s)) {
            i->WriteLine(output);
        }
    }
}

void Words::WriteWordsHaving(const StringBasic &s, std::ostream &output) const {
    StringBasic temp = s.Applied(&StringBasic::Sort);
    for (std::vector<StringBasic>::const_iterator i = begin(); i != end();
         i++) {
        if (i->Applied(&StringBasic::Sort).Contains(temp)) {
            i->WriteLine(output);
        }
    }
}

void Words::WriteWordsNotHaving(const StringBasic &s,
                                std::ostream      &output) const {
    for (std::vector<StringBasic>::const_iterator i = begin(); i != end();
         i++) {
        if (i->CountIf(s) == 0) {
            i->WriteLine(output);
        }
    }
}

} // namespace mar