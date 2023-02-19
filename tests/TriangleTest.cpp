//
// Created by marco on 18-02-2023.
//

#include "Triangle.h"
#include "gtest/gtest.h"


TEST(TriangleTestSuite, triangleConstruct) {
    mar::Triangle *t = new mar::Triangle();
    EXPECT_TRUE(t->IsOK());
    delete t;
}
TEST(TriangleTestSuite, triangleConstructWithPoints) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    EXPECT_TRUE(t.IsOK());
}
TEST(TriangleTestSuite, triangleConstructByCopy) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    mar::Triangle *u = new mar::Triangle(t);
    EXPECT_TRUE(u->IsOK());
    delete u;
}
TEST(TriangleTestSuite, triangleIsOKTrue) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    EXPECT_TRUE(t.IsOK());
}
TEST(TriangleTestSuite, triangleIsOKFalse) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 0.0);
    mar::Triangle t(p, q,r);
    EXPECT_FALSE(t.IsOK());
}
TEST(TriangleTestSuite, triangleBase) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    EXPECT_EQ(t.Base(), 2.0);
}
TEST(TriangleTestSuite, triangleHeight) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    EXPECT_EQ(t.Height(), 2.0);
}

TEST(TriangleTestSuite, triangleArea) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    double tolerance = 0.000001;
    EXPECT_NEAR(t.Area(), 2.0, tolerance);
}
TEST(TriangleTestSuite, trianglePerimeter) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    double tolerance = 0.000001;
    EXPECT_NEAR(t.Perimeter(), 6.828427, tolerance);
}
TEST(TriangleTestSuite, triangleContainsPoint) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    EXPECT_TRUE(t.Contains(p));
}
TEST(TriangleTestSuite, triangleContainsTriangle) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    EXPECT_TRUE(t.Contains(t));
}

TEST(TriangleTestSuite, triangleTranslate) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    t.Translate(2.0, 2.0);
    p.Translate(2.0, 2.0);
    q.Translate(2.0, 2.0);
    r.Translate(2.0, 2.0);
    mar::Triangle u(p, q,r);
    EXPECT_TRUE(t.Contains(u));
}
TEST(TriangleTestSuite, triangleScale) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    t.Scale(2.0, 2.0);
    p.Scale(2.0, 2.0);
    q.Scale(2.0, 2.0);
    r.Scale(2.0, 2.0);
    mar::Triangle u(p, q,r);
    EXPECT_TRUE(t.Contains(u));
}
TEST(TriangleTestSuite, triangleRotate) {
    mar::Point p(0.0, 0.0);
    mar::Point q(2.0, 0.0);
    mar::Point r(0.0, 2.0);
    mar::Triangle t(p, q,r);
    t.Rotate(3.1415926535);
    p.Rotate(3.1415926535);
    q.Rotate(3.1415926535);
    r.Rotate(3.1415926535);
    mar::Triangle u(p, q,r);
    EXPECT_TRUE(t.Contains(u));
}

