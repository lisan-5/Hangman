#include "game.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>

HangmanGame::HangmanGame() 
    : remainingTries(6), gameWon(false), currentScore(0), 
      difficulty(Difficulty::MEDIUM) {}

void HangmanGame::start(const std::string& player) {
    playerName = player;
    
    do {
        initializeGame();
        
        while (!isGameOver()) {
            display.showGameState(guessedWord, guessedLetters, remainingTries, 
                                currentScore, difficulty);
            processInput();
        }

        display.showGameState(guessedWord, guessedLetters, remainingTries, 
                            currentScore, difficulty);
        
        calculateScore();
        showGameSummary();
        
        if (currentScore > 0) {
            scoreManager.addScore(playerName, currentScore);
        }

        std::cout << "\nWould you like to play again? (y/n): ";
        char playAgain;
        std::cin >> playAgain;
        if (tolower(playAgain) != 'y') break;

    } while (true);
}

void HangmanGame::initializeGame() {
    currentWord = wordBank.getRandomWord();
    guessedWord = std::string(currentWord.length(), '_');
    guessedLetters.clear();
    
    switch (difficulty) {
        case Difficulty::EASY:
            remainingTries = 8;
            break;
        case Difficulty::HARD:
            remainingTries = 4;
            break;
        default:
            remainingTries = 6;
    }
    
    gameWon = false;
    currentScore = 0;
    hintSystem.resetHints();
}

void HangmanGame::processInput() {
    std::cout << "\nOptions:\n"
              << "1. Guess a letter\n"
              << "2. Get a hint\n"
              << "Choice: ";
    
    int choice;
    std::cin >> choice;
    
    if (choice == 2 && difficulty != Difficulty::HARD) {
        handleHint();
        return;
    }
    
    char guess;
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        guess = tolower(guess);
    } while (!isValidGuess(guess));

    guessedLetters.push_back(guess);
    bool correctGuess = makeGuess(guess);
    updateGameState(guess, correctGuess);
}

void HangmanGame::handleHint() {
    if (hintSystem.hintsRemaining() > 0) {
        std::string hint = hintSystem.getHint(currentWord, guessedWord);
        std::cout << "\nHint: " << hint << std::endl;
        currentScore -= 50; // Penalty for using a hint
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    } else {
        std::cout << "\nNo hints remaining!\n";
        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }
}

bool HangmanGame::isValidGuess(char guess) const {
    if (!isalpha(guess)) {
        std::cout << "Please enter a letter.\n";
        return false;
    }
    if (std::find(guessedLetters.begin(), guessedLetters.end(), tolower(guess)) 
        != guessedLetters.end()) {
        std::cout << "You already guessed that letter.\n";
        return false;
    }
    return true;
}

bool HangmanGame::makeGuess(char guess) {
    bool correctGuess = false;
    for (size_t i = 0; i < currentWord.length(); ++i) {
        if (tolower(currentWord[i]) == guess) {
            guessedWord[i] = currentWord[i];
            correctGuess = true;
        }
    }
    return correctGuess;
}

void HangmanGame::updateGameState(char guess, bool correctGuess) {
    if (!correctGuess) {
        remainingTries--;
    }
    gameWon = (guessedWord == currentWord);
}

void HangmanGame::calculateScore() {
    if (gameWon) {
        // Base score calculation
        currentScore = 100 * remainingTries;
        
        // Bonus for word length
        currentScore += currentWord.length() * 50;
        
        // Difficulty multiplier
        switch (difficulty) {
            case Difficulty::EASY:
                currentScore = static_cast<int>(currentScore * 0.8);
                break;
            case Difficulty::HARD:
                currentScore = static_cast<int>(currentScore * 1.5);
                break;
            default:
                break;
        }
    } else {
        currentScore = 0;
    }
}

void HangmanGame::showGameSummary() const {
    if (gameWon) {
        std::cout << "\nCongratulations! You won!\n";
        std::cout << "Final Score: " << currentScore << "\n";
    } else {
        std::cout << "\nGame Over! The word was: " << currentWord << "\n";
    }
}

void HangmanGame::setDifficulty(Difficulty diff) {
    difficulty = diff;
}

void HangmanGame::setCategory(WordCategory category) {
    wordBank.setCategory(category);
}