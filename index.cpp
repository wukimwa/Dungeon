#include <iostream>
using namespace std;

void menu(string playerName){
    cout << "Hello, " << playerName;
}

int main(){
    string playerName;
    int playerLv = 0, playerCoin = 0, playerExp = 0;

    cout << "Please enter your username: ";
    cin >> playerName;
    cout << endl;

    menu(playerName);

    return 0;
}