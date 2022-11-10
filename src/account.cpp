#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "account.h"

using namespace std;

Account::Account(string id, string password, string pseudo) {
    this->id = id;
    this->password = password;
    this->pseudo = pseudo;
}

string Account::getId() {
    return this->id;
}

string Account::getPassword() {
    return this->password;
}

void Account::connect() {
    
}