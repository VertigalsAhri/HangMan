//
// Created by User on 15-Jan-24.
//

#include "Trial.h"

Trial::Trial(string rijec){
    this->rijec_pog = rijec;
    this->sakrivenaRijec = string(rijec.size(), '_');
}

double Trial::getBodovi(){
    return this->bodovi;
}

bool Trial::pobjeda(){
    return this->sakrivenaRijec == this->rijec_pog;
}

void  Trial::Pogadjanje(int) {
    for (char slovo = 'A'; slovo <= 'Z'; ++slovo) {
        slova.push_back(slovo);
    }
    while (this->pobjeda() == false) {
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
                this->bodovi+=2;
            }else{
                this->bodovi-=0.5;
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
    if(pobjeda()== true){
        cout<<"\t\tPogodili ste rijec "<<rijec_pog<<endl;
        cout << "\t\tOsvojili ste " << this->getBodovi() << " bodova! " << endl;
    }


}