//
// Created by marco on 25-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRINGBASIC_H
#define PROGRAMACAOCOMCLASSES_STRINGBASIC_H

#import "Clonable.h"
#import <string>
#include <iostream>

namespace mar {
    class StringBasic: public Clonable {
    private:
        int capacity;
        char *p;
    private: // static
        static int defaultCapacity;
    public:
        StringBasic();
        StringBasic(const StringBasic& other);
        StringBasic(const std::string& s);
        StringBasic(const char *s);
        StringBasic(const StringBasic& other1, const StringBasic& other2);
        StringBasic(const StringBasic& other, int startPos, int endPos); // pre other.ValidRange(startPos, endPos);
        explicit StringBasic(char c);
        StringBasic(char lowerBound, char upperBound);
        explicit StringBasic(int capacity); // pre capacity >= 1;
        StringBasic(const StringBasic& other, int capacity); // pre !other.Empty() && capacity >= 1
                                                             // post Full();
        virtual ~StringBasic();

        virtual Clonable* Clone() const;
        virtual void Copy(const StringBasic& other);
        virtual StringBasic& operator = (const StringBasic& other);

        virtual int Capacity() const;
        virtual int Count() const;
        virtual bool Empty() const;
        virtual bool Full() const;

        virtual const char *Image() const;

        virtual void SetDefaultCapacity(int newDefaultCapacity);
        virtual void Append(const StringBasic& other);
        virtual void Select(int startPos, int endPos); // pre ValidRange(startPos, endPos);
        virtual void Insert(const StringBasic& other, int x); // pre ValidPosition(x);
        virtual void Replace(int startPos, int endPos, const StringBasic& other); // pre ValidRange(startPos, endPos);

        virtual void Erase(int startPos, int endPos); // pre ValidRange(startPos, endPos);
        virtual void Clear(); // post Empty();
        virtual int Position(const StringBasic& other) const;
        virtual int LastPosition(const StringBasic& other) const;
        virtual const char& At(int x) const; // pre ValidIndex(x);
        virtual void PutAt(char c, int );    // pre ValidIndex(x);

        virtual bool ValidIndex(int x) const;
        virtual bool ValidPosition(int x) const;
        virtual bool ValidRange(int x, int y) const;

        virtual bool operator == (const StringBasic& other) const;
        virtual bool operator != (const StringBasic& other) const;
        virtual bool operator <= (const StringBasic& other) const;
        virtual bool operator <  (const StringBasic& other) const;
        virtual bool operator >= (const StringBasic& other) const;
        virtual bool operator >  (const StringBasic& other) const;

        virtual bool Equals(const StringBasic& other) const;
        virtual bool LessThan(const StringBasic& other) const;

        virtual void Write(std::ostream& output = std::cout) const;
        virtual void WriteLine(std::ostream& output = std::cout) const;
        virtual void Read(std::istream& input = std::cin);
        virtual void Read(std::istream& input, char delimiter);
        virtual void Read(char delimiter);

        virtual void GrowTo(int n);
        virtual void Adjust(); // post Full();

    public: // friend
        friend std::ostream& operator << (std::ostream& output, const StringBasic& s);
        friend std::istream& operator >> (std::istream&  input, const StringBasic& s);

    public: // static
        static int i_strlen(const char *s);
        static void i_strcpy(char *s, const char *t);
    };
}

#endif //PROGRAMACAOCOMCLASSES_STRINGBASIC_H
