//メインのスレッド(ウィンドウ関連)とは別にEmuThreadがあるので、
//luaでは全ての処理を(起動しているなら)EmuThreadでやらせたいので、
//そのためにメッセージキューを管理する

#ifndef LUAMESSAGE_H
#define LUAMESSAGE_H

typedef void (*LuaMessageCallback)(void);

void postLuaMessage(LuaMessageCallback callback) ;
void processLuaMessage(void) ;

#endif
