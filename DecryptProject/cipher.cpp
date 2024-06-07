#include "cipher.h"

#include <iostream>

// Xor Cipher
xorCipher::xorCipher(std::string hexKey)
	:hexKey(hexKey) {}

std::string xorCipher::encrypt(const std::string& text)
{
    return xorDecrypt(text, hexKey);
}

std::string xorCipher::decrypt(const std::string& text)
{
    return xorDecrypt(text, hexKey);
}

std::string xorCipher::getName() const
{
    return "xorCipher (key: " + hexKey + ")";
}


// Vigenere Cipher
vigenereCipher::vigenereCipher(std::string key)
    :key(key) {}

std::string vigenereCipher::encrypt(const std::string& text)
{
    return vigenereDecrypt(text, key);
}

std::string vigenereCipher::decrypt(const std::string& text)
{
    return vigenereDecrypt(text, key);
}

std::string vigenereCipher::getName() const
{
    return "vigenereCipher (key: " + key + ")";
}


// Railfence Cipher
railfenceCipher::railfenceCipher(int key)
    :key(key) {}

std::string railfenceCipher::encrypt(const std::string& text)
{
    return decryptRailFence(text, key);
}

std::string railfenceCipher::decrypt(const std::string& text)
{
    return decryptRailFence(text, key);
}

std::string railfenceCipher::getName() const
{
    return "railfenceCipher (rails: " + std::to_string(key) + ")";
}


// Morse Cipher
std::string morseCipher::encrypt(const std::string& text)
{
    return morseDecode(text);
}

std::string morseCipher::decrypt(const std::string& text)
{
    return morseDecode(text);
}

std::string morseCipher::getName() const
{
    return "morseCipher";
}


// Affine Cipher
affineCipher::affineCipher(int a, int b)
    :a(a), b(b) {}

std::string affineCipher::encrypt(const std::string& text)
{
    return affineDecrypt(text, a, b);
}

std::string affineCipher::decrypt(const std::string& text)
{
    return affineDecrypt(text, a, b);
}

std::string affineCipher::getName() const
{
    return "affineCipher (a: " + std::to_string(a) + ", b: " + std::to_string(b) + ")";
}


// Rot Cipher
rotCipher::rotCipher(int shift)
    : shift(shift) {}

std::string rotCipher::encrypt(const std::string& text)
{
    return rotDecrypt(text, shift);
}

std::string rotCipher::decrypt(const std::string& text)
{
    return rotDecrypt(text, shift);
}

std::string rotCipher::getName() const
{
    return "rotCipher (shift: " + std::to_string(shift) + ")";
}


// Simple Substitution Cipher
simpleSubstitutionCipher::simpleSubstitutionCipher(std::string key)
    : key(key) {}

std::string simpleSubstitutionCipher::encrypt(const std::string& text)
{
    return simpleSubstitutionDecrypt(text, key);
}

std::string simpleSubstitutionCipher::decrypt(const std::string& text)
{
    return simpleSubstitutionDecrypt(text, key);
}

std::string simpleSubstitutionCipher::getName() const
{
    return "simpleSubstitutionCipher (key: " + key + ")";
}


// Atbash Cipher
std::string atbashCipher::encrypt(const std::string& text)
{
    return atbashDecrypt(text);
}

std::string atbashCipher::decrypt(const std::string& text)
{
    return atbashDecrypt(text);
}

std::string atbashCipher::getName() const
{
    return "atbashCipher";
}


// Baconian Cipher
std::string baconianCipher::encrypt(const std::string& text)
{
    return baconianDecrypt(text);
}

std::string baconianCipher::decrypt(const std::string& text)
{
    return baconianDecrypt(text);
}

std::string baconianCipher::getName() const
{
    return "baconianCipher";
}


// Base64 Cipher
std::string base64Cipher::encrypt(const std::string& text)
{
    return base64Decode(text);
}

std::string base64Cipher::decrypt(const std::string& text)
{
    return base64Decode(text);
}

std::string base64Cipher::getName() const
{
    return "base64Cipher";
}