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
