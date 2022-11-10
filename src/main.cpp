#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include "account.h"
#include "launcher.h"

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
    int i, choice;
    string line;
    vector<Account> accounts;

    ifstream csv("./accounts.csv");

    if(!csv.is_open()) {
        cout << "Error: accounts.csv not found" << endl;
        exit(1);
    }

    while(getline(csv, line)) {
        vector<string> data = split(line, ',');

        if(data.size() == 3) {
            Account account(data[1], data[2], data[0]);
            accounts.push_back(account);
        } else
            cout << "Error: invalid account data" << endl;
    }

    cout << "Choose an account number:" << endl;

    for(i = 0; i < accounts.size(); i++)
        cout << i << ")\t" << accounts[i].getId() << endl;

    cin >> choice;

    while(choice < 0 || choice > accounts.size() - 1) {
        cout << "Error: invalid entry" << accounts.size() << endl;
        cout << "Choose an account number:" << endl;
        cin >> choice;
    }








    Launcher L;
    L.disconnect();

    Sleep(7500);

    HWND test = FindWindowA(NULL, "Riot Client Main");
    SetForegroundWindow(test);

    RECT rect;
    HWND phwnd;

    GetWindowRect(test, &rect);
    phwnd = GetForegroundWindow();

    for(i = 0; i < accounts[choice].getId().size(); i++)
        keyboardWriting(accounts[choice].getId()[i]);

    Sleep(250);

    leftClick(rect.left + 170, rect.top + 325);

    Sleep(50);

    for(i = 0; i < accounts[choice].getPassword().size(); i++)
        keyboardWriting(accounts[choice].getPassword()[i]);

    Sleep(250);
    leftClick(rect.left + 170, rect.top + 430); // Stay signed in
    leftClick(rect.left + 170, rect.top + 700); // Connect button
    Sleep(3300);

    leftClick(rect.left + 170, rect.top + 800);
    return 0;
}