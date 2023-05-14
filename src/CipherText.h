//
// Created by m1martin on 12-05-2023.
//

#ifndef PROGRAMACAOCOMCLASSES_CIPHERTEXT_H
#define PROGRAMACAOCOMCLASSES_CIPHERTEXT_H

#include "StringCipher.h"

namespace mar {

    class CipherText {
    private:
        StringCipher* line;
        StringBasic key;

    public:
        CipherText(const StringCipher& prototype, const StringBasic& key);
        virtual ~CipherText();

        virtual void EncryptText(std::istream& input, std::ostream& output);
        virtual void DecryptText(std::istream& input, std::ostream& output);
    };

} // mar

#endif //PROGRAMACAOCOMCLASSES_CIPHERTEXT_H
