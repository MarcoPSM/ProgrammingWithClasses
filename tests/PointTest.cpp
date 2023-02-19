//
// Created by marco on 17-02-2023.
//

#include "Point.h"
#include "gtest/gtest.h"

#define PI 3.141592653589793238
#define TOLERANCE 0.000001

TEST(PointTestSuite, DistanceTo) {
    mar::Point p(0.0, 0.0);
    mar::Point q(1.0, 0.0);
    EXPECT_EQ(p.DistanceTo(q), 1.0);
}

TEST(PointTestSuite, RotateAround) {
    mar::Point p(0.0, 0.0);
    mar::Point q(1.0, 0.0);
    p.RotateAround(PI, q);
    EXPECT_NEAR(p.getX(), 2.0, TOLERANCE);
    EXPECT_NEAR(p.getY(), 0.0, TOLERANCE);
}
