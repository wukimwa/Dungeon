#include <iostream>
#include <iomanip>
using namespace std;
    
void showMenu(string m){
    cout << "-----     " << m << "     -----" << endl;
    if (m == "Main Menu"){
        cout << "1) Player" << endl;
        cout << "2) Dungeon" << endl;
        cout << "3) Save Game" << endl;
    }
    else if(m == "Player Menu"){
        cout << "1) Weapon Store" << endl;
        cout << "2) Level Up Rewards" << endl;
        cout << "3) Exit To Menu" << endl;
    }
    else if(m == "Dungeon Menu"){
        cout << "1) ENTER Dungeon  [ Easy ]" << endl;
        cout << "2) ENTER Dungeon  [Normal]" << endl;
        cout << "3) ENTER Dungeon  \033[96m[ Hard ] [Lv.05 Unlock]\033[0m" << endl;
        cout << "4) ENTER Dungeon  \033[93m[Mythic] [Lv.15 Unlock]\033[0m" << endl;
        cout << "5) Exit To Menu" << endl;
    }
}

void showWeapon(int x, int y, int z, string w){

    if (w == "WoodenSword"){
        cout << setw(x) << "300 EXP";
        cout << setw(y) << "WoodenSword";
        cout << setw(z) << "( 1 PMP; 10 ATK; 100 MHP )" << endl;
        cout << setw(x) << "";
        cout << setw(y) << "";
        cout << setw(z) << "( Lv.30 Upgrade to SilverSword Lv.1 )" << endl;
    }
    else if (w == "SilverSword"){
        cout << setw(x) << "850 EXP";
        cout << setw(y) << "SilverSword";
        cout << setw(z) << "( 2 PMP; 20 ATK; 200 MHP )" << endl;
        cout << setw(x) << "";
        cout << setw(y) << "";
        cout << setw(z) << "( Lv.30 Upgrade to GoldenSword Lv.1 )" << endl;
    }
    else if (w == "GoldenSword"){
        cout << setw(x) << "N/A";
        cout << setw(y) << "GoldenSword";
        cout << setw(z) << "( 3 PMP; 25 ATK; 300 MHP )" << endl;
    }
    else if (w == "StarSword"){
        cout << setw(x) << "1200 EXP";
        cout << setw(y) << "StarSword";
        cout << setw(z) << "( 3 PMP; 15 ATK; 150 MHP )" << endl;
        cout << setw(x) << "";
        cout << setw(y) << "";
        cout << setw(z) << "( Lv.30 Upgrade to MythicSword Lv.1 )" << endl;
    }
    else if (w == "MythicSword"){
        cout << setw(x) << "N/A";
        cout << setw(y) << "MythicSword";
        cout << setw(z) << "( 5 PMP; 20 ATK; 275 MHP )" << endl;
    }
}