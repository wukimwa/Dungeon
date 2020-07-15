#include <iostream>
#include "../index.cpp"

using namespace std;
    
void showMenu(string m){
    cout << "-----     " << m << "     -----" << endl;
    if(m == "Player Menu"){
        cout << "1) Weapon Store" << endl;
        cout << "2) Level Up Rewards" << endl;
        cout << "3) Exit To Menu" << endl;
    }
    else if(m == "Dungeon Menu"){
        cout << "1) ENTER Dungeon  [ Easy ]" << endl;
        cout << "2) ENTER Dungeon  [Normal]" << endl;
        cout << "3) ENTER Dungeon  " << BRIGHT_CYAN << "[ Hard ] [Lv.05 Unlock]" << RESET_COLOR << endl;
        cout << "4) ENTER Dungeon  " << BRIGHT_YELLOW << "[Mythic] [Lv.15 Unlock]" << RESET_COLOR << endl;
        cout << "5) Exit To Menu" << endl;
    }
}