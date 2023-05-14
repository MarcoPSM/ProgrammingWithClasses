//
// Created by m1martin on 09-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_CAESERCIPHER_H
#define PROGRAMACAOCOMCLASSES_CAESERCIPHER_H

#include "StringCipher.h"

namespace mar {

    class CaeserCipher: public StringCipher {
    public:
        CaeserCipher();
        CaeserCipher(const StringBasic& other);
        CaeserCipher(const CaeserCipher& other);

        virtual ~CaeserCipher();

        virtual Clonable* Clone() const;
        virtual void Copy(const CaeserCipher& other);
        virtual CaeserCipher& operator = (const CaeserCipher& other);

        virtual void Encrypt(const StringBasic& key);
        virtual void Decrypt(const StringBasic& key);
        virtual void Break();
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_CAESERCIPHER_H
