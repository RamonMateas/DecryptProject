#include "morse.h"
#include <sstream>
#include <map>

std::map<std::string, char> morseCode = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
    {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
    {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
    {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
    {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
    {"-.--", 'Y'}, {"--..", 'Z'}, {"-----", '0'}, {".----", '1'},
    {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'},
    {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'}
};

std::string morseDecode(const std::string& morseText) {
    std::string plaintext;
    std::string morseChar;
    for (char c : morseText) {
        if (c == ' ') {
            if (morseChar != "") {
                plaintext += morseCode[morseChar];
                morseChar = "";
            }
            plaintext += ' ';
        }
        else {
            morseChar += c;
        }
    }
    if (morseChar != "") {
        plaintext += morseCode[morseChar];
    }
    return plaintext;
}
