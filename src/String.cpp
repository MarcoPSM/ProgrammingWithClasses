//
// Created by marco on 22-03-2023.
//

#include "String.h"

namespace mar {
    string::string(const std::string &x):
        std::string(x) {

    }

    string::string():
        std::string() {

    }

    string::~string() {

    }


    string string::applied(void (string::*f)()) const {
        string temp(*this);
        (temp.*f)();
        return temp;
    }

    bool string::ends_by(const std::string &s) const {
        return s.size() <= size() && substr(size() - s.size()) == s;
    }

    bool string::starts_by(const std::string &s) const {
        return substr(0, s.size()) == s;
    }

    bool string::is_blank() const {
        return find_first_not_of("\x20\t") == npos; // \x20 espaco \t tab
    }

    void string::trim_left() {
        erase(0, find_first_not_of("\x20\t"));
    }

    void string::trim_right() {
        erase(find_last_not_of("\x20\t") + 1);
    }

    void string::trim() {
        trim_left();
        trim_right();
    }

    void string::trim_all() {
        std::string result;
        result.reserve(size());
        int n = 0;
        for (size_type i = find_first_not_of("\x20\t");
            i != npos ;
            i = find_first_not_of("\x20\t"), i) {
            size_type j = find_first_of("\x20\t", i);
            if (n++ > 0) {
                result.push_back(' ');
            }
            result.append(substr(i, j-i));
            i = j;
        }
        swap(result);
    }

    void string::detab(int x) {
        std::string result;
        trim_right();
        result.reserve(x * size());
        for (std::string::const_iterator i = begin(); i != end() ; ++i) {
            if (*i != '\t') {
                result.push_back(*i);
            } else {
                result += std::string(x - result.size() % x, ' ');
            }
        }
        result.shrink_to_fit();
        swap(result);
    }

    void string::reverse() {
        for (size_type i = 0, j = size() - 1 ; i < j; ++i, --j) {
            std::swap(at(i), at(j));
        }
    }

    bool string::is_palindrome() const {
        return *this == applied(&string::reverse);
    }

    std::string string::first() const {
        return substr(0, find_first_of(" "));
    }

    std::string string::last() const {
        return substr(find_last_of(" ") + 1);
    }

    void string::prune_all(const std::string &s) {
        size_type x = 0;
        while ((x = find(s, x)) != npos) {
            erase(x, s.size());
        }
    }

    void string::replace_all(const std::string &s, const std::string &r) {
        size_type x = 0;
        while ((x = find(s, x)) != npos) {
            replace(x, s.size(), r);
            x += r.size();
        }
    }

} // mar