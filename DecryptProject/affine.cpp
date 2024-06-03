#include "affine.h"
#include <cctype>

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

std::string affineDecrypt(const std::string& ciphertext, int a, int b) {
    std::string plaintext;
    int a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        return "Invalid 'a' value. No modular inverse found.";
    }
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plaintext += ((a_inv * (c - base - b + 26)) % 26) + base;
        }
        else {
            plaintext += c;
        }
    }
    return plaintext;
}
