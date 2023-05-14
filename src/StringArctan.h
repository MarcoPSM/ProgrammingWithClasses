//
// Created by m1martin on 14-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRINGARCTAN_H
#define PROGRAMACAOCOMCLASSES_STRINGARCTAN_H

#include "StringDecimal.h"

namespace mar {

    class StringArctan: public StringDecimal {
    private:
        int precision;
        static const int extra; // extra digits, for round off errors.

    public:
        StringArctan(int precision);
        virtual ~StringArctan();

        virtual void Compute(int x, int y); // pre x <= y;
        virtual void Pi();

        virtual void Write(std::ostream& output = std::cout) const;

    public: // static
        static double Arctan(double x); // pre: -1.0 <= x && x <= 1.0;

    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_STRINGARCTAN_H
