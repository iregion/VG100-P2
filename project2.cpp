#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	int end = 0;
	HANDLE hComl = CreateFile("\\\\.\\COM13", GENERIC_READ | GENERIC_WRITE,
		0, NULL, OPEN_EXISTING, 0, NULL);
	HANDLE hComr = CreateFile("\\\\.\\COM15", GENERIC_READ | GENERIC_WRITE,
		0, NULL, OPEN_EXISTING, 0, NULL);
	if (hComr == (HANDLE)-1 || hComl == (HANDLE)-1)
	{
		cout << MessageBox(NULL, "False!", "Warning", MB_OK) << endl;
		return FALSE;
	}

	SetupComm(hComl, 1024, 1024);
	SetupComm(hComr, 1024, 1024);
	COMMTIMEOUTS TimeOuts;
	TimeOuts.ReadIntervalTimeout = 0;
	TimeOuts.ReadTotalTimeoutMultiplier = 0;
	TimeOuts.ReadTotalTimeoutConstant = 0;
	TimeOuts.WriteTotalTimeoutMultiplier = 0;
	TimeOuts.WriteTotalTimeoutConstant = 0;
	SetCommTimeouts(hComl, &TimeOuts);
	SetCommTimeouts(hComr, &TimeOuts);
	DCB dcbl, dcbr;
	GetCommState(hComl, &dcbl);
	dcbl.BaudRate = 9600;
	dcbl.ByteSize = 8;
	dcbl.Parity = NOPARITY;
	dcbl.StopBits = ONESTOPBIT;
	SetCommState(hComl, &dcbl);
	PurgeComm(hComl, PURGE_TXCLEAR | PURGE_RXCLEAR);

	GetCommState(hComr, &dcbr);
	dcbr.BaudRate = 9600;
	dcbr.ByteSize = 8;
	dcbr.Parity = NOPARITY;
	dcbr.StopBits = ONESTOPBIT;
	SetCommState(hComr, &dcbr);
	PurgeComm(hComr, PURGE_TXCLEAR | PURGE_RXCLEAR);

	while (end == 0)
	{
		char strl, strr;
		DWORD wCountl, wCountr;
		
		ReadFile(hComl, &strl, 1, &wCountl, NULL);

		if (strl >= -128 && strl <= -103)
		{
			keybd_event(strl + 193, 0, 0, 0);
			keybd_event(strl + 193, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strl >= -102 && strl <= -77)
		{
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(strl + 167, 0, 0, 0);
			keybd_event(strl + 167, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strl >= -76 && strl <= -67)
		{
			keybd_event(strl + 124, 0, 0, 0);
			keybd_event(strl + 124, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strl == -66)
		{
			keybd_event(8, 0, 0, 0);
			keybd_event(8, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strl == -65)
		{
			keybd_event(13, 0, 0, 0);
			keybd_event(13, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strl == -64)
		{
			keybd_event(188, 0, 0, 0);
			keybd_event(188, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strl == -63)
		{
			keybd_event(110, 0, 0, 0);
			keybd_event(110, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strl == -62)
		{
			keybd_event(32, 0, 0, 0);
			keybd_event(32, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strl == -61)
		{
			keybd_event(20, 0, 0, 0);
			keybd_event(20, 0, KEYEVENTF_KEYUP, 0);
		}
		

		ReadFile(hComr, &strr, 1, &wCountr, NULL);
		if (strr >= -128 && strr <= -103)
		{
			keybd_event(strr + 193, 0, 0, 0);
			keybd_event(strr + 193, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strr >= -102 && strr <= -77)
		{
			keybd_event(VK_SHIFT, 0, 0, 0);
			keybd_event(strr + 167, 0, 0, 0);
			keybd_event(strr + 167, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strr >= -76 && strr <= -67)
		{
			keybd_event(strr + 124, 0, 0, 0);
			keybd_event(strr + 124, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strr == -66)
		{
			keybd_event(8, 0, 0, 0);
			keybd_event(8, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strr == -65)
		{
			keybd_event(13, 0, 0, 0);
			keybd_event(13, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strr == -64)
		{
			keybd_event(188, 0, 0, 0);
			keybd_event(188, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strr == -63)
		{
			keybd_event(110, 0, 0, 0);
			keybd_event(110, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strr == -62)
		{
			keybd_event(32, 0, 0, 0);
			keybd_event(32, 0, KEYEVENTF_KEYUP, 0);
		}
		else if (strr == -61)
		{
		keybd_event(20, 0, 0, 0);
		keybd_event(20, 0, KEYEVENTF_KEYUP, 0);
		}

	}
	CloseHandle(hComl);
	CloseHandle(hComr);
	return TRUE;
}