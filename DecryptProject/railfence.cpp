#include "railfence.h"
#include <string>
#include <vector>

std::string decryptRailFence(const std::string& cipher, int key) {
    if (key <= 1) {
        return cipher;
    }

    int len = cipher.length();
    std::vector<std::vector<char>> rail(key, std::vector<char>(len, '\n'));

    bool dir_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < len; i++) {
        if (row == 0) {
            dir_down = true;
        }
        if (row == key - 1) {
            dir_down = false;
        }

        rail[row][col++] = '*';

        dir_down ? row++ : row--;
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] == '*' && index < len) {
                rail[i][j] = cipher[index++];
            }
        }
    }

    std::string result;

    row = 0, col = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0) {
            dir_down = true;
        }
        if (row == key - 1) {
            dir_down = false;
        }

        if (rail[row][col] != '*') {
            result.push_back(rail[row][col++]);
        }

        dir_down ? row++ : row--;
    }

    return result;
}