Checkers Game in C++ 🏁

A terminal-based implementation of the classic Checkers game with complete rules support, written in C++.

Features 🎮
Complete checkers rules including forced captures and king promotion

Visual game board using Unicode emoji pieces (⚪🔴🫅🏻🫅🏿)

Two-player mode with turn-based gameplay

Win detection when a player loses all pieces

King mechanics with enhanced movement abilities

Input validation to prevent illegal moves

How to Play 🕹️
Players take turns moving their pieces

Enter moves in chess notation (e.g., "a3 b4")

Regular pieces move diagonally forward

Capture opponent pieces by jumping over them

Reach the opposite side to become a King

Kings can move and capture in all diagonal directions

Player wins by capturing all opponent pieces

Compilation and Execution 💻

# Compile with g++
g++ checkers.cpp -o checkers

# Run the game
./checkers

Game Rules 📜
Regular Pieces:

Move diagonally forward

Can only capture forward

Promote to King at opponent's back row

King Pieces:

Move diagonally in any direction

Capture in all diagonal directions

Shown with crown emoji (🫅🏻/🫅🏿)

Forced Capture:

If a capture is available, you must take it

Multiple captures in one turn are allowed

Board Layout 🎨

  +----+----+----+----+----+----+----+----+
1 |    | ⚪ |    | ⚪ |    | ⚪ |    | ⚪ |
  +----+----+----+----+----+----+----+----+
2 | ⚪ |    | ⚪ |    | ⚪ |    | ⚪ |    |
  +----+----+----+----+----+----+----+----+
3 |    | ⚪ |    | ⚪ |    | ⚪ |    | ⚪ |
  +----+----+----+----+----+----+----+----+
4 |    |    |    |    |    |    |    |    |
  +----+----+----+----+----+----+----+----+
5 |    |    |    |    |    |    |    |    |
  +----+----+----+----+----+----+----+----+
6 | 🔴 |    | 🔴 |    | 🔴 |    | 🔴 |    |
  +----+----+----+----+----+----+----+----+
7 |    | 🔴 |    | 🔴 |    | 🔴 |    | 🔴 |
  +----+----+----+----+----+----+----+----+
8 | 🔴 |    | 🔴 |    | 🔴 |    | 🔴 |    |
  +----+----+----+----+----+----+----+----+
    a    b    c    d    e    f    g    h

    Requirements 📦
C++ compiler (g++ or similar)

Terminal with Unicode support

Linux/macOS/Windows (with WSL for Windows)

Troubleshooting ⚠️
If you see question marks instead of emojis:

Ensure your terminal supports Unicode

Try a different terminal (e.g., Windows Terminal instead of cmd)

On Linux/macOS, install a proper font:

Future Improvements 🔮
Implement AI opponent

Add save/load game functionality

Create graphical interface (SDL/OpenGL)

Add move history and undo feature

Implement network multiplayer

License 📄
This project is licensed under the MIT License - see the LICENSE file for details.

