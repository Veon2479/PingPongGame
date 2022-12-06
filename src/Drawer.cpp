//
// Created by Andmin on 12/5/2022.
//

#include "../include/Drawer.h"

Drawer::Drawer()
{
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

    AddFontResource(FontPath);
    fontFamily = new Gdiplus::FontFamily(L"ugly MainMenuFont");
    solidBrush = new Gdiplus::SolidBrush(Gdiplus::Color(255, 50, 205, 50));

    MainMenuFont = new Gdiplus::Font(fontFamily, 72, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);

}

Drawer::~Drawer()
{
    delete MainMenuFont;

    delete solidBrush;
    delete fontFamily;
    RemoveFontResource("data/uglyFont.otf");
    Gdiplus::GdiplusShutdown(gdiplusToken);
}

void Drawer::Draw(HDC hdc, ServerState *state_)
{

    HDC memDC = CreateCompatibleDC(hdc);
    HBITMAP hBitMap = CreateCompatibleBitmap(hdc, xSize, ySize);
    SelectObject(memDC, hBitMap);

    Gdiplus::Graphics graphics(memDC);

    Gdiplus::SolidBrush back(Gdiplus::Color::Black);
    graphics.FillRectangle(&back, 0, 0, (int)xSize, (int)ySize);

    switch (Drawer::state)
    {
        case LocalGame:
        case RemoteGuestGame:
        case RemoteHostGame:
            DrawGameState(&graphics, state_);
            break;

        default:
            DrawNonGameState(&graphics);
            break;
    }

    BitBlt(hdc, 0, 0, (int)xSize, (int)ySize, memDC, 0, 0, SRCCOPY);
    DeleteObject(hBitMap);

}

void Drawer::DrawGameState(Gdiplus::Graphics* graphics, ServerState *state)
{

}

void Drawer::DrawNonGameState(Gdiplus::Graphics* graphics)
{
    Gdiplus::PointF      pointF(150.0f, 150.0f);
    graphics->DrawString(L"Let's play pong", -1, MainMenuFont, pointF, solidBrush);
}
