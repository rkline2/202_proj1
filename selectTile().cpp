const int MAXCHAR = 80;
const int MAXROW = 4;
const int MAXCOL = 4;
const int MAXELMNT = 16;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';
const int TWOVAL = 2;
const char TR_EDGE = '}';
const char TL_EDGE = '{';
const char BL_EDGE = '(';
const char BR_EDGE = ')';
const char T_SIDE = '^';
const char B_SIDE = '_';
const char L_SIDE = '[';
const char R_SIDE = ']';
const char CENTER = '-';
const int ZEROMKR = 0;


void selectTile(int board[MAXROW][MAXCOL]);
bool checkDirection(int board[MAXROW][MAXCOL], int usrRow, int usrCol);
char findLocation(int usrRow, int usrCol);
void swapTile(int board[MAXROW][MAXCOL], int usrRow, int usrCol);

int main()
{
    int board[MAXROW][MAXCOL] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,0,15} };
    int count = 0;
    cout << "How many times do you want to run this? ";
    cin >> count;
    while (count > 0) {
        selectTile(board);
        count--;
    }
    return 0;
}

void swapTile(int board[MAXROW][MAXCOL], int usrRow, int usrCol) {
    for (int row = 0; row < MAXROW; row++) {
        for (int col = 0; col < MAXCOL; col++) {
            if (board[row][col] == 0) {
                board[row][col] = board[usrRow][usrCol];
                board[usrRow][usrCol] = ZEROMKR;
            }

        }
    }
}



void selectTile(int board[MAXROW][MAXCOL]) {
    int usrRow = 0;
    int usrCol = 0;
    char checkVal = 'N';
    bool isValidCoord = true;
    do
    {
        // print board
        cout << "What is the row (left) and column (top) to slide?" << endl;
        cin >> usrRow;
        cin >> usrCol;
        cout << "Are you sure you want to enter these values? ('Y' or 'N'): ";
        cin >> checkVal;
        cout << endl;
        switch (checkVal)
        {
        case 'y':
        case 'Y':
            checkVal = 'Y';
            break;
        case 'n':
        case 'N':
            cout << "Okay" << endl;
            checkVal = 'N';
            break;
        default:
            cout << "Invald input" << endl;
            cin.clear();
            checkVal = 'N';
            break;
        }
        if (checkVal == 'Y') {
            usrRow--;
            usrCol--;
            isValidCoord = checkDirection(board, usrRow, usrCol);
            if (isValidCoord == false) {
                cout << "Coordinates are not valid" << endl;
            }
        }
    } while (checkVal != 'Y' || isValidCoord == false);
    cout << "You're Good!" << endl;

    // Swap the tiles
    swapTile(board, usrRow, usrCol);
}

bool checkDirection(int board[MAXROW][MAXCOL], int usrRow, int usrCol) {
    char location = findLocation(usrRow, usrCol);
    bool isValid = false;
    switch (location)
    {
    case WRONGVAL:
        break;
    case TR_EDGE:
        cout << "Top Right Corner" << endl;
        if ((board[usrRow + 1][usrCol] == ZEROMKR) || (board[usrRow][usrCol - 1] == ZEROMKR)) {
            isValid = true;
        }
        break; 
    case TL_EDGE:
        if ((board[usrRow + 1][usrCol] == ZEROMKR) || (board[usrRow][usrCol + 1] == ZEROMKR)) {
            isValid = true;
        }
        cout << "Top Left Corner" << endl;
        break;
    case BR_EDGE:
        if ((board[usrRow - 1][usrCol] == ZEROMKR) || (board[usrRow][usrCol - 1] == ZEROMKR)) {
            isValid = true;
        }
        cout << "Bottom Right Corner" << endl;
        break;
    case BL_EDGE:
        if ((board[usrRow + 1][usrCol] == ZEROMKR) || (board[usrRow][usrCol + 1] == ZEROMKR)) {
            isValid = true;
        }
        cout << "Bottom Left Corner" << endl;
        break;
    case T_SIDE:
        if ((board[usrRow][usrCol + 1] == ZEROMKR) || (board[usrRow + 1][usrCol] == ZEROMKR)
            ||(board[usrRow][usrCol - 1] == ZEROMKR)) {
            isValid = true;
        }
        cout << "Top Side" << endl;
        break;
    case B_SIDE:
        if ((board[usrRow][usrCol - 1] == ZEROMKR) || (board[usrRow - 1][usrCol] == ZEROMKR)
            || (board[usrRow][usrCol + 1] == ZEROMKR)) {
            isValid = true;
        }
        cout << "Bottom Side" << endl;
        break;
    case R_SIDE:
        if ((board[usrRow + 1][usrCol] == ZEROMKR) || (board[usrRow][usrCol - 1] == ZEROMKR)
            || (board[usrRow - 1][usrCol] == ZEROMKR)) {
            isValid = true;
        }
        cout << "Right Side" << endl;
        break;
    case L_SIDE:
        if ((board[usrRow - 1][usrCol] == ZEROMKR) || (board[usrRow][usrCol + 1] == ZEROMKR)
            || (board[usrRow + 1][usrCol] == ZEROMKR)) {
            isValid = true;
        }
        cout << "Left Side" << endl;
        break;
    default:
        if ((board[usrRow - 1][usrCol] == ZEROMKR) || (board[usrRow][usrCol + 1] == ZEROMKR)
            || (board[usrRow + 1][usrCol] == ZEROMKR) || (board[usrRow][usrCol - 1] == ZEROMKR)) {
            isValid = true;
        }
        cout << "Center" << endl; 
        break;
    }
    return isValid;
}


char findLocation(int usrRow, int usrCol) {
    char findSide = CENTER;
    
    if ((usrRow < 0 || usrRow >= MAXROW) || (usrCol < 0 || usrCol >= MAXCOL)) {
        findSide = WRONGVAL; 
    }
    // top left corner
    else if (usrRow == 0 && usrCol == 0) {
        findSide = TL_EDGE;
    }

    // top right corner
    else if (usrRow == 0 && usrCol == MAXCOL - 1) {
        findSide = TR_EDGE;
    }

    // bottom left corner
    else if (usrRow == MAXROW - 1 && usrCol == 0) {
        findSide = BL_EDGE;
    }

    // bottom right corner
    else if (usrRow == MAXROW - 1 && usrCol == MAXCOL - 1) {
        findSide = BR_EDGE;
    }

    // top edge
    else if (usrRow == 0) {
        findSide = T_SIDE;
    }

    // bottom edge
    else if (usrRow == MAXROW - 1) {
        findSide = B_SIDE;
    }

    // right edge
    else if (usrCol == MAXCOL - 1){
        findSide = R_SIDE;
    }

    // left edge
    else if (usrCol == 0) {
        findSide = L_SIDE;
    }
    return findSide; 
}
