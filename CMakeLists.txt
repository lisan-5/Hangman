cmake_minimum_required(VERSION 3.10)
project(hangman VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
add_executable(hangman
    main.cpp
    src/game/game.cpp
    src/display/display.cpp
    src/word_bank/word_bank.cpp
    src/score/score_manager.cpp
    src/hint/hint_system.cpp
    src/menu/menu.cpp
)

# Include directories
target_include_directories(hangman PRIVATE
    src/game
    src/display
    src/word_bank
    src/score
    src/hint
    src/menu
)
