
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
