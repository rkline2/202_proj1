

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;


const int MAXCHAR = 80;
const int MAXROW = 4;
const int MAXCOL = 4;
const int MAXELMNT = 16;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';
const int TWOVAL = 2;
const char TR_EDGE = '}';
const char TL_EDGE = '{';
const char BL_EDGE = '(';
const char BR_EDGE = ')';
const char T_SIDE = '^';
const char B_SIDE = '_';
const char L_SIDE = '[';
const char R_SIDE = ']';
const char CENTER = '-';
const int ZEROMKR = 0;

void startGame(int board[MAXROW][MAXCOL]);
void selectTile(int board[MAXROW][MAXCOL]);
void swapTile(int board[MAXROW][MAXCOL]);
bool checkDirection(int board[MAXROW][MAXCOL]);
void printBoard(int board[MAXROW][MAXCOL]);
void getBoard(char fileName[], int size, int board[MAXROW][MAXCOL]);
char checkWinner(int board[MAXROW][MAXCOL]);
void playGame(int board[MAXROW][MAXCOL]);
int findLen(char list[MAXELMNT]);
char playAgain();
char findLocation(int usrRow, int usrCol);

int main()
{
    
    int board[MAXROW][MAXCOL] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,0,15} };
    char anotherGame = YES;
    while (anotherGame == YES) {
        playGame(board);
        anotherGame = playAgain();
    }
    return 0;
}
