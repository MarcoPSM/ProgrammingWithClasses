//
// Created by m1martin on 01-04-2024.
//

#include "Library.h"

namespace mar {

Library::~Library() {}

Author &Library::AuthorOf(const StringBasic &name) {
    return authors[name];
}

Book &Library::BookOf(const StringBasic &name) {
    return books[name];
}

Friend &Library::FriendOf(const StringBasic &name) {
    return friends[name];
}

const Author &Library::AuthorOf(const StringBasic &name) const {
    return const_cast<Library *>(this)->AuthorOf(name);
}

const Book &Library::BookOf(const StringBasic &name) const {
    return const_cast<Library *>(this)->BookOf(name);
}

const Friend &Library::FriendOf(const StringBasic &name) const {
    return const_cast<Library *>(this)->FriendOf(name);
}

void Library::AddAuthor(const Author &author) {
    authors[author.Name()] = author;
}

void Library::AddBook(const Book &book) {
    books[book.Title()] = book;
}

void Library::AddFriend(const Friend &myFriend) {
    friends[myFriend.Name()] = myFriend;
}

void Library::WriteBooks(std::ostream &output) const {
    for (std::map<StringBasic, Book>::const_iterator i = books.begin();
         i != books.end(); i++) {
        i->second.WriteLine(output);
    }
}

void Library::WriteAuthors(std::ostream &output) const {
    for (std::map<StringBasic, Author>::const_iterator i = authors.begin();
         i != authors.end(); i++) {
        i->second.WriteLine(output);
    }
}

void Library::WriteFriends(std::ostream &output) const {
    for (std::map<StringBasic, Friend>::const_iterator i = friends.begin();
         i != friends.end(); i++) {
        i->second.WriteLine(output);
    }
}

void Library::DisplayBooksAway() const {
    for (std::map<StringBasic, Book>::const_iterator i = books.begin();
         i != books.end(); i++) {
        if (i->second.IsAway()) {
            std::cout << i->second.Title() << ";"
                      << i->second.BorrowedBy().Name() << std::endl;
        }
    }
}

void Library::DisplayTitlesBy(const StringBasic &authorName) const {
    std::map<StringBasic, Author>::const_iterator author =
        authors.find(authorName);
    if (author != authors.end()) {
        for (std::map<StringBasic, Book>::const_iterator book = books.begin();
             book != books.end(); book++) {
            if (book->second.AuthoredBy(author->second)) {
                book->second.Title().WriteLine();
            }
        }
    }
}
} // namespace mar