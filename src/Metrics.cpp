//
// Created by marco on 22-03-2023.
//

#include "Metrics.h"

mar::Metrics::Metrics(std::istream &s):
    input(s) {

}

mar::Metrics::~Metrics() {

}


int mar::Metrics::CountLinesOfCode() const {
    int result = 0;
    for (;;) {
        mar::string line;
        std::getline(input, line);
        if (!input) {
            break;
        }
        result += IsLineOfCode(line);
    }
    Reset();
    return result;
}

int mar::Metrics::CountLinesEndingWithSemicolon() const {
    int result = 0;
    for(;;) {
        mar::string line;
        std::getline(input, line);
        if (!input) {
            break;
        }
        result += IsLineOfCode(line) && line.ends_by(";");
    }
    Reset();
    return result;
}


void mar::Metrics::Reset() const {
    input.clear();
    input.seekg(0);
}


bool mar::Metrics::IsLineOfCode(const mar::string &s) {
    return !s.is_blank() && !IsCommentLine(s) && !IsBracketsOnly(s);
}

bool mar::Metrics::IsCommentLine(const mar::string &s) {
    return s.applied(&string::trim_left).starts_by("//");
    // mar::string temp(s);
    // temp.trim_left();
    // return temp.starts_by("//");
}

bool mar::Metrics::IsBracketsOnly(const mar::string &s) {
    return s.find_first_not_of("{}\x20\t") == std::string::npos;
}


