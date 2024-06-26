//
// Created by marco on 25-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRINGBASIC_H
#define PROGRAMACAOCOMCLASSES_STRINGBASIC_H

#include "Clonable.h"
#include <iostream>
#include <string>

namespace mar {
class StringBasic : public Clonable {
private:
    int   capacity;
    char *p;

private: // static
    static int defaultCapacity;

public: // static constants
    static const StringBasic uppercaseLetters;
    static const StringBasic lowercaseLetters;
    static const StringBasic letters;
    static const StringBasic digits;
    static const StringBasic null;

public:
    StringBasic();
    StringBasic(const StringBasic &other);
    StringBasic(const std::string &s);
    StringBasic(const char *s);
    StringBasic(const StringBasic &other1, const StringBasic &other2);
    StringBasic(const StringBasic &other, int startPos,
                int endPos); // pre other.ValidRange(startPos, endPos);
    explicit StringBasic(char c);
    StringBasic(char lowerBound, char upperBound);
    explicit StringBasic(int capacity); // pre capacity >= 1;
    StringBasic(const StringBasic &other,
                int capacity); // pre !other.Empty() && capacity >= 1
                               // post Full();
    virtual ~StringBasic();

    virtual Clonable    *Clone() const;
    virtual void         Copy(const StringBasic &other);
    virtual StringBasic &operator=(const StringBasic &other);
    virtual void         Set(const StringBasic &other);
    virtual void         Set(const StringBasic &other, int startPos,
                             int endPos); // pre other.ValidRange(startPos, endPos);
    virtual void         SwapOut(StringBasic &other);
    virtual void         CopySwap(const StringBasic &other);

    virtual int  Capacity() const;
    virtual int  Count() const;
    virtual bool Empty() const;
    virtual bool Full() const;

    virtual const char *Image() const;

    virtual void SetDefaultCapacity(int newDefaultCapacity);
    virtual void Append(const StringBasic &other);
    virtual void Prepend(const StringBasic &other);
    virtual void Select(int startPos,
                        int endPos); // pre ValidRange(startPos, endPos);
    virtual void Insert(const StringBasic &other,
                        int                x); // pre ValidPosition(x);
    virtual void
                 Replace(int startPos, int endPos,
                         const StringBasic &other); // pre ValidRange(startPos, endPos);
    virtual void Erase(int startPos,
                       int endPos); // pre ValidRange(startPos, endPos);
    virtual void Clear();           // post Empty();
    virtual void Head(int n);       // pre n >= 0;
    virtual void Tail(int n);       // pre n >= 0;
    virtual void Put(char c);       // pre !Full();
    virtual void Extend(char c);
    virtual void Insert(char c, int x); // pre ValidPosition(x);
    virtual void Precede(char c);

    virtual void Remove();        // pre !Empty();
    virtual void RemoveAt(int x); // pre ValidIndex(x);
    virtual void Prune(char c);
    virtual void PruneLast(char c);
    virtual void PruneAll(char c);

    virtual int         Position(const StringBasic &other) const;
    virtual int         LastPosition(const StringBasic &other) const;
    virtual int         Position(const StringBasic &other,
                                 int start) const; // pre ValidPosition(start);
    virtual int         LastPosition(const StringBasic &other,
                                     int start) const; // pre start < Count();
    virtual int         Position(const char c) const;
    virtual int         LastPosition(const char c) const;
    virtual int         Position(const char c,
                                 int        start) const; // pre ValidPosition(start);
    virtual int         LastPosition(const char c,
                                     int        start) const; // pre start < Count();
    virtual bool        Has(char c) const;
    virtual bool        HasString(const StringBasic &other) const;
    virtual const char &At(int x) const;      // pre ValidIndex(x);
    virtual char       &At(int x);            // pre ValidIndex(x);
    virtual void        PutAt(char c, int x); // pre ValidIndex(x);
    virtual const char &First() const;        // pre !Empt();
    virtual const char &Last() const;         // pre !Empt();

    virtual void RemoveLast();
    virtual void RemoveLast(int n); // pre n >= 0;
    virtual void RemoveFirst();
    virtual void RemoveFirst(int n); // pre n >= 0;

    virtual bool ValidIndex(int x) const;
    virtual bool ValidPosition(int x) const;
    virtual bool ValidRange(int x, int y) const;

    virtual bool        operator==(const StringBasic &other) const;
    virtual bool        operator!=(const StringBasic &other) const;
    virtual bool        operator<=(const StringBasic &other) const;
    virtual bool        operator<(const StringBasic &other) const;
    virtual bool        operator>=(const StringBasic &other) const;
    virtual bool        operator>(const StringBasic &other) const;
    virtual const char &operator[](int x) const; // pre ValidIndex(x);
    virtual char       &operator[](int x);       // pre ValidIndex(x);

    virtual StringBasic &operator+=(const StringBasic &other);
    virtual StringBasic &operator+=(char c);
    virtual StringBasic  operator+(const StringBasic &other) const;
    virtual StringBasic  operator+(char c) const;

    virtual StringBasic &operator*=(int n);      // pre n>=0;
    virtual StringBasic  operator*(int n) const; // pre n>=0;

    virtual operator std::string() const;

    virtual bool Equals(const StringBasic &other) const;
    virtual bool LessThan(const StringBasic &other) const;

    virtual void Write(std::ostream &output = std::cout) const;
    virtual void WriteLine(std::ostream &output = std::cout) const;
    virtual void Read(std::istream &input = std::cin);
    virtual void Read(std::istream &input, char delimiter);
    virtual void Read(char delimiter);
    virtual void Accept(const StringBasic &prompt);

    virtual void GrowTo(int n);
    virtual void Adjust(); // post Full();

    virtual const char &Item() const; // pre !Empt();
    virtual char       &Item();       // pre !Empt();

    virtual int CountIf(const StringBasic &other) const;
    virtual int CountIfNot(const StringBasic &other) const;

    virtual void PruneIf(const StringBasic &other);
    virtual void PruneIfNot(const StringBasic &other);

    virtual int PositionIf(const StringBasic &other) const;
    virtual int PositionIfNot(const StringBasic &other) const;
    virtual int LastPositionIf(const StringBasic &other) const;
    virtual int LastPositionIfNot(const StringBasic &other) const;
    virtual int PositionIf(const StringBasic &other,
                           int                start) const; // ore start>=0;
    virtual int PositionIfNot(const StringBasic &other,
                              int                start) const; // ore start>=0;
    virtual int LastPositionIf(const StringBasic &other,
                               int start) const; // ore start<Count();
    virtual int LastPositionIfNot(const StringBasic &other,
                                  int start) const; // ore start<Count();

    virtual void Trim();
    virtual void TrimLeft();
    virtual void TrimRight();

    virtual bool StartsBy(const StringBasic &other) const;
    virtual bool EndsBy(const StringBasic &other) const;

    virtual void Reverse();
    virtual void Swap(int x, int y); // pre ValidIndex(x) && ValidIndex(y);

    virtual void SendToBack();
    virtual void SendToBack(int n); // pre n >= 0;
    virtual void BringToFront();
    virtual void BringToFront(int n); // pre n >= 0;

    virtual void ToLowerCase();
    virtual void ToUpperCase();

    virtual int Sum() const;
    virtual int ArithmeticHash() const;
    virtual int Hash() const;

    virtual bool IsSorted() const;
    virtual void Sort(); // post IsSorted();
    virtual void Unique();

    virtual void Merge(const StringBasic &other);
    virtual void Intersect(const StringBasic &other);
    virtual void Subtract(const StringBasic &other);
    virtual bool Contains(const StringBasic &other) const;

    virtual void        Map(const StringBasic &from,
                            const StringBasic &to); // pre from.Count() <= to.Count();
    virtual StringBasic Applied(void (StringBasic::*F)()) const;

    virtual int AsInt(int base = 10) const; // pre 2 <= base && base <= 36;

public: // friend
    friend std::ostream &operator<<(std::ostream &output, const StringBasic &s);
    friend std::istream &operator>>(std::istream &input, StringBasic &s);

public: // static
    static int  i_strlen(const char *s);
    static void i_strcpy(char *s, const char *t);
    static char Digit(int x); // pre 0 <= x && x < 36;
    static int
    DigitValue(char c); // pre '0' <= c && c < '9' || 'A' <= c && c < 'Z';
    // pseudoconstructors
    static StringBasic Numeral(int n,
                               int base = 10); // pre 2 <= base && base <= 36;
    static StringBasic Fixed(double x, int precision = 6);
    static StringBasic Scientific(double x, int precision = 6);

private:
    virtual void ReadNext(std::istream &input, char delimiter);
    virtual void Reallocate(int newCapacity); // pre newCapacity >= Count() + 1;
    virtual void AppendNumeral(int n, int base); // pre 2 <= base && base <= 36;
    virtual void Quicksort(int lowerBound, int upperBound);
};
} // namespace mar

#endif // PROGRAMACAOCOMCLASSES_STRINGBASIC_H
