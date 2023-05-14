//
// Created by m1martin on 09-05-2023.
//

#include "StringCipher.h"

namespace mar {
    StringCipher::StringCipher():
            StringSpecial() {

    }

    StringCipher::StringCipher(const StringCipher& other):
            StringSpecial(other) {

    }

    StringCipher::StringCipher(const StringBasic &other):
            StringSpecial(other) {

    }

    StringCipher::~StringCipher() {

    }

    Clonable *StringCipher::Clone() const {
        return 0; // cannot be called
    }

} // mar