//
// Created by marco on 19-02-2023.
//
#include "Point.h"
#include "gtest/gtest.h"
#include "cmath"

#define PI 3.141592653589793238
#define TOLERANCE 0.000001

TEST(FigureTestSuite, RotateAroundPolymorphic) {
    // using atan function I get a precise value for PI
    double pi = 4 * std::atan(1.0);
    // Check if using atan function is equal to use macro
    EXPECT_EQ(PI, pi);

    mar::Point p(0.0, 0.0);
    mar::Point q(1.0, 0.0);
    mar::Figure *f = nullptr;
    f = &p;
    f->RotateAround(PI, q);
    EXPECT_NEAR(p.getX(), 2.0, TOLERANCE);
    EXPECT_NEAR(p.getY(), 0.0, TOLERANCE);

}

