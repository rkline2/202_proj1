const int MAXCHAR = 80;
const int MAXROW = 4;
const int MAXCOL = 4;
const int MAXELMNT = 15;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';
const int TENDIGIT = 10;

void startGame(int board[MAXROW][MAXCOL]);
void selectTile(int board[MAXROW][MAXCOL]);
void swapTile(int board[MAXROW][MAXCOL]);
bool checkDirection(int board[MAXROW][MAXCOL]);
void printBoard(int board[MAXROW][MAXCOL]);
char checkWinner(int board[MAXROW][MAXCOL]);
void playGame(int board[MAXROW][MAXCOL]);

void playGame(int board[MAXROW][MAXCOL]) {
    startGame(board);
    printBoard(board);
    char isWinner = checkWinner(board);
    while (isWinner == LOSER) {
        if (isWinner == LOSER){
        cout << "Board is not complete" << endl;
        }
        printBoard(board);
        selectTile(board);
    }
    cout << "Winner!" << endl;
}
