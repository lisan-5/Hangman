#include "display.hpp"
#include <iostream>
#include <algorithm>

const std::vector<std::string> Display::HANGMAN_STATES = {
    R"(
      +---+
      |   |
          |
          |
          |
          |
    =========)",
    R"(
      +---+
      |   |
      O   |
          |
          |
          |
    =========)",
    R"(
      +---+
      |   |
      O   |
      |   |
          |
          |
    =========)",
    R"(
      +---+
      |   |
      O   |
     /|   |
          |
          |
    =========)",
    R"(
      +---+
      |   |
      O   |
     /|\  |
          |
          |
    =========)",
    R"(
      +---+
      |   |
      O   |
     /|\  |
     /    |
          |
    =========)",
    R"(
      +---+
      |   |
      O   |
     /|\  |
     / \  |
          |
    =========)",
    R"(
      +---+
      |   |
     \O/  |
      |   |
     / \  |
          |
    =========)"
};

void Display::clearScreen() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Display::showHangman(int remainingTries) const {
    int stateIndex = HANGMAN_STATES.size() - 1 - remainingTries;
    stateIndex = std::clamp(stateIndex, 0, static_cast<int>(HANGMAN_STATES.size() - 1));
    std::cout << HANGMAN_STATES[stateIndex] << std::endl;
}

void Display::showWord(const std::string& guessedWord) const {
    std::cout << "\nWord: ";
    for (char c : guessedWord) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

void Display::showGuessedLetters(const std::vector<char>& guessedLetters) const {
    std::cout << "\nGuessed letters: ";
    for (char c : guessedLetters) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

void Display::showScore(int score) const {
    std::cout << "\nCurrent Score: " << score << std::endl;
}

std::string Display::getDifficultyString(Difficulty diff) const {
    switch (diff) {
        case Difficulty::EASY:
            return "Easy";
        case Difficulty::HARD:
            return "Hard";
        default:
            return "Medium";
    }
}

void Display::showDifficulty(Difficulty diff) const {
    std::cout << "\nDifficulty: " << getDifficultyString(diff) << std::endl;
}

void Display::showGameState(const std::string& guessedWord, 
                          const std::vector<char>& guessedLetters, 
                          int remainingTries,
                          int currentScore,
                          Difficulty diff) const {
    clearScreen();
    std::cout << "\n=== HANGMAN ===\n";
    showHangman(remainingTries);
    showWord(guessedWord);
    showGuessedLetters(guessedLetters);
    std::cout << "\nRemaining tries: " << remainingTries << std::endl;
    showScore(currentScore);
    showDifficulty(diff);
}