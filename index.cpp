#include <iostream>
using namespace std;

// function header
void menu();
void player();
void dungeon();
void dungeonNormal();
void dungeonReward();

// global variable
// player variable
string playerName;
int playerLv = 0;
int playerExp = 0;

// weapon variable
int playerWeaponLevel = 0;
string playerWeaponType = "None";

// const weapon value
const int woodenswordAttackValue = 250;
const int goldenswordAttackValue = 500;


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
        case 1:
            cout << endl << playerName << "'s Profile" << endl;
            cout << "Experiences: " << playerExp << " (Level " << playerLv << ")" << endl;
            cout << "Weapon Type: " << playerWeaponType << " (Level " << playerWeaponLevel << ")" << endl;
            break;
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
    int attacking = 0;
    cout << "Press enter to attack the monster." << endl;

    do {
        if (attacking == 0) {
            cout << "Attacking.";
            attacking++;
        }
        else if (attacking == 1) {
            cout << "Attacking..";
            attacking++;
        }
        else {
            cout << "Attacking...";
            attacking = 0;
        }
        
        cin.ignore();
        number++;
    } while (number < 50);

    if (number >= 50) {
        dungeonReward();
    }

}

void dungeonReward() {
    cout << endl << "Dungeon Completed" << endl;
    cout << endl << "Rewards: Exp x" << 50;
    playerExp += 50;
    menu();
}

int main() {

    if (playerName == "") {
        
        cout << endl << "Please enter a username: ";
        cin >> playerName;
        cout << endl;
        menu();
    }

    return 0;
}