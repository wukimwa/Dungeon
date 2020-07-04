#include <iostream>
using namespace std;

// function header
void menu();
void player();
void dungeon();
void dungeonNormal();
void dungeonReward();

// global variable
string playerName;
int playerLv = 0;
int playerExp = 0;
int playerCoin = 0;



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
        case 1: cout << endl << "Coins: " << playerCoin << endl << "Experiences: " << playerExp << endl; break;
        case 2: cout << endl << "Power Up Developing"; break;
        case 3: menu(); break;
        }

    } while (number >= 1 && number <= 3);
}

void dungeon() {
    int number = 0;

    do {

        cout << endl << endl;
        cout << "---Dungeon Menu---" << endl;
        cout << "1) Go into the dungeon" << endl;
        cout << "2) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1: dungeonNormal(); break;
        case 2: menu(); break;
        }

    } while (number >= 1 && number <= 3);
}

void dungeonNormal() {
    int number = 0;
    int attack;
    cout << "Press enter to attack the monster." << endl;

    do {
        cout << "Attacking...";
        cin.ignore();
        number++;
    } while (number < 250);

    if (number >= 250) {
        dungeonReward();
    }

}

void dungeonReward() {
    cout << endl << "Dungeon Completed" << endl;
    cout << endl << "Rewards: Coins x" << 100 << " Experiences x" << 50;
    playerCoin += 100;
    playerExp += 50;
    menu();
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