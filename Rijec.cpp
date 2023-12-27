//
// Created by DT User on 27/12/2023.
//

#include "Rijec.h"

Rijec::Rijec() {
    this->sakrivenaRijec = "";
    this->rijec_pog = "";
}

Rijec::Rijec(string rijec) {
    this->rijec_pog = rijec;
    this->sakrivenaRijec = string(rijec.size(), '_');
}

vector<Korisnik>& Rijec::getKorisnici(){
    return this->korisnici;
}