#include <iostream>

namespace UI {
    void launch() {
        
        //display mainMenu
        std::cout << std::endl << std::endl;
        std::cout << "*****************************************" << std::endl;
        std::cout << "******Welcome To Tetris Game System******" << std::endl;
        std::cout << "*****************************************" << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "          Login    (1)" << std::endl;
        std::cout << "          Register (2)" << std::endl;
        std::cout << "          Exit     (3)" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "\tEnter your choice: ";
        int choice;
        std::cin >> choice;
        
        while (choice < 1 || choice > 3){
            std::cout << "\tYour choice is not valid!" << std::endl;
            std::cout << "\tPlease make a valid choice: ";

            std::cin >> choice;
        }
        std::string name_login, psd_login, name, psd;
        std::string new_psd;
        
        //choice selection
        switch(choice){
            case 1:
            {
                std::cout << "******************Login******************" << std::endl;
                
//                ifstream infile;
//                infile.open("private.txt");
//                runQueries(infile);
//                infile.close();
//
//                if (line_num == 0) {
//                    std::cout << "You need register first!" << std::endl;
//                    mainMenu();
//
//                } else {
//                    string psd_intxt;
//
//                    do {
//                        std::cout << "\tEnter your password (type 'mainmenu' back to main menu): ";
//                        std::cin >> psd_login;
//                        if (psd_login == "mainmenu") {
//                            mainMenu();
//                        }
//
//                        char filename[20] = "private.txt";
//
//                        psd_intxt = know_line(filename, line_num + 1);
//
//                        psd_intxt = decode(psd_intxt);
//
//                        if (psd_login != psd_intxt) {
//                            std::cout << "Wrong password!!" << std::endl;
//                        }
//
//                    } while (psd_login != psd_intxt);
//
//                    line_num = 0;
//                    gameMenu();
//                }
            }
                break;
                
            case 2:
                
                std::cout << std::endl << std::endl;
                std::cout << "******************Register******************" << std::endl;
//                std::cout << "-User Name should be combination of less than digits or letters.\n";
//
//            {
//
//
//                std::cout << "-The length of username should be 5.";
//                name = setUsername();
//
//                ifstream infile;
//                infile.open("private.txt");
//                runQueries(infile);
//                infile.close();
//
//                if (line_num != 0) {
//                    std::cout << "username already exists, please change your username!" << std::endl;
//                    line_num = 0;
//
//                    std::cout << "-The length of username should be 5.";
//                    name = setUsername();
//
//                    ifstream infile;
//                    infile.open("private.txt");
//                    runQueries(infile);
//                    infile.close();
//
//                    if (line_num != 0) {
//                        std::cout << "username already exists, please change your username!" << std::endl;
//                        line_num = 0;
//                        std::cout << "-The length of username should be 5.";
//                        name = setUsername();
//
//                    }
//
//                }
//
//                std::cout << "\n-Password should be combination of 8 digits or letters";
//                psd = setPassword();
//
//                new_psd = encryption(psd);
//
//                save_to_Txt(name);
//                save_to_Txt(new_psd);
//
//
//                line_num = 0;
//                gameMenu();
//            }
                
                break;
                
            case 3:
                
                break;
        }
    }
}






int main() {
    
    UI::launch();
    
    
    
    
    
    
    
    
    return 0;
}
