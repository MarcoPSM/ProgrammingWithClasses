//
// Created by m1martin on 18-06-2023.
//

#include "ThermometerExtreme.h"

namespace mar {

    const StringBasic ThermometerExtreme::modes[] = {" ", "m ", "M "};

    ThermometerExtreme::ThermometerExtreme():
        ThermometerSimple(),
        max(Value()),
        min(Value()),
        mode(0) {

    }

    ThermometerExtreme::ThermometerExtreme(int bottom, int top) :
        ThermometerSimple(bottom, top),
        max(Value()),
        min(Value()),
        mode(0) {

    }

    ThermometerExtreme::ThermometerExtreme(const ThermometerExtreme &other):
        ThermometerSimple(other),
        max(other.max),
        min(other.min),
        mode(other.mode) {

    }

    ThermometerExtreme::~ThermometerExtreme() {

    }

    void ThermometerExtreme::WarmUp() {
        ThermometerSimple::WarmUp();
        if (Value() > max) {
            max = Value();
        }
    }

    void ThermometerExtreme::CoolDown() {
        ThermometerSimple::CoolDown();
        if (Value() < min) {
            min = Value();
        }
    }

    void ThermometerExtreme::Set(double degreesCelsius) {
        ThermometerSimple::Set(degreesCelsius);
        if (Value() < min) {
            min = Value();
        }
        else if (Value() > max) {
            max = Value();
        }

    }

    void ThermometerExtreme::Display() const {
        double x = (mode ==0) ? Value() : mode == 1 ? min : max;
        std::cout << modes[mode] << StringBasic::Fixed(x, 1);
    }

    void ThermometerExtreme::Reset() {
        max = min = Value();
    }

    double ThermometerExtreme::Min() const {
        return min;
    }

    double ThermometerExtreme::Max() const {
        return max;
    }

    void ThermometerExtreme::ChangeMode() {
        ++mode %= 3; //there are 3 modes: current, min, max
    }
} // mar