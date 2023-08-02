//
// Created by Marco Martins on 04-06-2023.
//


#include "gtest/gtest.h"
#include "ThermometerSimple.h"
#include "ThermometerExtreme.h"
#include "ThermometerMulti.h"
#include "Thermograph.h"
#include "Person.h"
#include "Friend.h"

TEST(PersonTestSuite, person) {
    mar::Person p1("Carla", mar::Person::FEMALE);
    p1.AddContact("carla@mail.com");
    mar::Person p2(p1);
    std::cout << p1 << std::endl;
    EXPECT_NE(p1, p2);
}

TEST(PersonTestSuite, friend) {
    mar::Person p("Carla", mar::Person::FEMALE);
    mar::Friend f1(p, 12, 1988);
    f1.AddContact("marco@mail.com");
    f1.RaiseLevel(5);
    f1.SetBirthdate(mar::Date(1980, 07, 25));
    //f1.WriteLine();
    EXPECT_EQ(17, f1.Level());
}