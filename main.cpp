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
void  loginMeni();

static int brKorisnika;

vector<Korisnik> korisnici;
vector<string> rijeci;

// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------VEKTOR RIJECI------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void VektorRijeci(){
    try {

        ifstream datoteka("rijeci.txt");
        if (datoteka.is_open()) {

            string rijec;

            string red;
            while (getline(datoteka, red)) {
               rijec=red;
               rijeci.push_back(rijec);
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
// ------------------------------------------------------DODAJ RIJEC--------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void dodajRijec(){
    int n;
    cout<<"Unesite koliko zelite unijeti novih rijeci ";
    cin>>n;
    string rijec,a;
    char r;
    for(int i=0; i<n; i++){
        cout<<"Unesite "<<i+1<<" rijec: ";
        cin>>rijec;
        for (int i=0; i<rijec.length(); i++){
            r= toupper(rijec[i]);
            a+=r;
        }
        rijec=a;
        rijeci.push_back(rijec);

    }
    ofstream datoteka_;
    datoteka_.open("rijeci.txt");
    for(int i=0; i<rijeci.size(); i++){
        datoteka_ << rijeci[i] <<"\n";
    }

    datoteka_.close();

}

// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------PREGELD RIJECI-----------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void pregledRijeci(){
    cout << "----- PREGLED RIJECI -----" << endl;
    for(int i =0; i<rijeci.size(); i++){
        cout << i+1 << ". " << rijeci[i] << endl;
    }

}
// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------BRISANJE RIJECI----------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


void izbrisiRijec(){
    pregledRijeci();
    int n;
    do{
        cout << "Unesite redni broj rijeci koju zelite obrisati: ";
        cin >> n;
    }while(n<1 || n>rijeci.size());

    rijeci.erase(rijeci.begin() + n - 1);
    string filePath="C:\\NTP\\probniprojekat3\\rijeci.txt";
    ofstream datoteka_;
    datoteka_.open(filePath);
    for(int i=0; i<rijeci.size(); i++){
        datoteka_ << rijeci[i] <<"\n";
    }

    datoteka_.close();

}
// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------ADMIN VEKTOR-------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------



void VektorAdmina(){
    try {
        ifstream datoteka("admini.txt");
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
        ifstream datoteka("k.txt");
        if (datoteka.is_open()) {

            string prezime, ime, username, password;
            double bodovi;
            string strbodovi;

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

                bodovi=stod(strbodovi);

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
// ------------------------------------------------------ADMIN MENI---------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void AdminMeni(){
    cout << "----- ADMIN MENI -----" << endl;
    cout << "1. Pregled rijeci" << endl;
    cout<<"2. Dodaj rijec\n";
}

// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------PROVJERA USERNAME--------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

bool provjeraUsername(string& username) {
    for (auto korisnik : korisnici) {
        if (korisnik.getUsername() == username) {
            return true;
        }
    }
    return false;
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


    ofstream datoteka_;
    datoteka_.open("k.txt", ios::app);
    datoteka_<< k.getIme()<< "\n";
    datoteka_<< k.getPrezime()<< "\n";
    datoteka_<< k.getUsername()<< "\n";
    datoteka_<< k.getPassword()<< "\n";
    datoteka_<<k.getBodovi()<<"\n";
    datoteka_<< "\n";
    datoteka_.close();
}
// -------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------BRISANJE KORISNIKA----------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void brisanje_korisnika(){
    int n;
    do{
        cout << "Unesite redni broj korisnika kojeg zelite obrisati: ";
        cin >> n;
    }while(n<1 || n>korisnici.size()-4);
    korisnici.erase(korisnici.begin() + n - 1);

    ofstream datoteka_;
    datoteka_.open("k.txt");
    for(int i=0; i<korisnici.size()-4;i++){
        datoteka_<< korisnici[i].getIme()<< "\n";
        datoteka_<< korisnici[i].getPrezime()<< "\n";
        datoteka_<< korisnici[i].getUsername()<< "\n";
        datoteka_<< korisnici[i].getPassword()<< "\n";
        datoteka_<<korisnici[i].getBodovi()<<"\n";
        datoteka_<< "\n";
    }
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
// ------------------------------------------------------ISPIS----------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


void ispis(){
    srand(time(nullptr));
    rand();
    int broj=rand()%rijeci.size();
    string r=rijeci[broj];
    Rijec rijec(r, korisnici);

    korisnici[brKorisnika].SETBodovi(0);



    korisnici=rijec.Pogadjanje(brKorisnika);


    ofstream datoteka_;
    datoteka_.open("k.txt");
    for(int i=0; i<korisnici.size(); i++){
        datoteka_<< korisnici[i].getIme()<< "\n";
        datoteka_<< korisnici[i].getPrezime()<< "\n";
        datoteka_<< korisnici[i].getUsername()<< "\n";
        datoteka_<< korisnici[i].getPassword()<< "\n";
        datoteka_<<korisnici[i].getBodovi()<<"\n";
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
        cout << "1. Login" << endl;
        cout << "2. Registracija clana" << endl;
        cout << "0. Dodaj rijec" << endl;
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
