//
// Created by marco on 16-03-2023.
//

#include "gtest/gtest.h"
#include "Date.h"

TEST(DateTestSuite, FirstDayOfYear) {
    mar::Date d(1980, 01, 01);
    EXPECT_EQ(d.FirstDayOfYear(d.Year()), 138426);
}
TEST(DateTestSuite, FirstDayOfMonth) {
    mar::Date d(1980, 02, 01);
    EXPECT_EQ(d.FirstDayOfMonth(d.Year(), d.Month()), 138457);
}

TEST(DateTestSuite, DaysInMonth) {
    mar::Date d(1980, 02, 01);
    EXPECT_EQ(d.DaysInMonth(d.Year(), d.Month()), 29);
}
TEST(DateTestSuite, DayNumber) {
    mar::Date d(1980, 2, 1);
    EXPECT_EQ(d.DayNumber(), 32);
}
