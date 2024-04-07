//
// Created by marco on 11-03-2023.
//

#include "NaiveDate.h"
#include "gtest/gtest.h"

TEST(NaiveDateTestSuite, Friday13Version0) {
    mar::NaiveDate d;
    int            count = 0;
    for (;;) {
        std::cout << "Count: " << count << std::endl;
        if (d.Day() == 13 && d.Weekday() == mar::NaiveDate::FRIDAY) {
            count++;
            d.WriteLine();
            if (count == 1) {
                break;
            }
        }
        d.Forth();
    }
    EXPECT_EQ(count, 1);
}
