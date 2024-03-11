#include <iostream>
#include<cstdlib> // Included this library to get the random number
#include <cmath> // Included this library to get the square root and power
#include <cctype>
using namespace std;
int subtract_coins(int coins_left, int coins_removed){ // The function I used to subtract coins removed by player from total coins
        return coins_left - coins_removed;
}
int random_coins(){ // The function I used to get the random number if used chose to do this
        srand(time(NULL));
        return 10 + rand() % (1000 - 10+ 1);
}
int main() {
    int coins_left;
    int coins_removed;
    int total_coins;
    int check1;
    int check2;
    int check;
    int check3;
    while (true) { //Main loop of the whole game until user chooses to exit the game
            cout << "Welcome to the 'Subtract a Square' game" << endl;
            while (true) {
                cout << "How do you like the number of coins be determined?" << endl;
                cout << "A) Submit the number of coins" << endl;
                cout << "B) Choose a random number" << endl;
                char choice1;
                cin >> choice1;
                choice1 = toupper(choice1);
                if (choice1 == 'A') {
                    cout << "How many?";
                    if (!(cin >> total_coins)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid, Please enter a number" << endl;
                    } else {
                        coins_left = total_coins;
                        break;
                    }
                } else if (choice1 == 'B') {
                    coins_left = random_coins();
                    break;
                } else {
                    cout << "Invalid choice" << endl;
                    break;
                }
            }
        while (coins_left > 0) {
            while (coins_left > 0) {
                cout << "Coins left = " << coins_left << endl;
                cout << "Player 1 choose the number of coins you want to subtract: ";
                cin >> coins_removed;
                if (coins_removed < 0) { //This is to validate that the number entered is positive
                    cout << "Invalid number of coins" << endl;
                } else if (coins_removed != 0) { //This is to validate that the number entered is a non-zero number
                    if (coins_left >= coins_removed) {
                        // This is the part I used to validate that the number entered is a square number
                        check1 = (sqrt(coins_removed)) / 1;
                        check2 = pow(check1, 2);
                        if (coins_removed == check2) {
                            coins_left = subtract_coins(coins_left, coins_removed);
                            if (coins_left == 0) {
                                cout << "Player 1 wins" << endl;
                            } else {
                                break;
                            }
                        }
                        else {
                            cout << "Invalid number of coins" << endl;
                        }
                    }
                }
                else {
                cout << "Invalid number of coins" << endl;
                }
            }
            while (coins_left > 0) {
                cout << "Coins left = " << coins_left << endl;
                cout << "Player 2 choose the number of coins you want to subtract: ";
                cin >> coins_removed;
                if (coins_removed < 0) {
                    cout << "Invalid number of coins" << endl;
                }
                else if (coins_removed != 0) {
                    if (coins_left >= coins_removed) {
                        check = (sqrt(coins_removed)) / 1;
                        check3 = pow(check, 2);
                        if (coins_removed == check3) {
                            coins_left = subtract_coins(coins_left, coins_removed);
                            if (coins_left == 0) {
                                cout << "Player 2 wins" << endl;
                            } else {
                                break;
                            }
                        }
                        else {
                            cout << "Invalid number of coins" << endl;
                        }
                    }
                }
                else {
                    cout << "Invalid number of coins" << endl;
                }
            }
        }
        //Last menu shown to user to know if he wants to continue playing or to exit the game
        while (true) {
            cout << "Do you like To continue playing?" << endl;
            cout << "A) Yes" << endl;
            cout << "B) No" << endl;
            char choice2;
            cin >> choice2;
            choice2 = toupper(choice2);
            if (choice2 == 'A') {
                break;
            } else if (choice2 == 'B') {
                cout << "Thanks for playing, See you next time.";
                exit(0);
            } else {
                cout << "Invalid" << endl;
            }
        }
    }
}
