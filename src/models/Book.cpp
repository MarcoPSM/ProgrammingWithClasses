//
// Created by m1martin on 31-03-2024.
//

#include "Book.h"

namespace mar {
Book::Book() {}
Book::Book(const StringBasic &title)
    : authors(), title(title), value(0), borrowedBy(0), comments() {}
Book::Book(const StringBasic &title, const Author &author)
    : authors(), title(title), value(0), borrowedBy(0), comments() {
    authors.push_back(&author);
}
Clonable *Book::Clone() const {
    return new Book(*this);
}

const std::list<const Author *> &Book::Authors() const {
    return authors;
}
void Book::AddAuthor(const Author &author) {
    authors.push_back(&author);
}
bool Book::AuthoredBy(const Author &author) const {
    for (std::list<const Author *>::const_iterator i = authors.begin();
         i != authors.end(); i++) {
        if (*i == &author) {
            return true;
        }
    }
    return false;
}
const StringBasic &Book::Title() const {
    return title;
}
void Book::LendTo(const Friend &x) {
    borrowedBy = &x;
}
void Book::Return() {
    borrowedBy = 0;
}
bool Book::IsAway() const {
    return borrowedBy != 0;
}
const Friend &Book::BorrowedBy() const {
    return *borrowedBy;
}
int Book::Value() const {
    return value;
}
void Book::SetValue(int value) {
    this->value = value;
}
const StringBasic &Book::Comments() const {
    return comments;
}
void Book::SetComments(const StringBasic &comments) {
    this->comments = comments;
}

void Book::Write(std::ostream &output) const {
    output << static_cast<unsigned>(authors.size()) << ";";
    for (std::list<const Author *>::const_iterator i = authors.begin();
         i != authors.end(); i++) {
        output << (*i)->Name() << ";";
    }
    output << title << ";" << value << ";" << comments << ";";
    if (borrowedBy != 0) {
        output << borrowedBy->Name();
    }
    output << ";";
}

void Book::WriteLine(std::ostream &output) const {
    Write(output);
    output << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Book &b) {
    b.Write(output);
    return output;
}

} // namespace mar