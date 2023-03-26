//
// Created by marco on 25-03-2023.
//

#include "StringSpecial.h"
#include <iomanip>
#include "UtilityFunctions.h"

void mar::StringSpecial::EraseMiddleNames() {
    Erase(Position(" ") + 1, LastPosition(" "));
}

void mar::StringSpecial::WriteLinesHavingThis(std::istream &input, std::ostream &output) {
    StringBasic line;
    int count = 0;
    for (;;) {
        line.Read(input);
        if (!input) {
            break;
        }
        count++;
        if (line.HasString(*this)) {
            output << count << " " << line << std::endl;
        }
    }
}

void mar::StringSpecial::WriteWithSpaces(std::ostream &output, int n) const {
    int count = Count();
    for(int i = 0; i < count - 1; i++) {
        output << At(i) << std::setw(n) <<"";
    }
    output << At(count - 1);
}

int mar::StringSpecial::CountMatchingChars(const mar::StringBasic &other) const {
    int result = 0;
    int count = Min(this->Count(), other.Count());
    for (int i = 0; i < count; ++i) {
        if (this->At(i) == other.At(i)) {
            result++;
        }
    }
    return result;
}

void mar::StringSpecial::ClearNonMatchingChars(const mar::StringBasic &other) {
    int count = Min(this->Count(), other.Count());
    for (int i = 0; i < count; ++i) {
        if (this->At(i) != other.At(i)) {
            PutAt(' ', i);
        }
    }
    for (int j = count; j < this->Count(); ++j) {
        PutAt(' ', j);
    }
}

void mar::StringSpecial::InsertAtPosition(const mar::StringBasic &other, char c) {
    int x = Position(c);
    Insert(other, x != -1 ? x : Count());
}
