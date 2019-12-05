#pragma once

#include "Offset.h"
#include "D2Intercepts.h"

PatchHook pHooks[] = {
	{PatchCall, GetOffset(0x0F5623), (DWORD)Multi, 6}, // 1.14d
	{PatchCall, GetOffset(0x0F5831), (DWORD)Windowname, 6}, // 1.14d
	{PatchJmp,  GetOffset(0x33809), (DWORD)InitMainMenu, 5} // 1.14d
//	{PatchCall, GetOffset(0x11944E), (DWORD)CacheFix, 6},
//	{PatchCall, GetOffset(0x119434), (DWORD)CacheFix, 6}
//	{PatchJmp,	GetOffset(0x053B30), (DWORD)GameDraw_STUB, 6}
};
