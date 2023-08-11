  /*group members 1.NDAYISHIMIYE Habibu 222005474
                2.UWABABYEYI MBABAZI Aline 222009293
                3.IRADUKUNDA Bonheur 222005615
                */
                     //Queation

/*CSC2161 – Advanced Programming in C++
Programming Assignment 3
Implement the simplified version of the Hangman game as follows: 
Your program is going to randomly select an English word and 
display a string of
– of the same length as the word and ask the user to guess the word one
character at a time
 The user starts with 6 guesses available to him/her
 At each step of the game the program notifies the user about the guesses
remaining, and the letters not yet used. After each guess, the program displays
the word the user’s guess with the characters already guessed displayed, and
the characters not yet guessed replaced by -
 If the user inputs a symbol other than a letter, notify and give him/her a warning.
At the start of the game, the user has 3 warnings available. If a user inputs a
non-letter symbol and has no warnings left, he/she should lose a guess.
 If the player inputs an already used character, he/she should lose a warning or a
guess, depending on whether there are any warnings available.
 If the player inputs a letter that is in the secret word and has not been already
guessed, the player does not lose a guess.
 If the player input a consonant not in the secret word, he/she should lose one
guess.
 If the player inputs a vowel (a,e,i,o,u), he/she should lose 2 guesses.
 The game ends when the player guesses the entire word before exhausting his
guesses ( WIN) or when the player exhausts his guesses(LOSS)
 In case of a win , the score for the player is computed as the number of
guesses remaining times the number of unique letters in the secret word.*/

                  //Answer
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

std::string selectRandomWord() {
    std::vector<std::string> words = {"habibu","aline","bonhuer","apple", "banana", "cherry", "dog", "elephant", "frog", "grape", "honey", "iguana", "jelly","workshop","baby","demon","pathogen","weekhow","kigali","following","tuesday","potato"};
    int randomIndex = std::rand() % words.size();
    return words[randomIndex];
}

std::string displayWord(const std::string& word, const std::set<char>& guessedLetters) {
    std::string display;
    for (char letter : word) {
        if (guessedLetters.count(letter) > 0) {
            display += letter;
        } else {
            display += '-';
        }
    }
    return display;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed random number generator

    std::string secretWord = selectRandomWord();
    std::set<char> guessedLetters;
    int warnings = 3;
    int guesses = 6;

    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << "Guess the secret word one letter at a time." << std::endl;

    while (guesses > 0) {
        std::cout << "\nGuesses left: " << guesses << std::endl;
        std::cout << "Warnings left: " << warnings << std::endl;
        std::cout << "Unused letters: ";
        for (char letter = 'a'; letter <= 'z'; ++letter) {
            if (guessedLetters.count(letter) == 0) {
                std::cout << letter << " ";
            }
        }
        std::cout << std::endl;

        std::string display = displayWord(secretWord, guessedLetters);
        std::cout << "Current progress: " << display << std::endl;

        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;
        guess = std::tolower(guess);

        if (!std::isalpha(guess)) {
            if (warnings > 0) {
                --warnings;
                std::cout << "Invalid input! You have " << warnings << " warnings left." << std::endl;
            } else {
                --guesses;
                std::cout << "Invalid input! You lost a guess. Guesses left: " << guesses << std::endl;
            }
            continue;
        }

        if (guessedLetters.count(guess) > 0) {
            if (warnings > 0) {
                --warnings;
                std::cout << "You've already guessed that letter. You have " << warnings << " warnings left." << std::endl;
            } else {
                --guesses;
                std::cout << "You've already guessed that letter. You lost a guess. Guesses left: " << guesses << std::endl;
            }
            continue;
        }

        guessedLetters.insert(guess);

        if (secretWord.find(guess) != std::string::npos) {
            display = displayWord(secretWord, guessedLetters);
            std::cout << "Good guess Habibu: " << display << std::endl;
            if (display == secretWord) {
                int score = guesses * std::set<char>(secretWord.begin(), secretWord.end()).size();
                std::cout << "Congratulations Habibu! You won!" << std::endl;
                std::cout << "Your score: " << score << std::endl;
                break;
            }
        } else {
            if (guess == 'a' || guess == 'e' || guess == 'i' || guess == 'o' || guess == 'u') {
                guesses -= 2;
            } else {
                --guesses;
            }
            std::cout << "Incorrect guess Habibu. Guesses left: " << guesses << std::endl;
        }
    }

    if (guesses == 0) {
        std::cout << "Sorry Habibu, you lost. The secret word was: " << secretWord << std::endl;
    }

    return 0;
}
