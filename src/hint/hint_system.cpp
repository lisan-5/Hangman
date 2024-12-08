#include "hint_system.hpp"
#include <vector>
#include <random>

std::string HintSystem::getHint(const std::string& word, const std::string& guessedWord) {
    if (remainingHints <= 0) {
        return "No hints remaining!";
    }
    
    // Collect unguessed letters
    std::vector<size_t> unguessedPositions;
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessedWord[i] == '_') {
            unguessedPositions.push_back(i);
        }
    }
    
    if (unguessedPositions.empty()) {
        return "No more letters to reveal!";
    }
    
    // Randomly select an unguessed position
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, unguessedPositions.size() - 1);
    size_t randomPos = unguessedPositions[dis(gen)];
    
    remainingHints--;
    return "The word contains the letter '" + 
           std::string(1, word[randomPos]) + 
           "' at position " + std::to_string(randomPos + 1);
}