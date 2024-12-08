#ifndef HINT_SYSTEM_HPP
#define HINT_SYSTEM_HPP

#include <string>

class HintSystem {
private:
    int remainingHints;
    
public:
    HintSystem() : remainingHints(3) {}
    
    void resetHints() { remainingHints = 3; }
    int hintsRemaining() const { return remainingHints; }
    
    std::string getHint(const std::string& word, const std::string& guessedWord);
};

#endif