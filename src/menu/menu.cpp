#include "menu.hpp"
#include <iostream>
#include <limits>

void Menu::showMainMenu() {
    while (true) {
        clearScreen();
        std::cout << "\n=== HANGMAN GAME ===\n"
                  << "1. Play Game\n"
                  << "2. Show Rules\n"
                  << "3. High Scores\n"
                  << "4. Select Category\n"
                  << "5. Set Difficulty\n"
                  << "6. Exit\n"
                  << "\nChoice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::string playerName = getPlayerName();
                game.start(playerName);
                break;
            }
            case 2:
                showRules();
                break;
            case 3:
                showHighScores();
                break;
            case 4:
                showCategories();
                break;
            case 5:
                setDifficulty();
                break;
            case 6:
                std::cout << "\nThanks for playing!\n";
                return;
            default:
                std::cout << "\nInvalid choice. Press Enter to continue...";
                std::cin.get();
        }
    }
}

void Menu::showRules() const {
    clearScreen();
    std::cout << "\n=== GAME RULES ===\n"
              << "1. Guess the hidden word one letter at a time\n"
              << "2. Each wrong guess adds a part to the hangman\n"
              << "3. You have 6 tries before the game is over\n"
              << "4. Score is calculated based on:\n"
              << "   - Word length\n"
              << "   - Remaining tries\n"
              << "   - Difficulty level\n"
              << "5. Hints are available but reduce final score\n"
              << "\nPress Enter to continue...";
    std::cin.get();
}

void Menu::showHighScores() const {
    clearScreen();
    scoreManager.displayHighScores();
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void Menu::showCategories() const {
    clearScreen();
    std::cout << "\n=== SELECT CATEGORY ===\n"
              << "1. Programming\n"
              << "2. Movies\n"
              << "3. Countries\n"
              << "4. Animals\n"
              << "5. Sports\n";
    
    int choice;
    std::cin >> choice;
    game.setCategory(static_cast<WordCategory>(choice));
}

void Menu::setDifficulty() {
    clearScreen();
    std::cout << "\n=== SELECT DIFFICULTY ===\n"
              << "1. Easy (More tries, hints available)\n"
              << "2. Medium (Standard rules)\n"
              << "3. Hard (Fewer tries, no hints)\n";
    
    int choice;
    std::cin >> choice;
    game.setDifficulty(static_cast<Difficulty>(choice));
}

std::string Menu::getPlayerName() const {
    clearScreen();
    std::cout << "\nEnter your name: ";
    std::string name;
    std::getline(std::cin, name);
    return name;
}

void Menu::clearScreen() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}