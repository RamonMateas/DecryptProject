#include "rot.h"
#include <cctype>

std::string rotDecrypt(const std::string& ciphertext, int shift) {
    std::string plaintext;
    shift = shift % 26;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plaintext += (c - base + shift + 26) % 26 + base;
        }
        else {
            plaintext += c;
        }
    }
    return plaintext;
}