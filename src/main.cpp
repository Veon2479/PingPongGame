#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include "../include/Game.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

Game *game = nullptr;
UINT timerInterval = 10;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    const wchar_t NAME[] = L"Ping-pong!";
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = NAME;

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            NAME,                     // Window class
            NAME,    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            nullptr,       // Parent window
            nullptr,       // Menu
            hInstance,  // Instance handle
            nullptr        // Additional application data
    );

    if (hwnd == nullptr)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    game = new Game();
    game->Start();
    SetTimer(hwnd, 1, timerInterval, nullptr);
    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, nullptr, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:

            KillTimer(hwnd, 1);
            game->Stop();
            delete game;

            PostQuitMessage(0);
            return 0;

        case WM_CHAR:

            game->DecodeKey((wchar_t)wParam);
            return 0;

        case WM_TIMER:

            game->Update();
            return 0;

        case WM_SIZE:

            RECT rc;
            GetClientRect(hwnd, &rc);
            game->SetWindowSize(rc);

        case WM_ERASEBKGND:

            return false;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            game->Paint(hdc);
            EndPaint(hwnd, &ps);
        }
            return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}