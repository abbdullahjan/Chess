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


bool isCheckMate(char board[8][8])
{
    //we can check chekmate if king is in check and all position around king are either filled or also in check
    //we could have checked this by using the function isblackkingincheck or iswhitekingincheck but those functions also include
    //to look out for location for king, so cannot use the function
    //creating a new function which checks for the given position, either it is in check or not
    //we will call that function for every position aroud the king.

    //first checking location of king...

    int kingRow,kingCol;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[i][j] == 'K' || board[i][j] == 'k')
            {
                kingRow = i;
                kingCol = j;
            }
        }
    } 
    int aboveKing;
    int belowKing;
    int rightToKing;
    int leftToKing;
    int righttopToKing;
    int rightbottomToKing;
    int lefttopToKing;
    int leftbottomToKing;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[kingRow][kingCol] == 'K')
            {
                if(board[i][j] >= 'A' && board[i][j] <= 'Z') 
                {
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (IsMoveLegal(i + '0', j + 'A', x + '0', y + 'A', board)) {
                            char temp = board[x][y];
                            board[x][y] = board[i][j];
                            board[i][j] = ' ';
                            
                            bool stillInCheck = isWhiteKingInCheck(board) ;
                            
                            board[i][j] = board[x][y];
                            board[x][y] = temp;
                            
                            if (!stillInCheck) {
                                return 0;
                            }
                        }
                    }
                }
            }
            } 

            if(board[kingRow][kingCol] == 'k')
            {
                if(board[i][j] >= 'a' && board[i][j] <= 'z') 
                {
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (IsMoveLegal(i + '0', j + 'A', x + '0', y + 'A', board)) {
                            char temp = board[x][y];
                            board[x][y] = board[i][j];
                            board[i][j] = ' ';
                            
                            bool stillInCheck = isBlackKingInCheck(board) ;
                            
                            board[i][j] = board[x][y];
                            board[x][y] = temp;
                            
                            if (!stillInCheck) {
                                return 0;
                            }
                        }
                    }
                }
            }
            }
        }
    }

    if((board[kingRow + 1][kingCol] == ' ' ) && (kingRow+1) < 8 )
    {
        board[kingRow + 1][kingCol] = board[kingRow][kingCol] ; //we need to look if every piece around king is in check, if we dont remove K piece from way of looking for check, returning value might be incorrect
        board[kingRow][kingCol] = ' ';//function call for looking out for check needs the piece to be k or K, for which we are checking the check, so we assigned k/K to piece and we will reassign at end
        aboveKing = PieceAroundKingInCheck(kingRow+1, kingCol,board);
        board[kingRow][kingCol] = board[kingRow + 1][kingCol] ;
        board[kingRow + 1][kingCol] = ' ';
    }
    else
    {
        aboveKing = 1; //1 means either place is occupied or is in check, In this case the block is occupied
    }

    if((board[kingRow - 1][kingCol] == ' ' ) && (kingRow-1) >= 0 )
    {
        board[kingRow - 1][kingCol] = board[kingRow][kingCol] ; //we need to look if every piece around king is in check, if we dont remove K piece from way of looking for check, returning value might be incorrect
        board[kingRow][kingCol] = ' ';//function call for looking out for check needs the piece to be k or K, for which we are checking the check, so we assigned k/K to piece and we will reassign at end
        belowKing = PieceAroundKingInCheck(kingRow-1, kingCol,board);
        board[kingRow][kingCol] = board[kingRow - 1][kingCol] ;
        board[kingRow - 1][kingCol] = ' ';
    }
    else
    {
        belowKing = 1; //1 means either place is occupied or is in check, In this case the block is occupied
    }

    if((board[kingRow][kingCol  +1  ] == ' ' ) && (kingCol+1) < 8 )
    {
        board[kingRow ][kingCol +1 ] = board[kingRow][kingCol] ; //we need to look if every piece around king is in check, if we dont remove K piece from way of looking for check, returning value might be incorrect
        board[kingRow][kingCol] = ' ';//function call for looking out for check needs the piece to be k or K, for which we are checking the check, so we assigned k/K to piece and we will reassign at end
        rightToKing = PieceAroundKingInCheck(kingRow, kingCol +1 ,board);
        board[kingRow][kingCol] = board[kingRow ][kingCol +1 ] ;
        board[kingRow][kingCol +1 ] = ' ';
    }
    else
    {
        rightToKing = 1; //1 means either place is occupied or is in check, In this case the block is occupied
    }

    if((board[kingRow][kingCol  - 1  ] == ' ' ) && (kingCol-1) >= 0 )
    {
        board[kingRow ][kingCol - 1 ] = board[kingRow][kingCol] ; //we need to look if every piece around king is in check, if we dont remove K piece from way of looking for check, returning value might be incorrect
        board[kingRow][kingCol] = ' ';//function call for looking out for check needs the piece to be k or K, for which we are checking the check, so we assigned k/K to piece and we will reassign at end
        leftToKing = PieceAroundKingInCheck(kingRow, kingCol - 1 ,board);
        board[kingRow][kingCol] = board[kingRow ][kingCol - 1 ] ;
        board[kingRow][kingCol - 1 ] = ' ';
    }
    else
    {
        leftToKing = 1; //1 means either place is occupied or is in check, In this case the block is occupied
    }

    if((board[kingRow +1 ][kingCol  +1  ] == ' ' ) && (kingCol+1) < 8 && (kingRow+1) < 8 )
    {
        board[kingRow +1  ][kingCol +1 ] = board[kingRow][kingCol] ; //we need to look if every piece around king is in check, if we dont remove K piece from way of looking for check, returning value might be incorrect
        board[kingRow][kingCol] = ' ';//function call for looking out for check needs the piece to be k or K, for which we are checking the check, so we assigned k/K to piece and we will reassign at end
        righttopToKing = PieceAroundKingInCheck(kingRow +1 , kingCol +1 ,board);
        board[kingRow][kingCol] = board[kingRow +1  ][kingCol +1 ] ;
        board[kingRow +1 ][kingCol +1 ] = ' ';
    }
    else
    {
        righttopToKing = 1; //1 means either place is occupied or is in check, In this case the block is occupied
    }    

    if((board[kingRow -1 ][kingCol  +1  ] == ' ' ) && (kingCol+1) < 8  && (kingRow-1) >= 0 )
    {
        board[kingRow -1  ][kingCol +1 ] = board[kingRow][kingCol] ; //we need to look if every piece around king is in check, if we dont remove K piece from way of looking for check, returning value might be incorrect
        board[kingRow][kingCol] = ' ';//function call for looking out for check needs the piece to be k or K, for which we are checking the check, so we assigned k/K to piece and we will reassign at end
        rightbottomToKing = PieceAroundKingInCheck(kingRow -1 , kingCol +1 ,board);
        board[kingRow][kingCol] = board[kingRow -1  ][kingCol +1 ] ;
        board[kingRow -1 ][kingCol +1 ] = ' ';
    }
    else
    {
        rightbottomToKing = 1; //1 means either place is occupied or is in check, In this case the block is occupied
    } 

    if((board[kingRow + 1][kingCol  - 1  ] == ' ' ) && (kingRow+1) < 8  && (kingCol-1) >= 0 )
    {
        board[kingRow + 1 ][kingCol - 1 ] = board[kingRow][kingCol] ; //we need to look if every piece around king is in check, if we dont remove K piece from way of looking for check, returning value might be incorrect
        board[kingRow][kingCol] = ' ';//function call for looking out for check needs the piece to be k or K, for which we are checking the check, so we assigned k/K to piece and we will reassign at end
        lefttopToKing = PieceAroundKingInCheck(kingRow + 1, kingCol - 1 ,board);
        board[kingRow][kingCol] = board[kingRow + 1 ][kingCol - 1 ] ;
        board[kingRow + 1][kingCol - 1 ] = ' ';
    }
    else
    {
        lefttopToKing = 1; //1 means either place is occupied or is in check, In this case the block is occupied
    }    

    if((board[kingRow - 1][kingCol  - 1  ] == ' ' )  && (kingRow-1) >= 0  && (kingCol-1) >= 0  )
    {
        board[kingRow - 1 ][kingCol - 1 ] = board[kingRow][kingCol] ; //we need to look if every piece around king is in check, if we dont remove K piece from way of looking for check, returning value might be incorrect
        board[kingRow][kingCol] = ' ';//function call for looking out for check needs the piece to be k or K, for which we are checking the check, so we assigned k/K to piece and we will reassign at end
        belowKing = PieceAroundKingInCheck(kingRow - 1, kingCol - 1 ,board);
        board[kingRow][kingCol] = board[kingRow - 1 ][kingCol - 1 ] ;
        board[kingRow - 1][kingCol - 1 ] = ' ';
    }
    else
    {
        leftbottomToKing = 1; //1 means either place is occupied or is in check, In this case the block is occupied
    }    


    if( aboveKing == 1 && belowKing == 1 && rightToKing == 1 && leftToKing == 1 && righttopToKing == 1 && rightbottomToKing == 1 && lefttopToKing == 1 && leftbottomToKing)
    {
        return 1;
    }

    return 0;
         


}
