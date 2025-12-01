/*
 * Created by Marco Martins on 30-11-2025
 */

#include "AccumulationBasic.h"

namespace mar {

AccumulationBasic::AccumulationBasic(int capacity) {
    reserve(capacity);
}

AccumulationBasic::~AccumulationBasic() {}

int AccumulationBasic::PartialSum(int x, int y) const {
    int result = 0;
    for (int i = x; i <= y; i++) {
        result += at(i);
    }
    return result;
}

int AccumulationBasic::Max(int x) const {
    /*
    int result = std::numeric_limits<int>::min();
    for (unsigned i = 0, j = i + x - 1; j < size(); i++, j++) {
        int temp = PartialSum(i, j);
        if (temp > result) {
            result = temp;
        }
    }
    */
    int result = PartialSum(0, x - 1);
    int sum    = result;
    for (unsigned i = 1, j = i + x - 1; j < size(); i++, j++) {
        sum += at(j) - at(i - 1);
        if (sum > result) {
            result = sum;
        }
    }

    return result;
}

std::pair<int, int> AccumulationBasic::BestLimits(int x) const {
    std::pair<int, int> result(0, x - 1);
    int                 sum        = PartialSum(0, x - 1);
    int                 currentMax = sum;
    for (unsigned i = 1, j = i + x - 1; j < size(); i++, j++) {
        sum += at(j) - at(i - 1);
        if (sum > currentMax) {
            currentMax = sum;
            result     = std::pair<int, int>(i, j);
        }
    }

    return result;
}

} // namespace mar