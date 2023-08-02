//
// Created by marco.martins on 24-06-2023.
//

#include "Thermograph.h"
#include "UtilityFunctions.h"
#include <cmath>
#include <iomanip>

namespace mar {
    Thermograph::Thermograph():
        ThermometerSimple(), temperatures() {
        temperatures.reserve(capacity);
    }

    Thermograph::Thermograph(int bottom, int top) : ThermometerSimple(bottom, top), temperatures() {
        temperatures.reserve(capacity);
    }

    Thermograph::Thermograph(const Thermograph &other):
        temperatures(other.temperatures) {

    }

    Thermograph::~Thermograph() {

    }

    void Thermograph::Take() {
        temperatures.push_back(Value());
    }

    void Thermograph::Reset() {
        temperatures.clear();
    }

    double Thermograph::Min() const {
        unsigned index = 0;
        for(unsigned i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] < temperatures[index]) {
                index = i;
            }
        }
        return temperatures[index];
    }

    double Thermograph::Max() const {
        unsigned index = 0;
        for(unsigned i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] > temperatures[index]) {
                index = i;
            }
        }
        return temperatures[index];
    }

    double Thermograph::Extent() const {
        return Max() - Min();
    }

    double Thermograph::Average() const {
        double sum = 0.0;
        for (unsigned i = 0; i < temperatures.size(); i++) {
            sum += temperatures[i];
        }
        return sum / temperatures.size();
    }

    double Thermograph::StandardDeviation() const {
        double sum = 0.0;
        double sum2 = 0.0;
        for (unsigned i = 0; i < temperatures.size(); i++) {
            sum += temperatures[i];
            sum2 += Square(temperatures[i]);
        }
        return std::sqrt((temperatures.size() * sum2 - Square(sum)) / Square(temperatures.size()));
    }

    int Thermograph::Count() const {
        return static_cast<int>(temperatures.size());
    }

    void Thermograph::Plot(std::ostream &output) {
        output << std::fixed << std::setprecision(1);
        for (unsigned i = 0; i < temperatures.size(); ++i) {
            output << temperatures[i] << std::endl;
        }
    }
} // mar