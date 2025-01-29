//SP24-BCS-142      ABDULLAH JAN
//SP24-BCS-174      M.MUSTAFA

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


extern void fillBoard(char board[8][8]);

extern void fillBoard(char board[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            board[i][j] = ' ';
        }
    }

    board[7][0]=board[7][7]='r'; //black rook r
    board[0][0]=board[0][7]='R'; //white rook R

    //knight is denoted by n and N coz K is for king
    board[7][1]=board[7][6]='n'; 
    board[0][1]=board[0][6]='N';

    //bishop is denoted by b and B
    board[7][2]=board[7][5]='b'; 
    board[0][2]=board[0][5]='B';  

    board[7][3]='q';
    board[0][3]='Q';

    board[7][4]='k';
    board[0][4]='K';

    //initialize second row of black to p
    for(int i=0;i<8;i++)
    {
        board[6][i] = 'p';
    }
    
    //initialize second row of black to P
    for(int i=0;i<8;i++)
    {
        board[1][i] = 'P';
    }
}
