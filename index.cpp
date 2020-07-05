#include <iostream>
using namespace std;

// function header
void menu();
void player();
void powerup();
void levelup();
void dungeon();
void dungeonNormal();
void dungeonReward();
void weaponStore();

// global variable
const string RESET_COLOR = "\033[0m";
const string BRIGHT_GREEN = "\033[92m";
const string BRIGHT_YELLOW = "\033[93m";
const string BRIGHT_CYAN = "\033[96m";

// player variable
string playerName;
int playerLv = 0;
int playerExp = 0;

// weapon variable
int playerWeaponLevel = 0;
string playerWeaponType = "None";

// const weapon value
const int woodenswordAttackValue = 25;
const int goldenswordAttackValue = 50;


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
        cout << "1) View " << BRIGHT_GREEN << playerName << RESET_COLOR << " Information" << endl;
        cout << "2) Power Up" << endl;
        cout << "3) Level Up" << endl;
        cout << "4) Weapon Store" << endl;
        cout << "5) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1:
            cout << endl << playerName << "'s Profile" << endl;
            cout << "Experiences: " << playerExp << " (Level " << playerLv << ")" << endl;
            cout << "Weapon Type: " << playerWeaponType << " (Level " << playerWeaponLevel << ")" << endl;
            break;
        case 2: powerup(); break;
        case 3: levelup(); break;
        case 4: weaponStore(); break;
        case 5: menu(); break;
        }

    } while (number >= 1 && number <= 4);
}

void levelup() {
    int number = 0;

    do {

        cout << endl << endl;
        cout << "---Level Up Menu---" << endl;
        cout << "1) Player Level +1 (Cost 50EXP) " << endl;
        cout << "2) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1:
            if (playerExp >= 50) {
                playerExp -= 50;
                playerLv += 1;
                cout << "Level Up!" << endl;
            }
            else {
                cout << "You do not have enough experiences." << endl;
            }
            menu(); break;

        case 2: menu(); break;
        }

    } while (number >= 1 && number <= 2);
}

void powerup() {
    int number = 0;

    do {

        cout << endl << endl;
        cout << "---Power Up Menu---" << endl;
        cout << "1) Weapon Level +1 (Cost 50EXP) " << endl;
        cout << "2) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1:
            if (playerExp >= 50) {
                playerExp -= 50;
                playerWeaponLevel += 1;
                cout << "Level Up!" << endl;
            }
            else {
                cout << "You do not have enough experiences." << endl;
            }
            menu(); break;

        case 2: menu(); break;
        }

    } while (number >= 1 && number <= 2);
}
void weaponStore() {
    int number = 0;
    cout << endl;
    cout << "Dungeon Weapon Store" << endl;
    cout << "500EXP Golden Sword (-" << goldenswordAttackValue << " Monster MAX Health)" << endl;
    cout << "200EXP Wooden Sword (-" << woodenswordAttackValue << " Monster MAX Health)" << endl;
    cout << endl;
    cout << "1) Get a Golden Sword (Cost 500EXP)" << endl;
    cout << "2) Get a Wooden Sword (Cost 200EXP)" << endl;
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

    // weapon deduct monster health
    if (playerWeaponType == "Wooden Sword") {
        monsterHealth -= woodenswordAttackValue;
    }
    else if (playerWeaponType == "Golden Sword") {
        monsterHealth -= goldenswordAttackValue;
    }

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
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 50% left..." << RESET_COLOR << endl;
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

        cout << BRIGHT_CYAN << "Dungeon Game" << RESET_COLOR << endl;

        cout << "https://github.com/wukimwa/game" << endl;
        cout << endl;

        cout << BRIGHT_YELLOW << "Login" << RESET_COLOR << endl;
        cout << "Username: " << BRIGHT_GREEN;
        cin >> playerName;
        cout << RESET_COLOR << endl;
        menu();
    }

    return 0;
}