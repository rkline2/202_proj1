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
    int selectBoard = 2;
    char fileName[80] = {};
    char var[80] = {};
    cout << "Welcome to the Fifteen Game" << endl;
    do {
        cout << "Would you like to load a board? \n"
        << "1. Yes \n" << "2. No \n";
        cin >> selectBoard; 
    } while (selectBoard != 1 && selectBoard != 2);
    if (selectBoard == 1) {
        cout << "What is the file name? " << endl;
        cin >> fileName;
        ifstream inputStream;
        inputStream.open(fileName);
        while (inputStream >> var) {
            /*Create a 2D-array of the file. You 
            can probably just do this with pointers 
            instaed of L1 = L2 bs*/
            cout << var << endl;
        }
        inputStream.close();

    }
    else {
        /*Create a 2D-array of the default */
    
    }
    

}
