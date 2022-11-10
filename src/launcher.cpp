#include <iostream>
#include <fstream>
#include <Windows.h>
#include "launcher.h"

using namespace std;

Launcher::Launcher() {
    if(!FindWindowA(NULL, "League of Legends") && !FindWindowA(NULL, "Riot Client Main"))
        this->start();

    this->window = FindWindowA(NULL, "League of Legends");
}

void Launcher::start() {
    ShellExecuteA(NULL, "open", "C:\\Riot Games\\Riot Client\\RiotClientServices.exe", "--launch-product=league_of_legends --launch-patchline=live", NULL, 0);
}

void Launcher::disconnect() {
    RECT rect;
    HWND phwnd;

    GetWindowRect(this->window, &rect);

    phwnd = GetForegroundWindow();

    SetForegroundWindow(this->window);
    leftClick(rect.right -20, rect.top + 10);
    leftClick(rect.left + 725, rect.top + 400);
}

void leftClick(int x, int y) {
    const double XSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CXSCREEN) - 1);
    const double YSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CYSCREEN) - 1);

    POINT cursorPos;
    GetCursorPos(&cursorPos);

    double nx = x * XSCALEFACTOR;
    double ny = y * YSCALEFACTOR;

    INPUT Input = {0};
    Input.type = INPUT_MOUSE;

    Input.mi.dx = (LONG)nx;
    Input.mi.dy = (LONG)ny;

    Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;

    SendInput(1, &Input, sizeof(INPUT));
}

void keyboardWriting(char c) {
    INPUT Input;

    Input.type = INPUT_KEYBOARD;
    Input.ki.wScan = c;
    Input.ki.time = 0;
    Input.ki.dwExtraInfo = 0;
    Input.ki.wVk = 0;
    Input.ki.dwFlags = KEYEVENTF_UNICODE;
    SendInput(1, &Input, sizeof(INPUT));

    // Release the key
    Input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &Input, sizeof(INPUT));
}