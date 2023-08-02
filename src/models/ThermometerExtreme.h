//
// Created by Marco Martins on 18-06-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_THERMOMETEREXTREME_H
#define PROGRAMACAOCOMCLASSES_THERMOMETEREXTREME_H

#include "ThermometerSimple.h"
#include "StringBasic.h"

namespace mar {

    class ThermometerExtreme: public ThermometerSimple {
    private:
        double max;
        double min;
        int mode;
    private: //static
        static const StringBasic modes[];

    public:
        ThermometerExtreme();
        ThermometerExtreme(int bottom, int top); //pre bottom <= top
        ThermometerExtreme(const ThermometerExtreme &other);
        virtual ~ThermometerExtreme();

        virtual void WarmUp();
        virtual void CoolDown();
        virtual void Set(double degreesCelsius);
        virtual void Display() const;
        virtual void Reset();
        virtual double Min() const;
        virtual double Max() const;
        virtual void ChangeMode();

    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_THERMOMETEREXTREME_H
