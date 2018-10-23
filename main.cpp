#include <windows.h>

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_COMMAND:
             if(HIWORD(wParam) == CBN_SELCHANGE) {
                                        int ItemIndex = SendMessage((HWND) lParam, (UINT) CB_GETCURSEL, 
                (WPARAM) 0, (LPARAM) 0);
            TCHAR  ListItem[256];
            (TCHAR) SendMessage((HWND) lParam, (UINT) CB_GETLBTEXT, (WPARAM) ItemIndex, (LPARAM) ListItem);
                               }
             break;
		/* Upon destruction, tell the main thread to stop */
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
	
	HWND hPrzycisk;
	HWND hCheckbox;
	HWND hRadio;
	HWND hRamka;
	HWND hPobierz;
	HWND hText;
	
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

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Tost z mas3em i serem",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		650, /* width */
		350, /* height */
		NULL,NULL,hInstance,NULL);
	
		/* Lista rozwijana*/
		HWND hCombo = CreateWindowEx
		(WS_EX_CLIENTEDGE, "COMBOBOX"
		, "NULL", WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN,
			25, 45, 150, 150, hwnd, (HMENU)123, hInstance, NULL);
			
				/*zawartosc */
		SendMessage (hCombo, CB_ADDSTRING, 0,
		(LPARAM) "ELEMENT 1");
		SendMessage (hCombo, CB_ADDSTRING, 0,
		(LPARAM) "ELEMENT 2");
		SendMessage (hCombo, CB_ADDSTRING, 0,
		(LPARAM) "ELEMENT 3");
		
		/* pole tekstowe */
		HWND hText = CreateWindowEx
		(WS_EX_CLIENTEDGE, "EDIT"
		, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER ,
			200, 45, 100, 30, hwnd, (HMENU)456, hInstance, NULL);
		
        /* Lista rozwijana*/
		HWND hCombo2 = CreateWindowEx
		(WS_EX_CLIENTEDGE, "COMBOBOX"
		, "NULL", WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN,
			325, 45, 150, 150, hwnd, NULL, hInstance, NULL);
			
				/*zawartosc */
		SendMessage (hCombo2, CB_ADDSTRING, 0,
		(LPARAM) "ELEMENT 1");
		SendMessage (hCombo2, CB_ADDSTRING, 0,
		(LPARAM) "ELEMENT 2");
		SendMessage (hCombo2, CB_ADDSTRING, 0,
		(LPARAM) "ELEMENT 3");
        
        
        /* pole tekstowe */
		HWND hText2 = CreateWindowEx
		(WS_EX_CLIENTEDGE, "EDIT"
		, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER ,
			485, 45, 100, 30, hwnd, NULL, hInstance, NULL);
            	
		/*przycisk*/
		 hPrzycisk = CreateWindowEx
		(WS_EX_CLIENTEDGE, "BUTTON"
		, "przycisk", WS_CHILD | WS_VISIBLE,
		500, 250, 100, 30, hwnd, NULL, hInstance, NULL);
		
		

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

