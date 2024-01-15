//
// Created by User on 15-Jan-24.
//

#ifndef HANGMAN_TRIAL_H
#define HANGMAN_TRIAL_H


#include "Rijec.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

class Trial:public Rijec {
private:
    string rijec_pog;
    string sakrivenaRijec;
    vector<char> slova;
    double bodovi;
public:
    Trial(string rijec);

    double getBodovi();

    bool pobjeda();

    void Pogadjanje(int);

    ~Trial()=default;

};



#endif //HANGMAN_TRIAL_H
