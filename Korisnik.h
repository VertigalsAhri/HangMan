//
// Created by DT User on 20/12/2023.
//

#ifndef HANGMAN_KORISNIK_H
#define HANGMAN_KORISNIK_H
#include "Osoba.h"
#include <iostream>
#include <cstring>
#include <string>

class Korisnik:public Osoba {
private:
    string username, password;
public:
    Korisnik();

    void setUsername();
    void setPassword();

    string &getUsername();
    string &getPassword();

    ~Korisnik();

};


#endif //HANGMAN_KORISNIK_H
