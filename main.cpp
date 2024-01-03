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

// -------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------REGISTRACIJA KORISNIKA--------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void registracija_korisnika(){
    Korisnik k;
    k.setIme();
    k.setPrezime();
    do{
        k.setUsername();
    }while(provjeraUsername(k.getUsername()));

    k.setPassword();
    k.setVrsta(korisnik);
    k.setBodovi(0);
    korisnici.push_back(k);

    string filePath="C:\\Users\\User\\CLionProjects\\probniprojekat2\\k.txt";
    ofstream datoteka_;
    datoteka_.open(filePath, ios::app);
    datoteka_<< k.getIme()<< "\n";
    datoteka_<< k.getPrezime()<< "\n";
    datoteka_<< k.getUsername()<< "\n";
    datoteka_<< k.getPassword()<< "\n";
    datoteka_<<k.getBodovi()<<"\n";
    datoteka_<< "\n";
    datoteka_.close();
}

// -------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------LOGIN----------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

int login(){
    Korisnik k;
    k.setUsername();
    k.setPassword();
    for(int i=0; i<korisnici.size(); i++){
        if(k.getUsername()==korisnici[i].getUsername() && k.getPassword()==korisnici[i].getPassword() && korisnici[i].getVrsta()==korisnik){
            brKorisnika=i;
            clanMeni();
        }else if(k.getUsername()==korisnici[i].getUsername() && k.getPassword()==korisnici[i].getPassword() && korisnici[i].getVrsta()==admin){
            AdminMeni();
        }
    }

    system("cls");
}

// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------IGRA----------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


void ispis(){
    srand(time(nullptr));
    rand();
    int broj=rand()%rijeci.size();
    string r=rijeci[broj];
    Rijec rijec(r, korisnici);

    korisnici[brKorisnika].SETBodovi(0);



    korisnici=rijec.Pogadjanje(brKorisnika);



    string filePath="C:\\Users\\User\\CLionProjects\\probniprojekat2\\k.txt";
    ofstream datoteka_;
    datoteka_.open(filePath);
    for(auto k:korisnici){
        datoteka_<< k.getIme()<< "\n";
        datoteka_<< k.getPrezime()<< "\n";
        datoteka_<< k.getUsername()<< "\n";
        datoteka_<< k.getPassword()<< "\n";
        datoteka_<<k.getBodovi()<<"\n";
        datoteka_<< "\n";
    }
    datoteka_.close();

}
// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------SCOREBOARD----------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void score(){
    cout << "Username" << "\t Bodovi" << endl;
    for(auto i: korisnici){
        cout << i;
    }
}
// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------LOGIN MENI---------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


void loginMeni(){
    while (true) {
        //cout << linija << "\t  LOGIN " << linija;
        cout << "1. Login" << endl;
        cout << "2. Registracija clana" << endl;
        cout << "0. dodaj ruc" << endl;
        cout << "3. Exit" << endl;

        int opcija;
        cout << "Izaberite opciju: ";
        cin >> opcija;
        system("cls");
        switch (opcija) {
            case 1:
                login();
                system("cls");

                break;
            case 2:
                registracija_korisnika();
                system("cls");
                break;
            case 0:

                system("cls");

                break;
            case 3:
                cout << "Exiting..." << endl;
                system("cls");

                exit(0);

            default:
                cout << "Netacan odabir. Pokusajte ponovo." << endl;
        }
    }
}


// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------CLAN MENI----------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void clanMeni() {

    while (true) {

        cout << "\t \t MENI" << endl;
        //cout << linija;
        cout << "1. Zapocni igru " << endl;
        cout << "2. Scoreboard " << endl;
        cout << "3. EXIT " << endl;

        int izbor;

        cout << "Unesite izbor: ";
        cin >> izbor;

        switch (izbor) {

            case 1:
                ispis();
                break;
            case 2:
                cin.ignore();
                score();
                break;
            case 3:
                loginMeni();
                system("CLS");
            default:
                cout << "Nepostojeca opcija!" << endl;
        }
    }
}

// -------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------MAIN------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

int main() {

    VektorKorisnika();
    VektorAdmina();

    loginMeni();

    return 0;
}