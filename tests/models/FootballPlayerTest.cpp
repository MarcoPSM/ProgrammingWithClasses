//
// Created by Marco Martins on 04-06-2023.
//

#include "FootballPlayer.h"
#include "FootballTeam.h"
#include "gtest/gtest.h"
#include <fstream>

TEST(FootballPlayerTestSuite, player) {
    mar::FootballPlayer p1("Marco", mar::Date(1980, 07, 25), 8,
                           mar::FootballPlayer::FORWARD, 13000);
    mar::FootballPlayer p2("Martins", mar::Date(1980, 07, 25), 9,
                           mar::FootballPlayer::FORWARD, 11000);
    EXPECT_GT(p1, p2);
    p1.RatingDown(3000);
    EXPECT_GT(p2, p1);
    p1.RatingUp(2000);
    EXPECT_GT(p1, p2);
    EXPECT_EQ(8, p1.Number());
    EXPECT_EQ(9, p2.Number());
    p1.Play(2);
    EXPECT_EQ(1, p1.Games());
    EXPECT_EQ(2, p1.Goals());
    p1.Injure();
    EXPECT_TRUE(p1.Injured());
    p1.UnInjure();
    EXPECT_FALSE(p1.Injured());
}

TEST(FootballPlayerTestSuite, team) {
    // copy txt file into build folder
    // cp ../tests/models/realmadrid.txt .
    std::ifstream     realmadrid("realmadrid.txt");
    mar::FootballTeam t;
    t.Read(realmadrid);
    t.PlayerOf("Casillas").WriteLine();
    t.Write();
    t.Sort();
    t.Write();
    t.MakeTeam(4, 3, 3).Write();

    mar::FootballPlayer p1("Marco", mar::Date(1980, 07, 25), 8,
                           mar::FootballPlayer::FORWARD, 13000);
    mar::FootballPlayer p2("Martins", mar::Date(1980, 07, 25), 9,
                           mar::FootballPlayer::FORWARD, 11000);
    EXPECT_GT(p1, p2);
    p1.RatingDown(3000);
    EXPECT_GT(p2, p1);
    p1.RatingUp(2000);
    EXPECT_GT(p1, p2);
    EXPECT_EQ(8, p1.Number());
    EXPECT_EQ(9, p2.Number());
    p1.Play(2);
    EXPECT_EQ(1, p1.Games());
    EXPECT_EQ(2, p1.Goals());
    p1.Injure();
    EXPECT_TRUE(p1.Injured());
    p1.UnInjure();
    EXPECT_FALSE(p1.Injured());
}
