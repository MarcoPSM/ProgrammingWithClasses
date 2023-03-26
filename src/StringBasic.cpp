//
// Created by marco on 25-03-2023.
//

#include "StringBasic.h"
#include <cstring>
#include "UtilityFunctions.h"

namespace mar {

    int StringBasic::defaultCapacity = 16;

    StringBasic::StringBasic():
        capacity(defaultCapacity), p(new char[defaultCapacity]) {
        *p = 0;
    }

    StringBasic::StringBasic(const StringBasic &other):
        capacity(other.capacity), p(new char[capacity]) {
        std::strcpy(p, other.p);
    }

    StringBasic::StringBasic(const std::string &s):
        capacity(s.size()+1), p(new char[capacity]) {
        std::strcpy(p, s.c_str());
    }

    StringBasic::StringBasic(const char *s):
        capacity(i_strlen(s)), p(new char[capacity]) {
        i_strcpy(p, s);
    }

    StringBasic::StringBasic(const StringBasic &other1, const StringBasic &other2):
        capacity(other1.Count() + other2.Count() + 1), p(new char[capacity]) {
        std::strcat(std::strcpy(p, other1.p), other2.p);
    }

    StringBasic::StringBasic(const StringBasic &other, int startPos, int endPos):
        capacity(endPos - startPos + 2), p(new char[capacity]) {
        std::strncpy(p, other.p + startPos, capacity - 1);
        p[capacity-1] = 0;
    }

    StringBasic::StringBasic(char c):
        capacity(2), p(new char[capacity]) {
        p[0] = c;
        p[1] = 0;
    }

    StringBasic::StringBasic(char lowerBound, char upperBound):
        capacity(Max(0, upperBound - lowerBound + 1) + 1), p(new char[capacity]) {
        for (int i = 0; i < capacity - 1; ++i) {
            p[i] = static_cast<char>(lowerBound + i);
        }
        p[capacity - 1] = 0;
    }

    StringBasic::StringBasic(int capacity):
        capacity(capacity), p(new char[capacity]) {
        *p = 0;
    }

    StringBasic::StringBasic(const StringBasic &other, int capacity):
        capacity(capacity), p(new char[capacity]) {
        int count = other.Count();
        for (int i = 0; i < capacity - 1; ++i) {
            p[i] = other.p[i % count];
        }
        p[capacity-1] = 0;
    }

    StringBasic::~StringBasic() {
        delete [] p;
    }


    Clonable *StringBasic::Clone() const {
        return new StringBasic(*this);
    }

    void StringBasic::Copy(const StringBasic &other) {
        if (this != &other) {
            delete [] this->p;
            this->capacity = other.Count() + 1;
            this->p = new char[this->capacity];
            std::strcpy(this->p, other.p);
        }
    }

    StringBasic &StringBasic::operator=(const StringBasic &other) {
        Copy(other);
        return *this;
    }

    void StringBasic::Set(const StringBasic &other) {
        if (this != &other) {
            Clear();
            Append(other);
        }
    }

    void StringBasic::Set(const StringBasic &other, int startPos, int endPos) {
        Set(StringBasic(other, startPos, endPos));
    }

    void StringBasic::SwapOut(StringBasic &other) {
        std::swap(capacity, other.capacity);
        std::swap(p, other.p);
    }

    void StringBasic::CopySwap(const StringBasic &other) {
        StringBasic temp(other);
        SwapOut(temp);
    }


    int StringBasic::Capacity() const {
        return capacity;
    }

    int StringBasic::Count() const {
        return std::strlen(p);
    }

    bool StringBasic::Empty() const {
        return *p == 0;
    }

    bool StringBasic::Full() const {
        return Count() == capacity - 1;
    }


    const char *StringBasic::Image() const {
        return p;
    }


    void StringBasic::SetDefaultCapacity(int newDefaultCapacity) {
        defaultCapacity = newDefaultCapacity;
    }


    void StringBasic::Append(const StringBasic &other) {
        if (this != &other) {
            GrowTo(this->Count() + other.Count() + 1);
            std::strcat(this->p, other.p);
        } else {
            Append(StringBasic(*this));
        }
    }

    void StringBasic::Prepend(const StringBasic &other) {
        Insert(other, 0);
    }


    void StringBasic::Select(int startPos, int endPos) {
        Head(endPos + 1);
        Erase(0, startPos - 1);
    }

    void StringBasic::Insert(const StringBasic &other, int x) {
        Replace(x, x-1, other);
    }

    void StringBasic::Replace(int startPos, int endPos, const StringBasic &other) {
        if (this != &other) {
            StringBasic temp(*this, endPos + 1, Count() - 1);
            Head(startPos);
            GrowTo(Count() - (endPos - startPos + 1) + other.Count() + 1);
            Append(other);
            Append(temp);
        } else {
            Replace(startPos, endPos, StringBasic(*this));
        }
    }

    void StringBasic::Erase(int startPos, int endPos) {
        std::memmove(p + startPos, p + endPos + 1, Count() - endPos);
    }

    void StringBasic::Clear() {
        *p = 0;
    }

    void StringBasic::Head(int n) {
        if (n<Count()) {
            p[n] = 0;
        }
    }

    void StringBasic::Tail(int n) {
        int count = Count();
        if (n < count) {
            std::memmove(p, p + count - n, n+1);
        }
    }

    void StringBasic::Put(char c) {
        int x = Count();
        p[x] = c;
        p[x + 1] = 0;
    }

    void StringBasic::Extend(char c) {
        GrowTo(Count() + 2);
        Put(c);
    }

    void StringBasic::Insert(char c, int x) {
        int count = Count();
        GrowTo(count + 2);
        std::memmove(p+x+1, p+x, count+1-x);
        p[x] = c;
    }

    void StringBasic::Precede(char c) {
        Insert(c, 0);
    }


    void StringBasic::Remove() {
        p[Count() - 1] = 0;
    }

    void StringBasic::RemoveAt(int x) {
        std::memmove(p+x, p+x+1, Count() - x);
    }

    void StringBasic::Prune(char c) {
        int x = Position(c);
        if (x != -1) {
            RemoveAt(x);
        }
    }

    void StringBasic::PruneLast(char c) {
        int x = LastPosition(c);
        if (x != -1) {
            RemoveAt(x);
        }
    }

    void StringBasic::PruneAll(char c) {
        int j = 0;
        for (int i = 0; p[i] != 0 ; ++i) {
            if (p[i] != c) {
                p[j++] = p[i];
            }
        }
        p[j] = 0;
    }


    int StringBasic::Position(const StringBasic &other) const {
        return Position(other, 0);
    }

    int StringBasic::LastPosition(const StringBasic &other) const {
        return LastPosition(other, Count() - 1);
    }

    int StringBasic::Position(const StringBasic &other, int start) const {
        const char* q = std::strstr(this->p + start, other.p);
        return q != 0 ? q - p : -1;
    }

    int StringBasic::LastPosition(const StringBasic &other, int start) const {
        for (int i = start; i >= 0 ; --i) {
            if (std::strstr(this->p+i, other.p) != 0) {
                return i;
            }
        }
        return -1;
    }

    int StringBasic::Position(const char c) const {
        return Position(c, 0);
    }

    int StringBasic::LastPosition(const char c) const {
        const char* q = std::strchr(p, c);
        return static_cast<int>(q != 0 ? q-p : -1);
    }

    int StringBasic::Position(const char c, int start) const {
        const char* q = std::strchr(p+start, c);
        return static_cast<int>(q != 0 ? q-p : -1);
    }

    int StringBasic::LastPosition(const char c, int start) const {
        for (int i = start; i >= 0 ; --i) {
            if (p[i] == c) {
                return i;
            }
        }
        return -1;
    }

    bool StringBasic::Has(char c) const {
        return std::strchr(p, c) != 0;
    }

    bool StringBasic::HasString(const StringBasic &other) const {
        return std::strstr(this->p, other.p) != 0;
    }

    const char &StringBasic::At(int x) const {
        return p[x];
    }

    char &StringBasic::At(int x) {
        return p[x];
    }

    void StringBasic::PutAt(char c, int x) {
        p[x] = c;
    }

    const char &StringBasic::First() const {
        return *p;
    }

    const char &StringBasic::Last() const {
        return p[Count() - 1];
    }

    void StringBasic::RemoveLast() {
        RemoveLast(1);
    }

    void StringBasic::RemoveLast(int n) {
        Head(mar::Max(0, Count() - n));
    }

    void StringBasic::RemoveFirst() {
        RemoveFirst(1);
    }

    void StringBasic::RemoveFirst(int n) {
        Tail(mar::Max(0, Count() - n));
    }


    bool StringBasic::ValidIndex(int x) const {
        return 0 <= x && x < Count();
    }

    bool StringBasic::ValidPosition(int x) const {
        return 0 <= x && x <= Count();
    }

    bool StringBasic::ValidRange(int x, int y) const {
        return ValidPosition(x) && ValidPosition(y+1) && x<=y+1;
    }


    bool StringBasic::operator==(const StringBasic &other) const {
        return std::strcmp(this->p, other.p) == 0;
    }

    bool StringBasic::operator!=(const StringBasic &other) const {
        return !operator==(other);
    }

    bool StringBasic::operator<=(const StringBasic &other) const {
        return std::strcmp(this->p, other.p) <= 0;
    }

    bool StringBasic::operator<(const StringBasic &other) const {
        return std::strcmp(this->p, other.p) < 0;
    }

    bool StringBasic::operator>=(const StringBasic &other) const {
        return !operator<(other);
    }

    bool StringBasic::operator>(const StringBasic &other) const {
        return !operator<=(other);
    }

    const char& StringBasic::operator[](int x) const {
        return p[x];
    }

    char &StringBasic::operator[](int x) {
        return p[x];
    }


    StringBasic &StringBasic::operator+=(const StringBasic &other) {
        Append(other);
        return *this;
    }

    StringBasic &StringBasic::operator+=(char c) {
        Extend(c);
        return *this;
    }

    StringBasic StringBasic::operator+(const StringBasic &other) const {
        return StringBasic(*this, other);
    }

    StringBasic StringBasic::operator+(char c) const {
        return StringBasic(*this, StringBasic(c));
    }

    StringBasic &StringBasic::operator*=(int n) {
        StringBasic temp(*this);
        Clear();
        GrowTo(n * temp.Count() + 1);
        for (int i = 0; i < n; ++i) {
            Append(temp);
        }
        return *this;
    }

    StringBasic StringBasic::operator*(int n) const {
        return StringBasic(*this, Count() * n + 1);
    }


    bool StringBasic::Equals(const StringBasic &other) const {
        return std::strcmp(this->p, other.p) == 0;
    }

    bool StringBasic::LessThan(const StringBasic &other) const {
        return std::strcmp(this->p, other.p) <= 0;
    }


    void StringBasic::Write(std::ostream &output) const {
        output << p;
    }

    void StringBasic::WriteLine(std::ostream &output) const {
        Write(output);
        output << std::endl;
    }

    void StringBasic::Read(std::istream &input) {
        Read(input, '\n');
    }

    void StringBasic::Read(std::istream &input, char delimiter) {
        /* slower version
        Clear();
        int c;
        while(c = input.get(), input && c != delimiter) {
            Extend(static_cast<char>(c));
        }
         */
        Clear();
        input.getline(p, capacity, delimiter);
        if (input.fail() && !input.eof()) {
            ReadNext(input, delimiter);
        }
    }

    void StringBasic::Read(char delimiter) {
        Read(std::cin, delimiter);
    }

    void StringBasic::Accept(const StringBasic &prompt) {
        prompt.Write();
        Read();
    }


    void StringBasic::GrowTo(int newCapacity) {
        if (newCapacity > capacity) {
            Reallocate(newCapacity);
        }
    }

    void StringBasic::Adjust() {
        if (!Full()) {
            Reallocate(Count() + 1);
        }
    }

    const char &StringBasic::Item() const {
        return p[Count() - 1];
    }

    char &StringBasic::Item() {
        return p[Count() - 1];
    }


    std::ostream &operator<<(std::ostream &output, const StringBasic &s) {
        s.Write(output);
        return output;
    }

    std::istream &operator>>(std::istream &input, StringBasic &s) {
        s.Read(input);
        return input;
    }


    int StringBasic::i_strlen(const char *s) {
        int i = 0;
        while (s[i != 0]) {
            i++;
        }
        return i;
    }

    void StringBasic::i_strcpy(char *s, const char *t) {
        int i;
        for (i = 0; t[i] != 0 ; ++i) {
            s[i] = t[i];
        }
        s[i] = 0;
    }

    void StringBasic::EraseDuplicateLines(std::istream &input, std::ostream &output) {
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

    // PRIVATE
    void StringBasic::ReadNext(std::istream &input, char delimiter) {
        input.clear();
        GrowTo(2*capacity);
        input.getline(p+capacity / 2 - 1, capacity / 2 + 1, delimiter);
        if (input.fail() && !input.eof()) {
            ReadNext(input, delimiter);
        }
    }

    void StringBasic::Reallocate(int newCapacity) {
        char *q = p;
        p = new char[newCapacity];
        capacity = newCapacity;
        std::strcpy(p, q);
        delete [] q;
    }


}