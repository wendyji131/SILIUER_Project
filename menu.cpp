#include <iostream>
#include <string>
#include "playerInfo.h"
#include <cctype>
using namespace std;

playerInfo player;

void mainMenu();
void gameMenu();
string setPassword();
string setUsername();
bool checkPassword(string& psw);

int main()
{
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
            //
            //check if the username is used by the other user or not
            //
            cout << "\n-Password should be combination of 8 digits or letters";
            psd = setPassword();   //set password

            player.setUsername(name);
            player.setPassword(psd);
            /*****************************************************/
            //save user's information
            /*****************************************************/
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
            cout << player.getScore() << endl;
            gameMenu();
            break;
        case 4:
            //Purchase

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
        setUsername();
        break;
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
    cout << "psw1=" << psw1 << endl;
    cout << "psw2=" << psw2 << endl;
    if (psw1==psw2){
        return psw1;
    }
    else{
        cout << endl;
        cout << "\t\tDifferent Password!" << endl;
        setPassword();

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
