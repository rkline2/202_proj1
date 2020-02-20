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
void getBoard(char fileName[], int size, int board[MAXROW][MAXCOL]);


void startGame(int board[MAXROW][MAXCOL]) {
    int selectBoard = 2;
    char fileName[MAXCHAR] = {};
    int count = 0;

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
    int boardRow = 0;
    int boardCol = 0;

    ifstream inputStream;
    inputStream.open(fileName);
    while (elmntCount <= size) {
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
}
