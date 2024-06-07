#pragma once

#include "cipher.h"

#include <vector>
#include <iostream>

class TextManager {
private:
    std::string text;
    std::vector<std::pair<std::unique_ptr<Cipher>, std::string>> history;

public:
    TextManager(const std::string& initialText);

    void applyCipher(std::unique_ptr<Cipher> cipher);

    void removeCipher(int index);

    void showHistory() const;
    std::string getText() const;
};
