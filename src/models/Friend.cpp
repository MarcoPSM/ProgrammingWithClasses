//
// Created by Marco Martins on 24-06-2023.
//

#include "Friend.h"

namespace mar {
    Friend::Friend() {

    }

    Friend::Friend(const Friend &other):
        Person(other), level(other.level), year(other.year), partner(other.partner), birthdate(other.birthdate) {

    }

    Friend::Friend(const Person &p, int level, int year):
        Person(p), level(level), year(year), partner(0), birthdate(Date().First()) {

    }

    Friend::Friend(const Person &p, int level, int year, const Person &partner):
        Person(p), level(level), year(year), partner(&partner), birthdate(Date().First()) {

    }

    Friend::~Friend() {

    }

    Clonable *Friend::Clone() const {
        return new Friend(*this);
    }

    void Friend::Copy(const Friend &other) {
        Person::Copy(other);
        this->level = other.level;
        this->year = other.year;
        this->partner = other.partner;
        this->birthdate = other.birthdate;
    }

    Friend &Friend::operator=(const Friend &other) {
        Copy(other);
        return *this;
    }

    int Friend::Level() const {
        return level;
    }

    void Friend::RaiseLevel(int x) {
        level += x;
    }

    void Friend::LowerLevel(int x) {
        level -= x;
    }

    int Friend::Year() const {
        return year;
    }

    int Friend::Duration() const {
        return Date().Year() - year;
    }

    bool Friend::BetterFriendThan(const Friend &other) const {
        return level > other.level || level == other.level && year <= other.year;
    }

    bool Friend::Single() const {
        return partner == 0;
    }

    const Person &Friend::Partner() const {
        return *partner;
    }

    void Friend::Marry(const Person &p) {
        partner = &p;
    }

    void Friend::Divorce() {
        partner = 0;
    }

    bool Friend::MarriedToFriend() const {
        return dynamic_cast<const Friend *>(partner) != 0;
    }

    int Friend::JointLevel() const {
        int result = level;
        if (const Friend *p = dynamic_cast<const Friend *>(partner)) {
            result += p->level;
        }
        return result;
    }

    void Friend::SetBirthdate(const Date &d) {
        birthdate = d;
    }

    bool Friend::BirthdateKnown() const {
        return birthdate != Date().First();
    }

    const Date &Friend::Birthdate() const {
        return birthdate;
    }

    int Friend::Age() const {
        return Date().Age(birthdate);
    }

    void Friend::Write(std::ostream &output) const {
        Person::Write(output);
        output << level << ";" << year << ";";
        if (!Single()) {
            partner->Name().Write(output);
        }
        output << ";";
        output << BirthdateKnown() << ";";
        if (BirthdateKnown()) {
            birthdate.Write(output);
            output << ";";
        }
    }

    void Friend::Read(std::istream &input) {
        StringBasic name;
        Read(name,input);
    }

    void Friend::Read(StringBasic &partnerName, std::istream &input) {
        Person::Read(input);
        if (!input) {
            return;
        }
        char c; // dummy char for reading
        input >> level >> c >> year >> c;
        partnerName.Read(input, ';');
        partner = 0;
        int b;
        input >> b >> c;
        if (b != 0) {
            //birthdate.Read(input); // TODO Date don't have Read method yet
            birthdate = Date().First();
        }
        else {
            birthdate = Date().First();
        }
    }

    bool Friend::IsFriend(const Person &p) {
        return false;
    }



} // mar