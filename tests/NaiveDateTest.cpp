//
// Created by marco on 11-03-2023.
//

#include "gtest/gtest.h"
#include "NaiveDate.h"

TEST(NaiveDateTestSuite, Friday13Version0) {
    mar::NaiveDate d;
    int count = 0;
    for(;;) {
        if (d.Day()==13 && d.Weekday()==mar::NaiveDate::FRIDAY ) {
            count++;
            //d.WriteLine();
            if (count==13) {
                break;
            }
        }
        d.Forth();
    }
    EXPECT_EQ(count, 13);
}

