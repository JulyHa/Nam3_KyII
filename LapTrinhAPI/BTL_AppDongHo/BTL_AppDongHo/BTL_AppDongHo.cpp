#include "framework.h"
#include "BTL_AppDongHo.h"
#include "math.h"
#include "windowsx.h"
#include "Richedit.h"

#define MAX_LOADSTRING 100
#define PI 3.1415926535
#define ID_BTN_DONGHO 1
#define ID_BTN_BAMGIO 2
#define ID_BTN_HENGIO 3
#define ID_BTN_ENDHENGIO 4
#define ID_BTN_BATDAU 5
#define ID_BTN_HUY 6
#define ID_GIO 7
#define ID_PHUT 8
#define ID_GIAY 9
#define ID_BTN_DATLAI 10
#define ID_BTN_VONG 11
#define ID_BTN_BATDAUDUNG 12
#define ID_LIST 13
#define ID_STATIC_TEXT 14
#define ID_STATIC_TIMER 15
#define ID_TIMER 16
#define ID_TXT_COUNT_TIME 17
#define TWOPI (2 * 3.14159)

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING] ;                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND btnDongHo, btnBamGio, btnHenGio, btnEndHenGio, btnBatDau, btnHuy,
    ComboBoxGio, ComboBoxPhut, ComboBoxGiay, txtGio, txtPhut, txtGiay, txtName, txtCountTime;
HWND btnDatLai, btnVong, btnBatDau_Dung, lstList, staticText, staticTimer;


WCHAR txtNoiDung[MAX_LOADSTRING] = L"Hẹn giờ kết thúc";
static bool clickBatDau = false, clickBatDau_HenGio = false;
static int startCount = 0;
static int gio = 0, phut = 0, giay = 0;
static TCHAR CountDown[20];
static HDC hdcDraw;
static bool startBamGio = false, startReset = false;
static int len, listCount;
static TCHAR time[30], kq[50];
static int btn = 1, check = 0;

static SYSTEMTIME localTime;
//dong ho so
static int cxClient, cyClient;
static SYSTEMTIME stPrevious;
BOOL fChange;
HDC hdc;
PAINTSTRUCT ps;
SYSTEMTIME st;
//dong ho dien tu
static BOOL f24Hour, fSuppress;
TCHAR szBuffer[2];

RECT rect;
HBRUSH hBrush;
HFONT hFont;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_BTLAPPDONGHO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BTLAPPDONGHO));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CLOCK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, TEXT("APP ĐỒNG HỒ"), WS_OVERLAPPEDWINDOW,
      400, 50, 400, 600, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void SetIsotropic(HDC hdc, int cxClient, int cyClient)
{
    SetMapMode(hdc, MM_ISOTROPIC);
    SetWindowExtEx(hdc, 1500, 1500, NULL);
    SetViewportExtEx(hdc, cxClient / 2, -cyClient / 2, NULL);
    SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2.5, NULL);
}
void RotatePoint(POINT pt[], int iNum, int iAngle)
{
    int i;
    POINT ptTemp;
    for (i = 0; i < iNum; i++)
    {
        ptTemp.x = (int)(pt[i].x * cos(TWOPI * iAngle / 360) +
            pt[i].y * sin(TWOPI * iAngle / 360));
        ptTemp.y = (int)(pt[i].y * cos(TWOPI * iAngle / 360) -
            pt[i].x * sin(TWOPI * iAngle / 360));
        pt[i] = ptTemp;
    }
}
void DrawClock(HDC hdc)
{
    int iAngle;
    POINT pt[3];
    for (iAngle = 0; iAngle < 360; iAngle += 6)
    {
        pt[0].x = 0;
        pt[0].y = 900;
        RotatePoint(pt, 1, iAngle);
        pt[2].x = pt[2].y = iAngle % 5 ? 33 : 100;
        pt[0].x -= pt[2].x / 2;
        pt[0].y -= pt[2].y / 2;
        pt[1].x = pt[0].x + pt[2].x;
        pt[1].y = pt[0].y + pt[2].y;
        SelectObject(hdc, GetStockObject(BLACK_BRUSH));
        Ellipse(hdc, pt[0].x, pt[0].y, pt[1].x, pt[1].y);
    }
}
void DrawHands(HDC hdc, SYSTEMTIME* pst, BOOL fChange)
{
    static POINT pt[3][5] = { 0, -150, 100, 0, 0, 600, -100, 0, 0, -150,
    0, -200, 50, 0, 0, 800, -50, 0, 0, -200,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 800 };
    int i, iAngle[3];
    POINT ptTemp[3][5];
    iAngle[0] = (pst->wHour * 30) % 360 + pst->wMinute / 2;
    iAngle[1] = pst->wMinute * 6;
    iAngle[2] = pst->wSecond * 6;
    memcpy(ptTemp, pt, sizeof(pt));
    for (i = fChange ? 0 : 2; i < 3; i++)
    {
        RotatePoint(ptTemp[i], 5, iAngle[i]);
        Polyline(hdc, ptTemp[i], 5);
    }
}
void reStart(HWND hWnd) {
    PAINTSTRUCT ps;
    // Tên hội thoại đồng hồ
    HDC reS = BeginPaint(hWnd, &ps);
   InvalidateRect(hWnd, NULL, TRUE);
    EndPaint(hWnd, &ps);

}

//ve dong ho dien tu
void DisplayDigit(HDC hdc, int iNumber)
{
    static BOOL fSevenSegment[10][7] = {
    1, 1, 1, 0, 1, 1, 1, // 0
    0, 0, 1, 0, 0, 1, 0, // 1
    1, 0, 1, 1, 1, 0, 1, // 2
    1, 0, 1, 1, 0, 1, 1, // 3
    0, 1, 1, 1, 0, 1, 0, // 4
    1, 1, 0, 1, 0, 1, 1, // 5
    1, 1, 0, 1, 1, 1, 1, // 6
    1, 0, 1, 0, 0, 1, 0, // 7
    1, 1, 1, 1, 1, 1, 1, // 8
    1, 1, 1, 1, 0, 1, 1 }; // 9
    static POINT ptSegment[7][6] = {
    7, 6, 11, 2, 31, 2, 35, 6, 31, 10, 11, 10,
    6, 7, 10, 11, 10, 31, 6, 35, 2, 31, 2, 11,
    36, 7, 40, 11, 40, 31, 36, 35, 32, 31, 32, 11,
    7, 36, 11, 32, 31, 32, 35, 36, 31, 40, 11, 40,
    6, 37, 10, 41, 10, 61, 6, 65, 2, 61, 2, 41,
    36, 37, 40, 41, 40, 61, 36, 65, 32, 61, 32, 41,
    7, 66, 11, 62, 31, 62, 35, 66, 31, 70, 11, 70 };
    int iSeg;
    for (iSeg = 0; iSeg < 7; iSeg++)
        if (fSevenSegment[iNumber][iSeg])
            Polygon(hdc, ptSegment[iSeg], 6);
}
void DisplayTwoDigits(HDC hdc, int iNumber, BOOL fSuppress)
{
    if (!fSuppress || (iNumber / 10 != 0))
        DisplayDigit(hdc, iNumber / 10);
    OffsetWindowOrgEx(hdc, -42, 0, NULL);
    DisplayDigit(hdc, iNumber % 10);
    OffsetWindowOrgEx(hdc, -42, 0, NULL);
}
void DisplayColon(HDC hdc)
{
    POINT ptColon[2][4] = { 2, 21, 6, 17, 10, 21, 6, 25,
    2, 51, 6, 47, 10, 51, 6, 55 };
    Polygon(hdc, ptColon[0], 4);
    Polygon(hdc, ptColon[1], 4);
    OffsetWindowOrgEx(hdc, -12, 0, NULL);
}
void DisplayTime(HDC hdc, BOOL f24Hour, BOOL fSuppress)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    if (f24Hour)
        DisplayTwoDigits(hdc, st.wHour, fSuppress);
    else
        DisplayTwoDigits(hdc, (st.wHour %= 24) ? st.wHour : 24, fSuppress);
    DisplayColon(hdc);
    DisplayTwoDigits(hdc, st.wMinute, FALSE);
    DisplayColon(hdc);
    DisplayTwoDigits(hdc, st.wSecond, FALSE);
}
void createDongHo(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    hBrush = CreateSolidBrush(RGB(0, 0, 0));

    SetTimer(hWnd, 1, 1000, NULL);
    GetLocalTime(&st);
    stPrevious = st;

    txtName = CreateWindow(TEXT("static"), TEXT("Đồng hồ"), WS_CHILD | WS_VISIBLE,
        130, 30, 200, 40, hWnd, NULL, hInst, NULL);
    hFont = CreateFont(35, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
    SendMessage(txtName, WM_SETFONT, WPARAM(hFont), TRUE);

}
void setTimeDongHo(HWND hWnd) {
    InvalidateRect(hWnd, NULL, TRUE);
    GetLocalTime(&st);
    fChange = st.wHour != stPrevious.wHour ||
        st.wMinute != stPrevious.wMinute;
    hdc = GetDC(hWnd);
    SetIsotropic(hdc, cxClient, cyClient);
    SelectObject(hdc, GetStockObject(WHITE_PEN));
    DrawHands(hdc, &stPrevious, fChange);
    SelectObject(hdc, GetStockObject(BLACK_PEN));
    DrawHands(hdc, &st, TRUE);
    ReleaseDC(hWnd, hdc);
    stPrevious = st;
}
void paintDongHo(HWND hWnd) {
    GetLocalTime(&localTime);
    //PAINTSTRUCT ps;
    //HDC hdc = BeginPaint(hWnd, &ps);

    GetClientRect(hWnd, &rect);
    double BK_Gio, BK_Phut, BK_Giay;

    //RoundRect(hdc, 40, 20, 340, 55, 20, 20);
    //TextOut(hdc, 155, 30, TEXT("ĐỒNG HỒ"), 10);

    RoundRect(hdc, 40, 370, 340, 450, 20, 20);
    SetIsotropic(hdc, cxClient, cyClient);
    DrawClock(hdc);
    DrawHands(hdc, &stPrevious, TRUE);

    //dong ho dien tu
    SetMapMode(hdc, MM_ISOTROPIC);
    SetWindowExtEx(hdc, 550, 144, NULL);
    SetViewportExtEx(hdc, cxClient, cyClient, NULL);
    SetWindowOrgEx(hdc, 138, 36, NULL);
    SetViewportOrgEx(hdc, cxClient / 2, 410, NULL);
    SelectObject(hdc, GetStockObject(NULL_PEN));
    SelectObject(hdc, hBrush);
    DisplayTime(hdc, f24Hour, fSuppress);

    EndPaint(hWnd, &ps);
}

void setTime(HWND x, int h){
    TCHAR A[16];
    int  k = 0;
    memset(&A, 0, sizeof(A));
    for (k=0; k <= h; k++)
    {
        wsprintf(A, L"%02d", k);
        wcscpy_s(A, sizeof(A) / sizeof(TCHAR), A);

        // Add string to combobox.
        SendMessage(x, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
    }

    SendMessage(x, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
}

void CreateHenGio(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

    txtName = CreateWindow(TEXT("static"), TEXT("Hẹn giờ"), WS_CHILD | WS_VISIBLE,
       130, 30, 200, 40, hWnd, NULL, hInst, NULL);
     hFont = CreateFont(35, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
    SendMessage(txtName, WM_SETFONT, WPARAM(hFont), TRUE);

    btnHuy = CreateWindow(TEXT("button"), TEXT("\nHủy"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        20, 300, 70, 50, hWnd, (HMENU)ID_BTN_HUY, NULL, NULL);
    EnableWindow(GetDlgItem(hWnd, ID_BTN_HUY), false);

    btnBatDau = CreateWindow(TEXT("button"), TEXT("Bắt\n đầu"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        300, 300, 70, 50, hWnd, (HMENU)ID_BTN_BATDAU, NULL, NULL);

    btnEndHenGio = CreateWindow(TEXT("button"), TEXT("\nKhi hẹn giờ kết thúc"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        20, 400, 340, 50, hWnd, (HMENU)ID_BTN_ENDHENGIO, NULL, NULL);

    txtGio = CreateWindow(TEXT("static"), TEXT("Giờ"), WS_CHILD | WS_VISIBLE,
        20, 150, 50, 20, hWnd, NULL, hInst, NULL);
    hFont = CreateFont(20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
    SendMessage(txtGio, WM_SETFONT, WPARAM(hFont), TRUE);

   ComboBoxGio = CreateWindow(TEXT("combobox"), TEXT(""),
       CBS_DROPDOWNLIST | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
        55, 145, 50, 150, hWnd, NULL, hInst,NULL);
   setTime(ComboBoxGio, 23);

   txtPhut = CreateWindow(TEXT("static"), TEXT("Phút"), WS_CHILD | WS_VISIBLE,
       140, 150, 50, 20, hWnd, NULL, hInst, NULL);
   hFont = CreateFont(20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
   SendMessage(txtPhut, WM_SETFONT, WPARAM(hFont), TRUE);

    ComboBoxPhut = CreateWindow(TEXT("combobox"), TEXT(""),
        CBS_DROPDOWNLIST | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
        185, 145, 50, 150, hWnd, NULL, hInst,NULL);
    setTime(ComboBoxPhut, 59);

    txtGiay = CreateWindow(TEXT("static"), TEXT("Giây"), WS_CHILD | WS_VISIBLE,
        270, 150, 50, 20, hWnd, NULL, hInst, NULL);
    hFont = CreateFont(20, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
    SendMessage(txtGiay, WM_SETFONT, WPARAM(hFont), TRUE);

    ComboBoxGiay = CreateWindow(TEXT("combobox"), TEXT(""),
        CBS_DROPDOWNLIST | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE | WS_VSCROLL,
        315, 145, 50, 150, hWnd, NULL, NULL, NULL);
    setTime(ComboBoxGiay, 59);

    txtCountTime = CreateWindow(TEXT("static"), TEXT(""), WS_CHILD | WS_VISIBLE,
        100, 200, 300, 50, hWnd,(HMENU)ID_TXT_COUNT_TIME, NULL, NULL);
    hFont = CreateFont(50, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
    SendMessage(txtCountTime, WM_SETFONT, WPARAM(hFont), TRUE);

}

void CreateBamGio(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

    txtName = CreateWindow(TEXT("static"), TEXT("Bấm giờ"), WS_CHILD | WS_VISIBLE,
        130, 30, 200, 40, hWnd, NULL, hInst, NULL);
    hFont = CreateFont(35, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
    SendMessage(txtName, WM_SETFONT, WPARAM(hFont), TRUE);

    staticTimer = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("static"), TEXT("00 : 00 : 00"), WS_CHILD | WS_VISIBLE | SS_CENTER,
        65, 135, 250, 50, hWnd, (HMENU)ID_STATIC_TIMER, GetModuleHandle(NULL), NULL);
    hFont = CreateFont(50, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
    SendMessage(staticTimer, WM_SETFONT, WPARAM(hFont), TRUE);

    btnDatLai = CreateWindow(TEXT("button"), TEXT("Đặt\n lại"), WS_CHILD | WS_VISIBLE |
        BS_DEFPUSHBUTTON, 40, 260, 80, 30, hWnd, (HMENU)ID_BTN_DATLAI, NULL, NULL);
    btnVong = CreateWindow(TEXT("button"), TEXT("Vòng"), WS_CHILD | WS_VISIBLE |
        BS_DEFPUSHBUTTON, 155, 260, 80, 30, hWnd, (HMENU)ID_BTN_VONG, NULL, NULL);
    btnBatDau_Dung = CreateWindow(TEXT("button"), TEXT("Bắt\n đầu"), WS_CHILD | WS_VISIBLE |
        BS_DEFPUSHBUTTON, 260, 260, 80, 30, hWnd, (HMENU)ID_BTN_BATDAUDUNG, NULL, NULL);
    lstList = CreateWindow(TEXT("listbox"), TEXT(""), WS_CHILD | WS_VISIBLE |
        WS_BORDER | WS_VSCROLL | LBS_NOTIFY, 40, 320, 300, 150, hWnd, (HMENU)ID_LIST, NULL, NULL);
    EnableWindow(btnDatLai, FALSE);
    EnableWindow(btnVong, FALSE);

    startBamGio = false;
}

void deleteChoice() {
    DestroyWindow(btnHuy);
    DestroyWindow(btnBatDau);
    DestroyWindow(btnEndHenGio);
    DestroyWindow(ComboBoxGio);
    DestroyWindow(ComboBoxPhut);
    DestroyWindow(ComboBoxGiay);
    DestroyWindow(txtGio);
    DestroyWindow(txtPhut);
    DestroyWindow(txtGiay);
    DestroyWindow(txtName);
    DestroyWindow(txtCountTime);

    DestroyWindow(staticTimer);
    DestroyWindow(btnDatLai);
    DestroyWindow(btnVong);
    DestroyWindow(btnBatDau_Dung);
    DestroyWindow(lstList);
}

void SetTimeBamGio(HWND hWnd) {
    static TCHAR timeLeft[20];
    HDC hdcText;
    giay++;
    if (giay == 60) {
        giay = 0;
        phut++;
    }
    if (phut == 60) {
        phut = 0;
        gio++;
    }
    wsprintf(timeLeft, L"%02d : %02d : %02d", gio, phut, giay);
    hdcText = GetDC(hWnd);
    SetWindowText(staticTimer, timeLeft);
}

void SetTimeHenGio(HWND hWnd) {
    if (startCount == 1 && clickBatDau == true) {

        if (gio == 0 && giay == 0 && phut == 0) {
            KillTimer(hWnd, 1);
            SetWindowText(txtCountTime, L"");
            MessageBox(hWnd, txtNoiDung, L"Thông báo", MB_OK | MB_ICONINFORMATION);
            clickBatDau = false;
            startCount = 0;
            Button_SetText(btnBatDau, L"Bắt\n đầu");
            EnableWindow(btnEndHenGio, true);
            EnableWindow(ComboBoxGio, true);
            EnableWindow(ComboBoxPhut, true);
            EnableWindow(ComboBoxGiay, true);
            EnableWindow(btnHuy, false);
            SendMessage(ComboBoxGio, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
            SendMessage(ComboBoxPhut, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
            SendMessage(ComboBoxGiay, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
            
           // InvalidateRect(hWnd, NULL, TRUE);

        }
        else {
            wsprintf(CountDown, L"%02d : %02d : %02d", gio, phut, giay);
            if (gio > 0 && phut == 0 && giay == 0) {
                gio -= 1;
                phut = 59;
                giay = 59;
            }
            else if (giay == 0 && phut > 0) {
                phut -= 1;
                giay = 59;
            }
            else if (giay > 0 && giay <= 59)giay -= 1;
            SetWindowText(txtCountTime, CountDown);
        }
       // InvalidateRect(hWnd, NULL, TRUE);
     


       /* hdcDraw = GetDC(hWnd);
        hFont = CreateFont(30, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
            CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
        SelectObject(hdcDraw, hFont);
        SetRect(&rect, 60, 240, 0, 0);
        SetTextColor(hdcDraw, RGB(255, 0, 0));

        DrawText(hdcDraw, CountDown, -1, &rect, DT_NOCLIP);
        ReleaseDC(hWnd, hdcDraw);*/

    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_BTN_DONGHO:
                KillTimer(hWnd, 1);
                reStart(hWnd);
                btn = 1;
                deleteChoice();
                createDongHo(hWnd, message, wParam, lParam);
               
                break;
            case ID_BTN_BAMGIO:
                KillTimer(hWnd, 1);
                reStart(hWnd);
                btn = 2;
                startBamGio = false; 
                gio = 0; phut = 0; giay = 0;
                clickBatDau = false;
                deleteChoice();
                CreateBamGio(hWnd, message, wParam, lParam);
                break;
            case ID_BTN_HENGIO:
                KillTimer(hWnd, 1);
                reStart(hWnd);
                btn = 3;
                deleteChoice();
                CreateHenGio(hWnd, message, wParam, lParam);
                break;
            case ID_BTN_BATDAU:
                EnableWindow(btnHuy, true);
                EnableWindow(btnEndHenGio, false);
                if (clickBatDau == false) {
                    SetTimer(hWnd, 1, 1000, NULL);
                    clickBatDau = true;
                    gio = SendMessage((HWND)ComboBoxGio, (UINT)CB_GETCURSEL,
                        (WPARAM)0, (LPARAM)0);
                    phut = SendMessage((HWND)ComboBoxPhut, (UINT)CB_GETCURSEL,
                        (WPARAM)0, (LPARAM)0);
                    giay = SendMessage((HWND)ComboBoxGiay, (UINT)CB_GETCURSEL,
                        (WPARAM)0, (LPARAM)0);                    
                    EnableWindow(ComboBoxGio, false);
                    EnableWindow(ComboBoxPhut, false);
                    EnableWindow(ComboBoxGiay, false);
                }
                else {
                    EnableWindow(btnHuy, true);
                }
                if (startCount == 0) {
                    Button_SetText(btnBatDau, L"Tạm\n dừng");
                    EnableWindow(btnEndHenGio, false);
                    startCount = 1;
                }
                else{

                    Button_SetText(btnBatDau, L"Bắt\n đầu");
                    EnableWindow(btnEndHenGio, true);
                    startCount = 0;
                }
                break;

            case ID_BTN_HUY:
                if (clickBatDau == true) {
                    clickBatDau = false;
                    startCount = 0;
                    Button_SetText(btnBatDau, L"Bắt\n đầu");
                    EnableWindow(btnEndHenGio, true);
                    EnableWindow(ComboBoxGio, true);
                    EnableWindow(ComboBoxPhut, true);
                    EnableWindow(ComboBoxGiay, true);
                    EnableWindow(btnHuy, false);
                    SendMessage(ComboBoxGio, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
                    SendMessage(ComboBoxPhut, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
                    SendMessage(ComboBoxGiay, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);                   
                    SetWindowText(txtCountTime, L"");
                }

                break;
            case ID_BTN_ENDHENGIO:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_CaiDat), hWnd, About);
                break;

            case ID_BTN_BATDAUDUNG:
                if (startBamGio == false) {
                    SetTimer(hWnd, 1, 1000, NULL);
                   
                    Button_SetText(btnBatDau_Dung, L"Dừng");
                    startBamGio = true;
                    EnableWindow(btnDatLai, TRUE);
                    EnableWindow(btnVong, TRUE);
                }
                else {
                    Button_SetText(btnBatDau_Dung, L"Bắt\n đầu");
                    KillTimer(hWnd, 1);
                    EnableWindow(btnVong, FALSE);
                    startBamGio = false;
                }
                break;

            case ID_BTN_VONG:
                GetWindowText(staticTimer, time, 30);
                wsprintf(kq, L"             Vòng %d:             %s", (listCount + 1), time);
                listCount++;
                gio = 0;
                phut = 0;
                giay = 0;
                SendMessage(lstList, LB_INSERTSTRING, -1, (LPARAM)kq);
                break;

            case ID_BTN_DATLAI:
                EnableWindow(btnDatLai, FALSE);
                EnableWindow(btnVong, FALSE);
                Button_SetText(btnBatDau_Dung, L"Bắt\n đầu");
                SetWindowText(staticTimer, TEXT("00 : 00 : 00"));
                gio = 0;
                phut = 0;
                giay = 0;
                KillTimer(hWnd, 1);
                startBamGio = false;
                SendMessage(lstList, LB_RESETCONTENT, 0, 0);
                listCount = 0;
                break;

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_CREATE:
        {
            btnDongHo = CreateWindow(TEXT("button"), TEXT("Đồng\n hồ"), WS_CHILD| WS_VISIBLE | BS_PUSHBUTTON,
                25, 500, 110, 40, hWnd, (HMENU)ID_BTN_DONGHO, NULL, NULL);
            btnBamGio = CreateWindow(TEXT("button"), TEXT("Bấm\n giờ"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                145, 500, 110, 40, hWnd, (HMENU)ID_BTN_BAMGIO, NULL, NULL);
            btnHenGio = CreateWindow(TEXT("button"), TEXT("Hẹn\n giờ"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                265, 500, 110, 40, hWnd, (HMENU)ID_BTN_HENGIO, NULL, NULL);

            createDongHo(hWnd, message, wParam, lParam);
        }
        return 0;
    case WM_TIMER:
        if (btn == 1)  setTimeDongHo(hWnd);
        else if (btn == 2) SetTimeBamGio(hWnd);
        else SetTimeHenGio(hWnd);   
        break;

    case WM_CTLCOLORSTATIC:
        SetTextColor((HDC)wParam, RGB(0, 0, 0));
        return (LRESULT)GetSysColorBrush(COLOR_BTNHILIGHT);
        break;
    case WM_CTLCOLORLISTBOX:
        SetTextColor((HDC)wParam, RGB(0, 0, 255));
        return (LRESULT)CreateSolidBrush(RGB(255, 255, 255));
        break;
    case WM_SETTINGCHANGE:
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_ITIME, szBuffer, 2);
        f24Hour = (szBuffer[0] == '1');
        GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_ITLZERO, szBuffer, 2);
        fSuppress = (szBuffer[0] == '0');
        //InvalidateRect(hWnd, NULL, TRUE);
        return 0;
    case WM_SIZE:
        cxClient = LOWORD(lParam);
        cyClient = HIWORD(lParam);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            // Tên hội thoại đồng hồ
            hdc = BeginPaint(hWnd, &ps);
            RoundRect(hdc, 40, 20, 340, 75, 20, 20);           
            if (btn == 1) {
                paintDongHo(hWnd);
            }
            EndPaint(hWnd, &ps);
        }
        break;
        return 0;
    case WM_DESTROY:

        KillTimer(hWnd, 1000);
        DeleteObject(hBrush);
        PostQuitMessage(0);
        break;
        return 0;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    
    switch (message)
    {
    case WM_INITDIALOG:
       
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        int len = 0;
        if (LOWORD(wParam) == IDC_Huy || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        else if (LOWORD(wParam) == IDC_ThietLap) {
           len = GetWindowText(GetDlgItem(hDlg, IDC_NoiDung), txtNoiDung, 50);
           if (len == 0) {
               MessageBox(hDlg, L"Bạn chưa nhập nội dung", L"Thông báo", MB_OK | MB_ICONINFORMATION);
           }
           else{
               MessageBox(hDlg, L"Thiết lập thành công", L"Thông báo", MB_OK);
               EndDialog(hDlg, LOWORD(wParam));
               return (INT_PTR)TRUE;
           }
        }
        break;
    }
    return (INT_PTR)FALSE;
}
