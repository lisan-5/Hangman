#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "word_bank.hpp"
#include "display.hpp"
#include "score_manager.hpp"
#include "hint_system.hpp"

enum class Difficulty { EASY = 1, MEDIUM, HARD };
enum class WordCategory { PROGRAMMING = 1, MOVIES, COUNTRIES, ANIMALS, SPORTS };

class HangmanGame {
private:
    WordBank wordBank;
    Display display;
    ScoreManager scoreManager;
    HintSystem hintSystem;
    
    std::string currentWord;
    std::string guessedWord;
    std::vector<char> guessedLetters;
    int remainingTries;
    bool gameWon;
    int currentScore;
    Difficulty difficulty;
    std::string playerName;
    
    void initializeGame();
    bool makeGuess(char guess);
    bool isGameOver() const;
    void updateGameState(char guess, bool correctGuess);
    void processInput();
    bool isValidGuess(char guess) const;
    void calculateScore();
    void showGameSummary() const;
    void handleHint();

public:
    HangmanGame();
    void start(const std::string& player);
    void setDifficulty(Difficulty diff);
    void setCategory(WordCategory category);
    int getCurrentScore() const { return currentScore; }
};

#endif