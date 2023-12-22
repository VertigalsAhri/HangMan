#include <iostream>
#include "Osoba.h"

using namespace std;
char * linija = "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

void AdminMeni(){

}

bool login() {
    string username;
    string password;
    cin.ignore();
    cout << linija << "\t Login " << linija;
    cout << "Korisnicko ime: ";
    cin >> username;
    cout << "Lozinka: ";
    cin >> password;

}

int loginMeni(){
    while (true) {
        cout << linija << "\t  LOGIN " << linija;
        cout << "1. Login" << endl;
        cout << "2. Registracija clana" << endl;
        cout << "3. Exit" << endl;

        int opcija;
        cout << "Izaberite opciju: ";
        cin >> opcija;
        system("cls");
        switch (opcija) {
            case 1:
                system("cls");
                break;
            case 2:

                system("cls");
                break;
            case 3:
                cout << "Exiting..." << endl;
                system("cls");
                return 1;
            default:
                cout << "Netacan odabir. Pokusajte ponovo." << endl;
        }
    }

    system("cls");

}
void clanMeni() {

    while (true) {
        cout << "\t \t MENI";
        cout << linija;
        cout << "1. Zapocni igru " << endl;
        cout << "2. Scoreboard " << endl;
        cout << "3. EXIT " << endl;

        int izbor;
        cout << "Unesite izbor: ";
        cin >> izbor;
        system("cls");

        switch (izbor) {

            case 1:

                break;
            case 2:

                break;
            case 3:
                return;
            default:
                cout << "Nepostojeca opcija!" << endl;
        }
    }
}

int main() {
    int izbor;
    cout << "----- MENI -----" << endl;
    cout << "\tUnesite izbor: ";
    cin >> izbor;
    switch(izbor){

    }
    return 0;
}