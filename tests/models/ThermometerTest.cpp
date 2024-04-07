//
// Created by Marco Martins on 04-06-2023.
//

#include "Thermograph.h"
#include "ThermometerExtreme.h"
#include "ThermometerMulti.h"
#include "ThermometerSimple.h"
#include "gtest/gtest.h"

TEST(ThermometerTestSuite, thermometer) {
    mar::ThermometerSimple t;
    EXPECT_EQ(20, t.Value());
    t.WarmUp();
    EXPECT_EQ(20.1, t.Value());

    t.Set(20.5);
    EXPECT_EQ(20.5, t.Value());

    t.CoolDown();
    EXPECT_EQ(20.4, t.Value());

    EXPECT_EQ(-40, t.Bottom());
    EXPECT_EQ(80, t.Top());
}

TEST(ThermometerTestSuite, thermometerExtreme) {
    mar::ThermometerExtreme t;
    EXPECT_EQ(20, t.Value());
    t.WarmUp();
    EXPECT_EQ(20.1, t.Value());

    t.Set(20.5);
    EXPECT_EQ(20.5, t.Value());

    t.CoolDown();
    EXPECT_EQ(20.4, t.Value());

    EXPECT_EQ(-40, t.Bottom());
    EXPECT_EQ(80, t.Top());

    EXPECT_EQ(20.5, t.Max());
    EXPECT_EQ(20, t.Min());
    t.Reset();
    EXPECT_EQ(t.Max(), t.Min());
    EXPECT_EQ(t.Min(), t.Value());
    EXPECT_EQ(20.4, t.Value());
}

TEST(ThermometerTestSuite, thermometerMulti) {
    mar::ThermometerMulti t(3);
    t.WarmUp();
    std::cout << "Display: ";
    t.Display();
    std::cout << std::endl;
    t.ChangeOutputStation();
    t.ChangeOutputStation();
    std::cout << "Display: ";
    t.Display();
    std::cout << std::endl;
    EXPECT_EQ(3, t.Count());
}

TEST(ThermometerTestSuite, thermograph) {
    mar::Thermograph t;
    t.WarmUp();
    t.Take();
    t.WarmUp();
    t.Take();
    t.WarmUp();
    t.Take();
    std::cout << "Display: ";
    std::cout << std::endl;
    // t.Display();
    // t.Plot(std::cout);
    EXPECT_EQ(3, t.Count());
    EXPECT_EQ(20.2, t.Average());
    double tolerance = 0.000001;
    EXPECT_NEAR(0.2, t.Extent(), tolerance);
    EXPECT_EQ(3, t.Count());
}