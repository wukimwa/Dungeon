#include <iostream>
using namespace std;

void menu(string playerName);

void player(string playerName) {
    int number = 0;

    do {

        cout << endl << endl;
        cout << "---Player Menu---" << endl;
        cout << "1) View " << playerName << " Information" << endl;
        cout << "2) Power Up" << endl;
        cout << "3) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1: cout << "Coins: 0\nExperiences: 0"; break;
        case 2: cout << "Power Up Developing"; break;
        case 3: menu(playerName); break;
        }

    } while (number >= 1 && number <= 3);
}

void dungeon(string playerName) {
    cout << "Dungeon Developing";
}

void menu(string playerName) {
    int number = 0;

    do {

        cout << endl << endl;
        cout << "---Main Menu---" << endl;;
        cout << "1) Player" << endl;
        cout << "2) Dungeon" << endl;
        cout << "3) Exit Game" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1: player(playerName); break;
        case 2: dungeon(playerName); break;
        case 3: break;
        }

    } while (number >= 1 && number <= 2);

}

int main() {
    string playerName;

    if (playerName == "") {
        int playerLv = 0, playerCoin = 0, playerExp = 0;

        cout << "Please enter your username: ";
        cin >> playerName;
        cout << endl;

        menu(playerName);
    }
    
    return 0;
}