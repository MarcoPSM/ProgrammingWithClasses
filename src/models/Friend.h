//
// Created by m1martin on 24-06-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_FRIEND_H
#define PROGRAMACAOCOMCLASSES_FRIEND_H

#include "Person.h"
#include "Date.h"

namespace mar {

    class Friend: public Person {
    private:
        int level;
        int year;
        const Person *partner;
        Date birthdate;

    public:
        Friend();
        Friend(const Friend &other);
        Friend(const Person &p, int level, int year);
        Friend(const Person &p, int level, int year, const Person &partner);
        virtual ~Friend();

        virtual Clonable *Clone() const;
        virtual void Copy(const Friend &other);
        virtual Friend &operator = (const Friend &other);

        virtual int Level() const;
        virtual void RaiseLevel(int x=1);
        virtual void LowerLevel(int x=1);

        virtual int Year() const;
        virtual int Duration() const;
        virtual bool BetterFriendThan(const Friend &other) const;

        virtual bool Single() const;
        virtual const Person &Partner() const; // pre: ! Single();
        virtual void Marry(const Person &p); // post: ! Single();
        virtual void Divorce(); // post: Single();
        virtual bool MarriedToFriend() const;
        virtual int JointLevel() const;

        virtual void SetBirthdate(const Date &d); // pre: d > Date().First();
        virtual bool BirthdateKnown() const;
        virtual const Date &Birthdate() const; // pre: BirthdateKnown();
        virtual int Age() const; // pre: BirthdateKnown();

        virtual void Write(std::ostream &output = std::cout) const;
        virtual void Read(std::istream &input = std::cin);
        virtual void Read(StringBasic &partnerName, std::istream &input = std::cin);

        virtual bool IsFriend(const Person &p);

    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_FRIEND_H
