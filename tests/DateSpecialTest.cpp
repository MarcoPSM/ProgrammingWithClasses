//
// Created by marco on 20-03-2023.
//

#include "gtest/gtest.h"
#include "DateSpecial.h"

TEST(DateSpecialTestSuite, returnToWork) {
    mar::DateSpecial d1(2023, 03, 11);
    mar::DateSpecial d2(2023, 03, 20);
    int vacationDays = 5;
    d1.ReturnToWork(vacationDays);
    EXPECT_EQ(d1, d2);
}
