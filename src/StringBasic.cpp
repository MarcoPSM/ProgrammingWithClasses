//
// Created by marco on 25-03-2023.
//

#include "StringBasic.h"

namespace mar {

    int StringBasic::defaultCapacity = 16;

    StringBasic::StringBasic():
        capacity(defaultCapacity), p(new char[defaultCapacity]) {
        *p = 0;
    }

    StringBasic::StringBasic(const StringBasic &other) {

    }

    StringBasic::StringBasic(const std::string &s) {

    }

    StringBasic::StringBasic(const char *s):
        capacity(i_strlen(s)), p(new char[capacity]) {
        i_strcpy(p, s);
    }

    StringBasic::StringBasic(const StringBasic &other1, const StringBasic &other2) {

    }

    StringBasic::StringBasic(const StringBasic &other, int startPos, int endPos) {

    }

    StringBasic::StringBasic(char c) {

    }

    StringBasic::StringBasic(char lowerBound, char upperBound) {

    }

    StringBasic::StringBasic(int capacity):
        capacity(capacity), p(new char[capacity]) {
        *p = 0;
    }

    StringBasic::StringBasic(const StringBasic &other, int capacity) {

    }

    StringBasic::~StringBasic() {

    }


    Clonable *StringBasic::Clone() const {
        return nullptr;
    }

    void StringBasic::Copy(const StringBasic &other) {

    }

    StringBasic &StringBasic::operator=(const StringBasic &other) {
        return *this;
    }


    int StringBasic::Capacity() const {
        return 0;
    }

    int StringBasic::Count() const {
        return 0;
    }

    bool StringBasic::Empty() const {
        return false;
    }

    bool StringBasic::Full() const {
        return false;
    }


    const char *StringBasic::Image() const {
        return nullptr;
    }


    void StringBasic::SetDefaultCapacity(int newDefaultCapacity) {
        defaultCapacity = newDefaultCapacity;
    }

    void StringBasic::Append(const StringBasic &other) {

    }

    void StringBasic::Select(int startPos, int endPos) {

    }

    void StringBasic::Insert(const StringBasic &other, int x) {

    }

    void StringBasic::Replace(int startPos, int endPos, const StringBasic &other) {

    }


    void StringBasic::Erase(int startPos, int endPos) {

    }

    void StringBasic::Clear() {

    }

    int StringBasic::Position(const StringBasic &other) const {
        return 0;
    }

    int StringBasic::LastPosition(const StringBasic &other) const {
        return 0;
    }

    const char &StringBasic::At(int x) const {
        return p[x];
    }

    void StringBasic::PutAt(char c, int) {

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
        return false;
    }

    bool StringBasic::operator!=(const StringBasic &other) const {
        return false;
    }

    bool StringBasic::operator<=(const StringBasic &other) const {
        return false;
    }

    bool StringBasic::operator<(const StringBasic &other) const {
        return false;
    }

    bool StringBasic::operator>=(const StringBasic &other) const {
        return false;
    }

    bool StringBasic::operator>(const StringBasic &other) const {
        return false;
    }


    bool StringBasic::Equals(const StringBasic &other) const {
        return false;
    }

    bool StringBasic::LessThan(const StringBasic &other) const {
        return false;
    }


    void StringBasic::Write(std::ostream &output) const {

    }

    void StringBasic::WriteLine(std::ostream &output) const {

    }

    void StringBasic::Read(std::istream &input) {

    }

    void StringBasic::Read(std::istream &input, char delimiter) {

    }

    void StringBasic::Read(char delimiter) {

    }


    void StringBasic::GrowTo(int n) {

    }

    void StringBasic::Adjust() {

    }


    std::ostream &operator<<(std::ostream &output, const StringBasic &s) {
        return output;
    }

    std::istream &operator>>(std::istream &input, const StringBasic &s) {
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


}