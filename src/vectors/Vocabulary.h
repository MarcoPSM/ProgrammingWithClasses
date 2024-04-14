//
// Created by m1martin on 14-04-2024
//

#ifndef PROGRAMACAOCOMCLASSES_VOCABULARY_H
#define PROGRAMACAOCOMCLASSES_VOCABULARY_H

#include <iostream>
#include <vector>

namespace mar {

class Vocabulary : public std::vector<std::string> {
private:
    std::vector<std::string>::iterator cursor;

public:
    Vocabulary(int capacity, std::istream &input);
    virtual ~Vocabulary();
    virtual void Search(const std::string &s);
    virtual void Show(int n);

private:
    virtual void Read(std::istream &input = std::cin);
};

} // namespace mar

#endif