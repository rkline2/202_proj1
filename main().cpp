

const int MAXCHAR = 80;
const int MAXROW = 4;
const int MAXCOL = 4;
const int MAXELMNT = 15;
const char WINNER = 'W';
const char LOSER = 'L';
const char YES = 'y';
const char NO = 'n';
const char WRONGVAL = '!';

int main()
{
    
    int board[MAXROW][MAXCOL] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,0,15} };
    char anotherGame = YES;
    while (anotherGame == YES) {
        playGame(board);
        anotherGame = playAgain();
    }
    return 0;
}
