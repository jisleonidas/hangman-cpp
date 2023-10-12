#include "header.hpp"

bool check_guess(char guess, Word word)
{
    for (char original_ch : word.original) { // For character in original word.
        if (guess == original_ch) {
            // For every character already guessed or displayed.
            for (char guessed_ch : word.obfuscated) {
                if (guess == guessed_ch) {
                    return false;
                }
                else {
                    for (int i = 0; i < word.length; i++) {
                        if (guess == word.original[i]) {
                            word.obfuscated[i] = guess;
                        }
                    }
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
}