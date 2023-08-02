//
// Created by m1martin on 24-06-2023.
//

#include "Person.h"

namespace mar {
    Person::Person() {

    }

    Person::Person(const Person &other):
        name(other.name), sex(other.sex), contacts(other.contacts) {

    }

    Person::Person(const StringBasic &name, Person::SexType sex):
        name(name), sex(sex), contacts() {

    }

    Person::~Person() {

    }

    Clonable *Person::Clone() const {
        return new Person(*this);
    }

    void Person::Copy(const Person &other) {
        this->name = other.name;
        this->sex = other.sex;
        this->contacts = other.contacts;
    }

    Person &Person::operator=(const Person &other) {
        Copy(other);
        return *this;
    }

    bool Person::operator==(const Person &other) const {
        return this == &other;
    }

    bool Person::operator<=(const Person &other) const {
        return name <= other.name;
    }

    Person::SexType Person::Sex() const {
        return sex;
    }

    const StringBasic &Person::Name() const {
        return name;
    }

    bool Person::IsMale() const {
        return sex == MALE;
    }

    bool Person::IsFemale() const {
        return sex == FEMALE;
    }

    void Person::AddContact(const StringBasic &contact) {
        contacts.push_back(contact);
    }

    void Person::WriteContacts(std::ostream &output) const {
        for (std::list<StringBasic>::const_iterator i = contacts.begin(); i != contacts.end(); i++) {
            output << *i << ";";
        }
    }

    void Person::WriteContactsBackWards(std::ostream &output) const {
        for (std::list<StringBasic>::const_reverse_iterator i = contacts.rbegin(); i != contacts.rend(); i++) {
            output << *i << ";";
        }
    }

    void Person::Write(std::ostream &output) const {
        output << name << ";" << SexLetter(sex) << ";";
        output << static_cast<unsigned>(contacts.size()) << ";";
        WriteContacts(output);
    }

    void Person::WriteLine(std::ostream &output) const {
        Write(output);
        output << std::endl;
    }

    void Person::Read(std::istream &input) {
        name.Read(input, ';');
        if (!input) {
            return;
        }
        StringBasic s;
        s.Read(input, ';');
        sex = SexOf(s[0]);
        int n;
        input >> n;
        char c;
        input >> c;
        contacts.clear();
        for (int i = 0; i < n; ++i) {
            StringBasic contact;
            contact.Read(input, ';');
            AddContact(contact);
        }
    }

    char Person::SexLetter(Person::SexType s) {
        return s == FEMALE ? 'F' : 'M';
    }

    Person::SexType Person::SexOf(char c) {
        return c == 'F' ? FEMALE : MALE;
    }

    std::ostream &operator<<(std::ostream &output, const Person &p) {
        p.Write(output);
        return output;
    }

    std::istream &operator>>(std::istream &input, Person &p) {
        p.Read(input);
        return input;
    }
} // mar