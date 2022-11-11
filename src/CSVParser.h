#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Account.h"

using namespace std;

class CSVParser {
private:
    string fileName;
    vector<string> split(const string &s, char c);
public:
    CSVParser(const string &s);
    vector<Account> parse();
};

#endif