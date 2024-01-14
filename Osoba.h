//
// Created by User on 16-Dec-23.
//

#ifndef HANGMAN_KORISNIK_H
#define HANGMAN_KORISNIK_H


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Osoba {
protected:
    string ime, prezime;
public:
    Osoba();
    Osoba(string i, string p);
    void setIme();
    void setPrezime();
    string getIme();
    string getPrezime();
    virtual void ispis();
    ~Osoba(){};
};


#endif //HANGMAN_KORISNIK_H
