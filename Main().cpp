// UMBC_Proj1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
const int MAXELMNT = 15;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';


void startGame(int board[MAXROW][MAXCOL]);
void selectTile(int board[MAXROW][MAXCOL]);
void swapTile(int board[MAXROW][MAXCOL]);
bool checkDirection(int board[MAXROW][MAXCOL]);
void printBoard(int board[MAXROW][MAXCOL]);
void getBoard(char fileName[], int size, int board[MAXROW][MAXCOL]);
char checkWinner(int board[MAXROW][MAXCOL]);
void playGame(int board[MAXROW][MAXCOL]);
char playAgain();

int main()
{
    
    int board[MAXROW][MAXCOL] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,0,15} };
    do {
        playGame(board);
    } while (playAgain() == YES);
    char boom = playAgain();
    cout << boom << endl;

    return 0;
}


void playGame(int board[MAXROW][MAXCOL]) {
    startGame(board);
    printBoard(board);
    char isWinner = checkWinner(board);
    while (isWinner == LOSER) {
        selectTile(board);
        if (checkDirection(board)) {
            swapTile(board);
        }
        else {
            cout << "Incorrect value" << endl;
        }
        printBoard(board);
    }
    cout << "Winner!" << endl;
}


void startGame(int board[MAXROW][MAXCOL]) {
    int selectBoard = 2;
    char fileName[MAXCHAR] = {};
  
    cout << "Welcome to the Fifteen Game" << endl;
    do {
        cout << "Would you like to load a board? \n"
            << "1. Yes \n" << "2. No \n";
        cin >> selectBoard;
    } while (selectBoard != 1 && selectBoard != 2);
    if (selectBoard == 1) {
        cout << "What is the file name? " << endl;
        cin >> fileName;
        getBoard(fileName, MAXELMNT, board);
    }
    /*This checks to make sure everything's a-okay.
      Delete this for-loop when you upload the project*/

    for (int x = 0; x < MAXROW; x++) {
        for (int y = 0; y < MAXCOL; y++)
        {
            cout << board[x][y] << endl;
        }
    }
}


void getBoard(char fileName[], int size, int board[MAXROW][MAXCOL]) {
    int elmntCount = 0;
    int selectBoard = 2;
    int newBoard[MAXROW][MAXCOL] = { {},{},{},{} };
    int boardRow = 0;
    int boardCol = 0;
    int* boardPtr;

    ifstream inputStream;
    inputStream.open(fileName);
    while (elmntCount <= size) {
        if (boardCol < MAXCOL && boardRow < MAXROW) {
            inputStream >> board[boardRow][boardCol];
            boardPtr = &board[boardRow][boardCol];
            boardCol++;
        }
        else if (boardCol >= MAXCOL && boardRow < MAXROW) {
            boardRow++;
            boardCol = 0;
            inputStream >> board[boardRow][boardCol];
            boardPtr = &board[boardRow][boardCol];
            boardCol++;
        }
        elmntCount++;
    }
    inputStream.close();
}
