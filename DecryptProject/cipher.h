#pragma once

#include <string>
#include <memory>

#include "xor.h"
#include "vigenere.h"
#include "railfence.h"
#include "morse.h"
#include "affine.h"
#include "rot.h"
#include "simple_substitution.h"
#include "atbash.h"
#include "baconian.h"
#include "base64.h"

class Cipher
{
public:
    virtual std::string encrypt(const std::string& text) = 0;
    virtual std::string decrypt(const std::string& text) = 0;
    virtual std::string getName() const = 0;
    virtual ~Cipher() = default;
};

// Xor Cipher
class xorCipher : public Cipher 
{
private:
    std::string hexKey;

public:
    xorCipher(std::string hexKey);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    std::string getName() const override;
};


// Vigenere Cipher
class vigenereCipher : public Cipher
{
private:
    std::string key;
public:
    vigenereCipher(std::string key);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    std::string getName() const override;
};


// Railfence Cipher
class railfenceCipher : public Cipher
{
private:
    int key;

public:
    railfenceCipher(int key);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    std::string getName() const override;
};


// Morse Cipher
class morseCipher : public Cipher
{
public:
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    std::string getName() const override;
};


// Affine Cipher
class affineCipher : public Cipher
{
private:
    int a, b;

public:
    affineCipher(int a, int b);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    std::string getName() const override;
};


// Rot Cipher
class rotCipher : public Cipher
{
private:
    int shift;

public:
    rotCipher(int shift);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    std::string getName() const override;
};


// Simple Substitution Cipher
class simpleSubstitutionCipher : public Cipher
{
private:
    std::string key;

public:
    simpleSubstitutionCipher(std::string key);
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    std::string getName() const override;
};


// Atbash Cipher
class atbashCipher : public Cipher
{
public:
    atbashCipher() = default;
    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;
    std::string getName() const override;
};


// Baconian Cipher
class baconianCipher : public Cipher
{
public:
    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);
    std::string getName() const;
};


// Base64 Cipher
class base64Cipher : public Cipher
{
public:
    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);
    std::string getName() const;
};