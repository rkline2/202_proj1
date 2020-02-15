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
    char var = ' ';
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
            cout << var << endl;
        }
        inputStream.close();

    }
    else {
    
    }
    

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
