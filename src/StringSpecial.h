//
// Created by marco on 25-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRINGSPECIAL_H
#define PROGRAMACAOCOMCLASSES_STRINGSPECIAL_H

#include "StringBasic.h"

namespace mar {
    class StringSpecial: public StringBasic{
    public:
        StringSpecial();
        StringSpecial(const StringSpecial& other);
        StringSpecial(const StringBasic& other);
        explicit StringSpecial(int capacity);
        virtual ~StringSpecial();

        virtual Clonable* Clone() const;
        virtual void Copy(const StringSpecial& other);
        virtual StringSpecial& operator=(const StringSpecial& other);

        virtual void EraseMiddleNames();
        virtual void WriteLinesHavingThis(std::istream& input, std::ostream& output);
        virtual void WriteWithSpaces(std::ostream& output, int n) const;
        virtual int CountMatchingChars(const StringBasic& other) const;
        virtual void ClearNonMatchingChars(const StringBasic& other);
        virtual void InsertAtPosition(const StringBasic& other, char c);
        virtual void UniqueNonAdjacent();

        virtual bool Neighbor(const StringBasic& other) const;
        virtual bool NeighborByExchange(const StringBasic& other) const; // pre: *this != other && Count() == other.Count();
        virtual bool NeighborBySubstitution(const StringBasic& other) const; // pre: *this != other && Count() == other.Count();
        virtual bool NeighborByRemoval(const StringBasic& other) const; // pre: Count() == other.Count() + 1 ;
        virtual bool NeighborByInsertion(const StringBasic& other) const; // pre: Count() == other.Count() - 1;

        virtual int MatchHead(const StringBasic& other) const;
        virtual int MatchTail(const StringBasic& other) const;

        virtual void WriteNeighbors(std::istream& input, std::ostream& output) const;


    public: //static
        static void EraseDuplicateLines(std::istream& input, std::ostream& output);
    };
}


#endif //PROGRAMACAOCOMCLASSES_STRINGSPECIAL_H
