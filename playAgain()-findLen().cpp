const int MAXCHAR = 80;
const int MAXROW = 4;
const int MAXCOL = 4;
const int MAXELMNT = 15;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';
const int DIGIT = 10;

int findLen(char list[MAXELMNT]);
char playAgain();

char playAgain() {
    char ans[MAXELMNT] = { WRONGVAL };
    while (ans[0] == WRONGVAL) {
        cout << "Play again? (y/n): ";
        cin >> ans;
        int valLen = findLen(ans);
        if (valLen == 1) {
            switch (ans[0]) {
            case 'y':
            case 'Y':
                cout << "Loading a new game..." << endl;
                ans[0] = 'y';
                break;
            case 'n':
            case 'N':
                cout << "Thank you for playing the game of fifteen!" << endl;
                ans[0] = 'n';
                break;

            default:
                cout << "Incorrect responce please try again" << endl;
                ans[0] = WRONGVAL;
                break;
            }
        }
        else {
            cout << "Incorrect responce please try again" << endl;
            ans[0] = WRONGVAL;
        }

    }
    return ans[0];
}

int findLen(char list[MAXELMNT]) {
    int index = 0;
    while (list[index] != 0) {
        index++;
    }
    return index;
}

