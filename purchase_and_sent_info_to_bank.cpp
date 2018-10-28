#include <iostream>
#include <string>

#include <fstream>

using namespace std;

void mainMenu();
void gameMenu();
void checkPassword(string psw);
void checkUsername(string name);


void purchase();
void getpay();
void save_to_bank(string pay_info);

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
            cout << "\t\tEnter your user name: ";
            cin >> name_login;
            //checkUsername(name_login);
            
            cout << "\t\tEnter your password: ";
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
            cout << "Press P to pause game";
            gameMenu();
            break;
        case 3:
            //High Score
            break;
        case 4:
            //Purchase
            purchase();
            
            break;
        case 5:
            //Exit
            break;
    }
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
