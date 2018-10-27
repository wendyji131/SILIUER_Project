#include <iostream>
#include <fstream>
#include <string>
int pid = 3104422; //user ID


void save_to_Txt(std::string playerinfo) {
    //save user's infomation to text file
    std::ofstream outFile;
    outFile.open("private.txt",std::ios::app);
    
    outFile << playerinfo;
    outFile << std::endl;
    
    outFile.close();
    
}


void save_pid_toTxt() {
    //save user's ID to text file
    std::ofstream outFile;
    outFile.open("private.txt",std::ios::app);
    
    outFile << pid << ".";
    outFile << std::endl;
    
}


int main() {
    //test
    std::string name, password;
    std::cout << "Please input your name: ";
    std::cin >> name;
    std::cout << "Please input your passward: ";
    std::cin >> password;
    
    save_pid_toTxt();
    
    save_to_Txt(name);
    save_to_Txt(password);
    
    return 0;
}


