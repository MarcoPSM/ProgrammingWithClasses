//
// Created by m1martin on 14-05-2023.
//

#include "StringArctan.h"

namespace mar {

    const int StringArctan::extra = 10;

    StringArctan::StringArctan(int precision):
        StringDecimal(precision, precision + extra + 2),
        precision(precision) {

    }

    StringArctan::~StringArctan() {

    }

    void StringArctan::Compute(int x, int y) {
        Set(Ten(precision + extra));
        Multiply(x);
        Divide(y);
        StringDecimal term(*this);
        int i = 1;
        while (!term.IsZero()) {
            term.Multiply(x*x);
            term.Divide(y*y);
            i += 2;
            StringDecimal temp(term);
            temp.Divide(i);
            if (i % 4 == 1) {
                Add(temp);
            }
            else {
                Subtract(temp);
            }

        }
    }

    void StringArctan::Pi() {
        StringArctan s1(precision);
        s1.Compute(1, 10);
        StringArctan s2(precision);
        s2.Compute(1, 515);
        StringArctan s3(precision);
        s3.Compute(1, 239);
        s1.Multiply(8);
        s2.Multiply(4);
        Copy(s1);
        Subtract(s2);
        Subtract(s3);
        Multiply(4);
    }

    void StringArctan::Write(std::ostream &output) const {
        StringDecimal temp(*this);
        temp.RemoveFirst(extra);
        if (temp.Count() < precision) {
            temp.Append(StringBasic("0", precision - temp.Count() + 1));
        }
        temp.Write(output);
    }

    double StringArctan::Arctan(double x) {
        double numerator = x;
        int i = 1;
        int sign = 1;
        double term = numerator;
        double result = term;
        double previous = 0.0;
        while (result != previous) {
            previous = result;
            numerator *= x * x ;
            i += 2;
            sign *= -1;
            term = sign * numerator / i;
            result += term;
        }
        return result;
    }
} // mar