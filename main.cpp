#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "cppreader.h"
using namespace std;
/*
// comment me
// me 2
*/

/**
 * splits string with a special char
 * @param eingabe
 * @param sucher
 * @return ausgabe
 */
vector<string> split(string eingabe, char sucher) {
    vector<string> ausgabe;
    stringstream ss(eingabe); //string zu stream
    string token;
    string s(1, sucher);
    while(getline(ss, token, sucher)) {
        ausgabe.push_back(token);
        ausgabe.push_back(s);
    }
    ausgabe.pop_back(); //letzer string zu viel, deshalb muss es weg
    return ausgabe;
}

/**
 * prints my awesome credits
 */
void credits() {
    std::ifstream inFile ("credits.txt");
    std::string input = "";
    if (inFile.is_open()) {
        while (getline (inFile,input)) {
            if(input.find("Q") != std::string::npos){   //find does not find?
                std::vector<std::string> vector = split(input, 'Q');    //split
                int teile = vector.size();
                for(int i = 0; i < teile; i++){
                    if(vector.at(i)=="Q") {     //red Q
//                        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(handle, FOREGROUND_RED);
                        cout << "\x1B[40m\x1B[5m\x1B[31m" + vector.at(i);
                    } else {
//                        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
//                                                        FOREGROUND_BLUE);
                        cout << "\x1B[0m\x1B[40m\x1B[37m"+vector.at(i);
                    }
                }
                cout << endl;
            } else {
//                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN |
//                                                FOREGROUND_BLUE);
                std::cout << "\x1B[40m\x1B[37m"+input << std::endl;
            }
        }
        cout << "\x1B[0m" <<endl;
        inFile.close();
    } else {
        cout << "Datei credits.txt kann nicht geoeffnet werden!";
    }
}

/*
 * main method
*/
int main(int argc, char *argv[]) {
    cppreader reader(argc, argv);
    reader.countlines();
    credits();
    return 0;
}