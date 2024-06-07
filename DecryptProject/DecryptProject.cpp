// DecryptProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
#include "vigenere.h"
#include "xor.h"
#include "affine.h"
#include "morse.h"
#include "railfence.h"
#include "rot.h"
#include "simple_substitution.h"
#include "atbash.h"
#include "baconian.h"
#include "base64.h"
#include "cipher.h"
#include "text.h"

void clearScreen() {
    #ifdef _WIN32
    std::system("cls");
    #else
    std::system("clear");
    #endif
}

void printMenu() {
    std::cout << "Select decryption algorithm:\n";
    std::cout << "1. Vigenere Cipher\n";
    std::cout << "2. XOR-HEX Cipher\n";
    std::cout << "3. Affine Cipher\n";
    std::cout << "4. Morse Code\n";
    std::cout << "5. Rail Fence Cipher\n";
    std::cout << "6. Atbash Cipher\n";
    std::cout << "7. Base64 Cipher\n";
    std::cout << "8. ROT Cipher\n";
    std::cout << "9. Simple Substitution Cipher\n";
    std::cout << "10. Baconian Cipher\n";
    std::cout << "11. Show History\n";
    std::cout << "12. Remove a Layer\n";
    std::cout << "13. Exit\n";
    std::cout << "Enter choice: ";
}

std::unique_ptr<Cipher> createCipher(int choice) {
    switch (choice) {
    case 1: {
        std::string key;
        std::cout << "Enter key: ";
        std::getline(std::cin, key);
        return std::make_unique<vigenereCipher>(key);
    }
    case 2: {
        std::string hexKey;
        std::cout << "Enter XOR key (hexadecimal format): ";
        std::getline(std::cin, hexKey);
        return std::make_unique<xorCipher>(hexKey);
    }
    case 3: {
        int a, b;
        std::cout << "Enter 'a' value: ";
        std::cin >> a;
        std::cout << "Enter 'b' value: ";
        std::cin >> b;
        std::cin.ignore();
        return std::make_unique<affineCipher>(a, b);
    }
    case 4: {
        return std::make_unique<morseCipher>();
    }
    case 5: {
        int numRails;
        std::cout << "Enter number of rails: ";
        std::cin >> numRails;
        std::cin.ignore();
        return std::make_unique<railfenceCipher>(numRails);
    }
    case 6: {
        return std::make_unique<atbashCipher>();
    }
    case 7: {
        return std::make_unique<base64Cipher>();
    }
    case 8: {
        int shift;
        std::cout << "Enter shift value: ";
        std::cin >> shift;
        std::cin.ignore();
        return std::make_unique<rotCipher>(shift);
    }
    case 9: {
        std::string key;
        std::cout << "Enter key: ";
        std::getline(std::cin, key);
        return std::make_unique<simpleSubstitutionCipher>(key);
    }
    case 10: {
        return std::make_unique<baconianCipher>();
    }
    default:
        return nullptr;
    }
}

int main() {
    int choice;
    std::string initialText;
    std::cout << "Enter the initial ciphertext: ";
    std::getline(std::cin, initialText);

    TextManager manager(initialText);

    do {
        clearScreen();
        printMenu();
        std::cin >> choice;
        std::cin.ignore();

        clearScreen();

        if (choice == 13) break;

        if (choice == 11) {
            manager.showHistory();
            std::cout << "Press Enter to continue...";
            std::cin.get();
            continue;
        }

        if (choice == 12) {
            int index;
            std::cout << "Enter the index of the layer to remove: ";
            std::cin >> index;
            std::cin.ignore();
            manager.removeCipher(index);
            std::cout << "Current text: " << manager.getText() << std::endl;
            std::cout << "Press Enter to continue...";
            std::cin.get();
            continue;
        }

        auto cipher = createCipher(choice);
        if (cipher) {
            manager.applyCipher(std::move(cipher));
            std::cout << "Current text: " << manager.getText() << std::endl;
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << "Press Enter to continue...";
        std::cin.get();

    } while (choice != 13);

    return 0;
}
