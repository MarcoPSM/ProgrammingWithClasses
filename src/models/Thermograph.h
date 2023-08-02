//
// Created by m1martin on 24-06-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_THERMOGRAPH_H
#define PROGRAMACAOCOMCLASSES_THERMOGRAPH_H

#include <vector>
#include <iostream>
#include "ThermometerSimple.h"

namespace mar {

    class Thermograph: public ThermometerSimple {
    private:
        static const int capacity = 128;
        std::vector<double> temperatures;

    public:
        Thermograph();
        Thermograph(int bottom, int top);
        Thermograph(const Thermograph &other);
        virtual ~Thermograph();

        virtual void Take(); // pre: Count() < capacity;
        virtual void Reset(); // post: Count() == 0;
        virtual double Min() const; //pre: Count() > 0;
        virtual double Max() const; //pre: Count() > 0;
        virtual double Extent() const; //pre: Count() > 0;
        virtual double Average() const; //pre: Count() > 0;
        virtual double StandardDeviation() const; //pre: Count() > 0;
        virtual int Count() const;
        virtual void Plot(std::ostream &output = std::cout);
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_THERMOGRAPH_H
