#include <windows.h>
#include <list>
#include <map>

#include "luaconsole.h"
#include "../main/win/main_win.h"
#include "../winproject/resource.h"


class LuaConsole {
	static std::list<LuaConsole*> allLuaConsoles;
	static std::map<HWND, LuaConsole*> hwndMap;
	HWND hwnd;

	static INT_PTR WINAPI dialogProc(HWND, UINT, WPARAM, LPARAM);

	LuaConsole() {
		hwnd = CreateDialog(
			app_hInstance,
			MAKEINTRESOURCE(IDD_LUACONSOLE),
			mainHWND, dialogProc);
	}

public:
	static void newLuaConsole() {
		LuaConsole *luaConsole = new LuaConsole();
		allLuaConsoles.push_back(luaConsole);
		hwndMap[luaConsole->hwnd] = luaConsole;
	}
};
std::list<LuaConsole*> LuaConsole::allLuaConsoles;
std::map<HWND, LuaConsole*> LuaConsole::hwndMap;

INT_PTR WINAPI LuaConsole::dialogProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	return FALSE;
}

