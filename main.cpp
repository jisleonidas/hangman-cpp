#include <iostream>
#include <fstream>
#include <vector>

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
    vector<string> words;
    ifstream words_file;
    string line;

    words_file.open("words.txt");

    if (words_file.is_open()) {
        while (getline(words_file, line)) {
            words.push_back(line);
        }
    }
    
    cout << "Hello. Let's play a game of hangman." << endl << endl;

    for (string w : words) {
        Word word(w);
        cout << "original: " << word.original << endl;
        cout << "obfuscated: " << word.obfuscated << endl;
        cout << "guessed: " << word.guessed << endl;
    }

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