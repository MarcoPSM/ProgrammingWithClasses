//
// Created by m1martin on 09-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_TRANSPOSITIONCIPHER_H
#define PROGRAMACAOCOMCLASSES_TRANSPOSITIONCIPHER_H

#include "StringCipher.h"

namespace mar {

    class TranspositionCipher: public StringCipher {
    public:
        TranspositionCipher();
        TranspositionCipher(const StringBasic& other);
        TranspositionCipher(const TranspositionCipher& other);
        virtual ~TranspositionCipher();

        virtual Clonable* Clone() const;
        virtual void Copy(const TranspositionCipher& other);
        virtual TranspositionCipher& operator = (const TranspositionCipher& other);

        virtual void Encrypt(const StringBasic& key);
        virtual void Decrypt(const StringBasic& key);
        virtual void Break();

    private:
        virtual void ExtendTranspositionKey();
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_TRANSPOSITIONCIPHER_H
