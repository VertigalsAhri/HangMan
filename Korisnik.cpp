#include <iostream>

#include "Korisnik.h"

#include <iomanip>


std::istream& operator>>(std::istream& stream, Korisnik &k){

    k.setIme();
    k.setPrezime();
    return stream;

}


std::ostream& operator<<(std::ostream& izlaz, Korisnik &k){

    izlaz << std::left << setw(20)<< k.getIme() << std::left << setw(20) << k.getPrezime() << std::left << setw(20) << k.getUsername() << std::left << setw(20) << k.getBodovi()<< std::left << setw(20)  ;
    return izlaz;

}


void Korisnik::ispis() {

    cout << std::left << setw(20) <<this->getIme() << std::left << setw(20)  << this->getPrezime() << std::left << setw(20) << this->getUsername() << std::left << setw(20) << this->getBodovi();

}


double Korisnik::getBodovi(){

    return this->bodovi;

}


void Korisnik::SETBodovi(){

    this->bodovi=0;

}


void Korisnik::setBodovi(double x){

    this->bodovi=x;

}


void Korisnik::operator++(int){

    this->bodovi+=2;

}


void Korisnik::operator--(int){

    this->bodovi+=0.5;

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
