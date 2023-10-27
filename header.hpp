#ifndef HEADER
#define HEADER

#include <iostream>
using namespace std;

const string VOWELS = "aeiou";

class Word
{
    int counter = 0;

    public:
        string original;
        string obfuscated;
        int length;

        Word(string orig)
        {
            original = orig;
            obfuscate_word();
            length = original.length();
        }
    
    void obfuscate_word();
};

bool isVowel(char ch)
{
    for (char vowel : VOWELS) {
        if (ch == vowel)
            return true;
    }

    return false;
}

void Word::obfuscate_word()
{
    obfuscated = "";

    for (char ch : original) {
        if (!(isVowel(ch)))
            obfuscated += "-";
        else
            obfuscated += ch;
    }

    counter++;
}

#endif