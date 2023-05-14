//
// Created by m1martin on 09-05-2023.
//

#include "TranspositionCipher.h"

namespace mar {
    TranspositionCipher::TranspositionCipher(): StringCipher() {

    }

    TranspositionCipher::TranspositionCipher(const StringBasic &other) : StringCipher(other) {

    }

    TranspositionCipher::TranspositionCipher(const TranspositionCipher &other): StringCipher() {

    }

    TranspositionCipher::~TranspositionCipher() {

    }

    Clonable *TranspositionCipher::Clone() const {
        return static_cast<Cipher*>(new TranspositionCipher(*this));
    }

    void TranspositionCipher::Copy(const TranspositionCipher &other) {
        StringBasic::Copy(other);
    }

    TranspositionCipher &TranspositionCipher::operator=(const TranspositionCipher &other) {
        return *this;
    }

    void TranspositionCipher::Encrypt(const StringBasic &key) {
        TranspositionCipher to(key);
        to.ExtendTranspositionKey();
        Map(uppercaseLetters, to);
    }

    void TranspositionCipher::Decrypt(const StringBasic &key) {
        TranspositionCipher to(key);
        to.ExtendTranspositionKey();
        Map(to, uppercaseLetters);
    }

    void TranspositionCipher::Break() {
        int toimplementinthefuture = 1;
    }

    void TranspositionCipher::ExtendTranspositionKey() {
        UniqueNonAdjacent();
        StringBasic rest(uppercaseLetters);
        rest.SendToBack(Last() - 'A' + 1);
        rest.PruneIf(*this);
        Append(rest);
    }
} // mar