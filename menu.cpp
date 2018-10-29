#include <iostream>
#include <string>
#include <cctype>
#include"../include/player.h"
#include "../include/game.h"
#include "../include/rand.h"
#include <fstream>
using namespace std;

void mainMenu();
void gameMenu();
string setPassword();
string setUsername();
bool checkPassword(string& psw);
void save_to_Txt(std::string playerinfo);
void purchase();
void getpay();
void save_to_bank(string pay_info);
string encryption(string& c);
string decode(string& c);

//player player1;

int main(){
    mainMenu();

    return 0;
}

void mainMenu(){
    cout << endl << endl;
    cout << "*****************************************" << endl;
    cout << "******Welcome To Tetris Game System******" << endl;
    cout << "*****************************************" << endl;
    cout << endl << endl;
    cout << "          Login    (1)" << endl;
    cout << "          Register (2)" << endl;
    cout << "          Exit     (3)" << endl;
    cout << endl;
    cout << endl;
    cout << "\tEnter your choice: ";
    int choice;
    cin >> choice;
    //check choice is legal or not
    while (choice != 1 && choice != 2 && choice != 3){
        cout << "\tYour choice is not valid!" << endl;
        cout << "\tPlease make a valid choice: ";
        cin >> choice;
    }
    string name_login, psd_login, name, psd;
    string new_psd;

    switch(choice){
        case 1:
            //LoginMenu
            cout << "*****************************************" << endl;
            cout << "\tEnter your user name: ";
            cin >> name_login;
            //check database if the user name exists


            cout << "\tEnter your password: ";
            cin >> psd_login;
            //check database if the password is correct

            gameMenu();

            break;
        case 2:
            //registerMenu
            //set username
            cout << endl << endl;
            cout << "******************Register******************" << endl;
            cout << "-User Name should be combination of less than digits or letters.\n";
            cout << "-The length of username should be 3 to 8.";
            name = setUsername(); //set username
            cout << "Test username = " << name << endl;
            //
            //check if the username is used by the other user or not
            //
            cout << "\n-Password should be combination of 8 digits or letters";
            psd = setPassword();   //set password

            //encryption password
            //int a[] = {1, 3, 7, 9, 8, 6, 4, 0};
            new_psd = encryption(psd);

            //save user name and password to database
            save_to_Txt(name);
            save_to_Txt(new_psd);

            gameMenu();

            break;
        case 3:
            //Exit

            break;
    }
}

void gameMenu(){
    cout << endl << endl;
    cout << "*****************************************" << endl;
    cout << "******************TETRIS******************" << endl;
    cout << "*****************************************" << endl;
    cout << endl << endl;
    cout << "          Play Game            (1)" << endl;
    cout << "          Game Instructions    (2)" << endl;
    cout << "          High Score           (3)" << endl;
    cout << "          Purchase             (4)" << endl;
    cout << "          Exit                 (5)" << endl;
    cout << endl;
    cout << endl;
    cout << "\tEnter your choice: ";

    int choice;
    cin >> choice;

    //check choice is legal or not
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
        cout << "\tYour choice is not valid!" << endl;
        cout << "\tPlease make a valid choice: ";
        cin >> choice;
    }

    switch(choice){
        case 1:
            //Play Game
            //Game g;
            //g.playGame();
            break;
        case 2:
            //Game Instructions
            cout << endl << endl;
            cout << "*****************************************" << endl;
            cout << "************Game Instructions************" << endl;
            cout << "*****************************************" << endl;
            cout << endl << endl;
            cout << "\tPress W to rotate\n";
            cout << "\tPress A to move left\n";
            cout << "\tPress D to move right\n";
            cout << "\tPress S to speed down\n";
            cout << "\tPress P to pause game\n";
            gameMenu();
            break;
        case 3:
            //High Score
            cout << endl << endl;
            cout << "*****************************************" << endl;
            cout << "**************Highest Score**************" << endl;
            cout << "*****************************************" << endl;
            cout << endl << endl;
            cout << "\tYour highest score is: ";
            //cout << player.getScore() << endl;
            //gameMenu();
            break;
        case 4:
            //Purchase
            purchase();
            //getpay();
            //save_to_bank(pay_info);

            break;
        case 5:
            //Exit
            break;
    }
}

string setUsername(){
    string name;

    cout << endl << endl;
    cout << "\tSet your user name: ";
    cin >> name;
    for (int i=0; i<name.length(); i++){
        if ( !isalnum(name[i]) ){
            cout << endl;
            cout << "Your username should be combination of digits or letters!";
            cout << endl ;
            cout << "Please reset your username!";
            cout << endl;
            setUsername();
            break;
        }
    }

    while (name.length()< 3 or name.length()>8){
        cout << "The length of the username should be 3 to 8!";
        cout << endl;
        cout << "Please reset your username!";
        cout << endl << endl;
        return setUsername();
    }

    return name;
}


string setPassword(){
    string psw1, psw2;
    cout << endl;
    cout << "\tSet your password: ";
    cin >> psw1;
    while(!checkPassword(psw1)) {
        cout << "\tSet your password: ";
        cin >> psw1;
    }

    cout << "\tRepeat your password: ";
    cin >> psw2;
    //cout << "psw1=" << psw1 << endl;
    //cout << "psw2=" << psw2 << endl;
    if (psw1==psw2){
        return psw1;
    }
    else{
        cout << endl;
        cout << "\t\tDifferent Password!" << endl;
        return setPassword();
    }
}

bool checkPassword(string& psw){
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

void save_to_Txt(std::string playerinfo) {
    //save user's infomation to text file
    std::ofstream outFile;
    outFile.open("private.txt",std::ios::app);

    outFile << playerinfo;
    outFile << std::endl;

    outFile.close();

}


void purchase() {

    string pay_choice;

    cout << "*****************************************" << endl;
    cout << "Our game has 10 levels," << endl;
    cout << "the level will automaticallyy increase when you reach a certain point of the score." << endl;
    cout << "Free to play, you could only has 1 to 3 levels," << endl;
    cout << "if a player want to unlock the rest of levels(4 to 10), he or she could purchase it(5 USD)." << endl;
    cout << "Pay for more fun!" << endl << endl;

    do {
        cout << "Do you want to unlock new levels? yes/no: ";
        cin >> pay_choice;
    } while (pay_choice != "yes" && pay_choice != "no");

    if (pay_choice == "yes") {
        getpay();
    } else {
        gameMenu();
    }

}

void getpay() {

    string cardholder;
    string cardnum;
    string securitynum;
    string month_year;

    cout << "*****************************************" << endl;
    cout << "Please input your pay card infomation" << endl;
    cout << "You could type 'exit' back to game menu" << endl << endl;

    cout << "cardholder name: ";
    cin >> cardholder;
    if (cardholder == "exit") {
        gameMenu();
    }

    cout << "card number: ";
    cin >> cardnum;
    if (cardnum == "exit") {
        gameMenu();
    }

    cout << "security number: ";
    cin >> securitynum;
    if (securitynum == "exit") {
        gameMenu();
    }

    cout << "valid month/year (such as: 08/21): ";
    cin >> month_year;
    if (month_year == "exit") {
        gameMenu();
    }

    save_to_bank(cardholder);
    save_to_bank(cardnum);
    save_to_bank(securitynum);
    save_to_bank(month_year);

    cout << endl << "Congratulations! You just got new game levels!" << endl;

    gameMenu();

}

void save_to_bank(string pay_info) {

    std::ofstream outFile;
    outFile.open("bank.txt",std::ios::app);

    outFile << pay_info;
    outFile << std::endl;

    outFile.close();

}

string encryption(string& c){
    int a[] = {1, 3, 7, 9, 8, 6, 4, 0};
    for(int i = 0, j = 0; c[j];j++, i = (i + 1) % 8){

        c[j]+=a[i];

        if(c[j] > 122) c[j] -= 90;
    }
    return c;
}

string decode(string& c){
    int a[] = {1, 3, 7, 9, 8, 6, 4, 0};
    for(int i = 0, j = 0; c[j];j++, i = (i + 1) % 8){

        c[j]-=a[i];

        if(c[j] < 32) c[j] += 90;
    }
    return c;
}
