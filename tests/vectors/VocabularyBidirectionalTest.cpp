//
// Created by Marco Martins on 27-04-2024.
//

#include "VocabularyBidirectional.h"
#include "StringBasic.h"
#include "Utilities_vector.h"
#include "gtest/gtest.h"
#include <vector>

TEST(VocabularyBidirectionalTestSuite, vocabularyBidirectional) {
    /* lower_bound and upper_bound give the same for elements not present in the
     * vector but differ in the elements present. For these, the lower_bound
     * function gives the iterator for the first occurrence and the upper_bound
     * function gives the iterator for the first element to the right of the
     * last occurrence.*/
    std::vector<int> v;
    v.reserve(16);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(7);
    mar::WriteLine(v);
    EXPECT_EQ(0, mar::LowerIndex(v, 1));
    EXPECT_EQ(0, mar::LowerIndex(v, 2));
    EXPECT_EQ(1, mar::LowerIndex(v, 4));
    EXPECT_EQ(4, mar::LowerIndex(v, 5));
    EXPECT_EQ(4, mar::LowerIndex(v, 7));
    EXPECT_EQ(5, mar::LowerIndex(v, 8));

    EXPECT_EQ(0, mar::UpperIndex(v, 1));
    EXPECT_EQ(1, mar::UpperIndex(v, 2));
    EXPECT_EQ(4, mar::UpperIndex(v, 4));
    EXPECT_EQ(4, mar::UpperIndex(v, 5));
    EXPECT_EQ(5, mar::UpperIndex(v, 7));
    EXPECT_EQ(5, mar::UpperIndex(v, 8));
}

TEST(VocabularyBidirectionalTestSuite, iterator_to_reverse_iterator) {
    std::vector<int> v;
    v.reserve(16);
    v.push_back(2);
    v.push_back(7);
    v.push_back(4);
    v.push_back(9);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    mar::WriteLine(v);
    std::vector<int>::iterator         i1 = v.begin() + 3;
    std::vector<int>::reverse_iterator i2(i1);
    EXPECT_EQ(9, *i1);
    EXPECT_EQ(4, *i2);
}