#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

// function header
void menu();
void save();
void dungeon();
void showInfo();
void playerMenu();
void dungeonMenu();
void weaponStore();
void dungeonReward(int rewardEXP);


// global variable
const string RESET_COLOR = "\033[0m";
const string BRIGHT_RED = "\033[91m";
const string BRIGHT_GREEN = "\033[92m";
const string BRIGHT_YELLOW = "\033[93m";
const string BRIGHT_CYAN = "\033[96m";

// player variable
string playerName;
int playerLv = 0;
int playerExp = 0;
int playerSpentExp = 0;

int bonusATK = 0; // level up rewards variable
int weaponATK = 0, weaponMMP = 0, weaponMHP = 0; // weapon variable

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

    // player weapon bonus
    if (playerWeaponType == "WoodenSword"){
        weaponATK = 3;
        if (playerWeaponLevel >= 5){
            weaponATK += 1;
        }
    }
    else if (playerWeaponType == "SilverSword"){
        weaponATK = 5;
        if (playerWeaponLevel >= 8){
            weaponATK += 2;
        }
    }
    else if (playerWeaponType == "StarSword"){
        weaponATK = 1;
        weaponMMP = 1;
        if (playerWeaponLevel >= 15){
            weaponATK += 2;
            weaponMMP += 1;
        }
        else if (playerWeaponLevel >= 25){
            weaponATK += 3;
            weaponMMP += 1;
        }
    }
    else if (playerWeaponType == "GoldenSword"){
        weaponATK = 8;
        weaponMHP = 10;
        if (playerWeaponLevel >= 12){
            weaponATK += 3;
            weaponMHP += 20;
        }
    }
    else if (playerWeaponType == "MythicSword"){
        weaponATK = 12;
        weaponMHP = 60;
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

    cout << "-----       Main Menu      -----" << endl;
    cout << "1) Player" << endl;
    cout << "2) Dungeon" << endl;
    cout << "3) Save Game" << endl;
    
    cin >> number;
    switch (number) {
    case 1: system("clear"); playerMenu(); break;
    case 2: system("clear"); dungeonMenu(); break;
    case 3: system("clear"); save(); break;
    default: system("clear"); menu();
    }

}

void save(){
    cout << endl;
    cout << "The following data will be saved: " << endl;
    cout << BRIGHT_YELLOW << "Player Name\nPlayer EXP\nPlayer Level\nPlayer Weapon Type\nPlayer Weapon Level" << RESET_COLOR << endl;
    cout << endl;
    cout << endl;
    string data = "/" + playerName + "-" + to_string(playerExp) + "-" + to_string(playerSpentExp) + "-" + playerWeaponType + "-" + to_string(playerWeaponLevel) + "/";
    cout << "Please use the following key for next login: " << endl;
    cout << BRIGHT_CYAN << data << RESET_COLOR;
    cout << endl << endl << endl << endl;

    cin.ignore();
    cout << BRIGHT_GREEN << "Press ENTER to continue..." << RESET_COLOR;
    cin.ignore();

    system("clear"); 
    menu();
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

    cout << BRIGHT_GREEN << "Price  " << BRIGHT_CYAN << "    Weapon Type " << BRIGHT_YELLOW << "   (Properties)" << RESET_COLOR;
    cout << endl << endl;

    // WoodenSword
    (playerWeaponType == "WoodenSword") ? cout << BRIGHT_YELLOW : cout;
    cout << "300 EXP    WoodenSword   ";
    cout << " (  3 ATK )" << endl;

    (playerWeaponLevel < 5) ? cout << RESET_COLOR : cout;
    cout << "                  Lv.5   ";
    cout << " ( +1 ATK )" << endl;

    (playerWeaponLevel < 8) ? cout << RESET_COLOR : cout;
    cout << "                  Lv.8   ";
    cout << " ( Upgrade to Lv.1 SilverSword )" << endl;
    cout << RESET_COLOR << endl;


    // SilverSword
    (playerWeaponType == "SilverSword") ? cout << BRIGHT_YELLOW : cout;
    cout << "650 EXP    SilverSword   ";
    cout << " (  5 ATK )" << endl;

    (playerWeaponLevel < 8) ? cout << RESET_COLOR : cout;
    cout << "                  Lv.8   ";
    cout << " ( +2 ATK )" << endl;

    (playerWeaponLevel < 12) ? cout << RESET_COLOR : cout;
    cout << "                 Lv.12   ";
    cout << " ( Upgrade to Lv.1 GoldenSword )" << endl;
    cout << RESET_COLOR << endl;


    // StarSword
    (playerWeaponType == "StarSword") ? cout << BRIGHT_YELLOW : cout;
    cout << "850 EXP      StarSword   ";
    cout << " (  1 ATK;  1 MMP )" << endl;

    (playerWeaponLevel < 15) ? cout << RESET_COLOR : cout;
    cout << "                 Lv.15   ";
    cout << " ( +2 ATK; +1 MMP )" << endl;

    (playerWeaponLevel < 25) ? cout << RESET_COLOR : cout;
    cout << "                 Lv.25   ";
    cout << " ( +3 ATK; +1 MMP )" << endl;
    cout << RESET_COLOR << endl;


    // GoldenSword
    (playerWeaponType == "GoldenSword") ? cout << BRIGHT_YELLOW : cout;
    cout << "N/A        GoldenSword   ";
    cout << " (  8 ATK;  10 MHP )" << endl;

    (playerWeaponLevel < 12) ? cout << RESET_COLOR : cout;
    cout << "                 Lv.12   ";
    cout << " ( +3 ATK; +20 MHP )" << endl;

    (playerWeaponLevel < 20) ? cout << RESET_COLOR : cout;
    cout << "                 Lv.20   ";
    cout << " ( Upgrade to Lv.1 MythicSword )" << endl;
    cout << RESET_COLOR << endl;


    // MythicSword
    (playerWeaponType == "MythicSword") ? cout << BRIGHT_YELLOW : cout;
    cout << "N/A        MythicSword   ";
    cout << " ( 12 ATK; 60 MHP )" << endl;
    cout << RESET_COLOR << endl;


    // player weapon
    cout << BRIGHT_GREEN;
    cout << "50 EXP    " << setw(12) << playerWeaponType;
    cout << "    (Power Up from Lv." << playerWeaponLevel << " to Lv." << (playerWeaponLevel + 1) << ")" << endl << endl;
    cout << RESET_COLOR;


    cout << "1) Get a WoodenSword" << endl;
    cout << "2) Get a SilverSword" << endl;
    cout << "3) Get a StarSword" << endl;
    cout << "4) Weapon Power Up" << endl;
    cout << "5) Exit To Menu" << endl;

    cin >> number;
    switch (number) {

    case 1:
        system("clear");
        if (playerExp >= 300 && playerWeaponType == "None") {
            playerExp -= 300;
            playerSpentExp += 300;
            playerWeaponType = "WoodenSword";
            cout << playerWeaponType << " purchased" << endl << endl;
        }
        else if (playerWeaponType != "None"){
            cout << BRIGHT_RED << "You already got a weapon." << RESET_COLOR << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
        }
        weaponStore(); break;

    case 2:
        system("clear");
        if (playerExp >= 650 && playerWeaponType == "None") {
            playerExp -= 650;
            playerSpentExp += 650;
            playerWeaponType = "SilverSword";
            cout << playerWeaponType << " purchased" << endl << endl;
        }
        else if (playerWeaponType != "None"){
            cout << BRIGHT_RED << "You already got a weapon." << RESET_COLOR << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
        }
        weaponStore(); break;

    case 3:
        system("clear");
        if (playerExp >= 850 && playerWeaponType == "None") {
            playerExp -= 850;
            playerSpentExp += 850;
            playerWeaponType = "StarSword";
            cout << playerWeaponType << " purchased" << endl << endl;
        }
        else if (playerWeaponType != "None"){
            cout << BRIGHT_RED << "You already got a weapon." << RESET_COLOR << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
        }
        weaponStore(); break;

    case 4:
        system("clear");
        if (playerExp >= 50 && playerWeaponType != "None") {
            playerExp -= 50;
            playerSpentExp += 50;
            playerWeaponLevel += 1;
            
            // weapon upgrade
            if(playerWeaponLevel < 8){
                cout << playerWeaponType << " Power Up by Lv.1!" << endl << endl;
            }
            else if(playerWeaponLevel >= 8 && playerWeaponType == "WoodenSword"){
                cout << playerWeaponType << " upgraded to Lv.1 SilverSword!" << endl << endl;
                playerWeaponLevel = 1;
                playerWeaponType = "SilverSword";
            }
            else if(playerWeaponLevel >= 12 && playerWeaponType == "SilverSword"){
                cout << playerWeaponType << " upgraded to Lv.1 GoldenSword!" << endl << endl;
                playerWeaponLevel = 1;
                playerWeaponType = "GoldenSword";
            }
            else if(playerWeaponLevel >= 20 && playerWeaponType == "GoldenSword"){
                cout << playerWeaponType << " upgraded to Lv.1 MythicSword!" << endl << endl;
                playerWeaponLevel = 1;
                playerWeaponType = "MythicSword";
            }

        }
        else if (playerWeaponType == "None") {
            cout << BRIGHT_RED << "You do not have any weapon." << RESET_COLOR << endl << endl;
        }
        else {
            cout << BRIGHT_RED << "You do not have enough experiences." << RESET_COLOR << endl << endl;
        }
        weaponStore(); break;

    case 5: system("clear"); menu(); break;
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
        monsterMaxHealth = 12500;
    else if (dungeonLevel == "Normal")
        monsterMaxHealth = 25000;
    else if (dungeonLevel == "Hard")
        monsterMaxHealth = 50000;
    else if (dungeonLevel == "Mythic")
        monsterMaxHealth = 200000;

    monsterHealth = monsterMaxHealth;


    int countATK = 8;
    int energyATK = 20;


    // player information
    int playerATK = 100; // initial attack value
    playerATK += bonusATK; // level up rewards deduct monster health
    playerATK += weaponATK; // weapon increase player's attack
    energyATK += weaponMMP; // weapon increase player's energy
    monsterHealth -= weaponMHP; // weapon deduct monster health


    do {

        if (energyATK == 0){
            system("clear");
            cout << BRIGHT_RED << "Energy is used up. Dungeon Quest Failed..." << RESET_COLOR << endl << endl;
            dungeonMenu();
        }

        else if (countATK >= 8){
            countATK = 0;
            system("clear");

            // energy
            cout << "Energy: ";
            if (energyATK>20){
                for(int i = 20; i > 0; i--){
                    cout << "*";
                }
                for(int i = (energyATK - 20); i > 0; i--){
                    cout << BRIGHT_YELLOW << "*" << RESET_COLOR;
                }
            }
            else{
                for(int i = energyATK; i > 0; i--){
                    cout << "*";
                }
            }

            cout << endl;

            if (monsterHealth <= (0.2 * monsterMaxHealth))
                cout << endl << endl << BRIGHT_CYAN << "Monster Health - 20% left..." << RESET_COLOR << endl;
            else if (monsterHealth <= (0.4 * monsterMaxHealth))
                cout << endl << endl << BRIGHT_CYAN << "Monster Health - 40% left..." << RESET_COLOR << endl;
            else if (monsterHealth <= (0.6 * monsterMaxHealth))
                cout << endl << endl << BRIGHT_CYAN << "Monster Health - 60% left..." << RESET_COLOR << endl;
            else if (monsterHealth <= (0.8 * monsterMaxHealth))
                cout << endl << endl << BRIGHT_CYAN << "Monster Health - 80% left..." << RESET_COLOR << endl;
            else
                cout << endl << endl << BRIGHT_GREEN << "Attacking the monster..." << RESET_COLOR << endl;

            cout << BRIGHT_YELLOW << "Continue attack the monster by pressing ENTER." << RESET_COLOR << endl;

            energyATK--;

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
    string login;

    cout << endl;
    cout << BRIGHT_CYAN << "         Dungeon Game" << RESET_COLOR << endl;

    cout << "https://github.com/wukimwa/game" << endl;
    cout << endl << endl << endl << endl << endl;

    cout << BRIGHT_YELLOW << "Login" << RESET_COLOR << endl;
    cout << "Username: " << BRIGHT_GREEN;
    cin >> login;
    cout << RESET_COLOR << endl;

    if (login[0] == '/'){

        int totalNum = 0;
        int countNum = 1, prevNum = 1;

        // player name
        for (int i = 1; login[i] != '-'; i++){
            countNum++;
            totalNum++;
            cout << login[i];
        }
        playerName = login.substr(1, totalNum);
        cout << " " << playerName << endl;
        countNum++;
        totalNum = 0;


        prevNum = countNum;
        // player experience
        for (int i = countNum; login[i] != '-'; i++){
            countNum++;
            totalNum++;
            cout << login[i];
        }
        playerExp = stoi(login.substr(prevNum, totalNum));
        cout << " " << playerExp << endl;
        countNum++;
        totalNum = 0;


        prevNum = countNum;
        // player level (spent experience)
        for (int i = countNum; login[i] != '-'; i++){
            countNum++;
            totalNum++;
            cout << login[i];
        }
        playerSpentExp = stoi(login.substr(prevNum, totalNum));
        cout << " " << playerSpentExp << endl;
        countNum++;
        totalNum = 0;


        prevNum = countNum;
        // player weapon type
        for (int i = countNum; login[i] != '-'; i++){
            countNum++;
            totalNum++;
            cout << login[i];
        }
        playerWeaponType = login.substr(prevNum, totalNum);
        cout << " " << playerWeaponType << endl;
        countNum++;
        totalNum = 0;


        prevNum = countNum;
        // player weapon level
        for (int i = countNum; login[i] != '/'; i++){
            countNum++;
            totalNum++;
            cout << login[i];
        }
        playerWeaponLevel = stoi(login.substr(prevNum, totalNum));
        cout << " " << playerWeaponLevel << endl;
        countNum++;
        totalNum = 0;

        system("clear");
        cout << BRIGHT_YELLOW << "Login successful." << RESET_COLOR;
        cout << endl << endl;
        menu();
    }

    // simple anti-cheat
    else if (playerLv == 0 && playerExp == 0 && playerSpentExp == 0 && playerWeaponType == "None" && playerWeaponLevel == 0){
        playerName = login;
        system("clear");
        cout << BRIGHT_YELLOW << "Login successful. You have received EXP 500 as a new player gift." << RESET_COLOR;
        cout << endl << endl;
        playerExp += 500;
        menu();
    }

    else{
        system("clear");
        cout << BRIGHT_RED << "Please do not modify player variables." << RESET_COLOR << endl << endl;
        main();
    }

    return 0;
}