// DecryptProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "vigenere.h"
#include "xor.h"
#include "affine.h"
#include "morse.h"
#include "railfence.h"

void printMenu() {
    std::cout << "Select decryption algorithm:\n";
    std::cout << "1. Vigenere Cipher\n";
    std::cout << "2. XOR-HEX Cipher\n";
    std::cout << "3. Affine Cipher\n";
    std::cout << "4. Morse Code\n";
    std::cout << "5. Rail Fence Cipher\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter choice: ";
}

int main() {
    int choice;
    do {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(); 

        if (choice == 6) break;

        std::string ciphertext;
        std::cout << "Enter ciphertext: ";
        std::getline(std::cin, ciphertext);

        switch (choice) {
        case 1: {
            std::string key;
            std::cout << "Enter key: ";
            std::getline(std::cin, key);
            std::string plaintext = vigenereDecrypt(ciphertext, key);
            std::cout << "Decrypted text: " << plaintext << std::endl;
            break;
        }
        case 2: {
            std::string hexKey;
            std::cout << "Enter XOR key (hexadecimal format): ";
            std::getline(std::cin, hexKey);
            std::string plaintext = xorDecrypt(ciphertext, hexKey);
            std::cout << "Decrypted text (Hex): " << stringToHex(plaintext) << std::endl;
            std::cout << "Decrypted text (ASCII): " << plaintext << std::endl;
            break;
        }
        case 3: {
            int a, b;
            std::cout << "Enter 'a' value: ";
            std::cin >> a;
            std::cout << "Enter 'b' value: ";
            std::cin >> b;
            std::cin.ignore();
            std::string plaintext = affineDecrypt(ciphertext, a, b);
            std::cout << "Decrypted text: " << plaintext << std::endl;
            break;
        }
        case 4: {
            for (char& c : ciphertext) {
                if (c == '|') {
                    c = ' ';
                }
            }
            std::string plaintext = morseDecode(ciphertext);
            std::cout << "Decrypted text: " << plaintext << std::endl;
            break;
        }
        case 5: {
            int numRails;
            std::cout << "Enter number of rails: ";
            std::cin >> numRails;
            std::cin.ignore();
            std::string plaintext = decryptRailFence(ciphertext, numRails);
            std::cout << "Decrypted text: " << plaintext << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
