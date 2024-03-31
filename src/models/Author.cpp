//
// Created by m1martin on 04-03-2024.
//

#include "Author.h"

namespace mar {

Author::Author() {}

Author::Author(const StringBasic &name, int yearBorn)
    : name(name), yearBorn(yearBorn), yearDied(yearBorn - 1) {}

Author::Author(const StringBasic &name, int yearBorn, int yearDied)
    : name(name), yearBorn(yearBorn), yearDied(yearDied) {}

Clonable *Author::Clone() const {
    return new Author(*this);
}

void Author::Die(int year) {
    yearDied = year;
}

const StringBasic &Author::Name() const {
    return name;
}

int Author::YearBorn() const {
    return yearBorn;
}

int Author::YearDied() const {
    return yearDied;
}

bool Author::Dead() const {
    return yearBorn <= yearDied;
}

void Author::Write(std::ostream &output) const {
    output << name << ";" << yearBorn << ";" << yearDied << ";";
}

void Author::WriteLine(std::ostream &output) const {
    Write(output);
    output << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Author &a) {
    a.Write(output);
    return output;
}

} // namespace mar