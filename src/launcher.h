#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class Launcher {
private:
    HWND window;
public:
    Launcher();
    void start();
    void disconnect();
};

void leftClick(int x, int y);
void keyboardWriting(char c);

#endif