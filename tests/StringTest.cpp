//
// Created by marco on 24-03-2023.
//

#include "gtest/gtest.h"
#include "String.h"

TEST(StringTestSuite, Palindrome) {
    mar::string s("MarcocraM");
    EXPECT_TRUE(s.is_palindrome());
}

TEST(StringTestSuite, Reverse) {
    mar::string s("Marco");
    mar::string r("ocraM");
    EXPECT_EQ(s.applied(&mar::string::reverse), r);
}
