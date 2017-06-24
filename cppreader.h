//
// Created by DJ_MacHack on 23.06.2017.
// Mtknr.: 374771
// mail@hendrik-haas.de
// Partner: Julian Bruna
//

#ifndef PROG2_8_CPPREADER_H
#define PROG2_8_CPPREADER_H


class cppreader {
public:
    cppreader(int args, char *argv[]);
    int countlines();
    void countcommentlines(std::string input);
    double calcPercentage();
    void countCapitals(char input);
    void countMinors(char input);
    void countDigits(char input);

private:
    char** args;
    int lines, comments, digits, capitals, minors, docs = 0;
    int toASCII(char c);
};


#endif //PROG2_8_CPPREADER_H
