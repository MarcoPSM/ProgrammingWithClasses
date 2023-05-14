//
// Created by m1martin on 09-05-2023.
//

#include "VigenereCipher.h"
#include "CaeserCipher.h"

namespace mar {
    VigenereCipher::VigenereCipher(): StringCipher() {

    }

    VigenereCipher::VigenereCipher(const StringBasic &other) : StringCipher(other) {

    }

    VigenereCipher::VigenereCipher(const VigenereCipher &other): StringCipher() {

    }

    VigenereCipher::~VigenereCipher() {

    }

    Clonable *VigenereCipher::Clone() const {
        return static_cast<Cipher*>(new VigenereCipher(*this));
    }

    void VigenereCipher::Copy(const VigenereCipher &other) {
        StringBasic::Copy(other);
    }

    VigenereCipher &VigenereCipher::operator=(const VigenereCipher &other) {
        return *this;
    }

    void VigenereCipher::Encrypt(const StringBasic &key) {
        StringSpecial old(*this);
        int keyCount = key.Count();
        for (int i = 0; i < keyCount; ++i) {
            CaeserCipher temp(old);
            temp.Encrypt(StringBasic(key[i]));
            for (int j = i; j < Count(); j+=keyCount) {
                PutAt(temp[j], j);
            }
        }
    }

    void VigenereCipher::Decrypt(const StringBasic &key) {
        StringSpecial old(*this);
        int keyCount = key.Count();
        for (int i = 0; i < keyCount; ++i) {
            CaeserCipher temp(old);
            temp.Decrypt(StringBasic(key[i]));
            for (int j = i; j < Count(); j+=keyCount) {
                PutAt(temp[j], j);
            }
        }
    }

    void VigenereCipher::Break() {
        int toimplementinthefuture = 1;
    }
} // mar