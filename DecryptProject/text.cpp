#include "text.h"

TextManager::TextManager(const std::string& initialText) 
    : text(initialText) {}

void TextManager::applyCipher(std::unique_ptr<Cipher> cipher)
{
    std::string tmp;

    if (history.size() == 0)
        tmp = text;
    else
        tmp = history.back().second;

    history.emplace_back(std::move(cipher), cipher->encrypt(tmp));
}

void TextManager::removeCipher(int index)
{
    if (index < 0 || index >= history.size())
    {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    std::string prevText;
    if (index == 0)
        prevText = text;
    else
        prevText = history[index - 1].second;

    for (int i = index + 1; i < history.size(); i++)
    {
        prevText = history[i].first->encrypt(prevText);
        history[i].second = prevText;
    }

    history.erase(history.begin() + index);
}

void TextManager::showHistory() const
{
    for (size_t i = 0; i < history.size(); i++) 
    {
        std::cout << "Layer " << i << ": " << history[i].first->getName() << " - " << history[i].second << std::endl;
        std::cout << std::endl;
    }
}

std::string TextManager::getText() const
{
    if (history.size() == 0)
        return text;

    return history.back().second;
}