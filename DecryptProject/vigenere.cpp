#include "vigenere.h"
#include <cctype>

std::string vigenereDecrypt(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    int keyIndex = 0;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = isupper(key[keyIndex]) ? key[keyIndex] : toupper(key[keyIndex]);
            plaintext += (c - base - (k - 'A') + 26) % 26 + base;
            keyIndex = (keyIndex + 1) % key.length();
        }
        else {
            plaintext += c;
        }
    }
    return plaintext;
}
