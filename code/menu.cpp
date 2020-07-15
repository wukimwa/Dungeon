#include <iostream>
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