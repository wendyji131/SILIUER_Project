//
// Created by wendyji on 12/6/18.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include "UI.h"
using namespace std;

namespace UI{
    void displayMainMenu(){
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
    }

    int makeChoice(){
        //player make choice
        cout << "\tEnter your choice: ";
        int choice;
        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3){
            cout << "\tYour choice is not valid!" << endl;
            cout << "\tPlease make a valid choice: ";
            cin >> choice;
        }
        return choice;
    }

}