#include <iostream>

using namespace std;

string VOWELS = "aeiou";

class Word
{
    int counter = 0;

    public:
        string original;
        string obfuscated;
        string guessed;

        Word(string orig)
        {
            original = orig;
            obfuscate_word();
            guessed = obfuscated;
        }
    
    void obfuscate_word();
};

int main()
{
    cout << "Hello. Let's play a game of hangman." << endl << endl;

    Word word("hangman");

    cout << "original: " << word.original << endl;
    cout << "obfuscated: " << word.obfuscated << endl;
    cout << "guessed: " << word.guessed << endl;
}

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