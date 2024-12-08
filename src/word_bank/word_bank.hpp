#ifndef WORD_BANK_HPP
#define WORD_BANK_HPP

#include <string>
#include <vector>
#include <map>
#include <random>
#include "game.hpp"

class WordBank {
private:
    std::map<WordCategory, std::vector<std::string>> categoryWords;
    WordCategory currentCategory;
    std::random_device rd;
    std::mt19937 gen;
    
    void initializeWords();

public:
    WordBank();
    std::string getRandomWord();
    void setCategory(WordCategory category);
    WordCategory getCurrentCategory() const { return currentCategory; }
};

#endif