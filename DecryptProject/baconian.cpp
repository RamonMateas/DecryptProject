#include "baconian.h"
#include <unordered_map>
#include <stdexcept>

std::string baconianDecrypt(const std::string& ciphertext) {
    std::unordered_map<std::string, char> baconianMap = {
        {"AAAAA", 'A'}, {"AAAAB", 'B'}, {"AAABA", 'C'}, {"AAABB", 'D'}, {"AABAA", 'E'},
        {"AABAB", 'F'}, {"AABBA", 'G'}, {"AABBB", 'H'}, {"ABAAA", 'I'}, {"ABAAB", 'J'},
        {"ABABA", 'K'}, {"ABABB", 'L'}, {"ABBAA", 'M'}, {"ABBAB", 'N'}, {"ABBBA", 'O'},
        {"ABBBB", 'P'}, {"BAAAA", 'Q'}, {"BAAAB", 'R'}, {"BAABA", 'S'}, {"BAABB", 'T'},
        {"BABAA", 'U'}, {"BABAB", 'V'}, {"BABBA", 'W'}, {"BABBB", 'X'}, {"BBAAA", 'Y'},
        {"BBAAB", 'Z'}
    };

    if (ciphertext.length() % 5 != 0) {
        throw std::invalid_argument("Invalid Baconian ciphertext");
    }

    std::string plaintext;
    for (size_t i = 0; i < ciphertext.length(); i += 5) {
        std::string segment = ciphertext.substr(i, 5);
        for (char& c : segment) {
            c = toupper(c) == 'A' ? 'A' : 'B';
        }
        plaintext += baconianMap[segment];
    }

    return plaintext;
}