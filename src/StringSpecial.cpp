//
// Created by marco on 25-03-2023.
//

#include "StringSpecial.h"
#include <iomanip>
#include "UtilityFunctions.h"

mar::StringSpecial::StringSpecial():StringBasic() {

}

mar::StringSpecial::StringSpecial(const mar::StringSpecial &other): StringBasic(other) {

}

mar::StringSpecial::StringSpecial(const mar::StringBasic &other) : StringBasic(other) {

}

mar::StringSpecial::StringSpecial(int capacity) : StringBasic(capacity) {

}

mar::StringSpecial::~StringSpecial() {

}


mar::Clonable *mar::StringSpecial::Clone() const {
    return new StringSpecial(*this);
}

void mar::StringSpecial::Copy(const mar::StringSpecial &other) {
    StringBasic::Copy(other);
}

mar::StringSpecial &mar::StringSpecial::operator=(const mar::StringSpecial &other) {
    Copy(other);
    return *this;
}

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

void mar::StringSpecial::UniqueNonAdjacent() {
    for (int i = Count() - 1; i > 0 ; --i) {
        if (Position(At(i)) < i) {
            RemoveAt(i);
        }
    }
}


bool mar::StringSpecial::Neighbor(const mar::StringBasic &other) const {
    switch (Count() - other.Count()) {
        case -1:
            return NeighborByInsertion(other);
        case 0:
            return operator==(other) ||
                    NeighborByExchange(other) ||
                    NeighborBySubstitution(other);
        case 1:
            return NeighborByRemoval(other);
        default:
            return false;
    }
}

bool mar::StringSpecial::NeighborByExchange(const mar::StringBasic &other) const {
    int i = MatchHead(other);
    int j = MatchTail(other);
    return i + j + 2 == Count() &&
        At(i) == other[i+1] &&
        At(i+1) == other[i];
}

bool mar::StringSpecial::NeighborBySubstitution(const mar::StringBasic &other) const {
    return MatchHead(other) + MatchTail(other) + 1 == Count();
}

bool mar::StringSpecial::NeighborByRemoval(const mar::StringBasic &other) const {
    return MatchHead(other) + MatchTail(other) >= Count() - 1;
}

bool mar::StringSpecial::NeighborByInsertion(const mar::StringBasic &other) const {
    return MatchHead(other) + MatchTail(other) >= Count();
}



void mar::StringSpecial::EraseDuplicateLines(std::istream &input, std::ostream &output) {
    StringBasic line;
    line.Read(input);
    while (input) {
        line.WriteLine(output);
        StringBasic current(line);
        do {
            line.Read(input);
        } while (input && line == current);
    }
}

int mar::StringSpecial::MatchHead(const mar::StringBasic &other) const {
    int limit = Min(this->Count(), other.Count());
    int i = 0;
    while (i < limit && At(i) == other[i]) {
        i++;
    }
    return i;
}

int mar::StringSpecial::MatchTail(const mar::StringBasic &other) const {
    int i = 0;
    for (int j = this->Count() - 1, k = other.Count() - 1;
        j >= 0 && k >= 0 && At(j) == other[k];
        j--, k--) {
        i++;
    }
    return i;
}

void mar::StringSpecial::WriteNeighbors(std::istream &input, std::ostream &output) const {
    StringBasic s;
    while (s.Read(input), input) {
        if (Neighbor(s)) {
            s.WriteLine(output);
        }
    }
}

