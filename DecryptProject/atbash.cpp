#include "atbash.h"
#include <cctype>

std::string atbashDecrypt(const std::string& ciphertext) {
    std::string plaintext;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            if (isupper(c)) {
                char base = 'A';
                plaintext += base + ('Z' - c);
            }
            else {
                char base = 'a';
                plaintext += base + ('z' - c);
            }
        }
        else {
            plaintext += c;
        }
    }
    return plaintext;
}