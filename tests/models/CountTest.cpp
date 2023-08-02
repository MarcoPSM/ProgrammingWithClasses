//
// Created by m1martin on 16-05-2023.
//

#include "gtest/gtest.h"
#include "Count.h"

TEST(CountTestSuite, countmethods) {
    mar::Count c;
    c.Increment();
    EXPECT_EQ(1, c.Value());
    c.Increment();
    c.Decrement();
    EXPECT_EQ(1, c.Value());
    c.Reset();
    EXPECT_TRUE(c.IsZero());

}
