#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account {
private:
    string id;
    string password;
    string pseudo;
public:
    Account(string id, string password, string pseudo);
    string getId();
};

#endif