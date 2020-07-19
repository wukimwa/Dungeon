#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "code/display.cpp"
using namespace std;

// function header
void menu();
void save();
void dungeon();
void playerMenu();
void levelReward();
void dungeonMenu();
void weaponStore();
void showInfo(string m);
void dungeonReward(int rewardEXP);
void purchaseWeapon(string w, int p);

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
int weaponATK = 0, weaponPMP = 0, weaponMHP = 0; // weapon variable
int number = 0; // user input
string message = "";

// weapon variable
int playerWeaponLevel = 0;
string playerWeaponType = "None";

// dungeon variable
string dungeonLevel;


void showInfo(string m) {

    system("clear");

    // show message
    if (message != "")
        cout << message << endl << endl;

    // update variable
    playerLv = (playerSpentExp * 0.2) / 20; // player level

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
        weaponPMP = 1;
        weaponATK = 10;
        weaponMHP = 100;
    }
    else if (playerWeaponType == "SilverSword"){
        weaponPMP = 2;
        weaponATK = 20;
        weaponMHP = 200;
    }
    else if (playerWeaponType == "GoldenSword"){
        weaponPMP = 3;
        weaponATK = 25;
        weaponMHP = 300;
    }
    else if (playerWeaponType == "StarSword"){
        weaponPMP = 3;
        weaponATK = 15;
        weaponMHP = 150;
    }
    else if (playerWeaponType == "MythicSword"){
        weaponPMP = 5;
        weaponATK = 20;
        weaponMHP = 275;
    }

    // player weapon level bonus
    if (playerWeaponLevel >= 25){
        weaponPMP += 3;
        weaponATK += 6;
        weaponMHP += 300;
    }
    else if (playerWeaponLevel >= 15){
        weaponPMP += 2;
        weaponATK += 3;
        weaponMHP += 225;
    }
    else if (playerWeaponLevel >= 5){
        weaponPMP += 1;
        weaponATK += 2;
        weaponMHP += 150;
    }

    cout << left << BRIGHT_GREEN << setw(11) << playerName << RESET_COLOR;
    cout << " Lv. " << BRIGHT_CYAN << setw(6) << playerLv << RESET_COLOR;
    cout << " EXP " << BRIGHT_YELLOW << setw(6) << playerExp << RESET_COLOR;
    cout << right; // default
    cout << endl << endl;

    message = "";
}

void menu() {

    showInfo(message);
    showMenu("Main Menu");
    cin >> number;
    switch (number) {
    case 1: playerMenu(); break;
    case 2: dungeonMenu(); break;
    case 3: save(); break;
    default: menu();
    }
}

void save(){
    cout << endl;
    cout << "The following data will be saved: " << endl;
    cout << BRIGHT_YELLOW << "Player Name\nPlayer Level\nPlayer Experience\nPlayer Weapon Type\nPlayer Weapon Level" << RESET_COLOR << endl;
    cout << endl << endl;

    string data = "/" + playerName + "-" + to_string(playerExp) + "-" + to_string(playerSpentExp) + "-" + playerWeaponType + "-" + to_string(playerWeaponLevel) + "/";
    cout << "Please use the following key for next login: " << endl;
    cout << BRIGHT_CYAN << data << RESET_COLOR;
    cout << endl << endl << endl << endl;

    cin.ignore();
    cout << BRIGHT_GREEN << "Press ENTER to continue..." << RESET_COLOR;
    cin.ignore();
    
    menu();
}

void playerMenu() {

    showInfo(message);
    showMenu("Player Menu");
    cin >> number;
    switch (number) {
    case 1: weaponStore(); break;
    case 2: levelReward(); break;
    case 3: menu(); break;
    default: playerMenu();
    }

}

void levelReward() {

        showInfo(message);
        showMenu("Level Up Rewards");

        const int LEVEL_WIDTH = 12;
        const int REWARDS_WIDTH = 20;

        cout << endl << left;

        cout << BRIGHT_GREEN << setw(LEVEL_WIDTH) << "Level";
        cout << BRIGHT_YELLOW << setw(REWARDS_WIDTH) << "Rewards" << endl;
        cout << RESET_COLOR;

        (playerLv >= 5) ? cout << BRIGHT_YELLOW : cout;
        cout << setw(LEVEL_WIDTH) << "Lv. 05";
        cout << setw(REWARDS_WIDTH) << "+1 ATK value" << endl;

        (playerLv < 10) ? cout << RESET_COLOR : cout;
        cout << setw(LEVEL_WIDTH) << "Lv. 10";
        cout << setw(REWARDS_WIDTH) << "+1 ATK value" << endl;

        (playerLv < 15) ? cout << RESET_COLOR : cout;
        cout << setw(LEVEL_WIDTH) << "Lv. 15";
        cout << setw(REWARDS_WIDTH) << "+2 ATK value" << endl;

        (playerLv < 20) ? cout << RESET_COLOR : cout;
        cout << setw(LEVEL_WIDTH) << "Lv. 20";
        cout << setw(REWARDS_WIDTH) << "+2 ATK value" << endl;

        cout << RESET_COLOR;
        cout << right; // default
        cout << endl;

        cout << "Total Bonus Added: " << BRIGHT_YELLOW << bonusATK << RESET_COLOR << " ATK" << endl;
        cout << endl << endl;

        cin.ignore();
        cout << BRIGHT_GREEN << "Press ENTER to continue..." << RESET_COLOR;
        cin.ignore();

        
        playerMenu();

}

void weaponStore() {

    showInfo(message);
    showMenu("Dungeon Weapon Store");
    cout << "ATK: Player's Attack Value;" << endl;
    cout << "PMP: Player's Energy Point;" << endl;
    cout << "MHP: Monster Max Health Deduction;" << endl;
    cout << endl << endl;

    cout << left;
    const int PRICE_WIDTH = 16;
    const int WEAPON_WIDTH = 16;
    const int PROPERTIES_WIDTH = 40;

    cout << BRIGHT_GREEN << setw(PRICE_WIDTH) << "Price";
    cout << BRIGHT_CYAN << setw(WEAPON_WIDTH) << "Weapon Type ";
    cout << BRIGHT_YELLOW << setw(PROPERTIES_WIDTH) << "( Properties )";
    cout << RESET_COLOR << endl << endl;
    
    // WoodenSword
    (playerWeaponType == "WoodenSword") ? cout << BRIGHT_YELLOW : cout;
    showWeapon(PRICE_WIDTH, WEAPON_WIDTH, PROPERTIES_WIDTH, "WoodenSword");
    cout << RESET_COLOR << endl;

    // SilverSword
    (playerWeaponType == "SilverSword") ? cout << BRIGHT_YELLOW : cout;
    showWeapon(PRICE_WIDTH, WEAPON_WIDTH, PROPERTIES_WIDTH, "SilverSword");
    cout << RESET_COLOR << endl;

    // GoldenSword
    (playerWeaponType == "GoldenSword") ? cout << BRIGHT_YELLOW : cout;
    showWeapon(PRICE_WIDTH, WEAPON_WIDTH, PROPERTIES_WIDTH, "GoldenSword");
    cout << RESET_COLOR << endl;

    cout << endl;

    // StarSword
    (playerWeaponType == "StarSword") ? cout << BRIGHT_YELLOW : cout;
    showWeapon(PRICE_WIDTH, WEAPON_WIDTH, PROPERTIES_WIDTH, "StarSword");
    cout << RESET_COLOR << endl;

    // MythicSword
    (playerWeaponType == "MythicSword") ? cout << BRIGHT_YELLOW : cout;
    showWeapon(PRICE_WIDTH, WEAPON_WIDTH, PROPERTIES_WIDTH, "MythicSword");
    cout << RESET_COLOR << endl;

    cout << endl << endl;


    // weapon level
    const int powerUpCost = 20;
    string showPlayerWeaponLevel;

    if (playerWeaponLevel <= 9)
        showPlayerWeaponLevel = "Lv.0" + to_string(playerWeaponLevel);
    else
        showPlayerWeaponLevel = "Lv." + to_string(playerWeaponLevel);
    
    // player weapon
    cout << BRIGHT_GREEN;
    cout << setw(PRICE_WIDTH) << playerWeaponType;
    cout << setw(WEAPON_WIDTH) << showPlayerWeaponLevel;
    cout << setw(PROPERTIES_WIDTH) << "( Power up the weapon by Lv.1 )";
    cout << RESET_COLOR << endl;

    cout << BRIGHT_YELLOW;
    (playerWeaponLevel < 5) ? cout << RESET_COLOR : cout;
    cout << setw(PRICE_WIDTH) << "";
    cout << setw(WEAPON_WIDTH) << "Lv.05";
    cout << setw(PROPERTIES_WIDTH) << "( +1 PMP; +2 ATK; +150 MHP )" << endl;

    (playerWeaponLevel < 15) ? cout << RESET_COLOR : cout;
    cout << setw(PRICE_WIDTH) << "";
    cout << setw(WEAPON_WIDTH) << "Lv.15";
    cout << setw(PROPERTIES_WIDTH) << "( +2 PMP; +3 ATK; +225 MHP )" << endl;

    (playerWeaponLevel < 25) ? cout << RESET_COLOR : cout;
    cout << setw(PRICE_WIDTH) << "";
    cout << setw(WEAPON_WIDTH) << "Lv.25";
    cout << setw(PROPERTIES_WIDTH) << "( +3 PMP; +6 ATK; +300 MHP )" << endl;

    cout << RESET_COLOR << endl;

    cout << right; // default
    cout << endl << endl;

    cout << "1) Get a WoodenSword" << endl;
    cout << "2) Get a SilverSword" << endl;
    cout << "3) Get a StarSword" << endl;
    cout << "4) Weapon Power Up" << endl;
    cout << "5) Exit To Menu" << endl;

    cin >> number;
    switch (number) {
    case 1: purchaseWeapon("WoodenSword", 300); break;
    case 2: purchaseWeapon("SilverSword", 850); break;
    case 3: purchaseWeapon("StarSword", 1200); break;
    case 4: purchaseWeapon("PowerUp", powerUpCost); break;
    case 5: menu(); break;
    default: weaponStore();
    }
}

void purchaseWeapon(string w, int p) {

    if (playerExp < p)
        message = "You do not have enough experiences.";
    else if (w == "PowerUp" && playerWeaponType == "None")
        message = "You do not have a weapon.";

    else if (w == "PowerUp"){
        playerExp -= p;
        playerSpentExp += p;
        playerWeaponLevel += 1;
        
        // weapon upgrade

        if (playerWeaponLevel >= 30 && playerWeaponType == "WoodenSword"){
            message = "WoodenSword is upgraded to Lv.1 SilverSword!";
            playerWeaponLevel = 1;
            playerWeaponType = "SilverSword";
        }
        else if (playerWeaponLevel >= 30 && playerWeaponType == "SilverSword"){
            message = "SilverSword is upgraded to Lv.1 GoldenSword!";
            playerWeaponLevel = 1;
            playerWeaponType = "GoldenSword";
        }
        else if (playerWeaponLevel >= 30 && playerWeaponType == "StarSword"){
            message = "StarSword is upgraded to Lv.1 MythicSword!";
            playerWeaponLevel = 1;
            playerWeaponType = "MythicSword";
        }
        else {
            message = "The weapon is Power Up by Lv.1!";
        }

    }

    else if(playerWeaponType != "None")
        message = "You already got a weapon.";

    else{
        playerExp -= p;
        playerSpentExp += p;
        playerWeaponType = w;
        message = "Purchased successfully.";
    }
    weaponStore();
}


void dungeonMenu() {

    showInfo(message);
    showMenu("Dungeon Menu");

    cin >> number;
    switch (number) {
    case 1: dungeonLevel = "Easy"; dungeon(); break;
    case 2: dungeonLevel = "Normal"; dungeon(); break;
    case 3: dungeonLevel = "Hard"; dungeon(); break;
    case 4: dungeonLevel = "Mythic"; dungeon(); break;
    case 5: menu(); break;
    default: dungeonMenu();
    }

}

void dungeon() {

    system("clear");

    // check player level
    if (playerLv < 5 && dungeonLevel == "Hard") {
        message = "The dungeon is now locked.";
        dungeonMenu();
    }
    else if (playerLv < 15 && dungeonLevel == "Mythic") {
        message = "The dungeon is now locked.";
        dungeonMenu();
    }

    // dungeon monster health
    int monsterHealth, monsterMaxHealth;

    if (dungeonLevel == "Easy")
        monsterMaxHealth = 18000;
    else if (dungeonLevel == "Normal")
        monsterMaxHealth = 20000;
    else if (dungeonLevel == "Hard")
        monsterMaxHealth = 25000;
    else if (dungeonLevel == "Mythic")
        monsterMaxHealth = 30000;

    monsterHealth = monsterMaxHealth;

    int countATK = 8;
    int energyATK = 20;

    // player information
    int playerATK = 100; // initial attack value
    playerATK += bonusATK; // level up rewards deduct monster health
    playerATK += weaponATK; // weapon increase player's attack
    energyATK += weaponPMP; // weapon increase player's energy
    monsterHealth -= weaponMHP; // weapon deduct monster health

    do {

        if (energyATK == 0){
            if (playerWeaponType == "None")
                message = "Energy is used up. Dungeon Quest Failed...\nTry to get a weapon from the weapon store.";
            else if (playerWeaponLevel < 25)
                message = "Energy is used up. Dungeon Quest Failed...\nTry to power up your weapon in weapon store.";
            else
                message = "Energy is used up. Dungeon Quest Failed...";
            dungeonMenu();
        }

        else if (countATK >= 8){

            countATK = 0;
            system("clear");

            // monster HP
            cout << "Monster HP: ";
            for(int i = (monsterHealth/double(monsterMaxHealth) * 25); i > 0; i--){
                cout << BRIGHT_RED << "*" << RESET_COLOR;
            }
            cout << endl << endl;

            // energy
            cout << "Player PMP: ";
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
        dungeonReward(monsterMaxHealth);
    }

}

void dungeonReward(int x) {

    system("clear");
    int rewardEXP = x / 500 * 0.85;
    int rewardPlayerExp = x / 500 * 0.15;

    cout << endl << BRIGHT_CYAN << "Dungeon Completed" << RESET_COLOR;
    cout << endl << endl;

    cout << BRIGHT_GREEN << "Rewards" << RESET_COLOR;
    cout << endl;
    cout << BRIGHT_YELLOW << setw(3) << rewardPlayerExp << RESET_COLOR << " Lv. Point";
    cout << endl;
    cout << BRIGHT_YELLOW << setw(3) << rewardEXP << RESET_COLOR << " Experience";
    cout << endl;
    
    cout << endl << endl;

    playerExp += rewardEXP;
    playerSpentExp += rewardPlayerExp;

    cout << "1) Exit To Player Menu" << endl;
    cout << "2) Exit To Dungeon Menu" << endl;

    cin >> number;
    switch (number) {
    case 1: playerMenu(); break;
    case 2: dungeonMenu(); break;
    default: menu();
    }

}

int main() {

    string login;
    system("clear");
    
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

        message = "Login successful.";
        menu();
    }

    // simple anti-cheat
    else if (playerLv == 0 && playerExp == 0 && playerSpentExp == 0 && playerWeaponType == "None" && playerWeaponLevel == 0){
        playerExp += 500;
        playerName = login;
        message = "Login successful. You have received EXP 500 as a new player gift.";
        menu();
    }

    else{
        cout << BRIGHT_RED << "Please do not modify player variables." << RESET_COLOR << endl << endl;
        main();
    }

    return 0;
}