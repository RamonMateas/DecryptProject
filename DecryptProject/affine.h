#ifndef AFFINE_H
#define AFFINE_H

#include <string>

int modInverse(int a, int m);
std::string affineDecrypt(const std::string& ciphertext, int a, int b);

#endif
#pragma once
