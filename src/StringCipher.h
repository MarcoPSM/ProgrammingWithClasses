//
// Created by m1martin on 09-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_STRINGCIPHER_H
#define PROGRAMACAOCOMCLASSES_STRINGCIPHER_H

#include "StringSpecial.h"
#include "Cipher.h"

namespace mar {

    class StringCipher: public StringSpecial, public Cipher {
    public:
        StringCipher();
        StringCipher(const StringCipher &other);
        StringCipher(const StringBasic& other);

        virtual ~StringCipher();
        virtual Clonable* Clone() const;
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_STRINGCIPHER_H
