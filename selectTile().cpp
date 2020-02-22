const int MAXCHAR = 80;
const int MAXROW = 4;
const int MAXCOL = 4;
const int MAXELMNT = 16;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';

void selectTile(int board[MAXROW][MAXCOL]);


void selectTile(int board[MAXROW][MAXCOL]) {
    int usrRow = 0;
    int usrCol = 0;
    char checkVal = 'N';
    do
    {
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
    } while (checkVal != 'Y');
        
}
