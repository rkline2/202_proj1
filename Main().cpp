// UMBC_Proj1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

void startGame();
void selectTile();
void swapTile();
void checkDirection();
void printBoard();


int main()
{
    startGame();
    return 0;
}

void startGame() {
    const int MAXCHAR = 80;
    const int MAXROW = 4;
    const int MAXCOL = 4;
    const int MAXELMNT = 15;
    int elmntCount = 0;
    int selectBoard = 2;
    char fileName[MAXCHAR] = {};
    int board[MAXROW][MAXCOL] = {{},{},{},{}};
    int boardRow = 0;
    int boardCol = 0;
    cout << "Welcome to the Fifteen Game" << endl;
    do {
        cout << "Would you like to load a board? \n"
        << "1. Yes \n" << "2. No \n";
        cin >> selectBoard; 
    } while (selectBoard != 1 && selectBoard != 2);
    if (selectBoard == 1) {
        cout << "What is the file name? " << endl;
        cin >> fileName;
        /*I would honestly put all of this into another function*/
        ifstream inputStream;
        inputStream.open(fileName);
        while (elmntCount <= MAXELMNT) {
            if (boardCol < MAXCOL && boardRow < MAXROW) {
                inputStream >> board[boardRow][boardCol];
                boardCol++;
            }
            else if (boardCol >= MAXCOL && boardRow < MAXROW) {
                boardRow++;
                boardCol = 0;
                inputStream >> board[boardRow][boardCol];
                boardCol++;
            }
            elmntCount++;
        }
        inputStream.close();
        /*This checks to make sure everythings a-okay*/
        for (int x = 0; x < MAXROW; x++) {
            for(int y = 0;  y < MAXCOL; y++)
            {
                cout << board[x][y] << endl;
            }
        }

    }
    else {
        /*Create a 2D-array of the default */
    
    }
    

}
