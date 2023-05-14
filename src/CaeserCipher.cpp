//
// Created by m1martin on 09-05-2023.
//

#include "CaeserCipher.h"

namespace mar {
    CaeserCipher::CaeserCipher(): StringCipher() {

    }

    CaeserCipher::CaeserCipher(const StringBasic &other) : StringCipher(other) {

    }

    CaeserCipher::CaeserCipher(const CaeserCipher &other): StringCipher(other) {

    }

    CaeserCipher::~CaeserCipher() {

    }

    Clonable *CaeserCipher::Clone() const {
        return static_cast<Cipher*>(new CaeserCipher(*this));
    }

    void CaeserCipher::Copy(const CaeserCipher &other) {
        StringBasic::Copy(other);
    }

    CaeserCipher &CaeserCipher::operator=(const CaeserCipher &other) {
        Copy(other);
        return *this;
    }

    void CaeserCipher::Encrypt(const StringBasic &key) {
        StringBasic to(uppercaseLetters);
        to.SendToBack(key.First() - 'A' + 1);
        Map(uppercaseLetters, to);
    }

    void CaeserCipher::Decrypt(const StringBasic &key) {
        StringBasic to(uppercaseLetters);
        to.SendToBack(key.First() - 'A' + 1);
        Map(to, uppercaseLetters);
    }

    void CaeserCipher::Break() {
        int toimplementinthefuture = 1;
    }
} // mar