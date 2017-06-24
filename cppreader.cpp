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

/**
 * constructor
 * @param args
 * @param argv
 */
cppreader::cppreader(int args, char *argv[]) {
    this->args = argv;
    this->docs = args;
}

/**
 * countlines and runs every other counter
 * @return
 */
void cppreader::countlines() {
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
        this->writeConsole(i);
    }
}

/**
 * count comments
 * @param input
 */
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

/**
 * calcs percentage comment/lines
 * @return
 */
double cppreader::calcPercentage() {
    return (static_cast<double>(this->comments) / static_cast<double>(this->lines));
}

/**
 * counts capitals
 * @param input
 */
void cppreader::countCapitals(char input) {
    int ascii = toASCII(input);
    if (ascii > 65 && ascii < 91) {
            this->capitals++;
    }
}

/**
 * counts minors
 * @param input
 */
void cppreader::countMinors(char input) {
    int ascii = toASCII(input);
    if (ascii > 96 && ascii < 123) {
            this->minors++;
    }
}

/**
 * counts digits
 * @param input
 */
void cppreader::countDigits(char input) {
    int ascii = toASCII(input);
    if (ascii > 47 && ascii < 58) {
            this->digits++;
    }
}

/**
 * from char to ASCII
 * @param c
 * @return
 */
int cppreader::toASCII(char c) {
    return static_cast<int>(c);
}

/**
 * prints formatted output
 */
void cppreader::writeConsole(int i) {
    const char separator    = ' ';
    const int nameWidth     = 20;
    std::cout << left << setw(nameWidth) << setfill(separator) << "File:";
    std::cout<< left << setw(nameWidth) << setfill(separator) << this->args[i];
    cout << endl;
    std::cout << left << setw(nameWidth) << setfill(separator) << "Lines: ";
    cout << left << setw(nameWidth) << setfill(separator) << this->lines;
    cout << endl;
    std::cout << left << setw(nameWidth) << setfill(separator) << "Comment lines: ";
    cout << left << setw(nameWidth) << setfill(separator) << this->comments;
    cout << std::endl;
    double perc = this->calcPercentage() * 100;
    std::cout << left << setw(nameWidth) << setfill(separator) << "Percentage: ";
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    cout << left  << perc << "%";
    cout << std::endl;
    std::cout << left << setw(nameWidth) << setfill(separator) << "Capitals : ";
    cout << left << setw(nameWidth) << setfill(separator)<< this->capitals;
    cout << std::endl;
    std::cout << left << setw(nameWidth) << setfill(separator) << "Minors: ";
    cout << left << setw(nameWidth) << setfill(separator) << this->minors;
    cout << std::endl;
    std::cout << left << setw(nameWidth) << setfill(separator) << "Digits: ";
    cout << left << setw(nameWidth) << setfill(separator) << this->digits << std::endl;
    std::cout << std::endl;
}
