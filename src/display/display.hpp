#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>
#include <vector>
#include "game.hpp"

class Display {
private:
    static const std::vector<std::string> HANGMAN_STATES;
    void clearScreen() const;
    void showHangman(int remainingTries) const;
    void showWord(const std::string& guessedWord) const;
    void showGuessedLetters(const std::vector<char>& guessedLetters) const;
    void showScore(int score) const;
    void showDifficulty(Difficulty diff) const;
    std::string getDifficultyString(Difficulty diff) const;

public:
    void showGameState(const std::string& guessedWord, 
                      const std::vector<char>& guessedLetters, 
                      int remainingTries,
                      int currentScore,
                      Difficulty diff) const;
};

#endif