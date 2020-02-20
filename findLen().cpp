const int MAXCHAR = 80;
const int MAXROW = 4;
const int MAXCOL = 4;
const int MAXELMNT = 15;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';

int findLen(char list[MAXELMNT]);
int findLen(int list[MAXELMNT]);


int findLen(char list[MAXELMNT]) {
    int index = 0;
    while (list[index] != 0) {
        index++;
    }
    return index;
}

int findLen(int list[MAXELMNT]) {
    int index = 0;
    while (list[index] != 0) {
        index++;
    }
    return index;
}
