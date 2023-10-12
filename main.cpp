#include "header.hpp"
#include <fstream>
#include <vector>

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
    }
}