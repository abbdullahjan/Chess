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

bool isBishopMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8])
{
    //difference between row of current index to next index is always equal to col difference
    // for a bishop move
    //using absolute function for positive values only coz bishop can move in any direction
    //having multiple scenarios where negative values may be returned
    int rowDiffer = abs(row - currentRow);
    int colDiffer = abs(col - currentCol);
    if(rowDiffer != colDiffer)
    {
        return 0;
    }

    //when testing for new location of bishop, we will check weather given bishop is uppercase(white)/lowercase(black)
    //and we will not allow same case alphabet to be on new location

    // or Q is used because same function is used for chekcing queen
    if(board[currentRow - 48][currentCol - 65] == 'B' || board[currentRow - 48][currentCol - 65] == 'Q' ) //show it's white's turn, 
    {
        //as it's white's turn, upper case alphabets already at recieving index, are not allowed
        // ie cannot move bishop to square occupied by same player

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

    for(int i=1;i<rowDiffer;i++) //checking that the way to next place is empty
    {
        //there are 4 different combinations where row and col increase or decrease
    //1
        if((currentRow < row) && (currentCol < col))
        {
            if(board[(currentRow - 48) + i][(currentCol - 65) + i] != ' ')
            {
                
                return 0;
            } 
        }
        else if((currentRow > row) && (currentCol > col)) //2...both current one's are greater than new
        {
            if(board[(currentRow - 48) - i][(currentCol - 65) - i] != ' ')
            {
                return 0;
            } 
        }
        //3, if both currentrows and curcol and not less&greater than next, than one must be less
        else if((currentRow < row))
        {
            if(board[(currentRow - 48) + i][(currentCol - 65) - i] != ' ')
            {
                return 0;
            } 
        }
        else if((currentCol < col))
        {
            if(board[(currentRow - 48) - i][(currentCol - 65) + i] != ' ')
            {
                return 0;
            } 
        }
    }

    return 1;
}
