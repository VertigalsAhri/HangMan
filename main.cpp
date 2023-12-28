#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <ctime>
#include <cstdlib>
#include "Korisnik.h"
#include "Rijec.h"

using namespace std;


// -------------------------------------------------GLOBALNE VARIJABLE------------------------------------------------------------

void clanMeni();
void AdminMeni();

static int brKorisnika;

vector<Korisnik> korisnici;
vector<string> rijeci={"KONJ", "KOBILA"};

//-------------------------------------------------------------------------------------------------------------------------------

void AdminMeni(){

}
void VektorAdmina(){
    try {
    string filePath = "C:\\Users\\User\\CLionProjects\\HangMan\\admini.txt"; //popraviti!!
    //Ovo treba popraviti nisam znala drugacije
        ifstream datoteka(filePath);
        if (datoteka.is_open()) {

            string ime, prezime, username, password;
            double bodovi;
            string strbodovi= to_string(bodovi);

            int i = 0;

            string red;
            while (getline(datoteka, red)) {
                if (red.empty()) {
                    continue;
                }

                ime = red;
                getline(datoteka, prezime);
                getline(datoteka, username);
                getline(datoteka, password);
                getline(datoteka, strbodovi);

                if (i >= 100) {
                    cout << "Prekoracen je broj clanova u datoteci." << endl;
                    break;
                }

                korisnici.emplace_back(ime, prezime, username, password, admin, bodovi);

                i++;
            }
        } else {
            throw "Nemoguce otvoriti datoteku! \n";
        }

        datoteka.close();
    }catch(const char *poruka){
        cout << poruka << endl;
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------KORISNIK VEKTOR----------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void VektorKorisnika(){
    try{
    string filePath="C:\\Users\\User\\CLionProjects\\HangMan\\k.txt";
    ifstream datoteka(filePath);
    if (datoteka.is_open()) {

        string prezime, ime, username, password;
        double bodovi;
        string strbodovi= to_string(bodovi);

        int i = 0;

        string red;
        while (getline(datoteka, red)) {
            if (red.empty()) {
                continue;
            }

            ime = red;
            getline(datoteka, prezime);
            getline(datoteka, username);
            getline(datoteka, password);
            getline(datoteka, strbodovi);

            if (i >= 100) {
                cout << "Prekoracen je broj clanova u datoteci." << endl;
                break;
            }

            korisnici.emplace_back(ime, prezime, username, password, korisnik, bodovi);

        i++;
    }
    }else{
        throw "Nemoguce otvoriti datoteku!\n " ;
    }

    datoteka.close();
        }catch(const char *poruka){
        cout << poruka << endl;
    }
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
