//SP24-BCS-142      ABDULLAH JAN
//SP24-BCS-174      M.MUSTAFA

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


extern void fillBoard(char board[8][8]);
extern void displayBoard(char board[8][8]);
extern bool IsMoveLegal(char currentRow,char currentCol,char row,char col,char currentLocation[8][8]);
extern bool isPawnMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isRookMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isBishopMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isQueenMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isKnightMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isKingMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern void PawnPromotion(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isWhiteKingInCheck(char board[8][8]);
extern bool isBlackKingInCheck(char board[8][8]);
extern bool isCheckFromRook(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckFromBishop(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckFromKnight(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckFromPawn(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckFromKing(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckMate(char board[8][8]);
extern bool PieceAroundKingInCheck(char kingRow,char kingCol,char board[8][8]);

bool isRookMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8])
{
    //when testing for new location of rook, we will check weather given rook is uppercase(white)/lowercase(black)
    //and we will not allow same case alphabet to be on new location

    // or Q is used because same function is used for chekcing queen
    if(board[currentRow - 48][currentCol - 65] == 'R' || board[currentRow - 48][currentCol - 65] == 'Q') //show it's white's turn, 
    {
        //as it's white's turn, upper case alphabets already at recieving index, are not allowed
        // ie cannot move rook to square occupied by same player

        //instead of selecting pieces, we give range of all capital letters
        if(board[row - 48][col - 65] >= 'A' && board[row - 48][col - 65]<='Z' )
        {
            return 0;
        }
    }
    else
    {
        if(board[row - 48][col - 65] >= 'a' && board[row - 48][col - 65]<='z' )
        {
            return 0;
        }
    }

    //to check that the path of rook is empty, we use the loop
    if(currentRow == row) //we stay same in either col or row in each rook move
    { 
    for(int i=currentRow - 48 ; i <= (row - 48) ; i++)
    {
        //using terniary operator for selecting increment decrement and condition check coz 
        //for black and white's turn... different condition test and increments will be used
        int j=0;
        j=((currentCol<col)?(currentCol-64):(currentCol-66));
        for(; (currentCol<col)?(j<(col - 65)):(j>(col-65))  ; (currentCol<col)?j++:j-- ) //j++ for moving right,j-- for moving left
        {
            if(board[i][j] != ' ')
            {
                return 0;
            }

        }
    }
    }
    else if(currentCol == col)
    {
        for(int i=currentCol - 65 ; i <= (col - 65) ; i++)
        {
            int j=0;
            ((currentRow<row)?(j=currentRow-47):(j=currentRow-49));//we need to start loop from next index, in black turn, next index in -1 and in whites next index is +1
            for(; (currentRow<row)?(j<(row - 48)):(j>(row-48))  ; (currentRow<row)?j++:j-- ) //j++ for moving up,j-- for moving down
            {
                if(board[j][i] != ' ')
                {
                    return 0;
                }
            }
        } 
    }

    if((currentCol != col) && (currentRow != row))
    return 0; // rook only moves in line so one of the index must remain same
    
    return 1;
}
