#include "header.hpp"

bool check_guess(char guess, Word *word)
{
    bool guess_in_original;
    bool already_guessed;
    guess_in_original = already_guessed = false;

    for (char original_ch : (*word).original) { // For character in original word.
        if (guess == original_ch) {
            guess_in_original = true;
            break;
        }
    }

    if (!guess_in_original)
        return false;

    for (char obfuscated_ch : (*word).obfuscated) {
        if (guess == obfuscated_ch) {
            return false;
        }
    }

    for (int i = 0; i < (*word).length; i++) {
        if (guess == (*word).original[i]) {
            (*word).obfuscated[i] = guess;
        }
    }
    return false;
}