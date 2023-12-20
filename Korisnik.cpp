//
// Created by DT User on 20/12/2023.
//

#include "Korisnik.h"

string &Korisnik::getUsername()  {
    return this->username;
}

 string &Korisnik::getPassword()  {
    return this->password;
}

void Korisnik::setUsername() {
    cout << "Unesite username: ";
    cin >> this->username;
}

void Korisnik::setPassword() {
    cout << "Unesite password: ";
    cin >> this->password;
}
