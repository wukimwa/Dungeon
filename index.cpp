#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// function header
void menu();
void player();
void showInfo();
void dungeon();
void dungeonMenu();
void dungeonReward(int rewardEXP);
void weaponStore();

// global variable
const string RESET_COLOR = "\033[0m";
const string BRIGHT_RED = "\033[91m";
const string BRIGHT_GREEN = "\033[92m";
const string BRIGHT_YELLOW = "\033[93m";
const string BRIGHT_CYAN = "\033[96m";

// player variable
string playerName;
int playerExp = 0;
int playerSpentExp = 0;

int playerLv;

int bonusATK = 0; // level up rewards variable

// weapon variable
int playerWeaponLevel = 0;
string playerWeaponType = "None";

// dungeon variable
string dungeonLevel;

// const weapon value
const int woodenswordAttackValue = 25;
const int silverswordAttackValue = 45;
const int goldenswordAttackValue = 65;


void showInfo() {
    cout << left << BRIGHT_GREEN << setw(11) << playerName << RESET_COLOR;
    cout << " Lv. " << BRIGHT_CYAN << setw(6) << playerLv << RESET_COLOR;
    cout << " EXP " << BRIGHT_YELLOW << setw(6) << playerExp << RESET_COLOR;
    cout << right; // default
}

void menu() {
    int number = 0;
    playerLv = (playerExp + playerSpentExp) / 50;

    if (playerLv >= 5)
        bonusATK = 1;
    else if (playerLv >= 10)
        bonusATK = 2;
    else if (playerLv >= 15)
        bonusATK = 4;
    else if (playerLv >= 20)
        bonusATK = 6;

    showInfo();

    do {
        cout << endl << endl;
        cout << "-----       Main Menu      -----" << endl;
        cout << "1) Player" << endl;
        cout << "2) Dungeon" << endl;
        cout << "3) Exit Game" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1: system("clear"); player(); break;
        case 2: system("clear"); dungeonMenu(); break;
        case 3: system("clear"); break;
        default:
            system("clear");
            menu();
        }

    } while (number >= 1 && number <= 3);

}

void player() {
    int number = 0;
    playerLv = (playerExp + playerSpentExp) / 50;

    showInfo();

    do {

        cout << endl << endl;
        cout << "-----      Player Menu     -----" << endl;
        cout << "1) View " << BRIGHT_GREEN << playerName << RESET_COLOR << " Information" << endl;
        cout << "2) Weapon Store" << endl;
        cout << "3) Level Up Rewards" << endl;
        cout << "4) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1:
            system("clear");
            cout << endl << endl;


            cout << endl;
            cin.ignore();
            cout << BRIGHT_GREEN << "Press ENTER to continue..." << RESET_COLOR;
            cin.ignore();

            system("clear");
            break;
        case 2: system("clear"); weaponStore(); break;
        case 3:
            system("clear");
            cout << BRIGHT_CYAN << "Level Up Rewards" << RESET_COLOR << endl << endl;
            cout << "Level      Rewards" << endl;


            (playerLv >= 5) ? cout << BRIGHT_YELLOW : cout;
            cout << "Lv. 05" << "     " << "+1 ATK value" << endl;
            (playerLv < 10) ? cout << RESET_COLOR : cout;

            cout << "Lv. 10" << "     " << "+1 ATK value" << endl;
            (playerLv < 15) ? cout << RESET_COLOR : cout;

            cout << "Lv. 15" << "     " << "+2 ATK value" << endl;
            (playerLv < 20) ? cout << RESET_COLOR : cout;

            cout << "Lv. 20" << "     " << "+2 ATK value" << endl;
            cout << RESET_COLOR;


            cout << endl;
            cout << "Total Bonus Added: " << " ATK";
            break;
        case 4: system("clear"); menu(); break;
        }

    } while (number >= 1 && number <= 4);
}


void weaponStore() {
    int number = 0;
    playerLv = (playerExp + playerSpentExp) / 50;

    showInfo();

    cout << endl << endl;
    cout << "----- Dungeon Weapon Store -----" << endl;

    cout << BRIGHT_CYAN << "Price  " << BRIGHT_YELLOW << "  Weapon Type" << RESET_COLOR;
    cout << endl;
    cout << "300 EXP    Wooden Sword   ";
    cout << " (-" << woodenswordAttackValue << " Monster MAX HP)" << endl;
    cout << "550 EXP    Silver Sword   ";
    cout << " (-" << silverswordAttackValue << " Monster MAX HP)" << endl;
    cout << "800 EXP    Golden Sword   ";
    cout << " (-" << goldenswordAttackValue << " Monster MAX HP)" << endl;
    cout << "Current    " << BRIGHT_YELLOW << setw(12) << playerWeaponType << RESET_COLOR << endl;

    cout << endl << endl;

    cout << "1) Weapon Power Up (Cost 50EXP)" << endl;
    cout << "2) Get a Wooden Sword" << endl;
    cout << "3) Get a Silver Sword" << endl;
    cout << "4) Get a Golden Sword" << endl;
    cout << "5) Exit To Menu" << endl;
    cin >> number;

    switch (number) {
    case 1:
        system("clear");
        if (playerExp >= 50 && playerWeaponType != "None") {
            playerExp -= 50;
            playerWeaponLevel += 1;
            cout << "Power Up!" << endl << endl;
        }
        else if (playerWeaponType == "None") {
            cout << BRIGHT_RED << "You do not have any weapon." << RESET_COLOR << endl << endl;
            weaponStore();
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
            weaponStore();
        }
        menu(); break;

    case 2:
        system("clear");
        if (playerExp >= 300) {
            playerExp -= 300;
            playerWeaponType = "Wooden Sword";
            cout << playerWeaponType << " purchased" << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
            weaponStore();
        }
        menu(); break;

    case 3:
        system("clear");
        if (playerExp >= 550) {
            playerExp -= 550;
            playerWeaponType = "Silver Sword";
            cout << playerWeaponType << " purchased" << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
            weaponStore();
        }
        menu(); break;

    case 4:
        system("clear");
        if (playerExp >= 800) {
            playerExp -= 800;
            playerWeaponType = "Golden Sword";
            cout << playerWeaponType << " purchased" << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
            weaponStore();
        }
        menu(); break;

    case 5: system("clear"); menu(); break;
    }
}

void dungeonMenu() {
    int number = 0;
    playerLv = (playerExp + playerSpentExp) / 50;

    showInfo();

    do {

        cout << endl << endl;
        cout << "-----     Dungeon Menu     -----" << endl;

        cout << "1) ENTER Dungeon  [ Easy ]" << endl;
        cout << "2) ENTER Dungeon  [Normal]" << endl;
        cout << "3) ENTER Dungeon  " << BRIGHT_CYAN << "[ Hard ] [Lv.05 Unlock]" << RESET_COLOR << endl;
        cout << "4) ENTER Dungeon  " << BRIGHT_YELLOW << "[Mythic] [Lv.15 Unlock]" << RESET_COLOR << endl;
        cout << "5) Exit To Menu" << endl;
        cin >> number;
        cout << endl;

        switch (number) {
        case 1: system("clear"); dungeonLevel = "Easy"; dungeon(); break;
        case 2: system("clear"); dungeonLevel = "Normal"; dungeon(); break;
        case 3:
            system("clear");
            if (playerLv >= 5) {
                dungeonLevel = "Hard";
                dungeon();
            }
            else {
                cout << BRIGHT_RED << "The dungeon is now locked." << RESET_COLOR << endl << endl;
                dungeonMenu();
            }
            break;
        case 4:
            system("clear");
            if (playerLv >= 15) {
                dungeonLevel = "Mythic";
                dungeon();
            }
            else {
                cout << BRIGHT_RED << "The dungeon is now locked." << RESET_COLOR << endl << endl;
                dungeonMenu();
            }
            break;
        case 5: system("clear"); menu(); break;
        }

    } while (number >= 1 && number <= 3);
}

void dungeon() {

    // dungeon monster health

    int monsterHealth, monsterMaxHealth;

    if (dungeonLevel == "Easy") {
        monsterMaxHealth = 50;
    }
    else if (dungeonLevel == "Normal") {
        monsterMaxHealth = 200;
    }
    else if (dungeonLevel == "Hard") {
        monsterMaxHealth = 500;
    }
    else if (dungeonLevel == "Mythic") {
        monsterMaxHealth = 2000;
    }
    monsterHealth = monsterMaxHealth;

    // weapon deduct monster health
    if (playerWeaponType == "Wooden Sword") {
        monsterHealth -= woodenswordAttackValue;
    }
    else if (playerWeaponType == "Silver Sword") {
        monsterHealth -= goldenswordAttackValue;
    }
    else if (playerWeaponType == "Golden Sword") {
        monsterHealth -= goldenswordAttackValue;
    }

    // level up rewards deduct monster health
    monsterHealth -= bonusATK;


    do {

        if (monsterHealth == monsterMaxHealth) {
            system("clear");
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 100% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Press ENTER to attack the monster." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.8 * monsterMaxHealth)) {
            system("clear");
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 80% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.6 * monsterMaxHealth)) {
            system("clear");
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 60% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.4 * monsterMaxHealth)) {
            system("clear");
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 40% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.2 * monsterMaxHealth)) {
            system("clear");
            cout << endl << endl << BRIGHT_YELLOW << "Monster Health - 20% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }

        cin.ignore();

        monsterHealth--;
    } while (monsterHealth > 0);

    if (monsterHealth <= 0) {
        system("clear");
        dungeonReward(monsterMaxHealth / 5);
    }

}

void dungeonReward(int rewardEXP) {
    cout << endl << BRIGHT_YELLOW << "Dungeon Completed" << RESET_COLOR << endl;
    cout << endl << "Rewards: " << rewardEXP << "EXP" << endl << endl;
    playerExp += rewardEXP;
    menu();
}

int main() {

    if (playerName == "") {

        cout << endl;
        cout << BRIGHT_CYAN << "         Dungeon Game" << RESET_COLOR << endl;

        cout << "https://github.com/wukimwa/game" << endl;
        cout << endl << endl << endl << endl << endl;

        cout << BRIGHT_YELLOW << "Login" << RESET_COLOR << endl;
        cout << "Username: " << BRIGHT_GREEN;
        cin >> playerName;
        cout << RESET_COLOR << endl;

        system("clear");

        menu();
    }

    return 0;
}