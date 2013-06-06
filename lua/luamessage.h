//MainThread(ウィンドウ関連)とは別にEmuThreadがあるので、
//luaの全ての処理をEmuThreadでやらせたいので、
//そのためにメッセージキューを管理する。
//MainThreadからEmuThreadで動かしたい処理のみをpostする。
//MainThreadでやりたいのは、mainThreadにいるならその場で呼べばいい。
//EmuThreadからMainThreadでやりたい場合はSendMessage/PostMessageすればいい。

#ifndef LUAMESSAGE_H
#define LUAMESSAGE_H

typedef void (*LuaMessageCallback)(void);

void postLuaMessage(LuaMessageCallback callback);
void processLuaMessages();

#endif
