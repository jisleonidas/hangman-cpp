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
    
    cout << "Hello. Let's play a game of hangman." << endl << endl;

    for (int i = 0; i < total_words; i++) {
        int word_index;

        word_index = (rand() % words.size());
        Word word(words[word_index]);
        words.erase(words.begin() + word_index);

        has_been_guessed = false;
        cout << "obfuscated: " << word.obfuscated << endl;
        for (int i = 0; i < 10; i++) {
            if (word.original == word.obfuscated) {
                cout << "\nYAY. YOU HAVE GUESSED THE WORD. LET'S GO TO THE NEXT WORD.\n\n";
                has_been_guessed = true;
                break;
            }
            cout << "\nEnter guess: ";
            getline(cin, line);
            if (line.length() > 1 || line.length() == 0) {
                cout << "INVALID INPUT.";
                i--;
                continue;
            }
            else {
                guess = line[0];
            }
            check_guess(guess, &word);
            cout << "obfuscated: " << word.obfuscated << endl;
        }
        if (!has_been_guessed)
            cout << "\nYOU'VE RUN OUT OF CHANCES. WORD NOT GUESSED. MOVING ON.\n\n";
    }

    cout << "ALL WORDS GUESSED. CONGRATULATIONS!\n";
}
