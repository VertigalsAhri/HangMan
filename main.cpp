#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Korisnik.h"
#include "Rijec.h"


using namespace std;

// izbrisat ptr!!!!
// try and catch u rijeci i u trial

// -------------------------------------------------GLOBALNE VARIJABLE------------------------------------------------------------

void clanMeni();
void AdminMeni();
void  loginMeni();

static int brKorisnika;

vector<Korisnik> korisnici;
vector<string> rijeci;

//-------------------------------------------------------------------------------------------------------------------------------

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
// ------------------------------------------------------ADMIN VEKTOR-------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void VektorAdmina(){
    try {
        ifstream datoteka("admini.txt");
        if (datoteka.is_open()) {

            string ime, prezime, username, password;

            string red;
            while (getline(datoteka, red)) {
                if (red.empty()) {
                    continue;
                }

                ime = red;
                getline(datoteka, prezime);
                getline(datoteka, username);
                getline(datoteka, password);


                korisnici.emplace_back(ime, prezime, username, password, admin, 0);

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

                bodovi=stod(strbodovi);

                korisnici.emplace_back(ime, prezime, username, password, korisnik, bodovi);

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
// ---------------------------------------------------ADMIN MENI FUNKCIJE---------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


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
        for (int j=0; j<rijec.length(); j++){
            r= toupper(rijec[j]);
            a+=r;
        }
        rijec=a;
        rijeci.push_back(rijec);
        rijec="";
        a="";

    }
    ofstream datoteka_;
    datoteka_.open("rijeci.txt");
    for(auto i:rijeci){
        datoteka_ << i << endl;
    }
    /*for(int i=0; i<rijeci.size(); i++){
        datoteka_ << rijeci[i] <<"\n";
    }*/

    datoteka_.close();

}

// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------BRISANJE RIJECI----------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


void izbrisiRijec(){
    pregledRijeci();
    int n;
    do{
        try{
            cout << "Unesite redni broj rijeci koju zelite obrisati: ";
            cin >> n;
            if(n<1 || n>rijeci.size()){
                throw n;
            }
        }catch(int n){
            cout << "Pogresan odabir. Ta rijec ne postoji!" << endl;
        }
    }while(n<1 || n>rijeci.size());

    rijeci.erase(rijeci.begin() + n - 1);
    ofstream datoteka_;
    datoteka_.open("rijeci.txt");
    for(int i=0; i<rijeci.size(); i++){
        datoteka_ << rijeci[i] <<"\n";
    }

    datoteka_.close();
    pregledRijeci();
}

// -------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------PREGLED KORISNIKA-----------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void pregled_korisnika(){
    cout << std::left << setw(3) << "" << std::left << setw(23) << "IME " << std::left << setw(20) << "PREZIME" << std::left << setw(20) << "USERNAME" << std::left << setw(20) << "BODOVI" << std::left << setw(20) << "BODOVI" << endl;
    for(int i=0; i<korisnici.size()-4; i++){
        cout << i+1 << ". ";


            if(korisnici[i].getBodovi()>=75){
                cout <<  "GOLD" << endl;
            }else if(korisnici[i].getBodovi()>=50 && korisnici[i].getBodovi()<75 ){
                cout << "SILVER" << endl;
            }else if(korisnici[i].getBodovi()>=25 && korisnici[i].getBodovi()<50 ){
                cout <<"BRONZE" << endl;
            }else {
                cout<< "NONE" << endl;
            }

    }
}

// -------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------RESET BODOVA KORISNIKA------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void reset_bodova_korisnika(){
    int n, broj_korisnika, br;
    cout << "Resetiraj bodove: " << endl;
    cout << "1. Jednom korisniku" << endl;
    cout << "2. Dva ili viĹˇe korisnika" << endl;
    cout << "3. Svim korisnicima" << endl;
    do{
        try{
            cout << "Unesite izbor(1,2,3): ";
            cin >> n;
            if(n<1 || n>3){
                throw n;
            }
        }catch(int n){
            cout << endl<< "Pogresan unos. Pokusajte ponovo!" << endl;
        }
    }while(n<1 || n>3);

    if(n==1){
        pregled_korisnika();
        do{
            try{
                cout << "Unesite redni broj korisnika kojem zelite resetirati bodove: ";
                cin >> br;
                if(br<1 || br>korisnici.size()-4){
                    throw br;
                }
                if(korisnici[br-1].getBodovi()==0){
                    cout << endl << "Korisnik vec ima 0 bodova. Izaberite drugog!" << endl;
                }
            }catch(int x){
                cout <<endl<< "Unos van opsega broja korisnika. Pokusajte ponovo!"<< endl;
            }

        }while(br<1 || br>korisnici.size()-4 || korisnici[br-1].getBodovi()==0);



        pregled_korisnika();

    }else if(n==2){
        pregled_korisnika();
        do{
            cout << "Unesite broj korisnika kojima zelite resetirati bodove: ";
            cin >>broj_korisnika;
            if(broj_korisnika<1 || broj_korisnika>korisnici.size()-4){
                cout << "Ne postoji toliko korisnika. Unesite novu kolicinu. \n";
            }
        }while(broj_korisnika<1 || broj_korisnika>korisnici.size()-4);

        for(int i=0; i<broj_korisnika; i++){
            do{
                try{
                    cout << "Unesite redni broj korisnika kojem zelite resetirati bodove: ";
                    cin >> br;
                    if(br<1 || br>korisnici.size()-4){
                        throw br;
                    }
                    if(korisnici[br-1].getBodovi()==0){
                        cout << endl << "Korisnik vec ima 0 bodova. Izaberite drugog!" << endl;
                    }
                }catch(int n){
                    cout <<endl<< "Unos van opsega broja korisnika. Pokusajte ponovo!"<< endl;
                }

            }while(br<1 || br>korisnici.size()-4 || korisnici[br-1].getBodovi()==0);

        }

        pregled_korisnika();




    }else{
        for(int i=0; i < korisnici.size()-4; i++){

        }
        pregled_korisnika();
    }

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
    cin.ignore();
}

// -------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------BRISANJE KORISNIKA----------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------

void brisanje_korisnika(){
    pregled_korisnika();
    int n;
    do{
        try{
            cout << "Unesite redni broj korisnika kojeg zelite obrisati: ";
            cin >> n;
            if(n<1 || n>korisnici.size()-4){
                throw n;
            }
        }catch(int n){
            cout <<endl<< "Unos van opsega broja korisnika. Pokusajte ponovo!"<< endl;
        }

    }while(n<1 || n>korisnici.size()-4);
    korisnici.erase(korisnici.begin() + n - 1);

    cout << endl << "Korisnik je uspjesno obrisan!" << endl;

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
// ---------------------------------------------------CLAN MENI FUNKCIJE---------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------IGRA----------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


void igra(){
    srand(time(nullptr));
    rand();
    int broj=rand()%rijeci.size();
    string r=rijeci[broj];
    Rijec rijec(r, korisnici);


    rijec.Pogadjanje(brKorisnika);
    korisnici=rijec.getKorisnici();
    VektorAdmina();


    ofstream datoteka_;
    datoteka_.open("k.txt");
    for(int i=0; i<korisnici.size()-4; i++){
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
// ------------------------------------------------------SCOREBOARD---------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------


void rekurzivniSort(int n, vector<Korisnik>& k) {
    if (n== 1) return;

    for (int i = 0; i < k.size() - 1; i++) {
        if (k[i].getBodovi() < k[i + 1].getBodovi()) {
            swap(k[i], k[i + 1]);
        }
    }

    rekurzivniSort(n - 1, k);
}

// -------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------ADMIN MENI---------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------



void AdminMeni(){
    while (true) {

        cout << "----- ADMIN MENI -----" << endl;
        cout << "1. Pregled rijeci" << endl;
        cout << "2. Pregled korisnika " << endl;
        cout << "3. Brisanje korisnika" << endl;
        cout << "4. Dodaj rijec\n";
        cout << "5. Ukloni rijec\n";
        cout << "6. EXIT\n";
        //RESETIRAJ BODOVE SVIH IGRACA

        int izbor;

        cout << "Unesite izbor: ";
        cin >> izbor;

        switch (izbor) {

            case 1:
                pregledRijeci();
                break;
            case 2:
                pregled_korisnika();
                break;
            case 3:

                break;
            case 4:
                dodajRijec();
                break;
            case 5:
                izbrisiRijec();
                system("CLS");
            case 6:
                loginMeni();
            default:
                cout << "Nepostojeca opcija!" << endl;
        }
    }

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
    unique_ptr<Korisnik> temp= make_unique<Korisnik>();
    temp->setIme();
    temp->setPrezime();
    do{
        temp->setUsername();
    }while(provjeraUsername(temp->getUsername()));
    temp->setPassword();
    temp->setVrsta(korisnik);
    temp->SETBodovi(0);
    /*Korisnik k;
    k.setIme();
    k.setPrezime();
    do{
        k.setUsername();
    }while(provjeraUsername(k.getUsername()));

    k.setPassword();
    k.setVrsta(korisnik);
    k.SETBodovi(0);*/

    int mjesto=korisnici.size()-4;
    auto it =korisnici.begin()+mjesto;
    korisnici.emplace(it, *temp);

    string filePath="C:\\NTP\\probniprojekat3\\k.txt";
    ofstream datoteka_;
    datoteka_.open(filePath, ios::app);
    datoteka_<< temp->getIme()<< "\n";
    datoteka_<< temp->getPrezime()<< "\n";
    datoteka_<< temp->getUsername()<< "\n";
    datoteka_<< temp->getPassword()<< "\n";
    datoteka_<< temp->getBodovi()<<"\n";
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
