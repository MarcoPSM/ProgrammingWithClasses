//
// Created by m1martin on 04-06-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_THERMOMETERSIMPLE_H
#define PROGRAMACAOCOMCLASSES_THERMOMETERSIMPLE_H

#include "Thermometer.h"

namespace mar {

    class ThermometerSimple: public Thermometer {
    private:
        int bottom; // degreesCelsius
        int top; // degreesCelsius
        int tenths; // tenths of degreesCelsius

    public:
        ThermometerSimple();
        ThermometerSimple(int bottom, int top); //pre bottom <= top
        ThermometerSimple(const ThermometerSimple &other);
        virtual ~ThermometerSimple();

        virtual void WarmUp();
        virtual void CoolDown();
        virtual void Set(double degreesCelsius);
        virtual double Value() const;
        virtual int Bottom() const;
        virtual int Top() const;
        virtual void Display() const;

    private: // static
        static const int defaultBottom = -40;
        static const int defaultTop = 80;
    };

}


#endif //PROGRAMACAOCOMCLASSES_THERMOMETERSIMPLE_H
