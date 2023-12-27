//
// Created by DT User on 20/12/2023.
//

#include "Korisnik.h"

std::istream& operator>>(std::istream& stream, Korisnik &k){
    k.setIme();
    k.setPrezime();
    return stream;
}

std::ostream& operator<<(std::ostream& izlaz, Korisnik &k){
    izlaz << k.getUsername() << "\t\t" << k.getBodovi() << endl;
    return izlaz;
}

void Korisnik::setBodovi(double b){
    this->bodovi+=b;
}


double Korisnik::getBodovi(){
    return this->bodovi;
}

Korisnik::Korisnik(std::string u, std::string p, Vrsta v) {
    this->username=u;
    this->password=p;
    this->vrsta=v;
}

void Korisnik::setVrsta(Vrsta v){
    this->vrsta=v;
}

Vrsta  Korisnik::getVrsta(){
    return this->vrsta;
}

string &Korisnik::getUsername()  {
    return this->username;
}

string &Korisnik::getPassword()  {
    return this->password;
}

void Korisnik::setUsername() {
    cout << "Unesite username: ";
    cin >> this->username;
    cin.ignore();
}

void Korisnik::setPassword() {
    cout << "Unesite password: ";
    cin >> this->password;
    cin.ignore();
}
