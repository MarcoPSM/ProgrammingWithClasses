//
// Created by m1martin on 24-06-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_PERSON_H
#define PROGRAMACAOCOMCLASSES_PERSON_H

#include "Clonable.h"
#include "StringBasic.h"
#include <list>

namespace mar {

    class Person: public Clonable {
    public:
        enum SexType {FEMALE, MALE};

    private:
        StringBasic name;
        SexType sex;
        std::list<StringBasic> contacts;

    public:
        Person();
        Person(const Person &other);
        Person(const StringBasic &name, SexType sex);
        virtual ~Person();

        virtual Clonable* Clone() const;
        virtual void Copy(const Person &other);
        virtual Person &operator = (const Person &other);

        virtual bool operator == (const Person &other) const;
        virtual bool operator <= (const Person &other) const;

        virtual SexType Sex() const;
        virtual const StringBasic& Name() const;

        virtual bool IsMale() const;
        virtual bool IsFemale() const;

        virtual void AddContact(const StringBasic &contact);
        virtual void WriteContacts(std::ostream &output = std::cout) const;
        virtual void WriteContactsBackWards(std::ostream &output = std::cout) const;

        virtual void Write(std::ostream &output = std::cout) const;
        virtual void WriteLine(std::ostream &output = std::cout) const;
        friend std::ostream &operator << (std::ostream &output, const Person &p);

        virtual void Read(std::istream &input = std::cin);
        friend std::istream &operator >> (std::istream &input, Person &p);

    public: // static
        static char SexLetter(SexType s);
        static SexType SexOf(char c);

    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_PERSON_H
