//
// Created by m1martin on 24-06-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_THERMOMETERMULTI_H
#define PROGRAMACAOCOMCLASSES_THERMOMETERMULTI_H

#include <vector>
#include "Thermometer.h"
#include "ThermometerExtreme.h"

namespace mar {

    class ThermometerMulti: public Thermometer {
    private:
        std::vector<ThermometerExtreme> t;
        int count;
        int input;
        int output;

    public:

        ThermometerMulti(int count = 2); //pre count(>=1);
        ThermometerMulti(const ThermometerMulti& other);
        virtual ~ThermometerMulti();

        virtual int Count() const;
        virtual void WarmUp();
        virtual void CoolDown();
        virtual void Set(double degreesCelsius);
        virtual void Reset();
        virtual double Value() const;
        virtual double Min() const;
        virtual double Max() const;
        virtual int Bottom() const;
        virtual int Top() const;
        virtual void ChangeMode();
        virtual void Display() const;

        virtual void ChangeOutputStation();
        virtual void SelectInputStation(int x); // pre 0<= x && x < Count();
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_THERMOMETERMULTI_H
