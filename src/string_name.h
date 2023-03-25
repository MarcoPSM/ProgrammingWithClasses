//
// Created by marco on 25-03-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRING_NAME_H
#define PROGRAMACAOCOMCLASSES_STRING_NAME_H

#include "String.h"

namespace mar {
class string_name : public mar::string {
public: // static constants
    static const int count_particles = 6;
    static const std::string particles[];

public:
        string_name();
        string_name(const mar::string& x);
        string_name(const std::string& x);

        virtual string_name artistic() const;
        virtual string_name normalized() const;
        virtual string_name telephonic() const;
        virtual string_name initialized() const;
        virtual string_name initials() const;

    };
}

#endif //PROGRAMACAOCOMCLASSES_STRING_NAME_H
