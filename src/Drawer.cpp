//
// Created by Andmin on 12/5/2022.
//


#include "../include/Drawer.h"

void Drawer::Draw(HDC hdc, ServerState *state) {

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

//    HDC memDC = CreateCompatibleDC(hdc);
//    HBITMAP hBitMap = CreateCompatibleBitmap(hdc, xSize, ySize);
//    SelectObject(memDC, hBitMap);
//
//    Gdiplus::Graphics graphics(memDC);
//
//    //TODO: drawing
//    Gdiplus::SolidBrush back(Gdiplus::Color::Black);
//    graphics.FillRectangle(&back, 0, 0, (int)600, (int)480);
//
//
//    BitBlt(hdc, 0, 0, (int)600, (int)480, memDC, 0, 0, SRCCOPY);
//    DeleteObject(hBitMap);

    Gdiplus::Graphics graphics(hdc);
    Gdiplus::SolidBrush back(Gdiplus::Color::Black);
    graphics.FillRectangle(&back, 0, 0, (int)xSize, (int)ySize);


}

void Drawer::ChangeEntry(int dChosenEntry) {



}

Drawer::State Drawer::ChangeState() {
    return Drawer::Menu;
}

Drawer::Drawer() {
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);
}

Drawer::~Drawer() {
    Gdiplus::GdiplusShutdown(gdiplusToken);
}

Drawer::State Drawer::ReturnToPrevState() {
    return Drawer::None;
}
