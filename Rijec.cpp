//
// Created by DT User on 27/12/2023.
//

#include "Rijec.h"

Rijec::Rijec() {
    this->sakrivenaRijec = "";
    this->rijec_pog = "";
}

Rijec::Rijec(string rijec,vector<Korisnik> prosljedjeni) {
    this->rijec_pog = rijec;
    this->sakrivenaRijec = string(rijec.size(), '_');
    for(auto i:prosljedjeni){
        this->getKorisnici().push_back(i);
    }
}

vector<Korisnik>& Rijec::getKorisnici(){
    return this->korisnici;
}

vector<Korisnik>&  Rijec::Pogadjanje(int i) {
    for (char slovo = 'A'; slovo <= 'Z'; ++slovo) {
        slova.push_back(slovo);
    }
    while (this->Pobjeda() == false) {

        cout << this->sakrivenaRijec << endl << endl << endl;
        for (int i = 0; i < slova.size(); i++) {
            cout << slova[i] << " ";
        }

        char slovo;
        cout << endl;
        cout << "Unesite slovo za pogadanje:";
        cin >> slovo;
        cout << endl;
        slovo = toupper(slovo);
        bool nadjeno=false;

        for (int i = 0; i < this->rijec_pog.length(); i++) {
            if (this->rijec_pog[i] == slovo) {
                this->sakrivenaRijec[i] = slovo;
                nadjeno=true;
                system("CLS");

            }
        }
        if(nadjeno){
            korisnici[i].setBodovi(0.2);
        }else{
            korisnici[i].setBodovi(-0.1);
        }

        for (int i = 0; i < slova.size(); i++) {
            if (slovo == slova[i]) {
                slova[i] = ' ';
                //system("pause");
                _sleep(500);
                break;
            }
            system("CLS");
        }
    }
    system("CLS");
    if(Pobjeda()== true){
        cout<<"Pogodili ste rijec "<<rijec_pog<<endl;
    }

    return korisnici;
}
