


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ͷ�ļ�
#include "stdafx.h"
#include <strsafe.h>
#include <WinUser.h>
#include "BugTrace.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma comment(linker, "/EXPORT:CreateUploadBOSDDumpThread=_AheadLib_CreateUploadBOSDDumpThread,@1")
#pragma comment(linker, "/EXPORT:InitializeBugTrace=_AheadLib_InitializeBugTrace,@2")
#pragma comment(linker, "/EXPORT:SetBOSDDumpInfo=_AheadLib_SetBOSDDumpInfo,@3")
#pragma comment(linker, "/EXPORT:UploadBOSDDump=_AheadLib_UploadBOSDDump,@4")

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
PVOID pfnCreateUploadBOSDDumpThread;
PVOID pfnInitializeBugTrace;
PVOID pfnSetBOSDDumpInfo;
PVOID pfnUploadBOSDDump;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �궨��
#define EXTERNC extern "C"
#define NAKED __declspec(naked)
#define EXPORT __declspec(dllexport)

#define ALCPP EXPORT NAKED
#define ALSTD EXTERNC EXPORT NAKED void __stdcall
#define ALCFAST EXTERNC EXPORT NAKED void __fastcall
#define ALCDECL EXTERNC NAKED void __cdecl
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AheadLib �����ռ�
namespace AheadLib
{
	HMODULE m_hModule = NULL;	// ԭʼģ����
	DWORD m_dwReturn[4] = {0};	// ԭʼ�������ص�ַ

	void WINAPI GetAddress();

	// ����ԭʼģ��
	BOOL WINAPI Load()
	{
		CHAR tzPath[MAX_PATH];
		CHAR tzTemp[MAX_PATH * 2];

		strcpy_s(tzPath, TEXT("BugTrace_"));
		m_hModule = LoadLibraryA(tzPath);
		if (m_hModule == NULL)
		{
			sprintf_s(tzTemp, TEXT("�޷����� %s�������޷��������С�"), tzPath);
			//MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
		}
		else
			GetAddress();
		return (m_hModule != NULL);	
	}
		
	// �ͷ�ԭʼģ��
	VOID WINAPI Free()
	{
		if (m_hModule)
		{
			FreeLibrary(m_hModule);
		}
	}

	// ��ȡԭʼ������ַ
	FARPROC WINAPI GetAddress(PCSTR pszProcName)
	{
		FARPROC fpAddress;
		CHAR szProcName[16];
		TCHAR tzTemp[MAX_PATH];

		fpAddress = GetProcAddress(m_hModule, pszProcName);
		if (fpAddress == NULL)
		{
			if (HIWORD(pszProcName) == 0)
			{
				sprintf_s(szProcName, "%d", pszProcName);
				pszProcName = szProcName;
			}

			sprintf_s(tzTemp, TEXT("�޷��ҵ����� %hs�������޷��������С�"), pszProcName);
			//MessageBox(NULL, tzTemp, TEXT("AheadLib"), MB_ICONSTOP);
			ExitProcess(-2);
		}

		return fpAddress;
	}
	// ��ȡԭʼ������ַ
	void WINAPI GetAddress()
	{
		pfnCreateUploadBOSDDumpThread=GetAddress("CreateUploadBOSDDumpThread");
		pfnInitializeBugTrace=GetAddress("InitializeBugTrace");
		pfnSetBOSDDumpInfo=GetAddress("SetBOSDDumpInfo");
		pfnUploadBOSDDump=GetAddress("UploadBOSDDump");
	}
}
using namespace AheadLib;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��ں���
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, PVOID pvReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		return Load();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		Free();
	}

	return TRUE;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_CreateUploadBOSDDumpThread(void)
{
	__asm JMP pfnCreateUploadBOSDDumpThread;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_InitializeBugTrace(void)
{
	__asm JMP pfnInitializeBugTrace;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_SetBOSDDumpInfo(void)
{
	__asm JMP pfnSetBOSDDumpInfo;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������
ALCDECL AheadLib_UploadBOSDDump(void)
{
	__asm JMP pfnUploadBOSDDump;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////