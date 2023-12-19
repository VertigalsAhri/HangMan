//
// Created by User on 16-Dec-23.
//

#include <iostream>
#include <cstring>
#include <string>
#include "Osoba.h"

using namespace std;

Osoba::Osoba() {
    this->ime="Neko";
    this->prezime="Drugi";
}

Osoba::Osoba(std::string i, std::string p) {
    this->ime=i;
    this->prezime=p;
}

string Osoba::getIme() {
    return this->ime;
}

string Osoba::getPrezime() {
    return this->prezime;
}

void Osoba::setIme() {
    cout << "Unesite ime: ";
    cin >> this->ime;
}

void Osoba::setPrezime() {
    cout << "Unesite prezime: ";
    cin >> this->prezime;
}