//
// Created by m1martin on 09-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_VIGENERECIPHER_H
#define PROGRAMACAOCOMCLASSES_VIGENERECIPHER_H

#include "StringCipher.h"

namespace mar {

    class VigenereCipher: public StringCipher {
    public:
        VigenereCipher();
        VigenereCipher(const StringBasic& other);
        VigenereCipher(const VigenereCipher& other);
        virtual ~VigenereCipher();

        virtual Clonable* Clone() const;
        virtual void Copy(const VigenereCipher& other);
        virtual VigenereCipher& operator = (const VigenereCipher& other);

        virtual void Encrypt(const StringBasic& key);
        virtual void Decrypt(const StringBasic& key);
        virtual void Break();
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_VIGENERECIPHER_H
