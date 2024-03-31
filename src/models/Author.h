//
// Created by m1martin on 04-03-2024.
//

#ifndef PROGRAMACAOCOMCLASSES_AUTHOR_H
#define PROGRAMACAOCOMCLASSES_AUTHOR_H

#include "StringBasic.h"

namespace mar {

class Author : public Clonable {
private:
    StringBasic name;
    int         yearBorn;
    int         yearDied;

public:
    Author();
    Author(const StringBasic &name, int yearBorn);
    Author(const StringBasic &name, int yearBorn, int yearDied);

    virtual Clonable *Clone() const;

    virtual void
    Die(int year); // pre !Dead() && year >= YearBorn(); post Dead();
    virtual const StringBasic &Name() const;
    virtual int                YearBorn() const;
    virtual int                YearDied() const; // pre Dead();
    virtual bool               Dead() const;

    virtual void         Write(std::ostream &output = std::cout) const;
    virtual void         WriteLine(std::ostream &output = std::cout) const;
    friend std::ostream &operator<<(std::ostream &output, const Author &p);
};

} // namespace mar

#endif // PROGRAMACAOCOMCLASSES_AUTHOR_H