//
// Created by DT User on 27/12/2023.
//

#ifndef HANGMAN_RIJEC_H
#define HANGMAN_RIJEC_H


#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "Korisnik.h"
using namespace std;



class Rijec {
private:
    string rijec_pog;
    string sakrivenaRijec;
    vector<char> slova;
    vector<Korisnik> korisnici;
public:
    Rijec();

    Rijec(string rijec);
    vector<Korisnik>& getKorisnici();
};


#endif //HANGMAN_RIJEC_H
