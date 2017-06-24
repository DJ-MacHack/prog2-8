//
// Created by DJ_MacHack on 23.06.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "cppreader.h"

using namespace std;

cppreader::cppreader(int args, char *argv[]) {
    this->args = argv;
    this->docs = args;
}

int cppreader::countlines() {
    for (int i = 1; i < this->docs; i++) {
        this->lines = this->comments = this->digits = this->minors = this->capitals = 0;
        std::ifstream inFile(this->args[i]);
        std::string input = "";
        if (inFile.is_open()) {
            while (getline(inFile, input)) {
                this->lines++;
                this->countcommentlines(input);
                for(int j = 0; j < input.size(); j++) {
                    this->countCapitals(input.at(j));
                    this->countDigits(input.at(j));
                    this->countMinors(input.at(j));
                }
            }
            inFile.close();
        } else {
            std::cout << "Datei kann nicht geoeffnet werden!" << std::endl;
        }
        //if (input.find("//") != std::string::npos) {   //Ausgabe von find wenn nichts gefunden wird
        std::cout << "File: " << this->args[i] << std::endl;
        std::cout << "Lines: " << this->lines << std::endl;
        std::cout << "Comment lines: " << this->comments << std::endl;
        double perc = this->calcPercentage() * 100;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        std::cout << "Percentage: " << perc << "%" << std::endl;
        std::cout << "Capitals : " << this->capitals << std::endl;
        std::cout << "Minors: " << this->minors << std::endl;
        std::cout << "Digits: " << this->digits << std::endl;
        std::cout << std::endl;
    }
}


void cppreader::countcommentlines(std::string input) {
    if (input.size() < 2) {
        return;
    }
    if (input.at(0) == '/' && input.at(1) == '/') {
        this->comments++;
    } else {
        if (input.at(0) == '/' && input.at(1) == '*') {
            this->comments++;
        } else {
            if (input.at(0) == '*' && input.at(1) == '/') {
                this->comments++;
            }
        }
    }
}

double cppreader::calcPercentage() {
    return (static_cast<double>(this->comments) / static_cast<double>(this->lines));
}

void cppreader::countCapitals(char input) {
    int ascii = toASCII(input);
    if (ascii > 65 && ascii < 91) {
            this->capitals++;
    }
}

void cppreader::countMinors(char input) {
    int ascii = toASCII(input);
    if (ascii > 96 && ascii < 123) {
            this->minors++;
    }
}

void cppreader::countDigits(char input) {
    int ascii = toASCII(input);
    if (ascii > 47 && ascii < 58) {
            this->digits++;
    }
}

int cppreader::toASCII(char c) {
    return static_cast<int>(c);
}
