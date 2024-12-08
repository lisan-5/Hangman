#include "score_manager.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iomanip>

ScoreManager::ScoreManager() {
    loadScores();
}

void ScoreManager::addScore(const std::string& playerName, int score) {
    highScores.emplace_back(playerName, score, getCurrentDate());
    sortScores();
    
    if (highScores.size() > MAX_SCORES) {
        highScores.resize(MAX_SCORES);
    }
    
    saveScores();
}

void ScoreManager::displayHighScores() const {
    std::cout << "\n=== HIGH SCORES ===\n\n";
    std::cout << std::setw(5) << "Rank" 
              << std::setw(20) << "Player" 
              << std::setw(10) << "Score" 
              << std::setw(12) << "Date" << "\n";
    std::cout << std::string(47, '-') << "\n";
    
    for (size_t i = 0; i < highScores.size(); ++i) {
        std::cout << std::setw(5) << (i + 1)
                  << std::setw(20) << highScores[i].playerName
                  << std::setw(10) << highScores[i].score
                  << std::setw(12) << highScores[i].date << "\n";
    }
}

void ScoreManager::sortScores() {
    std::sort(highScores.begin(), highScores.end(),
              [](const Score& a, const Score& b) {
                  return a.score > b.score;
              });
}

std::string ScoreManager::getCurrentDate() const {
    time_t now = time(nullptr);
    struct tm tstruct = *localtime(&now);
    char buf[11];
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return std::string(buf);
}

void ScoreManager::loadScores() {
    std::ifstream file("highscores.txt");
    if (!file) return;
    
    std::string name, date;
    int score;
    while (file >> name >> score >> date) {
        highScores.emplace_back(name, score, date);
    }
    sortScores();
}

void ScoreManager::saveScores() const {
    std::ofstream file("highscores.txt");
    if (!file) return;
    
    for (const auto& score : highScores) {
        file << score.playerName << " "
             << score.score << " "
             << score.date << "\n";
    }
}