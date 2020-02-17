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
