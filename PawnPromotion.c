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



void PawnPromotion(char currentRow,char currentCol,char row,char col,char board[8][8])
{
    if(board[row - 48][col-65] == 'P')
    {
        label1:
        printf("\nPawn Promotion, Press (Q,R,N,B): \n");
        scanf(" %c",&board[row - 48][col-65]);
        //convert lowerCase to Upper Case
        if(board[row - 48][col-65] >= 'a' && board[row - 48][col-65] <='z')
        {
            board[row - 48][col-65] -= 32;
        }
        if((board[row - 48][col-65] != 'Q') && (board[row - 48][col-65] != 'R') && (board[row - 48][col-65] != 'N') && (board[row - 48][col-65] != 'B')  )
        {
            printf("Invalid Promotion\n");
            goto label1;
        }
    }
    else if(board[row - 48][col-65] == 'p')
    {
        label2:
        printf("\nPawn Promotion, Press (Q,R,N,B): \n");
        scanf(" %c",&board[row - 48][col-65]);
        //convert lowerCase to Upper Case
        if(board[row - 48][col-65] >= 'A' && board[row - 48][col-65] <='Z')
        {
            board[row - 48][col-65] += 32;
        }
        if((board[row - 48][col-65] != 'q') && (board[row - 48][col-65] != 'r') && (board[row - 48][col-65] != 'n') && (board[row - 48][col-65] != 'b')  )
        {
            printf("Invalid Promotion\n");
            goto label2;
        }
    }
}
