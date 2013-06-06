#include <windows.h>
#include <queue>

#include "luamessage.h"

//Look-free queueÇ∆Ç©Ç‡Ç†ÇÈÇÒÇæÇÎÇ§ÇØÇ«Åc
static std::queue<LuaMessageCallback> q;

class CriticalSection {
	CRITICAL_SECTION cs;
	
public:
	CriticalSection() {
		InitializeCriticalSection(&cs);
	}
	~CriticalSection() {
		DeleteCriticalSection(&cs);
	}

	void enter() { EnterCriticalSection(&cs); }
	void leave() { LeaveCriticalSection(&cs); }
};
CriticalSection cs;

void postLuaMessage(LuaMessageCallback callback) {
	cs.enter();

	q.push(callback);

	cs.leave();
}

void processLuaMessages() {
	cs.enter();

	while(!q.empty()) {
		q.front()();
		q.pop();
	}

	cs.leave();
}

