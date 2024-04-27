//
// Created by Marco Martins on 04-06-2023.
//

#include "Vocabulary.h"
#include "StringBasic.h"
#include "gtest/gtest.h"
#include <fstream>

TEST(VocabularyTestSuite, vocabulary) {
    // Create data file for test
    std::ofstream output("Pt.txt");
    if (output.is_open()) {
        output << "Sara\n";
        output << "Ana\n";
        output << "Marco\n";
        output << "Manuel\n";
        output << "Marco\n";
        output.close();
    }

    std::ifstream   input("Pt.txt");
    mar::Vocabulary voc(28000, input);
    for (;;) {
        mar::StringBasic s(256);
        s.Accept("Uma palavra para procurar no ficheiro PT.txt (Ex: Ana) - "
                 "para sair '!': ");
        if (!s.Empty() && s[0] == '!') {
            break;
        }
        if (!s.Empty()) {
            voc.Search(s);
        }
        voc.Show(10);
    }
    EXPECT_NE(1, 2);
}
