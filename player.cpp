#include "../include/player.h"
#include "../include/game.h"
#include <string>
#include <iostream>
using namespace std;

player::player(){
    username_ = "";
    psd_ ="";
    //gender_ = '';
    //email_="X@X";
    does_pay_ = false;
    //login_date_ = "10/10/2018";
    highest_score_ = 0;
    scores_ = {};
}

player::player(string username, string psd){
        username_ = username;
        psd_ = psd;
        highest_score_ = 0;
        scores_ = {};
}

//player::~player(){}

string player::getUsername(){
    return username_;
}

string player::getPassword() {
    return psd_;
}

void player::changePassword(){
    psd_ = setPassword();
}

string player::setPassword(){
    string psw1, psw2;
    cout << endl;
    cout << "\tSet your password: ";
    cin >> psw1;
    while( !checkPassword(psw1) ) {
        cout << "\tSet your password: ";
        cin >> psw1;
    }

    cout << "\tRepeat your password: ";
    cin >> psw2;

    if (psw1 != psw2){
        cout << endl;
        cout << "\t\tDifferent Password!" << endl;
        return setPassword();
    }

    else
        return psw1;
}

bool player::checkPassword(string& psw){
    //check if the psd1 is combination of digits or letters
    for (int i=0; i<psw.length(); i++){
        if ( !isalnum(psw[i]) ){
            cout << endl;
            cout << "\nYour password should be combination of digits or letters!";
            cout << endl ;
            cout << "Please reset your password!";
            cout << endl;
            return 0;
        }
    }
    //check if the length of psd1 is 8
    while (psw.length()!= 8){
        cout << "\nThe length of the password should be 8!";
        cout << endl;
        cout << "Please reset your password!";
        cout << endl << endl;
        return 0;

    }
    return 1;
}

void player::printPlayerInfo() {
    cout << "\tUsername:      " << username_ << endl;
    cout << "\tEmail Address: " << email_ << endl;
    cout << "\tHighest Score: " << getHighestScore() << endl;
}

void player::printScores(){
    cout << endl << "\tYour scores are: :" << endl;
    for (int i=scores_.size()-1; i>=0; i--){
        cout << scores_.at(i) << endl;
    }
    cout << endl;
}

int player::getHighestScore(){
    int max =scores_[0];
    for (int i=0; i<scores_.size(); i++){
        if (scores_[0]>max)
            max = scores_[0];
    }
    return max;
}


/*
 main(){}
 */
