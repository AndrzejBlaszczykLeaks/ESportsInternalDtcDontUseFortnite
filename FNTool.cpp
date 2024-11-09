#include "FNTool.h"
#include "spoof_call.h"
#include "Memory.h"
#include "safecall.h"
#include "encrypt.h"


bool FNTool::Initialize(uintptr_t GObjects, uintptr_t GetNameByIndex, uintptr_t FnFree)
{

	

	this->ObjectsCount = *(DWORD*)(GObjects + 0x14);
	if (this->ObjectsCount > 0x9000) this->ObjectsCount = 0x9000;

	uintptr_t GObjects_deref = *(uintptr_t*)GObjects;
	spoof_call(itsjustaispoof(IsBadWritePtr), (const LPVOID)GObjects_deref, (UINT_PTR)8);

	uintptr_t GObjects_deref2 = *(uintptr_t*)GObjects_deref;
	spoof_call(itsjustaispoof(IsBadWritePtr), (const LPVOID)GObjects_deref2, (UINT_PTR)8);

	this->UObjectArray = GObjects_deref2;
	this->GetNameByIndex = GetNameByIndex;
	this->FnFree = FnFree;

	return true;
}

BOOLEAN MaskCompare(PVOID buffer, LPCSTR pattern, LPCSTR mask) {
	for (auto b = reinterpret_cast<PBYTE>(buffer); *mask; ++pattern, ++mask, ++b) {
		if (*mask == 'x' && *reinterpret_cast<LPCBYTE>(pattern) != *b) {
			return FALSE;
		}
	}

	return TRUE;
}

PBYTE FindPattern2(LPCSTR pattern, LPCSTR mask) {
	MODULEINFO info = { 0 };
	GetModuleInformation(itsjustaispoof(GetCurrentProcess)(), GetModuleHandle(0), &info, sizeof(info));

	info.SizeOfImage -= static_cast<DWORD>(strlen(mask));

	for (auto i = 0UL; i < info.SizeOfImage; ++i) {
		auto addr = reinterpret_cast<PBYTE>(info.lpBaseOfDll) + i;
		if (MaskCompare(addr, pattern, mask)) {
			return addr;
		}
	}
}

uintptr_t FNTool::FindSignature(const char* Signature) {
	uintptr_t SigResult = MemoryHelper::Pattern::PatternScan(Signature);
	return SigResult;
}
void FNTool::cFixName(char* Name)
{
	for (int i = 0; Name[i] != '\0'; i++)
	{
		if (Name[i] == '_')
		{
			if (Name[i + 1] == '0' ||
				Name[i + 1] == '1' ||
				Name[i + 1] == '2' ||
				Name[i + 1] == '3' ||
				Name[i + 1] == '4' ||
				Name[i + 1] == '5' ||
				Name[i + 1] == '6' ||
				Name[i + 1] == '7' ||
				Name[i + 1] == '8' ||
				Name[i + 1] == '9')
				Name[i] = '\0';
		}
	}

	return;
}

void FNTool::FreeObjName(uintptr_t Address)
{
	if (Address == NULL) return;

	auto func = reinterpret_cast<__int64(__fastcall*)(__int64)>(this->FnFree);

	spoof_call( func, (__int64)Address);
}
