//
// Created by marco on 22-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_METRICS_H
#define PROGRAMACAOCOMCLASSES_METRICS_H

#include <iostream>
#include "String.h"

namespace mar {

    class Metrics {
    private:
        std::istream& input;

    public:
        Metrics(std::istream& s);
        virtual ~Metrics();

        virtual int CountLinesOfCode() const;
        virtual int CountLinesEndingWithSemicolon() const;

    private:
        void operator = (const Metrics&) {};
        virtual void Reset() const;

    public: // static
        static bool IsLineOfCode(const mar::string& s);
        static bool IsCommentLine(const mar::string& s);
        static bool IsBracketsOnly(const mar::string& s);

    };

}

#endif //PROGRAMACAOCOMCLASSES_METRICS_H
