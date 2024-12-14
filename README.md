# Advanced C++ Hangman Game 🎮

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-brightgreen.svg)](https://github.com/lisan-5/cpp-hangman)

An advanced, feature-rich implementation of the classic Hangman game, built with modern C++ and designed with clean architecture principles. This console-based game offers an engaging and interactive experience with multiple gameplay modes and features.

## ✨ Key Features

- 🎯 Multiple Game Categories:
  - Programming
  - Movies
  - Countries
  - Animals
  - Sports

- 🎚️ Difficulty Levels:
  - Easy (8 tries, hints available)
  - Medium (6 tries, hints available)
  - Hard (4 tries, no hints)

- 🏆 Advanced Scoring System:
  - Dynamic score calculation based on word length
  - Difficulty multipliers
  - Persistent high scores tracking
  - Date-stamped records

- 💡 Hint System:
  - 3 hints per game (Easy/Medium modes)
  - Strategic hint penalties
  - Smart letter revelation

- 🎨 Visual Features:
  - ASCII art hangman display
  - Clean console interface
  - Progressive word revelation
  - Real-time game statistics

## 🚀 Getting Started

### Prerequisites
- C++ Compiler with C++17 support
  - GCC 7+ or
  - Clang 5+ or
  - MSVC 2017+
- CMake 3.10 or higher
- Git (optional, for cloning)

### Building from Source

```bash
# Clone the repository
https://github.com/lisan-5/hangman.git

# Navigate to project directory
cd cpp-hangman

# Create and enter build directory
mkdir build && cd build

# Generate build files
cmake ..

# Build the project
cmake --build .
```

### Running the Game

```bash
# From the build directory
./hangman
```

## 🎮 How to Play

1. **Start the Game**
   - Launch the executable
   - Enter your player name
   - Choose your preferred category and difficulty

2. **Gameplay**
   - Guess letters one at a time
   - Watch the hangman progress with each wrong guess
   - Use hints strategically (if available)
   - Try to solve the word before running out of tries

3. **Scoring**
   - Base points for each correct guess
   - Bonus points for completing words
   - Multipliers based on difficulty
   - Penalty for using hints

## 🏗️ Project Structure

```
hangman/
├── src/
│   ├── game/          # Core game logic
│   ├── display/       # UI components
│   ├── word_bank/     # Word management
│   ├── score/         # Score tracking
│   ├── hint/          # Hint system
│   └── menu/          # Menu interface
├── main.cpp           # Entry point
└── CMakeLists.txt    # Build configuration
```

## 🛠️ Technical Details

- Modern C++ features (C++17)
- Object-oriented design
- SOLID principles
- Exception handling
- File I/O for persistent storage
- Random number generation
- Smart pointers
- STL containers

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit changes (`git commit -m 'Add AmazingFeature'`)
4. Push to branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🎯 Future Enhancements

- [ ] Multiplayer mode
- [ ] Custom word categories
- [ ] GUI version
- [ ] Network play
- [ ] Achievement system
- [ ] Word difficulty ratings
