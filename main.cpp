
#include "main.h"

BOOL Globals::sleepy = FALSE;
BOOL Globals::cachefix = FALSE;


BOOL WINAPI DllMain(HINSTANCE hDll,DWORD dwReason,LPVOID lpReserved) 
{
	if(dwReason==DLL_PROCESS_ATTACH) 
	{
		DisableThreadLibraryCalls(hDll);

		if(GetModuleHandleA("Game.exe"))
		{
			Install();
		}
	}
	if (dwReason == DLL_PROCESS_DETACH)
		RemovePatches();

	return TRUE;
}

VOID WINAPI Install()
{
	sLine *Command;

	ParseCommandLine(GetCommandLineA());
	
	/*Command = GetCommand("-cachefix");
	if(Command)
		Globals::cachefix = TRUE;

	Command = GetCommand("-sleepy");
	if(Command)
		Globals::sleepy = TRUE;*/

	DefineOffsets();
	InstallPatches();
	
	Command = GetCommand("-mpq");
	if(Command)
	{
		D2_InitMPQ(Command->szText, 0, 0, 3000);
	}
}

DWORD WINAPI Unload(LPVOID lpParam)
{
	Sleep(100);
	HMODULE hModule = NULL;
	GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)&DllMain, &hModule);
	FreeLibraryAndExitThread(hModule, 0);

	return 0;
}

VOID WINAPI Shutdown()
{
	//if (!Globals::cachefix && !Globals::sleepy)
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Unload,0,0,NULL);
}

