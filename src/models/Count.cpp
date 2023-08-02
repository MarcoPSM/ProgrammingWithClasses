//
// Created by m1martin on 14-05-2023.
//

#include "Count.h"


namespace mar {
    Count::Count():
        value(0) {
    }

    Count::Count(const Count &other):
        value(other.value) {

    }

    Count::~Count() {

    }

    void Count::Increment() {
        value++;
    }

    void Count::Decrement() {
        if (value > 0) {
            value--;
        }
    }

    void Count::Reset() {
        value=0;
    }

    int Count::Value() const {
        return value;
    }

    bool Count::IsZero() const {
        return value == 0;
    }

} // mar