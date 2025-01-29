# Chess Game in C

## Overview
This is a **terminal-based Chess game** written in C. The game offers an interactive chess-playing experience with a visually structured board, move validation, and game rules enforcement. A key feature is that the game **saves its state whenever it is closed**, allowing players to resume their game when they restart the program.

## Features
- **Fully functional chess game** with all rules implemented.
- **Move validation** for each chess piece (Pawn, Rook, Knight, Bishop, Queen, and King).
- **Check and Checkmate detection** to ensure proper game rules.
- **Castling and Pawn Promotion** functionalities are included.
- **Game state persistence** - the game saves progress in a file (`save.txt`) and allows resuming after closing.
- **Turn-based play** for two players, alternating between White and Black.
- **Error handling** for illegal moves, invalid inputs, and incorrect piece selection.
- **Brilliant terminal interface** that visually represents the board.

## How to Compile & Run

### Compilation
Use the following command to compile the program using GCC:
```sh
gcc .\main.c .\displayBoard.c .\fillBoard.c .\IsBishpMoveLegal.c .\IsBlackKingInCheck.c \
    .\IsCheckFromBishop.c .\IsCheckFromKing.c .\IsCheckFromKnight.c .\IsCheckfromPawn.c \
    .\IsCheckFromRook.c .\isCheckmate.c .\IsKingMoveLegal.c .\IsKnightMoveLegal.c \
    .\IsMoveLegal.c .\IsPawnMoveLegal.c .\IsQueenMoveLegal.c .\IsRookMoveLegal.c \
    .\IsWhiteKingInCheck.c .\LoadGame.c .\PawnPromotion.c .\PieceAroundKingCHECK.c \
    .\iscastlingLegal.c -o game
```

### Running the Game
After compiling, run the game using:
```sh
.\game.exe
```

### Loading a Saved Game
When you start the program, it will prompt:
```
Press (L) to Load Previous game, (N) for New game:
```
Press **L** or **l** to resume a previously saved game. Press **N** or **n** to start a new game.

## How to Play
- The game follows standard **Chess rules**.
- Moves should be entered in the format: `B2-B3` (from current position to new position).
- The board updates after each move.
- **Castling**, **Pawn Promotion**, and **Checkmate Detection** are supported.
- The game automatically **saves each move** so that progress is retained even after closing.

## Notes
- The game is **console-based**, meaning it runs entirely in the terminal.
- It provides an **interactive, structured, and visually appealing** interface.
- Designed for **two players**; no AI opponent is included.

## Contributor
- **SP24-BCS-142 - Abdullah Jan**


## License
This project is open-source. Feel free to modify and improve it!

