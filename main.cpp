#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include "include/Game.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

Game *game = nullptr;
UINT timerInterval = 10;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    const wchar_t NAME[] = L"Ping-pong!";
    WNDCLASS wc = { };

    BYTE CursorMaskAND[] = { 0xFF};
    BYTE CursorMaskXOR[] = { 0x00 };
    wc.hCursor = CreateCursor(nullptr, 0, 0, 1, 1, CursorMaskAND, CursorMaskXOR);

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = NAME;

    RegisterClass(&wc);

    // Create the window.

    HMONITOR hmon = MonitorFromWindow(nullptr,
                                      MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi = { sizeof(mi) };
    GetMonitorInfo(hmon, &mi);

    game = new Game();

    HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            NAME,                     // Window class
            NAME,    // Window text
            WS_MAXIMIZE | WS_POPUPWINDOW,            // Window style

            // Size and position
            mi.rcMonitor.left - 1, mi.rcMonitor.top - 1,
            mi.rcMonitor.right - mi.rcMonitor.left + 2,
            mi.rcMonitor.bottom - mi.rcMonitor.top + 2,
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
        case WM_CREATE:
            RECT rc;
            GetClientRect(hwnd, &rc);
            game->SetWindowSize(rc);
            InvalidateRect(hwnd, nullptr, true);
            return 0;

        case WM_DESTROY:

            KillTimer(hwnd, 1);
            game->Stop();
            delete game;

            PostQuitMessage(0);
            return 0;

        case WM_KEYDOWN:
            game->DecodeKey((wchar_t)wParam);
            InvalidateRect(hwnd, nullptr, false);
            return 0;

        case WM_TIMER:
            game->Update();
            InvalidateRect(hwnd, nullptr, false);
            return 0;

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