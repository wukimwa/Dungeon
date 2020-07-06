#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// function header
void menu();
void player();
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
        cout << "-----Main Menu-----" << endl;
        cout << BRIGHT_YELLOW << setw(15) << playerExp << RESET_COLOR << " EXP" << endl << endl;

        cout << "1) Player" << endl;
        cout << "2) Dungeon" << endl;
        cout << "3) Exit Game" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1: system("cls"); player(); break;
        case 2: system("cls"); dungeon(); break;
        case 3: system("cls"); break;
        }

    } while (number >= 1 && number <= 3);

}

void player() {
    int number = 0;

    do {

        cout << endl << endl;
        cout << "-----Player Menu-----" << endl;
        cout << BRIGHT_YELLOW << setw(17) << playerExp << RESET_COLOR << " EXP" << endl << endl;

        cout << "1) View " << BRIGHT_GREEN << playerName << RESET_COLOR << " Information" << endl;
        cout << "2) Level Up" << endl;
        cout << "3) Weapon Store" << endl;
        cout << "4) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1:
            system("cls");
            cout << endl << endl;
            cout << " Player Lv.: " << playerLv << endl;
            cout << "Experiences: " << playerExp << " EXP" << endl;
            cout << "Weapon Type: " << playerWeaponType << " (Level " << playerWeaponLevel << ")" << endl;
            break;
        case 2: system("cls"); levelup(); break;
        case 3: system("cls"); weaponStore(); break;
        case 4: system("cls"); menu(); break;
        }

    } while (number >= 1 && number <= 4);
}

void levelup() {
    int number = 0;

    do {

        cout << endl << endl;
        cout << "-----Level Up Menu-----" << endl;
        cout << "1) Player Level +1 (Cost 50EXP) " << endl;
        cout << "2) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1:
            system("cls");
            if (playerExp >= 50) {
                playerExp -= 50;
                playerLv += 1;
                cout << "Level Up!" << endl;
            }
            else {
                cout << "You do not have enough experiences." << endl;
            }
            menu(); break;

        case 2: system("cls"); menu(); break;
        }

    } while (number >= 1 && number <= 2);
}


void weaponStore() {
    int number = 0;
    cout << endl;
    cout << "-----Dungeon Weapon Store-----" << endl;
    cout << BRIGHT_YELLOW << setw(26) << playerExp << RESET_COLOR << " EXP" << endl << endl;

    cout << "Wooden Sword";
    cout << " (-" << woodenswordAttackValue << " Monster MAX Health)" << endl;
    cout << "Golden Sword";
    cout << " (-" << goldenswordAttackValue << " Monster MAX Health)" << endl;

    cout << endl << endl;

    cout << "1) (Cost  50EXP) Weapon Power Up" << endl;
    cout << "2) (Cost 200EXP) Get a Wooden Sword" << endl;
    cout << "3) (Cost 500EXP) Get a Golden Sword" << endl;
    cout << "4) Exit To Menu" << endl;
    cin >> number;

    switch (number) {
    case 1:
        system("cls");
        if (playerExp >= 50 && playerWeaponType != "None") {
            playerExp -= 50;
            playerWeaponLevel += 1;
            cout << "Power Up!" << endl;
        }
        else if (playerWeaponType == "None") {
            cout << "You do not have any weapon." << endl;
        }
        else {
            cout << "You do not have enough experiences." << endl;
        }
        menu(); break;

    case 2:
        system("cls");
        if (playerExp >= 200) {
            playerExp -= 200;
            playerWeaponType = "Wooden Sword";
            cout << playerWeaponType << " purchased" << endl;
        }
        else {
            cout << "You do not have enough experiences." << endl;
        }
        menu(); break;

    case 3:
        system("cls");
        if (playerExp >= 500) {
            playerExp -= 500;
            playerWeaponType = "Golden Sword";
            cout << playerWeaponType << " purchased" << endl;
        }
        else {
            cout << "You do not have enough experiences." << endl;
        }
        menu(); break;

    case 4: system("cls"); menu(); break;
    }
}

void dungeon() {
    int number = 0;

    do {
        
        cout << endl << endl;
        cout << "-----Dungeon Menu-----" << endl;
        cout << "1) ENTER Normal Dungeon" << endl;
        cout << "2) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1: system("cls"); dungeonNormal(); break;
        case 2: system("cls"); menu(); break;
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



    do {

        if (monsterHealth == monsterMaxHealth) {
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 100% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Press ENTER to attack the monster." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.75 * monsterMaxHealth)) {
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 75% left..." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.5 * monsterMaxHealth)) {
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 50% left..." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.25 * monsterMaxHealth)) {
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 25% left..." << RESET_COLOR << endl;
        }

        cin.ignore();

        monsterHealth--;
    } while (monsterHealth > 0);

    if (monsterHealth <= 0) {
        system("cls");
        dungeonReward();
    }

}

void dungeonReward() {
    cout << endl << BRIGHT_YELLOW << "Dungeon Completed" << RESET_COLOR << endl;
    cout << endl << "Rewards: " << 50 << "EXP" << endl << endl;
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
        system("cls");
        menu();
    }

    return 0;
}