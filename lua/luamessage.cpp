#include <windows.h>
#include <queue>

#include "luamessage.h"

//Look-free queue�Ƃ�������񂾂낤���ǁc
static std::queue<LuaMessageCallback> q;
static CRITICAL_SECTION cs;

void postLuaMessage(LuaMessageCallback callback) {
	EnterCriticalSection(&cs);

	q.push(callback);

	LeaveCriticalSection(&cs);
}

void processLuaMessage(void) {
	EnterCriticalSection(&cs);

	while(!q.empty()) {
		q.front()();
		q.pop();
	}

	LeaveCriticalSection(&cs);
}

