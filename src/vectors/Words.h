//
// Created by m1martin on 28-04-2024
//

#ifndef PROGRAMACAOCOMCLASSES_WORDS_H
#define PROGRAMACAOCOMCLASSES_WORDS_H

#include "StringBasic.h"
#include <vector>

namespace mar {

class Words : public std::vector<StringBasic> {
public:
    Words(int capacity, std::istream &input);
    virtual ~Words();
    virtual void WriteWordsEndingBy(const StringBasic &s,
                                    std::ostream &output = std::cout) const;
    virtual void WriteWordsStartingBy(const StringBasic &s,
                                      std::ostream &output = std::cout) const;
    virtual void WriteWordsHaving(const StringBasic &s,
                                  std::ostream      &output = std::cout) const;
    virtual void WriteWordsNotHaving(const StringBasic &s,
                                     std::ostream &output = std::cout) const;

private:
    virtual void Read(std::istream &input = std::cin);
};

} // namespace mar

#endif