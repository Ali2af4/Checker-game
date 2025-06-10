# Checkers Game in C++ 🏁

A terminal-based implementation of the classic Checkers game with complete rules support, written in C++.

## Features 🎮

* **Complete** checkers rules including forced captures and king promotion
* **Visual game board** using Unicode emoji pieces (⚪🔴🫅🏻🫅🏿)
* **Two-player mode** with turn-based gameplay
* **Win detection** when a player loses all pieces
* **King mechanics** with enhanced movement abilities
* **Input validation** to prevent illegal moves

## How to Play 🕹️

1. Players take turns moving their pieces
2. Enter moves in chess notation (e.g., "a3 b4")
3. Regular pieces move diagonally forward
4. Capture opponent pieces by jumping over them
5. Reach the opposite side to become a King
6. Kings can move and capture in all diagonal directions
7. Player wins by capturing all opponent pieces

## Compilation and Execution 💻

```bash
# Compile with g++
g++ checkers.cpp -o checkers

# Run the game
./checkers
