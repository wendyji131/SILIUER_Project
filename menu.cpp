#include <iostream>
#include <string>

using namespace std;

void mainMenu();
void gameMenu();
void checkPassword(string psw);
void checkUsername(string name);

int main()
{
    mainMenu();
    return 0;
}

void checkPassword(string psw){}
void checkUsername(string name){}

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
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    //check choice is legal or not
    while (choice != 1 && choice != 2 && choice != 3){
        cout << "Your choice is not valid!" << endl;
        cout << "Please make a valid choice: ";
        cin >> choice;
    }
    string name_login, name, psd, psd1, psd2;

    switch(choice){
        case 1:
            //LoginMenu
            cout << "*****************************************" << endl;
            cout << "\t\tEnter your user name: " << endl;
            cin >> name_login;
            //checkUsername(name_login);

            cout << "\t\tEnter your password: " << endl;
            cin >> psd;
            checkPassword(psd);

            gameMenu();

            break;
        case 2:
            //registerMenu
            //set username
            //tring name, password1, password2;
            cout << "*****************************************" << endl;
            cout << "\t\t-User Name should be combination of less than 8 digits or letters";
            cout << endl;
            cout << "\t\tSet your user name: ";

            cin >> name;
            /*****************************************************/
            //check if the username is used by the other user or not
            /*****************************************************/
            //checkUsername(name);

            //set password
            cout << endl;
            cout << "\t\t-Password should be combination of 8 digits or letters";
            cout << endl;

            cout << "\t\tSet your password: ";
            cin >> psd1;
            checkUsername(name);
            cout << "\t\t-Repeat your password:";
            cin >> psd2;

            while (psd1 != psd2) {
                cout << endl;
                cout << "\t\tDifferent Password!" << endl;

                cout << "\t\tSet your password: ";
                cin >> psd1;
                checkUsername(name);
                cout << "\t\t-Repeat your password:";
                cin >> psd2;
            }

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
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    //check choice is legal or not
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
        cout << "Your choice is not valid!" << endl;
        cout << "Please make a valid choice: ";
        cin >> choice;
    }

    switch(choice){
        case 1:
            //Play Game

            break;
        case 2:
            //Game Instructions
            cout << "Press W to rotate\n";
            cout << "Press A to move left\n";
            cout << "Press D to move right\n";
            cout << "Press S to speed down\n";
            cout << "Press P to pause game\n";
            gameMenu();
            break;
        case 3:
            //High Score

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


