//
// Created by marco on 25-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRINGSPECIAL_H
#define PROGRAMACAOCOMCLASSES_STRINGSPECIAL_H

#include "StringBasic.h"

namespace mar {
    class StringSpecial: public StringBasic{
    public:
        virtual void EraseMiddleNames();
        virtual void WriteLinesHavingThis(std::istream& input, std::ostream& output);
        virtual void WriteWithSpaces(std::ostream& output, int n) const;
        virtual int CountMatchingChars(const StringBasic& other) const;
        virtual void ClearNonMatchingChars(const StringBasic& other);
        virtual void InsertAtPosition(const StringBasic& other, char c);
    };
}


#endif //PROGRAMACAOCOMCLASSES_STRINGSPECIAL_H
