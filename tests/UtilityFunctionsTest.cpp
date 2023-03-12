//
// Created by marco on 12-03-2023.
//

#include "gtest/gtest.h"
#include "UtilityFunctions.h"
#include "NaiveDate.h"

TEST(UtilityFunctionsTestSuite, minFunction) {
    mar::NaiveDate d1(2023, 03, 11);
    mar::NaiveDate d2(2023, 03, 12);
    EXPECT_EQ(mar::Min(d1, d2), d1);
    EXPECT_EQ(mar::Min(14, 13), 13);
}
