#pragma once
#include "include.h"
#include <Windows.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include "safecall.h"
#include "encrypt.h"

#include "FNTool.h"
#include "VMTHook.h"
#include "DrawTransition.h"
#include "shit.h"
#include "actorloop.h"
#include "gui.h"
#include "menu.h"

class FText {
private:
	char _padding_[0x28];
	PWCHAR Name;
	DWORD Length;
public:


	inline PWCHAR c_wstr() {
		return Name;
	}

	inline char* c_str()
	{

		char sBuff[255];
		wcstombs((char*)sBuff, (const wchar_t*)this->Name, sizeof(sBuff));
		return sBuff;
	}
};


 void actorloop() {

 }

