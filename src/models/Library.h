//
// Created by m1martin on 01-04-2024.
//

#ifndef PROGRAMACAOCOMCLASSES_LIBRARY_H
#define PROGRAMACAOCOMCLASSES_LIBRARY_H

#include "Book.h"
#include "StringBasic.h"
#include <map>

namespace mar {

class Library {
private:
    std::map<StringBasic, Friend> friends;
    std::map<StringBasic, Author> authors;
    std::map<StringBasic, Book>   books;

public:
    virtual ~Library();
    virtual void AddBook(const Book &book);
    virtual void AddAuthor(const Author &author);
    virtual void AddFriend(const Friend &myFriend);

    virtual const Author &AuthorOf(const StringBasic &name) const;
    virtual Author       &AuthorOf(const StringBasic &name);
    virtual const Book   &BookOf(const StringBasic &name) const;
    virtual Book         &BookOf(const StringBasic &name);
    virtual const Friend &FriendOf(const StringBasic &name) const;
    virtual Friend       &FriendOf(const StringBasic &name);

    virtual void WriteBooks(std::ostream &output = std::cout) const;
    virtual void WriteAuthors(std::ostream &output = std::cout) const;
    virtual void WriteFriends(std::ostream &output = std::cout) const;

    void DisplayTitlesBy(const StringBasic &authorName) const;
    void DisplayBooksAway() const;
};
} // namespace mar

#endif // PROGRAMACAOCOMCLASSES_LIBRARY_H