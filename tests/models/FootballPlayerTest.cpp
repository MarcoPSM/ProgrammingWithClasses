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
    // Create data file for test
    std::ofstream output("realmadrid.txt");
    if (output.is_open()) {
        output << "11\n";
        output << "Trubin;1981 5 20;1;0;0;0;25000;0;\n";
        output << "Morato;1982 5 22;2;0;0;0;26000;0;\n";
        output << "Carreras;1983 5 23;3;0;0;0;24000;0;\n";
        output << "Otamendi;1984 5 24;3;0;0;0;24000;0;\n";
        output << "Tomas;1985 5 25;3;0;0;0;14000;0;\n";
        output << "Neres;1986 5 10;1;0;0;0;15000;0;\n";
        output << "Joao Neves;1987 5 11;2;0;0;0;16000;0;\n";
        output << "Joao Mario;1988 5 12;3;0;0;0;34000;0;\n";
        output << "Cabral;1989 5 13;3;0;0;0;44000;0;\n";
        output << "Di Maria;1990 5 04;3;0;0;0;54000;0;\n";
        output << "Rafa;1991 5 05;3;0;0;0;64000;0;";
        output.close();
    }

    std::ifstream     realmadrid("realmadrid.txt");
    mar::FootballTeam t;
    t.Read(realmadrid);
    t.PlayerOf("Trubin").WriteLine();
    t.Write();
    t.Sort();
    t.Write();
    t.MakeTeam(4, 3, 3).Write();
    /*
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
        */
}
