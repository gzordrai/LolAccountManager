#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "account.h"

using namespace std;

vector<string> split(string s, char c) {
    int start = 0;
    vector<string> ret;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == c) {
            ret.push_back(s.substr(start, i - start));
            start = i + 1;
        }
    }

    if(s[s.size() - 1] != c)
        ret.push_back(s.substr(start, s.size() - start));

    return ret;
}

int main(int argc, char **argv) {
    int i;

    ifstream csv("./accounts.csv");

    if(!csv.is_open()) {
        cout << "Error: accounts.csv not found" << endl;
        exit(1);
    }

    string line;
    vector<Account> accounts;

    while(getline(csv, line)) {
        vector<string> data = split(line, ',');

        if(data.size() == 3) {
            Account account(data[0], data[1], data[2]);
            accounts.push_back(account);
        } else
            cout << "Error: invalid account data" << endl;
    }

    return 0;
}