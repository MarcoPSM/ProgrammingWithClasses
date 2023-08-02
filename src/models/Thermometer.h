//
// Created by m1martin on 04-06-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_THERMOMETER_H
#define PROGRAMACAOCOMCLASSES_THERMOMETER_H

namespace mar {

    class Thermometer {
    public:
        virtual ~Thermometer() {};
        virtual void WarmUp() = 0; //raise temperature by one unit
        virtual void CoolDown() = 0; //lowers temperature by one unit
        virtual void Set(double degreesCelsius) = 0; // pre Bottom() <= degreesCelsius && degreesCelsius <= Top();
        virtual double Value() const = 0;
        virtual int Bottom() const = 0;
        virtual int Top() const = 0;
        virtual void Display() const = 0;
    };

}


#endif //PROGRAMACAOCOMCLASSES_THERMOMETER_H
