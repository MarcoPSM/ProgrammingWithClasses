//
// Created by marco on 25-03-2023.
//

#include "string_name.h"

const std::string mar::string_name::particles[count_particles] = {
        "de", "da", "do", "das", "dos", "e"
};

mar::string_name::string_name():
    string() {

}

mar::string_name::string_name(const mar::string &x):
    string(x) {

}

mar::string_name::string_name(const std::string &x):
    string(x) {

}

mar::string_name mar::string_name::artistic() const {
    string_name result = first();
    if (find(" ") != npos) {
        result += " " + last();
    }
    return result;
}

mar::string_name mar::string_name::normalized() const {
    string_name result(*this);
    for (int i = 0; i < count_particles; ++i) {
        result.replace_all(" " + particles[i] + " ", " ");
    }
    return result;
}

mar::string_name mar::string_name::telephonic() const {
    string_name result = last();
    if (find(" ") != npos) {
        result += ", " + substr(0, find_last_of(" "));
    }
    return result;
}

mar::string_name mar::string_name::initialized() const {
    string_name temp = normalized();
    string_name result = temp.first();
    if (temp.find(" ") != npos) {
        std::string m = temp.initials();
        if (m.size() > 2) {
            result += " " + m.substr(1, m.size() - 2);
        }
        result += " " + temp.last();
    }
    return result;
}

mar::string_name mar::string_name::initials() const {
    string_name result;
    result.reserve(size() / 4 + 1); // a guess
    for (size_type i = 0; i != std::string::npos; i = find_first_not_of(" ", find_first_of(" ", i))) {
        result.push_back(at(i));
    }
    return result;
}
