//
// Created by m1martin on 12-05-2023.
//

#include "CipherText.h"

namespace mar {
    CipherText::CipherText(const StringCipher &prototype, const StringBasic &key):
        line(dynamic_cast<StringCipher *> (prototype.Clone())),
        key(key) {

    }

    CipherText::~CipherText() {
        delete line;
    }

    void CipherText::EncryptText(std::istream &input, std::ostream &output) {
        for(;;) {
            line->Read(input);
            if (!input) {
                break;
            }
            line->ToUpperCase();
            line->PruneIfNot(StringBasic::uppercaseLetters);
            line->Encrypt(key);
            line->WriteLine(output);
        }
    }

    void CipherText::DecryptText(std::istream &input, std::ostream &output) {
        for(;;) {
            line->Read(input);
            if (!input) {
                break;
            }
            line->Decrypt(key);
            line->WriteLine(output);
        }
    }
} // mar