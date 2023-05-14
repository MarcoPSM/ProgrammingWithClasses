//
// Created by m1martin on 13-05-2023.
//

#include "StringDecimal.h"
#include "UtilityFunctions.h"

namespace mar {
    // public static consts
    const StringDecimal StringDecimal::zero(0);
    const StringDecimal StringDecimal::one(1);

    // constructors
    StringDecimal::StringDecimal(): StringBasic("0") {

    }

    StringDecimal::StringDecimal(const StringDecimal &other): StringBasic(other) {

    }

    StringDecimal::StringDecimal(int n) : StringBasic(StringBasic::Numeral(n)) {
        Reverse();
    }

    StringDecimal::StringDecimal(int n, int capacity):StringBasic(Max(capacity, CountDigits(n)+1)) {
        Append(Numeral(n));
        Reverse();
    }

    StringDecimal::StringDecimal(const StringBasic &other) : StringBasic(other) {
        Reverse();
        Normalize();
    }

    StringDecimal::~StringDecimal() {

    }

    // static pseudo constructors
    StringDecimal StringDecimal::Ten(int x) {
        return StringBasic('1') + StringBasic('0') * x;
    }

    // public functions
    Clonable *StringDecimal::Clone() const {
        return new StringDecimal(*this);
    }

    void StringDecimal::Copy(const StringDecimal &other) {
        StringBasic::Copy(other);
    }

    StringDecimal &StringDecimal::operator = (const StringDecimal &other) {
        Copy(other);
        return *this;
    }

    void StringDecimal::Add(const StringDecimal &other) {
        Append(StringBasic("0", Max(0, other.Count()- Count()) + 1 ));
        int count = Count();
        bool carry = false;
        for (int i = 0; i < count; ++i) {
            int x = DigitValue(At(i)) + other.DigitValueAt(i) + carry;
            PutAt(Digit(x%10), i);
            carry = x >= 10;
        }
        if (carry) {
            Extend('1');
        }
    }

    void StringDecimal::Subtract(const StringDecimal &other) {
        int count = Count();
        bool carry = false;
        for (int i = 0; i < count; ++i) {
            int x = 10 + DigitValue(At(i)) - other.DigitValueAt(i) - carry;
            PutAt(Digit(x%10), i);
            carry = x < 10;
        }
        Normalize();
    }

    void StringDecimal::Multiply(const StringDecimal &other) {
        StringDecimal a(*this);
        StringDecimal b(other);
        Set(zero);
        int count = b.Count();
        for (int i = 0; i < count; ++i) {
            StringDecimal temp(a);
            temp.Multiply(DigitValue(b[i]));
            Add(temp);
            a.Multiply10();
        }
    }

    void StringDecimal::Divide(const StringDecimal &other) {
        StringDecimal temp;
        Divide(other, temp);
    }

    void StringDecimal::Remainder(const StringDecimal &other) {
        StringDecimal temp;
        Divide(other, temp);
        SwapOut(temp);
    }


    void StringDecimal::Write(std::ostream &output) const {
        StringBasic temp(*this);
        temp.Reverse();
        temp.Write(output);
    }

    bool StringDecimal::operator==(const StringDecimal &other) const {
        return StringBasic::operator == (other);
    }

    bool StringDecimal::operator!=(const StringDecimal &other) const {
        return ! StringBasic::operator==(other);
    }

    bool StringDecimal::operator<=(const StringDecimal &other) const {
        if (this->Count() != other.Count()) {
            return this->Count() < other.Count();
        }
        else {
            StringBasic temp1(*this);
            StringBasic temp2(other);
            temp1.Reverse();
            temp2.Reverse();
            return temp1 <= temp2;
        }
    }

    bool StringDecimal::operator<(const StringDecimal &other) const {
        return operator<=(other) && !operator==(other);
    }

    bool StringDecimal::operator>=(const StringDecimal &other) const {
        return !operator<=(other) || operator==(other);
    }

    bool StringDecimal::operator>(const StringDecimal &other) const {
        return !operator<=(other);
    }

    bool StringDecimal::IsDecimal() const {
        return IsDecimal(*this);
    }

    bool StringDecimal::IsZero() const {
        return First() == '0' && Count() == 1;
    }

    bool StringDecimal::IsOne() const {
        return First() == '1' && Count() == 1;
    }

    StringDecimal &StringDecimal::operator+=(const StringDecimal &other) {
        Add(other);
        return *this;
    }

    StringDecimal &StringDecimal::operator-=(const StringDecimal &other) {
        Subtract(other);
        return *this;
    }

    StringDecimal &StringDecimal::operator*=(const StringDecimal &other) {
        Multiply(other);
        return *this;
    }

    StringDecimal &StringDecimal::operator/=(const StringDecimal &other) {
        Divide(other);
        return *this;
    }

    StringDecimal &StringDecimal::operator%=(const StringDecimal &other) {
        Remainder(other);
        return *this;
    }

    StringDecimal StringDecimal::operator+(const StringDecimal &other) const {
        StringDecimal result(*this);
        result += other;
        return result;
    }

    StringDecimal StringDecimal::operator-(const StringDecimal &other) const {
        StringDecimal result(*this);
        result -= other;
        return result;
    }

    StringDecimal StringDecimal::operator*(const StringDecimal &other) const {
        StringDecimal result(*this);
        result *= other;
        return result;
    }

    StringDecimal StringDecimal::operator/(const StringDecimal &other) const {
        StringDecimal result(*this);
        result /= other;
        return result;
    }

    StringDecimal StringDecimal::operator%(const StringDecimal &other) const {
        StringDecimal result(*this);
        result %= other;
        return result;
    }

    bool StringDecimal::IsDecimal(const StringBasic &s) {
        return !s.Empty() && s.CountIfNot(StringBasic('0', '9')) == 0;
    }

    StringDecimal StringDecimal::Factorial(int x) {
        StringDecimal result(1, 3*x);
        for (int i = 1; i <= x ; ++i) {
            result.Multiply(i);
        }
        result.Adjust();
        return result;
    }

    // private functions
    void StringDecimal::Normalize() {
        while (Count() > 1 && Last() == '0') {
            Remove();
        }
    }

    void StringDecimal::Add(int x) {
        int count = Count();
        int n = x;
        bool carry = false;
        for (int i = 0; i < count && n+carry > 0; ++i) {
            int s = DigitValue(At(i)) + n % 10 + carry;
            PutAt(Digit(s % 10), i);
            carry = s >= 10;
            n /= 10;
        }
        if (n + carry != 0) {
            Append(StringDecimal(n+carry));
        }
    }

    void StringDecimal::Subtract(int x) {
        int n = x;
        bool carry = false;
        for (int i = 0; n + carry > 0; ++i) {
            int s = 10 + DigitValue(At(i)) - n % 10 - carry;
            PutAt(Digit(s % 10), i);
            carry = s < 10;
            n /= 10;
        }
        Normalize();
    }

    void StringDecimal::Multiply(int x) {
        int carry = 0;
        int count = Count();
        for (int i = 0; i < count; ++i) {
            int s = x * DigitValue(At(i)) + carry;
            PutAt(Digit(s%10), i);
            carry = s / 10;
        }
        Append(StringDecimal(carry));
        Normalize();
    }

    void StringDecimal::Divide(int x) {
        int r;
        Divide(x, r);
    }

    void StringDecimal::Remainder(int x) {
        int r;
        Divide(x, r);
        StringDecimal temp(r);
        SwapOut(temp);
    }

    void StringDecimal::Divide(int x, int &r) {
        int remainder = 0;
        for (int i = Count() - 1; i >= 0; i--) {
            int s = 10 * remainder + DigitValue(At(i));
            PutAt(Digit(s / x), i);
            remainder = s % x;
        }
        Normalize();
        r = remainder;
    }

    void StringDecimal::Increment() {
        int count = Count();
        int i = 0;
        while (i<count && At(i) == '9') {
            PutAt('0', i++);
        }
        if (i == count) {
            Extend('0');
        }
        At(i)++;
    }

    void StringDecimal::Decrement() {
        int i = 0;
        while (At(i) == '0') {
            PutAt('9', i++);
        }
        At(i)--;
        Normalize();
    }

    const StringDecimal &StringDecimal::operator++(int) {
        Increment();
        return *this;
    }

    const StringDecimal &StringDecimal::operator--(int) {
        Decrement();
        return *this;
    }

    int StringDecimal::DigitValueAt(int x) const {
        return x < Count() ? DigitValue(At(x)) : 0;
    }

    void StringDecimal::Multiply10() {

        if (! operator == (zero)) {
            Precede('0');
        }
    }

    int StringDecimal::Modulus10() const {
        return DigitValue(First());
    }

    void StringDecimal::Divide10() {
        RemoveFirst();
        if (Empty()) {
            Put('0');
        }
    }

    void StringDecimal::Square() {
        Multiply(*this);
    }

    int StringDecimal::Power(int x, int y) {
        return y==0 ? 1 : Power(x*x,y/2) * (y%2==0 ? 1 : x);
    }

    void StringDecimal::Power(int x) {
        if (x==0) {
            Set(one);
        }
        else {
            PowerPositive(x);
        }
    }

    void StringDecimal::PowerPositive(int x) {
        if (x > 1) {
            StringDecimal temp(*this);
            Square();
            PowerPositive(x/2);
            if (x % 2 == 1) {
                Multiply(temp);
            }
        }
    }

    int StringDecimal::Divides(int x, int y) {
        int t = y;
        while (t <= x) {
            t *= 2;
        }
        int r = x;
        int q = 0;
        while (t != y) {
            t /= 2;
            q *= 2;
            if (t <= r) {
                r -= t;
                q++;
            }
        }
        return q;
    }

    void StringDecimal::Twice() {
        Multiply(2);
    }

    void StringDecimal::Halve() {
        Divide(2);
    }

    bool StringDecimal::IsOdd() const {
        return First() % 2 == 1;
    }

    void StringDecimal::Divide(const StringDecimal &other, StringDecimal &remainder) {
        if (this == &other) {
            Set(one);
            remainder.Set(zero);
            return;
        }
        StringDecimal t(other);
        while (operator>=(t)) {
            t.Twice();
        }
        StringDecimal r(*this);
        Set(zero);
        while (t != other) {
            t.Halve();
            Twice();
            if (t <= r) {
                r.Subtract(t);
                Increment();
            }
        }
        remainder.SwapOut(r);
    }


} // mar