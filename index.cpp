#include <iostream>
using namespace std;

// function header
void menu();
void player();
void dungeon();
void dungeonNormal();
void dungeonReward();
void weaponStore();

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

    } while (number >= 1 && number <= 3);

}

void player() {
    int number = 0;

    do {

        cout << endl << endl;
        cout << "---Player Menu---" << endl;
        cout << "1) View " << playerName << " Information" << endl;
        cout << "2) Power Up" << endl;
        cout << "3) Weapon Store" << endl;
        cout << "4) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1:
            cout << endl << playerName << "'s Profile" << endl;
            cout << "Experiences: " << playerExp << " (Level " << playerLv << ")" << endl;
            cout << "Weapon Type: " << playerWeaponType << " (Level " << playerWeaponLevel << ")" << endl;
            break;
        case 2: cout << endl << "Power Up Developing"; break;
        case 3: weaponStore(); break;
        case 4: menu(); break;
        }

    } while (number >= 1 && number <= 4);
}

void weaponStore() {
    int number = 0;
    cout << "Dungeon Weapon Store" << endl;
    cout << "500EXP Golden Sword (-5 Monster MAX Health)" << endl;
    cout << "200EXP Wooden Sword (-2 Monster MAX Health)" << endl;
    cout << endl;
    cout << "1) Get a golden sword (500 Experiences)" << endl;
    cout << "2) Get a wooden sword (200 Experiences)" << endl;
    cout << "3) Exit To Menu" << endl;
    cin >> number;

    switch (number) {
    case 1:
        if (playerExp >= 500) {
            playerExp -= 500;
            playerWeaponType = "Golden Sword";
            cout << playerWeaponType << " purchased" << endl;
        }
        else {
            cout << "You do not have enough experiences." << endl;
        }
        menu(); break;

    case 2:    
        if (playerExp >= 200) {
            playerExp -= 200;
            playerWeaponType = "Wooden Sword";
            cout << playerWeaponType << " purchased" << endl;
        }
        else {
            cout << "You do not have enough experiences." << endl;
        }
        menu(); break;

    case 3: menu(); break;
    }
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

    int attack;
    int attacking = 0;

    int monsterMaxHealth = 200; // dungeon monster health
    int monsterHealth = monsterMaxHealth;
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

        if (monsterHealth == (0.5 * monsterMaxHealth)) {
            cout << endl << endl << "Monster Health - 50% left..." << endl;
        }
        
        cin.ignore();
        monsterHealth--;
    } while (monsterHealth > 0);

    if (monsterHealth <= 0) {
        dungeonReward();
    }

}

void dungeonReward() {
    cout << endl << "Dungeon Completed" << endl;
    cout << endl << "Rewards: " << 50 << "EXP";
    playerExp += 50;
    menu();
}

int main() {

    if (playerName == "") {
        cout << endl << "Dungeon Game" << endl;
        cout << "https://github.com/wukimwa/game" << endl << endl;
        cout << "Please enter a username: ";
        cin >> playerName;
        cout << endl;
        menu();
    }

    return 0;
}