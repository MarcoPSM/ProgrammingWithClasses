//
// Created by m1martin on 31-03-2024.
//

#ifndef PROGRAMACAOCOMCLASSES_BOOK_H
#define PROGRAMACAOCOMCLASSES_BOOK_H

#include "Author.h"
#include "Friend.h"
#include "StringBasic.h"

namespace mar {

class Book : public Clonable {
private:
    std::list<const Author *> authors;
    StringBasic               title;
    int                       value;
    const Friend             *borrowedBy;
    StringBasic               comments;

public:
    Book();
    Book(const StringBasic &title);
    Book(const StringBasic &title, const Author &author);

    virtual Clonable *Clone() const;

    virtual const std::list<const Author *> &Authors() const;
    virtual void                             AddAuthor(const Author &author);
    virtual bool               AuthoredBy(const Author &author) const;
    virtual const StringBasic &Title() const;
    virtual int                Value() const;
    virtual void               SetValue(int value);
    virtual const StringBasic &Comments() const;
    virtual void               SetComments(const StringBasic &comments);
    virtual void LendTo(const Friend &x); // pre!IsAway(); post IsAway();
    virtual void Return();                // pre IsAway(); post !IsAway();
    virtual bool IsAway() const;
    virtual const Friend &BorrowedBy() const; // pre IsAway();

    virtual void         Write(std::ostream &output = std::cout) const;
    virtual void         WriteLine(std::ostream &output = std::cout) const;
    friend std::ostream &operator<<(std::ostream &output, const Book &p);
};

} // namespace mar

#endif // PROGRAMACAOCOMCLASSES_BOOK_H