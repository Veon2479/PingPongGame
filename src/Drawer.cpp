//
// Created by Andmin on 12/5/2022.
//

#include <windef.h>
#include "../include/Drawer.h"

void Drawer::Draw(HDC hdc, Player *playerOne, Player *playerTwo, ServerState *state) {

//    RECT rc;
//    GetClientRect(hwnd, &rc);
//
//    HDC memDC = CreateCompatibleDC(hdc);
//    //const int nMemDc = SaveDC(memDC);
//
//    HBITMAP hBitMap = CreateCompatibleBitmap(hdc, rc.right - rc.left, rc.bottom - rc.top);
//    SelectObject(memDC, hBitMap);
//
//    Gdiplus::Graphics graphics(memDC);
//    Gdiplus::SolidBrush back(curColor);
//    graphics.FillRectangle(&back, (int)rc.left, (int)rc.top, (int)(rc.right-rc.left), (int)(rc.bottom-rc.top));
//
//    graphics.DrawImage(curImage, x, y);
//
//    BitBlt(hdc, (int)rc.left, (int)rc.top, (int)(rc.right-rc.left), (int)(rc.bottom-rc.top), memDC, (int)rc.left, (int)rc.top, SRCCOPY);
//    //RestoreDC(memDC, nMemDc);
//    DeleteObject(hBitMap);

}

void Drawer::ChangeEntry(int dChosenEntry) {



}

Drawer::State Drawer::ChangeState() {
    return Drawer::Menu;
}
