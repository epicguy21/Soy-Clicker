#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define WM_MOUSEWHEEL 0x020A

int delay = 1;
int rdelay = 1;
bool toggle = true;
bool rtoggle = true;
int mincps = 9;
int maxcps = 16;
bool hidden = false;
int hotbarslot = 1;
POINT pt;
int olds;

using namespace std;

int randomizer()
{
    int c = (rand() % 100)+1;
    if (c <= 5)
    {
        return mincps;
    }
    else
    {
        if (c <= 10)
        {
            return mincps + (rand() % 3) + 1;
        }
        else
        {
            if (c < 30)
            {
                return 10 + (rand() % 2)+1;
            }
            else
            {
                if (c >= 30)
                {
                    return 16 + (rand() % 4);
                }
            }
        }
    }
}

void click()
{
    GetCursorPos(&pt);
    SendMessage(GetForegroundWindow(), WM_LBUTTONDOWN, 0, MAKELPARAM(pt.x, pt.y));
    Sleep(50);
    SendMessage(GetForegroundWindow(), WM_LBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
}

void rightclick()
{
    GetCursorPos(&pt);
    SendMessage(GetForegroundWindow(), WM_RBUTTONDOWN, 0, MAKELPARAM(pt.x, pt.y));
    Sleep(50);
    SendMessage(GetForegroundWindow(), WM_RBUTTONUP, 0, MAKELPARAM(pt.x, pt.y));
}

void updateDisplay()
{
    HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
    system("CLS");
    system("COLOR 0F");
    cout << "Soy clicker PRO" << endl;
    if (toggle == true)
    {
        SetConsoleTextAttribute(con, 10);
        cout << "Left Click: On" << endl;
    }
    else
    {
        SetConsoleTextAttribute(con, 4);
        cout << "Left Click: Off" << endl;
    }

    if (rtoggle == true)
    {
        SetConsoleTextAttribute(con, 10);
        cout << "Right Click: On" << endl;
    }
    else
    {
       SetConsoleTextAttribute(con, 4);
        cout << "Right Click: Off" << endl;
    }

    SetConsoleTextAttribute(con, 7);
    cout << "Press F to toggle left click" << endl;
    cout << "Press R to toggle right click" << endl;
    cout << "Press F4 to hide window (glitchy)" << endl;
    cout << "Press \\| key to quit" << endl;
    cout << "Tool bar slot: " << hotbarslot << endl;
}

int main()
{
    SetConsoleTitle(_T("Google Chrome"));
    updateDisplay();
    while (true) {
        if (GetAsyncKeyState(0x46) & 0x8000)
        {
            toggle = !toggle;
            updateDisplay();
            Sleep(250);
        }

        if (GetAsyncKeyState(0x52) & 0x8000)
        {
            rtoggle = !rtoggle;
            updateDisplay();
            Sleep(250);
        }

        if (GetAsyncKeyState(VK_LBUTTON) && toggle == true && hotbarslot == 1)
        {
            Sleep(500/delay);
            click();
            ZeroMemory(&delay, sizeof(delay));
            delay = randomizer();
        }

        if (GetAsyncKeyState(VK_RBUTTON) && rtoggle == true && hotbarslot == 4)
        {
            Sleep(500/rdelay);
            rightclick();
            ZeroMemory(&rdelay, sizeof(rdelay));
            rdelay = randomizer();
        }

        if (GetAsyncKeyState(VK_F4) && 0x8000)
        {
            if (hidden == false)
            {
                hidden = true;
                FreeConsole();
            }
            else
            {
                hidden = false;
                AllocConsole();
                freopen("CONIN$", "r", stdin);
                freopen("CONOUT$", "w", stdout);
                freopen("CONOUT$", "w", stderr);
            }
            updateDisplay();
            Sleep(250);
        }

        if (GetAsyncKeyState(0x31) & 0x8000)
        {
            hotbarslot = 1;
            updateDisplay();
        } else
        {
            if (GetAsyncKeyState(0x32) & 0x8000)
            {
                hotbarslot = 2;
                updateDisplay();
            }
            else
            {
                if (GetAsyncKeyState(0x33) & 0x8000)
                {
                    hotbarslot = 3;
                    updateDisplay();
                }
                else
                {
                    if (GetAsyncKeyState(0x34) & 0x8000)
                    {
                        hotbarslot = 4;
                        updateDisplay();
                    }
                    else
                    {
                        if (GetAsyncKeyState(0x35) & 0x8000)
                        {
                            hotbarslot = 5;
                            updateDisplay();
                        }
                        else
                        {
                            if (GetAsyncKeyState(0x36) & 0x8000)
                            {
                                hotbarslot = 6;
                                updateDisplay();
                            }
                            else
                            {
                                if (GetAsyncKeyState(0x37) & 0x8000)
                                {
                                    hotbarslot = 7;
                                    updateDisplay();
                                }
                                else
                                {
                                    if (GetAsyncKeyState(0x38) & 0x8000)
                                    {
                                        hotbarslot = 8;
                                        updateDisplay();
                                    }
                                    else
                                    {
                                        if (GetAsyncKeyState(0x39) & 0x8000)
                                        {
                                            hotbarslot = 9;
                                            updateDisplay();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (GetAsyncKeyState(0xDC) & 0x8000)
        {
            break;
        }
    }

    return 0;
}

