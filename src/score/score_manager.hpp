#ifndef SCORE_MANAGER_HPP
#define SCORE_MANAGER_HPP

#include <string>
#include <vector>
#include <utility>

class ScoreManager {
private:
    struct Score {
        std::string playerName;
        int score;
        std::string date;
        
        Score(const std::string& name, int s, const std::string& d)
            : playerName(name), score(s), date(d) {}
    };
    
    std::vector<Score> highScores;
    const size_t MAX_SCORES = 10;
    
    void sortScores();
    std::string getCurrentDate() const;
    void loadScores();
    void saveScores() const;

public:
    ScoreManager();
    void addScore(const std::string& playerName, int score);
    void displayHighScores() const;
};

#endif