//
// Created by m1martin on 04-06-2023.
//

#include "ThermometerSimple.h"
#include "StringBasic.h"

mar::ThermometerSimple::ThermometerSimple():
    bottom(defaultBottom), top(defaultTop), tenths((bottom + top) * 5) {

}

mar::ThermometerSimple::ThermometerSimple(int bottom, int top):
        bottom(bottom), top(top), tenths((bottom + top) * 5)  {

}

mar::ThermometerSimple::ThermometerSimple(const mar::ThermometerSimple &other):
        bottom(other.bottom), top(other.top), tenths(other.tenths)  {

}

mar::ThermometerSimple::~ThermometerSimple() {

}

void mar::ThermometerSimple::WarmUp() {
    if (tenths < top * 10) {
        tenths++;
    }
}

void mar::ThermometerSimple::CoolDown() {
    if (tenths > bottom * 10) {
        tenths--;
    }
}

void mar::ThermometerSimple::Set(double degreesCelsius) {
    tenths = static_cast<int>(degreesCelsius * 10);
}

double mar::ThermometerSimple::Value() const {
    return tenths / 10.0;
}

int mar::ThermometerSimple::Bottom() const {
    return bottom;
}

int mar::ThermometerSimple::Top() const {
    return top;
}

void mar::ThermometerSimple::Display() const {
    StringBasic::Fixed(tenths / 10.0 , 1).WriteLine();
}
