#include <iostream>
using namespace std;

// function header
void menu();

// global variable
string playerName;
int playerLv = 0;
int playerExp = 0;
int playerCoin = 0;

void player() {
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
        case 1: cout << endl << "Coins: 0\nExperiences: 0"; break;
        case 2: cout << endl << "Power Up Developing"; break;
        case 3: menu(); break;
        }

    } while (number >= 1 && number <= 3);
}

void dungeon() {
    cout << "Dungeon Developing";
}

void menu() {
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
        case 1: player(); break;
        case 2: dungeon(); break;
        case 3: break;
        }

    } while (number >= 1 && number <= 2);

}

int main() {

    if (playerName == "") {
        
        cout << "Please enter your username: ";
        cin >> playerName;
        cout << endl;

        menu();
    }

    return 0;
}