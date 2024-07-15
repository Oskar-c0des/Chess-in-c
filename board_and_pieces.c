#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define BOARD_SIZE 8


//notes: for now don't care about making it clear which pieces are black or white otb, i'll change to using unicode characters after the logic works


typedef struct{
    char type;
    char colour;
} Board;

Board board[BOARD_SIZE][BOARD_SIZE];

void initBoard()
{
    board[0][0].type = board[0][7].type = board[7][0].type = board[7][7].type = 'R';
    board[0][1].type = board[0][6].type = board[7][1].type = board[7][6].type = 'N';
    board[0][2].type = board[0][5].type = board[7][2].type = board[7][5].type = 'B';
    board[0][3].type = board[7][3].type = 'Q';
    board[0][4].type = board[7][4].type = 'K';

    for(int i=0;i<BOARD_SIZE;i++)
    {
        board[1][i].type = board[6][i].type = 'P';
        board[0][i].colour = 'B';
        board[1][i].colour = 'B';
        board[6][i].colour = 'W';
        board[7][i].colour = 'W';
        for(int j=2;j<6;j++)
        {
            board[j][i].type = '.';
        }
    }
}

void printBoard()
{
    for(int i=0;i<BOARD_SIZE;i++)
    {
        printf("\n%d",8-i);
        for(int j=0;j<BOARD_SIZE;j++)
        {
            printf(" %c ", board[i][j].type);
        }
    }
    printf("\n ");
    for(int i=0;i<BOARD_SIZE;i++)
    {
        printf(" %d ", i + 1);
    }
    printf("\n");
}

//for generic valid conditions (board boundaries, is space empty)
bool isValidMove(int startX, int startY, int endX, int endY)
{
    char piece = board[startX][startY].type;
    if(startX < 0 || startX > BOARD_SIZE || startY < 0 || startY > BOARD_SIZE ||
        endX < 0 || endX > BOARD_SIZE || endY < 0 || endY > BOARD_SIZE){
        return false;
        }
        if(piece == 'P')
        {

        }
        return true;

}


void movePiece(int startX, int startY, int endX, int endY)
{
    //for an index position we must check: what piece it is, what moves it can make, what move it will make
    int x1 = startX-1, x2 = endX-1, y1 = 8-startY, y2 = 8-endY;
    if(isValidMove(x1,x2,y1,y2))
    {
        board[y2][x2].type = board[y1][x1].type;
        board[y1][x1].type = '.';
        printBoard();
    }
}

int main()
{
    int playerTurn = 1; //odd is white even is black
    initBoard();
    printBoard();
    char piece;
    int startX, startY, endX, endY;
    do
    {
        if(playerTurn %2 !=0 )
        {
            printf("\nplayer turn: %d", playerTurn);
            printf("White's turn\n");
            printf("Enter your move (startX startY endX endY)\n");
            scanf("%d %d %d %d",&startX, &startY, &endX, &endY);
            movePiece(startX, startY, endX, endY);
            playerTurn++;
        }
        else
        {
            printf("\nplayer turn: %d", playerTurn);
            printf("Black's turn\n");
            printf("Enter your move (startX startY endX endY)\n");
            scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
            movePiece(startX, startY, endX, endY);
            playerTurn++;
        }
    }while(isValidMove(startX, startY, endX, endY));
    return 0;
}



