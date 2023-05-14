//
// Created by m1martin on 09-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_CIPHER_H
#define PROGRAMACAOCOMCLASSES_CIPHER_H

#include "Clonable.h"
#include "StringBasic.h"

namespace mar {

    class Cipher: public Clonable {
    public:
        virtual ~Cipher();

        virtual void Encrypt(const StringBasic& key) = 0;
        virtual void Decrypt(const StringBasic& key) = 0;
        virtual void Break() = 0;
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_CIPHER_H
