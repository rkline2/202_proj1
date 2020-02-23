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
const char SPACE = ' ';
const char H_BAR = '|';
const char B_BAR = '_';
const char BAR = '-';
const char PERIOD = '.';
const int TENDIGIT = 10;
const char SPACE = ' ';
const char H_BAR = '|';
const char B_BAR = '_';
const char BAR = '-';
const char PERIOD = '.';


void printBoard(int board[MAXROW][MAXCOL]);
int findLen(int testNum);
void addSpaces(int maxspace);
void createBar(int barLim, char symbol);
void createBar(int barLim, char symbol, int numSpaces);



void addSpaces(int maxspace) {
    for (int space = 1; space < maxspace; space++) {
        cout << SPACE;
    }
}

void createBar(int barLim, char symbol) {
    for (int bar = 1; bar <= barLim; bar++) {
        if (bar == barLim) {
            cout << symbol << endl;

        }
        else if (bar == 1) {
            cout << '\t' << symbol;
        }
        else {
            cout << symbol;
        }
    }
}

void createBar(int barLim, char symbol, int numSpaces) {
    cout << endl;
    addSpaces(MAXROW + 4);
    cout << H_BAR;
    for (int bar = 1; bar <= barLim; bar++) {
        if (bar == barLim) {
            cout << H_BAR << endl;

        }
        else if (bar % 5 == 0) {
            cout << H_BAR;
        }
        else if (bar == 1) {
            addSpaces(numSpaces);
            cout << symbol;
        }
        else {
            cout << symbol;
        }
    }
}



void printBoard(int board[MAXROW][MAXCOL]) {
    int underBarLim = (MAXCOL * 3 + MAXCOL * 2);
    int twoDig = 1;
    int numSpace = 2;
    for (int i = 1; i <= MAXCOL; i++) {
        if (i == 1) {
            cout << '\t' << SPACE << i << PERIOD;
        }
        else if (i < MAXCOL && i > 1) {
            // add spaces here
            addSpaces(MAXCOL);
            cout << i << PERIOD;
        }
        else if (i == MAXCOL) {
            addSpaces(MAXCOL);
            cout << i << PERIOD << endl;
        }
    }

    createBar(underBarLim, B_BAR);

    for (int row = 0; row < MAXROW; row++) {
        addSpaces(MAXROW + 2);
        cout << row + 1 << PERIOD<< H_BAR;
        for (int col = 0; col < MAXCOL; col++) {
            int checkLen = findLen(board[row][col]);
            if (checkLen == 1) {
                // changes here
                addSpaces(numSpace + 1);
                cout << board[row][col] << SPACE<< H_BAR;
            }
            else {
                addSpaces(numSpace);
                cout << board[row][col]  << SPACE << H_BAR;
            }
        }
        
        createBar(underBarLim, BAR, 0);
        
    }
}

int findLen(int testNum) {
    int numdigit = 0;
    if (testNum == 0) {
        numdigit = 1;
    }
    while (testNum > 0) {
        testNum /= TENDIGIT;
        ++numdigit;
    }

    return numdigit;
}
