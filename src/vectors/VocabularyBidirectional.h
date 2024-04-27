//
// Created by m1martin on 25-04-2024
//

#ifndef PROGRAMACAOCOMCLASSES_VOCABULARYBIDIRECTIONAL_H
#define PROGRAMACAOCOMCLASSES_VOCABULARYBIDIRECTIONAL_H

#include "Vocabulary.h"

namespace mar {

class VocabularyBidirectional : public Vocabulary {
private:
    std::vector<std::string>::reverse_iterator cursor;

public:
    VocabularyBidirectional(int capacity, std::istream &input);
    virtual void SearchBack(const std::string &s);
    virtual void ShowBack(int n);
};

} // namespace mar

#endif