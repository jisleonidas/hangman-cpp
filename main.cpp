#include "header.hpp"
#include "guess.cpp"
#include <fstream>
#include <vector>
#include <ctime>

int main()
{
    vector<string> words;
    ifstream words_file;
    string line;
    char guess;
    bool has_been_guessed;

    srand((unsigned) time(0));

    words_file.open("words.txt");

    if (words_file.is_open()) {
        while (getline(words_file, line)) {
            words.push_back(line);
        }
    }

    int total_words = words.size();

    words_file.close();
    
    cout << "Hello. Let's play a game of hangman." << endl; 

    for (int i = 0; i < total_words; i++) {
        int word_index;

        word_index = (rand() % words.size());
        Word word(words[word_index]);
        words.erase(words.begin() + word_index);

        has_been_guessed = false;
        for (int i = 0; i < 10; i++) {
            if (word.original == word.obfuscated) {
                cout << "\nobfuscated: " << word.obfuscated << endl;
                cout << "YAY. YOU HAVE GUESSED THE WORD. LET'S GO TO THE NEXT WORD.\n";
                has_been_guessed = true;
                break;
            }
            cout << "\nobfuscated: " << word.obfuscated << endl;
            cout << "Enter guess: ";
            getline(cin, line);
            if (line.length() > 1 || line.length() == 0) {
                cout << "INVALID INPUT.\n";
                i--;
                continue;
            }
            else {
                guess = line[0];
            }
            check_guess(guess, &word);
        }
        if (!has_been_guessed)
            cout << "\nYOU'VE RUN OUT OF CHANCES. WORD NOT GUESSED. MOVING ON.\n\n";
    }

    cout << "\nALL WORDS GUESSED. CONGRATULATIONS!\n";
}
