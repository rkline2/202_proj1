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
const int MAXELMNT = 16;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';


char checkWinner(int board[MAXROW][MAXCOL]);
void makeRand(int board[MAXROW][MAXCOL]);
bool isValid(int board[MAXROW][MAXCOL], int rand, int maxRow, int maxCol);
void printBoard(int board[MAXROW][MAXCOL]);
void test(int board[MAXROW][MAXCOL]);
void delay(int amnt);

void makeRand(int board[MAXROW][MAXCOL]) {
    srand(time(NULL));
    for (int row = 0; row < MAXROW; row++) {
        for (int col = 0; col < MAXCOL; col++) {
            int testNum = rand() % (15 + 1);
            bool areYouVal = isValid(board, testNum, row, col);
            while (areYouVal == false) {
                testNum = rand() % (15 + 1);
                areYouVal = isValid(board, testNum, row, col);
            }
            board[row][col] = testNum;
        }
    }
}

void delay(int amnt) {
    for (int i = 0; i < amnt; i++) {
        for (int y = 0; y < amnt; y++) {
            {}
        }
    }
}

bool isValid(int board[MAXROW][MAXCOL], int rand, int maxRow, int maxCol) {
    bool goodNum = true;
    for (int row = 0; row <= maxRow; row++) {
        if (row < maxRow) {
            for (int col = 0; col < MAXCOL; col++) {
                if (board[row][col] == rand) {
                    goodNum = false;
                }
            }
        }
        else {
            for (int col = 0; col < maxCol; col++) {
                if (board[row][col] == rand) {
                    goodNum = false;
                }
            }
        }
    }
    return goodNum;
}

void printBoard(int board[MAXROW][MAXCOL]) {
    for (int r = 0; r < MAXROW; r++) {
        for (int c = 0; c < MAXCOL; c++) {
            cout << board[r][c] << " ";
        }
    }
    cout << endl;
}

void test(int board[MAXROW][MAXCOL]) {
    srand(time(NULL));
    board[0][0] = rand() % (15 + 1);
}

int main()
{
    int board[MAXROW][MAXCOL] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,0,15} };
    int testNum = 0;

    cout << "How many tests do you want to run? ";
    cin >> testNum;
    
    while (testNum > 0) {
        delay(20000);
        makeRand(board);        
        char test = checkWinner(board);
        cout << "Board: ";
        printBoard(board);
        cout << "Results: " << test << endl;
    
        testNum -= 1;
    }
    
    return 0;
}

char checkWinner(int board[MAXROW][MAXCOL]) {
    char isWinner = 'W';
    for (int row = 0; row < MAXROW; row++) {
        for (int col = 0; col < MAXCOL; col++) {
            if (col + 1 < MAXCOL && row != MAXROW - 1) {
                int testValue = board[row][col+1];
                if ((testValue - board[row][col]) != 1) {
                    isWinner = 'L';
                }
            }
            else if (col == MAXCOL - 1 && row != MAXROW -1 ) {
                int testValue = board[row + 1][0];
                if ((testValue - board[row][col]) != 1) {
                    isWinner = 'L';
                }
            }
            else if ((col == MAXCOL - 1 && row == MAXROW - 1) && (board[row][col] != 0)) {
                isWinner = 'L';
            }            
        }
    }
    return isWinner;
}
