#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"
#include "CSVParser.h"

using namespace std;

vector<string> CSVParser::split(const string &s, char c)
{
    int start = 0;
    vector<string> ret;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != c)
            continue;

        ret.push_back(s.substr(start, i - start));
        start = i + 1;
    }

    if(s.size() > 0) {
        if (s[s.size() - 1] != c)
            ret.push_back(s.substr(start, s.size() - start));
    }

    return ret;
}

CSVParser::CSVParser(const string &s)
{
    ifstream file(s);

    if (!file.is_open())
    {
        cout << "Error: " << s << " not found !" << endl;
        exit(2);
    }

    this->fileName = s;
}

vector<Account> CSVParser::parse() {
    ifstream file(this->fileName);
    string line;
    vector<Account> accounts;

    while (getline(file, line))
    {
        vector<string> data = split(line, '|');

        if(data.size() != 3) {
            cout << "Error: invalid account data" << endl;
            exit(3);
        }

        Account account(data[0], data[1], data[2]);
        accounts.push_back(account);
    }

    return accounts;
}