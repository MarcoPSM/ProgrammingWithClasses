//
// Created by Marco Martins on 04-06-2023.
//

#include "Words.h"
#include "Predicates_StringBasic.h"
#include "StringBasic.h"
#include "gtest/gtest.h"
#include <fstream>

TEST(WordsTestSuite, words) {
    EXPECT_TRUE(mar::Palindromic().Good("salas"));
}