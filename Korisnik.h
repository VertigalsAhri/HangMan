//
// Created by DT User on 20/12/2023.
//

#ifndef HANGMAN_KORISNIK_H
#define HANGMAN_KORISNIK_H
#include <iostream>
#include <vector>
#include "Osoba.h"
using namespace std;

enum Vrsta{korisnik=0, admin};

class Korisnik:public Osoba {
private:
    string username, password;
    Vrsta vrsta;
    double bodovi;
public:
    Korisnik(){};
    Korisnik(string i, string prez, string u, string p, Vrsta v, double b) : Osoba(i, prez), username(u), password(p), vrsta(v) , bodovi(b){
        this->username=u;
        this->password=p;
        this->vrsta=v;
        this->bodovi=b;
    }
    Korisnik(string u, string p, Vrsta v);

    void setBodovi(double b);

    void SETBodovi(double b){
        this->bodovi=b;
    }
    double getBodovi();

    void setVrsta(Vrsta v);

    void setUsername();
    void setPassword();
    friend std::istream& operator>>(std::istream& stream, Korisnik &k);
    friend std::ostream& operator<<(std::ostream& stream, Korisnik &k);

    string &getUsername();
    string &getPassword();
    Vrsta getVrsta();

    ~Korisnik()=default;
};


#endif //HANGMAN_KORISNIK_H
