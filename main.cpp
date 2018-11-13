#include <windows.h>
#include <stdio.h>
#define IDD_DLGFIRST 101


	static HWND cb_handle = 0;
    static HWND cb_handle2 = 0;
	 HWND hText;
    static HWND g_hPrzycisk;
    static int pozycja_1 = 0;
    static int pozycja_2 = 0;
    static int pozycja_3 = 0;
    static int pozycja_4 = 0;
    static int pozycja_5 = 0;
    static int pozycja_6 = 0;
    static int pozycja_7 = 0;
    static int pozycja_8 = 0;
    static int pozycja_9 = 0;
    static int pozycja_10 = 0;
    static int pozycja_11 = 0;
    static int pozycja_12 = 0;
    static int pozycja_13 = 0;
    static int pozycja_14 = 0;
    static int pozycja_15 = 0;
    static int pozycja_16 = 0;
    static int pozycja_17 = 0;
    static int pozycja_18 = 0;
    static int pozycja_19 = 0;
    static int pozycja_20 = 0;
    static int pozycja_21 = 0; 
    static int pozycja_22 = 0;
    char buff[1024];
    float stala_1;
    float stala_2;
    int x;
    float z=0;
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {	
			case WM_CREATE:
				
			hText = CreateWindowEx
			(WS_EX_CLIENTEDGE, "EDIT"
			, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER ,
			200, 45, 100, 30, hwnd, (HMENU)5,((LPCREATESTRUCT)lParam)->hInstance,NULL);
		
			
			/* Lista rozwijana*/
		cb_handle = CreateWindowEx
		(WS_EX_CLIENTEDGE, "COMBOBOX"
		, "NULL", WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWN,
			25, 45, 150, 150, hwnd, NULL,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			
				/*zawartosc */
             pozycja_1 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"kilometr (km)");
             pozycja_2 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"metr (m)");
             pozycja_3 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"decymetr (dm)");
             pozycja_4 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"centymetr (cm)");
             pozycja_5 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"milimetr (mm)");
             pozycja_6 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"cal (in)");
             pozycja_7 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"stopa (ft)");
             pozycja_8 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"jard (yd)");
             pozycja_9 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"sążeń (fm)");
             pozycja_10 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"mila (M)");
             pozycja_11 = SendMessage(cb_handle, CB_ADDSTRING,0, (LPARAM)"mila morska (Mn)");
			
			/* Lista rozwijana2*/
		cb_handle2 = CreateWindowEx
		(WS_EX_CLIENTEDGE, "COMBOBOX"
		, "NULL", WS_CHILD | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWN,
			325, 45, 150, 150, hwnd, NULL,((LPCREATESTRUCT)lParam)->hInstance,NULL);
			
				/*zawartosc */
             pozycja_12 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"kilometr (km)");
             pozycja_13 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"metr (m)");
             pozycja_14 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"decymetr (dm)");
             pozycja_15 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"centymetr (cm)");
             pozycja_16 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"milimetr (mm)");
             pozycja_17 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"cal (in)");
             pozycja_18 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"stopa (ft)");
             pozycja_19 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"jard (yd)");
             pozycja_20 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"sążeń (fm)");
             pozycja_21 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"mila (M)");
             pozycja_22 = SendMessage(cb_handle2, CB_ADDSTRING,0, (LPARAM)"mila morska (Mn)");
			
			break;
		case WM_COMMAND:
             if (lParam == (LPARAM)cb_handle && HIWORD (wParam) == CBN_SELENDOK)
             {
                 //jesli wybor sie zmienil to sprawdzamy jaka aktualnie
                 //pozycja jest wybrana
                 int iIndex = SendMessage(cb_handle, CB_GETCURSEL, 0, 0);
                 //i jesli to pozycja 3 wyswietlamy komunikat
                 if (pozycja_1 == iIndex)
                 {
						stala_1=1000;
                 }
                 else if (pozycja_2 == iIndex)
                 {
						stala_1=1;
                 }
                  else if (pozycja_3 == iIndex)
                 {
                 		stala_1=0.1;                                         
                 }
                  else if (pozycja_4 == iIndex)
                 {
						stala_1=0.01;
                 }
                  else if (pozycja_5 == iIndex)
                 {
						stala_1=0.001;
                 }
                 else if (pozycja_6 == iIndex)
                 {
						stala_1=0.0254;
                 }
                 else if (pozycja_7 == iIndex)
                 {
						stala_1=0.2048;
                 }
                 else if (pozycja_8 == iIndex)
                 {
						stala_1=0.9144;
                 }
                 else if (pozycja_9 == iIndex)
                 {
						stala_1=1.8288;
                 }
                 else if (pozycja_10 == iIndex)
                 {
						stala_1=1609.344;
                 }
                 else if (pozycja_11 == iIndex)
                 {
						stala_1=1852;
                 }
             }
             
              if (lParam == (LPARAM)cb_handle2 && HIWORD (wParam) == CBN_SELENDOK)
             {
                 //jesli wybor sie zmienil to sprawdzamy jaka aktualnie
                 //pozycja jest wybrana
                 int iIndex = SendMessage(cb_handle2, CB_GETCURSEL, 0, 0);
                
                 if (pozycja_12 == iIndex)
                 {
						stala_1=1000;
                 }
                 else if (pozycja_13 == iIndex)
                 {
						stala_2=1;
                 }
                  else if (pozycja_14 == iIndex)
                 {
                 		stala_2=0.1;                                         
                 }
                  else if (pozycja_15 == iIndex)
                 {
						stala_2=0.01;
                 }
                  else if (pozycja_16 == iIndex)
                 {
						stala_2=0.001;
                 }
                 else if (pozycja_17 == iIndex)
                 {
						stala_2=0.0254;
                 }
                 else if (pozycja_18 == iIndex)
                 {
						stala_2=0.2048;
                 }
                 else if (pozycja_19 == iIndex)
                 {
						stala_2=0.9144;
                 }
                 else if (pozycja_20 == iIndex)
                 {
						stala_2=1.8288;
                 }
                 else if (pozycja_21 == iIndex)
                 {
						stala_2=1609.344;
                 }
                 else if (pozycja_22 == iIndex)
                 {
						stala_2=1852;
                 }
             }
             x = GetDlgItemInt(hwnd, 5, NULL, TRUE);
             
             z=x*stala_1/stala_2 ;
              sprintf(buff, " %f",z);
			
                          if (lParam == (LPARAM)g_hPrzycisk)
			 
                         MessageBox(hwnd, buff, "Wynik", MB_OK | MB_ICONQUESTION);
     
             break;
		
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}
	LPSTR NazwaKlasy = "klasa";
	
	MSG Komunikat;
	
	
	HWND hCheckbox;
	HWND hRadio;
	HWND hRamka;
	HWND hPobierz;

	
	LRESULT CALLBACK WndProc (HWND hwnd, UINT msg
								, WPARAM wParam
								, LPARAM lParam);
	
/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

		
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Konwerter jednostek dlugosci",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		650, /* width */
		350, /* height */
		NULL,NULL,hInstance,NULL);
		

 
	
	
		
		

		
                 //jesli wybor sie zmienil to sprawdzamy jaka aktualnie
                 //pozycja jest wybrana
                 
		
		/* pole tekstowe */
			
			
						
		
		
        
        
			

         	   	
		/*przycisk*/
		 g_hPrzycisk = CreateWindowEx( 0, "BUTTON", "Oblicz", WS_CHILD | WS_VISIBLE,
			100, 100, 150, 30, hwnd, NULL, hInstance, NULL );
			

		
		

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
