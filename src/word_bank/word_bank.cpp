#include "word_bank.hpp"

WordBank::WordBank() : gen(rd()), currentCategory(WordCategory::PROGRAMMING) {
    initializeWords();
}

void WordBank::initializeWords() {
    categoryWords[WordCategory::PROGRAMMING] = {
        "ALGORITHM", "PROGRAMMING", "DEVELOPER", "DATABASE", "FUNCTION",
        "VARIABLE", "COMPILER", "DEBUGGING", "INTERFACE", "FRAMEWORK",
        "JAVASCRIPT", "PYTHON", "INHERITANCE", "POLYMORPHISM", "ENCAPSULATION"
    };
    
    categoryWords[WordCategory::MOVIES] = {
        "INCEPTION", "AVATAR", "TITANIC", "MATRIX", "GLADIATOR",
        "JAWS", "FROZEN", "GODFATHER", "CASABLANCA", "GOODFELLAS"
    };
    
    categoryWords[WordCategory::COUNTRIES] = {
        "AUSTRALIA", "BRAZIL", "CANADA", "DENMARK", "EGYPT",
        "FRANCE", "GERMANY", "HUNGARY", "INDIA", "JAPAN"
    };
    
    categoryWords[WordCategory::ANIMALS] = {
        "ELEPHANT", "GIRAFFE", "PENGUIN", "DOLPHIN", "KANGAROO",
        "LEOPARD", "OCTOPUS", "RHINOCEROS", "TIGER", "ZEBRA"
    };
    
    categoryWords[WordCategory::SPORTS] = {
        "BASKETBALL", "FOOTBALL", "TENNIS", "VOLLEYBALL", "CRICKET",
        "HOCKEY", "BASEBALL", "SWIMMING", "BOXING", "GOLF"
    };
}

std::string WordBank::getRandomWord() {
    const auto& words = categoryWords[currentCategory];
    std::uniform_int_distribution<> dis(0, words.size() - 1);
    return words[dis(gen)];
}

void WordBank::setCategory(WordCategory category) {
    currentCategory = category;
}