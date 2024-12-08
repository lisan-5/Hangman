#ifndef MENU_HPP
#define MENU_HPP

#include "game.hpp"
#include "score_manager.hpp"
#include <string>

class Menu {
private:
    HangmanGame game;
    ScoreManager scoreManager;
    
    void showRules() const;
    void showHighScores() const;
    void showCategories() const;
    void setDifficulty();
    std::string getPlayerName() const;
    void clearScreen() const;

public:
    void showMainMenu();
};

#endif