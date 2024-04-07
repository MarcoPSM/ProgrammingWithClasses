//
// Created by Marco Martins on 07-04-2024.
//

#include "Library.h"
#include "Author.h"
#include "Book.h"
#include "Friend.h"
#include "gtest/gtest.h"

TEST(LibraryTestSuite, addAuthors) {
    mar::Library library;
    // Add Authors
    library.AddAuthor(mar::Author("Saramago", 1922));
    library.AddAuthor(mar::Author("Garcia Marques", 1928));
    library.AddAuthor(mar::Author("Dijkstra", 1932, 2002));
    library.AddAuthor(mar::Author("Hoare", 1935));
    library.AddAuthor(mar::Author("Dahl", 1938, 2002));
    // Add Books
    library.AddBook(
        mar::Book("Memorial do convento", library.AuthorOf("Saramago")));
    library.AddBook(mar::Book("El general en su laberinto",
                              library.AuthorOf("Garcia Marques")));
    library.AddBook(mar::Book("Structured Programming"));
    library.BookOf("Structured Programming")
        .AddAuthor(library.AuthorOf("Dijkstra"));
    library.BookOf("Structured Programming")
        .AddAuthor(library.AuthorOf("Hoare"));
    library.BookOf("Structured Programming")
        .AddAuthor(library.AuthorOf("Dahl"));
    // Add friends
    library.AddFriend(
        mar::Friend(mar::Person("Gil", mar::Person::MALE), 12, 1979));
    // Lend a book to a friend
    mar::Book  &book     = library.BookOf("Memorial do convento");
    mar::Friend myFriend = library.FriendOf("Gil");
    book.LendTo(myFriend);
    library.BookOf("El general en su laberinto")
        .LendTo(library.FriendOf("Gil"));

    library.WriteAuthors();
    std::cout << std::endl;
    library.WriteBooks();
    std::cout << std::endl;
    library.WriteFriends();
    std::cout << std::endl;

    EXPECT_TRUE(library.BookOf("Memorial do convento").IsAway());
}
