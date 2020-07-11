#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// function header
void menu();
void dungeon();
void showInfo();
void playerMenu();
void dungeonMenu();
void weaponStore();
void dungeonReward(int rewardEXP);


// global variable
const string RESET_COLOR = "\033[0m";
const string GREEN = "\033[32m";
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
int weaponATK = 0, weaponMHP = 0; // weapon variable

// weapon variable
int playerWeaponLevel = 0;
string playerWeaponType = "None";

// dungeon variable
string dungeonLevel;


void showInfo() {

    // update variable
    playerLv = (playerSpentExp * 0.2) / 50; // player level

    // player level rewards bonus
    if (playerLv >= 5 && playerLv < 10)
        bonusATK = 1;
    else if (playerLv >= 10 && playerLv < 15)
        bonusATK = 2;
    else if (playerLv >= 15 && playerLv < 20)
        bonusATK = 4;
    else if (playerLv >= 20)
        bonusATK = 6;

    // player level rewards bonus
    if (playerWeaponType == "Wooden Sword"){
        weaponATK = 3;
        if (playerWeaponLevel >= 5){
            weaponATK += 1;
        }
    }
    else if (playerWeaponType == "Silver Sword"){
        weaponATK = 5;
        if (playerWeaponLevel >= 8){
            weaponATK += 2;
        }
    }
    else if (playerWeaponType == "Golden Sword"){
        weaponATK = 8;
        weaponMHP = 1;
        if (playerWeaponLevel >= 12){
            weaponATK += 3;
            weaponMHP += 2;
        }
    }
    else if (playerWeaponType == "Mythic Sword"){
        weaponATK = 12;
        weaponMHP = 6;
    }


    cout << left << BRIGHT_GREEN << setw(11) << playerName << RESET_COLOR;
    cout << " Lv. " << BRIGHT_CYAN << setw(6) << playerLv << RESET_COLOR;
    cout << " EXP " << BRIGHT_YELLOW << setw(6) << playerExp << RESET_COLOR;
    cout << right; // default
    cout << endl << endl;
}

void menu() {
    int number = 0;

    showInfo();

    cout << GREEN << "Tips: Every EXP you have spent helps you to get level up." << RESET_COLOR << endl << endl;

    cout << "-----       Main Menu      -----" << endl;
    cout << "1) Player" << endl;
    cout << "2) Dungeon" << endl;
    cout << "3) Exit Game" << endl;
    
    cin >> number;
    switch (number) {
    case 1: system("clear"); playerMenu(); break;
    case 2: system("clear"); dungeonMenu(); break;
    case 3: system("clear"); break;
    default: system("clear"); menu();
    }

}

void playerMenu() {

    int number = 0;

    showInfo();

    cout << "-----      Player Menu     -----" << endl;
    cout << "1) Weapon Store" << endl;
    cout << "2) Level Up Rewards" << endl;
    cout << "3) Exit To Menu" << endl;

    cin >> number;
    switch (number) {
    case 1: system("clear"); weaponStore(); break;
    case 2:
        system("clear");
        showInfo();

        cout << BRIGHT_CYAN << "-----    Level Up Rewards   -----" << RESET_COLOR << endl << endl;
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
        cout << "Total Bonus Added: " << BRIGHT_YELLOW << bonusATK << RESET_COLOR << " ATK" << endl;
        cout << endl;

        cin.ignore();
        cout << BRIGHT_GREEN << "Press ENTER to continue..." << RESET_COLOR;
        cin.ignore();

        system("clear");
        playerMenu();

        break;
    case 3: system("clear"); menu(); break;
    default: system("clear"); playerMenu();
    }

}


void weaponStore() {
    int number = 0;

    showInfo();

    cout << "----- Dungeon Weapon Store -----" << endl;
    cout << "ATK: Player's Attack Value; MHP: Monster Max Health Deduction" << endl << endl;

    cout << BRIGHT_GREEN << "Price  " << BRIGHT_CYAN << "    Weapon Type " << BRIGHT_YELLOW << "    (Properties)" << RESET_COLOR;
    cout << endl;
    cout << "300 EXP    Wooden Sword   ";
    cout << " (  3 ATK )" << endl;
    cout << "                   Lv.5   ";
    cout << " ( +1 ATK )" << endl;
    cout << "                   Lv.8   ";
    cout << " ( Upgrade to Lv.1 Silver Sword )" << endl;
    cout << endl;

    cout << "650 EXP    Silver Sword   ";
    cout << " (  5 ATK )" << endl;
    cout << "                   Lv.8   ";
    cout << " ( +2 ATK )" << endl;
    cout << "                  Lv.12   ";
    cout << " ( Upgrade to Lv.1 Golden Sword )" << endl;
    cout << endl;

    cout << "N/A        Golden Sword   ";
    cout << " (  8 ATK;  1 MHP )" << endl;
    cout << "                  Lv.12   ";
    cout << " ( +3 ATK; +2 MHP )" << endl;
    cout << "                  Lv.20   ";
    cout << " ( Upgrade to Lv.1 Mythic Sword )" << endl;
    cout << endl;

    cout << "N/A        Mythic Sword   ";
    cout << " ( 12 ATK; 6 MHP )" << endl;
    cout << endl;

    // player weapon
    cout << endl;
    cout << BRIGHT_YELLOW;
    cout << "Current    " << setw(12) << playerWeaponType;
    cout << "    (Lv." << playerWeaponLevel << ")" << endl;
    cout << RESET_COLOR;

    cout << endl;

    cout << "1) Get a Wooden Sword" << endl;
    cout << "2) Get a Silver Sword" << endl;
    cout << "3) Weapon Power Up by Lv.1 (Cost 50 EXP)" << endl;
    cout << "4) Exit To Menu" << endl;

    cin >> number;
    switch (number) {

    case 1:
        system("clear");
        if (playerExp >= 300 && playerWeaponType == "None") {
            playerExp -= 300;
            playerSpentExp += 300;
            playerWeaponType = "Wooden Sword";
            cout << playerWeaponType << " purchased" << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences / You already got a weapon." << RESET_COLOR << endl << endl;
            weaponStore();
        }
        menu(); break;

    case 2:
        system("clear");
        if (playerExp >= 550 && playerWeaponType == "None") {
            playerExp -= 550;
            playerSpentExp += 550;
            playerWeaponType = "Silver Sword";
            cout << playerWeaponType << " purchased" << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
            weaponStore();
        }
        menu(); break;

    case 3:
        system("clear");
        if (playerExp >= 50 && playerWeaponType != "None") {
            playerExp -= 50;
            playerSpentExp += 50;
            playerWeaponLevel += 1;
            
            // weapon upgrade
            if(playerWeaponLevel < 8){
                cout << playerWeaponType << " Power Up by Lv.1!" << endl << endl;
            }
            else if(playerWeaponLevel >= 8 && playerWeaponType == "Wooden Sword"){
                cout << playerWeaponType << " upgraded to Lv.1 Silver Sword!" << endl << endl;
                playerWeaponLevel = 1;
                playerWeaponType = "Silver Sword";
            }
            else if(playerWeaponLevel >= 12 && playerWeaponType == "Silver Sword"){
                cout << playerWeaponType << " upgraded to Lv.1 Golden Sword!" << endl << endl;
                playerWeaponLevel = 1;
                playerWeaponType = "Golden Sword";
            }
            else if(playerWeaponLevel >= 20 && playerWeaponType == "Golden Sword"){
                cout << playerWeaponType << " upgraded to Lv.1 Mythic Sword!" << endl << endl;
                playerWeaponLevel = 1;
                playerWeaponType = "Mythic Sword";
            }

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

    case 4: system("clear"); menu(); break;
    default: system("clear"); weaponStore();
    }
}

void dungeonMenu() {
    int number = 0;
    playerLv = (playerExp + playerSpentExp) / 50;

    showInfo();

    cout << "-----     Dungeon Menu     -----" << endl;

    cout << "1) ENTER Dungeon  [ Easy ]" << endl;
    cout << "2) ENTER Dungeon  [Normal]" << endl;
    cout << "3) ENTER Dungeon  " << BRIGHT_CYAN << "[ Hard ] [Lv.05 Unlock]" << RESET_COLOR << endl;
    cout << "4) ENTER Dungeon  " << BRIGHT_YELLOW << "[Mythic] [Lv.15 Unlock]" << RESET_COLOR << endl;
    cout << "5) Exit To Menu" << endl;

    cin >> number;
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
    default: system("clear"); dungeonMenu();
    }

}

void dungeon() {

    // dungeon monster health
    int monsterHealth, monsterMaxHealth;

    if (dungeonLevel == "Easy")
        monsterMaxHealth = 5000;
    else if (dungeonLevel == "Normal")
        monsterMaxHealth = 20000;
    else if (dungeonLevel == "Hard")
        monsterMaxHealth = 50000;
    else if (dungeonLevel == "Mythic")
        monsterMaxHealth = 200000;

    monsterHealth = monsterMaxHealth;



    // player information
    int playerATK = 100; // initial attack value
    playerATK += bonusATK; // level up rewards deduct monster health
    playerATK += weaponATK; // weapon increase player's attack
    monsterHealth -= weaponMHP; // weapon deduct monster health


    int countATK = 0;
    bool startATK = true;

    do {

        if (startATK == true) {
            system("clear");
            startATK = false;
            cout << endl << endl << BRIGHT_GREEN << "Attacking the monster..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.8 * monsterMaxHealth)) {
            countATK = 0;
            system("clear");
            cout << endl << endl << BRIGHT_CYAN << "Monster Health - 80% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.6 * monsterMaxHealth)) {
            countATK = 0;
            system("clear");
            cout << endl << endl << BRIGHT_CYAN << "Monster Health - 60% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.4 * monsterMaxHealth)) {
            countATK = 0;
            system("clear");
            cout << endl << endl << BRIGHT_CYAN << "Monster Health - 40% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }
        else if (monsterHealth == (0.2 * monsterMaxHealth)) {
            countATK = 0;
            system("clear");
            cout << endl << endl << BRIGHT_CYAN << "Monster Health - 20% left..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }
        else if (countATK >= 10){
            countATK = 0;
            system("clear");
            cout << endl << endl << BRIGHT_GREEN << "Attacking the monster..." << RESET_COLOR << endl;
            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;
        }

        cin.ignore();

        countATK++;
        monsterHealth -= playerATK;

    } while (monsterHealth > 0);

    if (monsterHealth <= 0) {
        system("clear");
        dungeonReward(monsterMaxHealth / 500);
    }

}

void dungeonReward(int rewardEXP) {
    int number;

    cout << endl << BRIGHT_CYAN << "Dungeon Completed" << RESET_COLOR << endl;
    cout << endl << "Rewards: " << BRIGHT_YELLOW << rewardEXP << RESET_COLOR << " EXP" << endl << endl;
    playerExp += rewardEXP;

    cout << "1) Exit To Player Menu" << endl;
    cout << "2) Exit To Dungeon Menu" << endl;

    cin >> number;
    switch (number) {
    case 1: system("clear"); playerMenu(); break;
    case 2: system("clear"); dungeonMenu(); break;
    default: system("clear"); menu();
    }

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