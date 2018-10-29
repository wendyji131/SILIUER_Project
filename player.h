#ifndef PLAYER_H_
#define PLAYER_H_

#define TRUE 1
#define FALSE 0

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class player{
public:
    player();
    player(string username, string psd);
    //~player();

    string getUsername();
    string getPassword();
    void changePassword();
    string setPassword();
    bool checkPassword(string& psw);
    void printPlayerInfo();
    void printScores();
    int getHighestScore();

private:
    string username_;
    string psd_;
    //char gender_;
    //string email_;
    bool does_pay_;
    //string login_date_;
    int highest_score_;
    vector<int> scores_;
};

#endif
