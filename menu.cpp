#include <iostream>
#include <string>
#include <cctype>
#include"../include/player.h"
#include "../include/game.h"
#include "../include/rand.h"
#include <fstream>
#include <unistd.h>
#include <sstream>
#include <vector>
#include <memory>
#include <set>
#include <map>

#define SPEED 500000
#define PENAL_SIZE (17*24*sizeof(int))
#define CUBE_SIZE (3*3*sizeof(int))


using namespace std;

unsigned long line_num = 0;

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
void* listenKey(void *ptr);
void startPlay();

pthread_mutex_t	mutex_lock;
int num = 0;
static int stop_flag;
static Rand r;
Game g;
player player1;

//-----------------new------------
class QueryResult;
std::ostream& print(std::ostream& os, const QueryResult &qr);


class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream& );
    QueryResult query(const std::string& ) const;
private:
    std::shared_ptr<std::vector<std::string> > file;
    std::map<std::string, std::shared_ptr<std::set<line_no> > > wm;
};


TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
    std::string text;

    while (std::getline(is, text)) {

        file->push_back(text);
        auto n = file->size() - 1;
        std::istringstream line(text);
        std::string word;

        while (line >> word) {
            auto& lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}


class QueryResult {
    friend std::ostream& print (std::ostream&, const QueryResult& );
public:
    using line_no = std::vector<std::string>::size_type;

    QueryResult (std::string s,
                 std::shared_ptr<std::set<line_no>> p,
                 std::shared_ptr<std::vector<std::string>> f) :
            sought(s), lines(p), file(f) {}

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


QueryResult TextQuery::query(const std::string& sought) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(sought);

    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
};


std::string make_plural (std::size_t ctr, const std::string& word, const std::string ending) {
    return (ctr > 1) ? word + ending : word;
}

std::ostream& print(std::ostream& os, const QueryResult &qr) {

    for(auto num : *qr.lines) {
        line_num = num + 1;
    }
    return os;
}


void runQueries (std::ifstream &infile) {
    TextQuery tq(infile);

    cout << "\n\tEnter your user name: ";
    std::string s;

    cin >> s;

    print(std::cout, tq.query(s)) << std::endl;

}
//-----------------end------------



//-----------------new------------
int CountLines(char *filename) {
    ifstream outFile;
    int n = 0;
    string tmp;
    outFile.open(filename, ios::in);

    if(outFile.fail()) {
        return 0;
    }
    else
    {
        while(getline(outFile, tmp)) {
            n++;
        }
        outFile.close();

        return n;
    }
}

string ReadLine(char *filename, int line)
{
    int lines, i=0;
    string temp;
    fstream outfile;
    outfile.open(filename, ios::in);
    lines=CountLines(filename);

    while(getline(outfile, temp) && i < line-1) {
        i++;
    }
    outfile.close();
    return temp;
}

//-----------------end------------



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
    string db_psd = "25:=<961";
    switch(choice){
        case 1:
            //LoginMenu

            //-----------------new------------
        {
            cout << "******************Login******************";

            ifstream infile;
            infile.open("private.txt");
            runQueries(infile);
            infile.close();

            if (line_num == 0) {
                cout << "You need to register first!" << endl;
                mainMenu();

            } else {
                string psd_intxt;

                do {
                    cout << "\tEnter your password (type 'mainmenu' back to main menu): ";
                    cin >> psd_login;
                    if (psd_login == "mainmenu") {
                        mainMenu();
                    }

                    char filename[20] = "private.txt";


                    psd_intxt = ReadLine(filename, line_num + 1);

                    //此处添加解密算法对于 string psd_intxt.
                    //check database if the password is correct
                    psd_intxt = decode(psd_intxt);
                    /*while(psd_login != decode(db_psd)){
                        cout << "\tWrong Password! " << endl;
                        cout << "\tEnter your password: ";
                        cin >> psd_login;

                    }

                    if (psd_login == decode(db_psd)){
                        gameMenu();
                    }

                    */
                    if (psd_login != psd_intxt) {
                        cout << "Wrong password!!" << endl;
                    }

                } while (psd_login != psd_intxt);

                line_num = 0;
                gameMenu();

            }
        }
            //-----------------end------------



            //check database if the password is correct
//            while(psd_login != decode(db_psd)){
//                cout << "\tWrong Password! " << endl;
//                cout << "\tEnter your password: ";
//                cin >> psd_login;
//
//            }
//
//            if (psd_login == decode(db_psd)){
//                gameMenu();
//            }

            break;

        case 2:
            //registerMenu
            //set username
            cout << endl << endl;
            cout << "******************Register******************" << endl;
            cout << "-User Name should be combination of less than digits or letters.\n";

            //-----------------new------------
            //此处用户名长度已改为5
            {


                cout << "-The length of username should be 5.";
                name = setUsername(); //set username
                //cout << "Test username = " << name << endl;

                ifstream infile;
                infile.open("private.txt");
                runQueries(infile);
                infile.close();

                if (line_num != 0) {
                    cout << "username already exists, please change your username!" << endl;
                    line_num = 0;

                    cout << "-The length of username should be 5.";
                    name = setUsername(); //set username
                    cout << "Test username = " << name << endl;

                    ifstream infile;
                    infile.open("private.txt");
                    runQueries(infile);
                    infile.close();

                    if (line_num != 0) {
                        cout << "username already exists, please change your username!" << endl;
                        line_num = 0;
                        cout << "-The length of username should be 5.";
                        name = setUsername(); //set username
                        cout << "Test username = " << name << endl;

                    }

                }



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


                line_num = 0;
                gameMenu();
            }
            //-----------------end------------
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
            startPlay();
            gameMenu();
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
            cout << player1.getHighestScore() << endl;
            gameMenu();
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
    cout << "\tEnter your user name: ";
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
    //此处用户名长度已改为5
    while (name.length() != 5){
        cout << "The length of the username should be 5!";
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
    string todo = c;
    //cout << "Before decode, argument c= " << c << endl;
    //cout << "Before decode, todo = " << todo << endl;
    int a[] = {1, 3, 7, 9, 8, 6, 4, 0};
    for(int i = 0, j = 0; todo[j];j++, i = (i + 1) % 8){

        todo[j]-=a[i];

        if(todo[j] < 32) todo[j] += 90;
    }
    //cout << "After decode, argument c= " << c << endl;
    //cout << "After decode " << todo << endl;
    return todo;
}



void* listenKey(void *ptr)
{
    Game* ptrg = (Game*)ptr;
    char key;
    while(1)
    {
        system("stty -icanon -echo");
        key = getchar();
        system("stty icanon echo");
        switch(key)
        {
            case 'a':
                ptrg->move(LEFT);break;
            case 'd':
                ptrg->move(RIGHT);break;
            case 'w':
                ptrg->roll();break;
            case 's':
                //速降
                while(1)
                {
                    if(stop_flag == 1)
                    {
                        stop_flag = 0;
                        break;
                    }
                    ptrg->move(DOWN);
                }
                break;

            case 'p':
                if(GAME_RUN == ptrg->getMark())
                    ptrg->setMark(GAME_PAUSE);
                else ptrg->setMark(GAME_RUN);
                break;

            default:
                break;
        }
    }
}

void startPlay(){
    pthread_t t1;
    pthread_mutex_init(&mutex_lock, NULL);
    system("clear");
    //Game g;
    //g.createCube();
    g.gameInit();
    pthread_create(&t1, NULL, listenKey, (void *) (&g));

    while (1) {
        fflush(stdout);
        usleep(SPEED);
        g.move(DOWN);
    }
}

/*

#include <iostream>
#include <string>
#include <cctype>
#include"../include/player.h"
#include "../include/game.h"
#include "../include/rand.h"
#include <fstream>
#include <unistd.h>

#define SPEED 500000
#define PENAL_SIZE (17*24*sizeof(int))
#define CUBE_SIZE (3*3*sizeof(int))
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
void* listenKey(void *ptr);
void startPlay();

pthread_mutex_t	mutex_lock;
int num = 0;
static int stop_flag;
static Rand r;
Game g;


int main(){
    //startPlay();
    mainMenu();

    return 0;
}


void mainMenu(){
    //startPlay();
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
    string db_psd = "25:=<961";
    switch(choice){
        case 1:
            //LoginMenu
            cout << "******************Login******************";
            cout << "\n\tEnter your user name: ";
            cin >> name_login;
            ///////////////////////////////////////
            //check database if the user name exists
            //assume the username exists
            //decode
            cout << "\tEnter your password: ";
            cin >> psd_login;

            //check database if the password is correct
            while(psd_login != decode(db_psd)){
                cout << "\tWrong Password! " << endl;
                cout << "\tEnter your password: ";
                cin >> psd_login;

            }

            if (psd_login == decode(db_psd)){
                gameMenu();
            }

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
            cout << "Keep Trying" << endl;
            startPlay();
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
            purchase();
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
    string todo = c;
    //cout << "Before decode, argument c= " << c << endl;
    //cout << "Before decode, todo = " << todo << endl;
    int a[] = {1, 3, 7, 9, 8, 6, 4, 0};
    for(int i = 0, j = 0; todo[j];j++, i = (i + 1) % 8){

        todo[j]-=a[i];

        if(todo[j] < 32) todo[j] += 90;
    }
    //cout << "After decode, argument c= " << c << endl;
    //cout << "After decode " << todo << endl;
    return todo;
}

void* listenKey(void *ptr)
{
    Game* ptrg = (Game*)ptr;
    char key;
    while(1)
    {
        system("stty -icanon -echo");
        key = getchar();
        system("stty icanon echo");
        switch(key)
        {
            case 'a':
                ptrg->move(LEFT);break;
            case 'd':
                ptrg->move(RIGHT);break;
            case 'w':
                ptrg->roll();break;
            case 's':
                //速降
                while(1)
                {
                    if(stop_flag == 1)
                    {
                        stop_flag = 0;
                        break;
                    }
                    ptrg->move(DOWN);
                }
                break;

            case 'p':
                if(GAME_RUN == ptrg->getMark())
                    ptrg->setMark(GAME_PAUSE);
                else ptrg->setMark(GAME_RUN);
                break;

            default:
                break;
        }
    }
}

void startPlay(){
    pthread_t t1;
    pthread_mutex_init(&mutex_lock, NULL);
    system("clear");
    //Game g;
    //g.createCube();
    g.gameInit();
    pthread_create(&t1, NULL, listenKey, (void *) (&g));


    while (1) {
        fflush(stdout);
        usleep(SPEED);
        g.move(DOWN);
    }
}
*/