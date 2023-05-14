//
// Created by marco on 12-03-2023.
//

#include "UtilityFunctions.h"
#include <iostream>
#include <limits>

namespace mar {

    void SkipLine(std::istream &input, char delimiter) {
        input.ignore(std::numeric_limits<int>::max(), delimiter);
    }

    int CountDigits(int x, int base) {
        int result = 0;
        do {
            result++;
            x /= base;
        } while (x>0);
        return result;
    }
}