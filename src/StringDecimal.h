//
// Created by m1martin on 13-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRINGDECIMAL_H
#define PROGRAMACAOCOMCLASSES_STRINGDECIMAL_H

#include "StringBasic.h"

namespace mar {

    class StringDecimal: public StringBasic {
        // invariant IsDecimal();
    public: // static consts
        static const StringDecimal zero;
        static const StringDecimal one;

    public:
        StringDecimal();
        StringDecimal(const StringDecimal& other);
        StringDecimal(int n); // pre: n >= 0;
        StringDecimal(int n, int capacity); // pre: n >= 0 && capacity >= 1;
        StringDecimal(const StringBasic& other); // pre: IsDecimal(other);
        virtual ~StringDecimal();

        // static pseudo constructors
        static StringDecimal Ten(int x = 1); // pre: x >= 0;

        // public functions
        virtual Clonable* Clone() const;
        virtual void Copy(const StringDecimal& other);
        virtual StringDecimal& operator=(const StringDecimal& other);

        virtual int DigitValueAt(int x) const; // pre: x >= 0;


        virtual void Add(const StringDecimal& other);
        virtual void Subtract(const StringDecimal& other); // pre: operator >= (other);
        virtual void Multiply(const StringDecimal& other);
        virtual void Divide(const StringDecimal& other); // pre: !other.IsZero();
        virtual void Remainder(const StringDecimal& other); // pre: !other.IsZero();
        virtual void Divide(const StringDecimal& other, StringDecimal& remainder); // pre: !other.IsZero();

        virtual void Add(int x); // pre: x >= 0;
        virtual void Subtract(int x); // pre: operator >= (x);
        virtual void Multiply(int x); // pre: x >= 0
        virtual void Divide(int x);  // pre: x > 0;
        virtual void Remainder(int x);  // pre: x > 0;
        virtual void Divide(int x, int& r);  // pre: x > 0; // r is the remainder

        virtual void Write(std::ostream& output = std::cout) const;

        virtual bool operator == (const StringDecimal& other) const;
        virtual bool operator != (const StringDecimal& other) const;
        virtual bool operator <= (const StringDecimal& other) const;
        virtual bool operator <  (const StringDecimal& other) const;
        virtual bool operator >= (const StringDecimal& other) const;
        virtual bool operator >  (const StringDecimal& other) const;

        virtual bool IsDecimal() const;
        virtual bool IsZero() const;
        virtual bool IsOne() const;

        virtual StringDecimal& operator += (const StringDecimal& other);
        virtual StringDecimal& operator -= (const StringDecimal& other);
        virtual StringDecimal& operator *= (const StringDecimal& other);
        virtual StringDecimal& operator /= (const StringDecimal& other);
        virtual StringDecimal& operator %= (const StringDecimal& other);

        virtual StringDecimal operator + (const StringDecimal& other) const;
        virtual StringDecimal operator - (const StringDecimal& other) const;
        virtual StringDecimal operator * (const StringDecimal& other) const;
        virtual StringDecimal operator / (const StringDecimal& other) const;
        virtual StringDecimal operator % (const StringDecimal& other) const;

        virtual void Increment();
        virtual void Decrement(); // pre: !IsZero();

        virtual const StringDecimal& operator ++ (int);
        virtual const StringDecimal& operator -- (int); // pre: !IsZero();

        virtual void Multiply10();
        virtual int Modulus10() const;
        virtual void Divide10();

        virtual void Square();
        virtual void Power(int x); // pre: x >= 0;
        virtual void PowerPositive(int x); // pre: x >= 1;

        virtual void Twice();
        virtual void Halve();
        virtual bool IsOdd() const;

    public: // static
        static bool IsDecimal(const StringBasic& s);
        static int Power(int x, int y);

    public: // examples
        static StringDecimal Factorial(int x);
        static int Divides(int x, int y);

    private: // functions
        virtual void Normalize(); // pre: !Empty();
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_STRINGDECIMAL_H
