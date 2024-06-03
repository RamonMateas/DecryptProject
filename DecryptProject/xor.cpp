#include "xor.h"
#include <sstream>
#include <iomanip>

std::string stringToHex(const std::string& input) {
    std::stringstream ss;
    for (char c : input) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)c;
    }
    return ss.str();
}

std::string hexToString(const std::string& input) {
    std::stringstream ss;
    for (size_t i = 0; i < input.length(); i += 2) {
        std::string part = input.substr(i, 2);
        char ch = (char)strtol(part.c_str(), nullptr, 16);
        ss << ch;
    }
    return ss.str();
}

std::string xorDecrypt(const std::string& hexCiphertext, const std::string& hexKey) {
    std::string ciphertext = hexToString(hexCiphertext);
    std::string key = hexToString(hexKey);

    std::string plaintext;
    size_t keyLength = key.length();
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        plaintext += ciphertext[i] ^ key[i % keyLength];
    }
    return plaintext;
}
