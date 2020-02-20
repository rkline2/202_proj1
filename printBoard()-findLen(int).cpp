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


void printBoard(int board[MAXROW][MAXCOL]);
int findLen(int testNum);


void printBoard(int board[MAXROW][MAXCOL]){
    for (int i = 1; i <= 4; i++) {
        if (i == 1) {
            cout << "\t" <<"\t" << i << "." << "\t";
        }
        else if (i < MAXCOL && i > 1) {
            cout << "\t" << i << "." << "\t";
        }
        else if (i == MAXCOL) {
            cout << "\t" << i << "." << "\t" << endl;
        }
    }
    for (int row = 0; row < MAXROW; row++) {
        int col = 0;
        cout << "\t" << row + 1 << ".";
        for (int col = 0; col < MAXCOL; col++) {
            int checkLen = findLen(board[row][col]);
            if (checkLen == 1) {
                cout << "\t" << " " << board[row][col] << "|\t";
            }
            else {
                cout << "\t" << board[row][col] << "|\t";
            }
        }
        cout << endl;
    }
}

int findLen(int testNum) {
    int numdigit = 0;
    if (testNum == 0) {
        numdigit = 1;
    }
    while (testNum > 0){
        testNum /= TENDIGIT;
        ++numdigit;
    }
   
    return numdigit;
}
