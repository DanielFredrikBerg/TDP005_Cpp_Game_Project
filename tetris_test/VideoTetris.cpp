//
// Created by danhu849 on 2020-11-01.
//
#include <iostream>
#include <Windows.h>
#include "VideoTetris.h"
using namespace std;

//Tetromino blocks made out of wstring
wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

//Console screen Size X and Y
int nScreenWidth = 80;
int nScreenHeight = 30;

int Rotate(int px, int py, int r)
{
    switch (r % 4)
    {
        case 0: return py * 4 + px;
        case 1: return 12 + py - (px * 4);
        case 2: return 15 - (py * 4) - px;
        case 3: return 3 - py + (px * 4);
    }
    return 0;
}

int main
{
    //Create assets 4x4. Full stop represents empty space. X the shape.
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

tetromino[1].append(L"..X.");
tetromino[1].append(L".XX.");
tetromino[1].append(L".X..");
tetromino[1].append(L"....");

tetromino[2].append(L".X..");
tetromino[2].append(L".XX.");
tetromino[2].append(L"..X.");
tetromino[2].append(L"....");

tetromino[3].append(L"....");
tetromino[3].append(L".XX.");
tetromino[3].append(L".XX.");
tetromino[3].append(L"....");

tetromino[4].append(L"..X.");
tetromino[4].append(L".XX.");
tetromino[4].append(L"..X.");
tetromino[4].append(L"....");

tetromino[5].append(L"....");
tetromino[5].append(L".XX.");
tetromino[5].append(L"..X.");
tetromino[5].append(L"..X.");

tetromino[6].append(L"....");
tetromino[6].append(L".XX.");
tetromino[6].append(L".X..");
tetromino[6].append(L".X..");

    pField = new unsigned char[nFieldWidth * nFieldHeight]; // Create playing field buffer.
    for (int x = 0; x < nFieldWidth; x++) // Board Boundary
        for (int y = 0; y < nFieldHeight; x++)
            pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0; //Boundary are 9, empty space 0

    wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    return 0;
};
