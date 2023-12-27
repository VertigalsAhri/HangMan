//
// Created by User on 16-Dec-23.
//

#ifndef KVIZ_OSOBA_H
#define KVIZ_OSOBA_H

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
    virtual string getIme();
    virtual string getPrezime();
    ~Osoba(){};
};



#endif //KVIZ_OSOBA_H
