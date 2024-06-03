#ifndef XOR_H
#define XOR_H

#include <string>

std::string xorDecrypt(const std::string& hexCiphertext, const std::string& hexKey);
std::string stringToHex(const std::string& input);
std::string hexToString(const std::string& input);

#endif
