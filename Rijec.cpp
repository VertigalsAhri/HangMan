//
// Created by DT User on 27/12/2023.
//
#include "Rijec.h"
Rijec::Rijec() {
    this->sakrivenaRijec = "";
    this->rijec_pog = "";
}

Rijec::Rijec(string rijec, vector<Korisnik> prosljedjeni) {
    this->rijec_pog = rijec;
    this->sakrivenaRijec = string(rijec.size(), '_');
    for(int i=0; i<prosljedjeni.size()-4; i++){
        this->getKorisnici().push_back(prosljedjeni[i]);
    }
}

bool Rijec::Pobjeda() {
    return this->sakrivenaRijec == this->rijec_pog;
}

vector<Korisnik>& Rijec::getKorisnici(){
    return this->korisnici;
}

void  Rijec::Pogadjanje(int a) {
    for (char slovo = 'A'; slovo <= 'Z'; ++slovo) {
        slova.push_back(slovo);
    }
    while (this->Pobjeda() == false) {
        try{
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
                this->korisnici[a]++;
            }else{
                this->korisnici[a]--;
                throw slovo;
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
        }catch(char s){
            cout<< endl << "\t\tTo slovo nije dio rijeci koju trebate pogoditi. Pokusajte ponovo!" <<endl << endl;
        }

    }
    system("CLS");
    if(Pobjeda()== true){
        cout<<"\t\tPogodili ste rijec "<<rijec_pog<<endl;
        cout << "\t\tOsvojili ste " << korisnici[a].getBodovi() << " bodova!" << endl;
    }


}
