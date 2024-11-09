#pragma once
#include "include.h"
#include "custom_runtimes.h"
#include "custom_runtimes.cpp"
#include <sstream>
#include <fstream>

bool ShowMenu = true;
bool check = true;
UCanvas* static_canvas;


using DrawTransitionOrg = void(*)(uintptr_t _this, uintptr_t canvas);
DrawTransitionOrg DrawTransitionOriginal = 0;
APlayerController* PlayerController;


#pragma region trackingfilesblocker

//real winapi function
HANDLE(WINAPI* Real_CreateFileW) (
	LPCWSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile) = CreateFileW;

//real winapi function
BOOL(WINAPI* Real_CreateDirectoryW) (
	LPCWSTR lpPathName,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectoryW;


//our own hooked function
HANDLE WINAPI _CreateFileW(LPCWSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile)
{
	//ignore pak, sig files and anything to fortnite and pipes
	if (wcsstr(lpFileName, e(L".pak")) || wcsstr(lpFileName, e(L".sig")) || wcsstr(lpFileName, e(L"Fortnite")) || wcsstr(lpFileName, e(L"\\.\\")))
		return Real_CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	else
		return Real_CreateFileW(e(L"C:\\Windows\\a"), dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

//our own hooked function
BOOL WINAPI _CreateDirectoryW(LPCWSTR lpPathName,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	//ignore fortnite folder creation
	if (wcsstr(lpPathName, e(L"Fortnite")))
		return Real_CreateDirectoryW(lpPathName, lpSecurityAttributes);
	else
		return Real_CreateDirectoryW(e(L"C:\\Windows\\a"), lpSecurityAttributes);
}

typedef struct _OBJECT_ATTRIBUTES {
	ULONG Length;
	HANDLE RootDirectory;
	PUNICODE_STRING ObjectName;
	ULONG Attributes;
	PVOID SecurityDescriptor;
	PVOID SecurityQualityOfService;
} OBJECT_ATTRIBUTES;
typedef OBJECT_ATTRIBUTES* POBJECT_ATTRIBUTES;
typedef struct _IO_STATUS_BLOCK {
#pragma warning(push)
#pragma warning(disable: 4201) // we'll always use the Microsoft compiler
	union {
		NTSTATUS Status;
		PVOID Pointer;
	} DUMMYUNIONNAME;
#pragma warning(pop)

	ULONG_PTR Information;
} IO_STATUS_BLOCK, * PIO_STATUS_BLOCK;
typedef
VOID
(NTAPI* PIO_APC_ROUTINE) (
	IN PVOID ApcContext,
	IN PIO_STATUS_BLOCK IoStatusBlock,
	IN ULONG Reserved
	);



typedef NTSTATUS(NTAPI* p_NtCreateFile)(PHANDLE FileHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PIO_STATUS_BLOCK IoStatusBlock, PLARGE_INTEGER AllocationSize, ULONG FileAttributes, ULONG ShareAccess, ULONG CreateDisposition, ULONG CreateOptions, PVOID EaBuffer, ULONG EaLength);
#define SERVICE_PROXY_KERNEL	L"\\??\\pipe\\11010"
static p_NtCreateFile o_NtCreateFile;
typedef VOID(WINAPI* p_RtlInitUnicodeString)(PUNICODE_STRING Object, LPCWSTR String);
static p_RtlInitUnicodeString o_RtlInitUnicodeString;
NTSTATUS NTAPI NtCreateFile_Hook(PHANDLE FileHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, PIO_STATUS_BLOCK IoStatusBlock, PLARGE_INTEGER AllocationSize, ULONG FileAttributes, ULONG ShareAccess, ULONG CreateDisposition, ULONG CreateOptions, PVOID EaBuffer, ULONG EaLength)
{
	
	DWORD dwWritten = 0;
	NTSTATUS Status = -1;
	if (ObjectAttributes &&
		ObjectAttributes->ObjectName &&
		ObjectAttributes->ObjectName->Buffer &&
		wcsstr(ObjectAttributes->ObjectName->Buffer, L"BattlEye") &&
		wcsstr(ObjectAttributes->ObjectName->Buffer, L"pipe")) // the pipename is \\??\\pipe\\BattlEye 内核名字和应用层不一样
	{

	
		o_RtlInitUnicodeString(ObjectAttributes->ObjectName, SERVICE_PROXY_KERNEL);
		MessageBoxA(0, e("yes yes"), e("pysen"), MB_OK | MB_ICONERROR);
		NTSTATUS Status = o_NtCreateFile(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, AllocationSize, FileAttributes, ShareAccess, CreateDisposition, CreateOptions, EaBuffer, EaLength);


		return Status;
	}
	
	return o_NtCreateFile(FileHandle, DesiredAccess, ObjectAttributes, IoStatusBlock, AllocationSize, FileAttributes, ShareAccess, CreateDisposition, CreateOptions, EaBuffer, EaLength);

};
BOOL GetFileNameFromHandle(HANDLE hFile, std::string& fileName)
{
	DWORD size = MAX_PATH * sizeof(WCHAR) + sizeof(DWORD);
	FILE_NAME_INFO* Path = (FILE_NAME_INFO*)malloc(size);
	memset(Path, 0, size);
	BOOL ret = GetFileInformationByHandleEx(hFile, FILE_INFO_BY_HANDLE_CLASS::FileNameInfo, Path, size);
	if (!ret) return false;
	std::wstring wstr = Path->FileName;
	fileName = std::string(wstr.begin(), wstr.end());
	free(Path);
	return true;
}
std::ostringstream OutputBuffer;
void hex_dump(PVOID Buffer, size_t length, std::ostringstream& OutputBuffer) {
	OutputBuffer.str("");
	OutputBuffer.clear();
	OutputBuffer << "│ ";
	for (size_t i = 0; i < length; i++)
	{
		OutputBuffer.fill('0');
		OutputBuffer.width(2);
		OutputBuffer << std::hex << (int)(*((unsigned char*)Buffer + i));
		OutputBuffer << " ";
	}
	OutputBuffer << std::endl << "│ ";
	for (size_t i = 0; i < length; i++)
	{
		OutputBuffer << *((unsigned char*)Buffer + i);
	}
}
BOOL(WINAPI* Real_ReadFile)(HANDLE a0,
	LPVOID a1,
	DWORD a2,
	LPDWORD a3,
	LPOVERLAPPED a4)
	= ReadFile;
BOOL(WINAPI* Real_WriteFile)(HANDLE hFile,
	LPCVOID lpBuffer,
	DWORD nNumberOfBytesToWrite,
	LPDWORD lpNumberOfBytesWritten,
	LPOVERLAPPED lpOverlapped)
	= WriteFile;
NTSTATUS NTAPI ZwReadFile_Hook(HANDLE a0,
	LPVOID a1,
	DWORD a2,
	LPDWORD a3,
	LPOVERLAPPED a4)
{
	std::string fileName;
	if (GetFileNameFromHandle(a0, fileName))
	{
		bool isBattlEye = fileName.compare("\\BattlEye") == 0;
		if (isBattlEye) {
		//	MessageBoxA(0, e("BattlEye"), e("pysen"), MB_OK | MB_ICONERROR);
		
			DWORD cbWritten;

			hex_dump(a1, a2, OutputBuffer);
			if (a2 < 10)
				return  Real_ReadFile(a0, a1, a2, a3, a4);
			std::string fileName1 = OutputBuffer.str();
			bool a = fileName1.find("fVfRfOfFf");
			if (a != std::string::npos) {
	//			MessageBoxA(0, e("BattlEye fVfRfOfFf"), e("pysen"), MB_OK | MB_ICONERROR);
				return Real_ReadFile(a0, a1, a2, a3, a4);

			}
			else
				return 0;

			
		}
		return Real_ReadFile(a0, a1, a2, a3, a4);
	}
	return Real_ReadFile(a0, a1, a2, a3, a4);
}

NTSTATUS NTAPI ZwWriteFile_Hook(HANDLE hFile,
	PVOID lpBuffer,
	DWORD nNumberOfBytesToWrite,
	LPDWORD lpNumberOfBytesWritten,
	LPOVERLAPPED lpOverlapped)
{
	std::string fileName;
	if (GetFileNameFromHandle(hFile, fileName))
	{
		bool isBattlEye = fileName.compare("\\BattlEye") == 0;
		if (isBattlEye) {
		//	MessageBoxA(0, e("BattlEye"), e("pysen"), MB_OK | MB_ICONERROR);
			
			DWORD cbWritten;

			hex_dump(lpBuffer, nNumberOfBytesToWrite, OutputBuffer);
			if (nNumberOfBytesToWrite < 10)
				return  Real_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
			std::string fileName1 = OutputBuffer.str();
			bool a = fileName1.find("fVfRfOfFf");
			if (a != std::string::npos) {
			//	MessageBoxA(0, e("BattlEye fVfRfOfFf"), e("pysen"), MB_OK | MB_ICONERROR);
				return Real_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);

			}
			else
				return 0;

		
		}
		
		
		return Real_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
	}
	return Real_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
	
	
}

#pragma endregion trackingfilesblocker
class UGameViewportClient
{
public:


};

void itsjustai() {
	
	
}



float color_speed = -10.0;