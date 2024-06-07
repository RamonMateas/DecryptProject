#include "simple_substitution.h"
#include <unordered_map>
#include <cctype>

std::string simpleSubstitutionDecrypt(const std::string& ciphertext, const std::string& key) {
    std::unordered_map<char, char> decryptionMap;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (size_t i = 0; i < alphabet.size(); ++i) {
        decryptionMap[key[i]] = alphabet[i];
    }

    std::string plaintext;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char upperC = toupper(c);
            char decryptedChar = decryptionMap[upperC];
            plaintext += islower(c) ? tolower(decryptedChar) : decryptedChar;
        }
        else {
            plaintext += c;
        }
    }

    return plaintext;
}