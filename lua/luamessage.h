//MainThread(�E�B���h�E�֘A)�Ƃ͕ʂ�EmuThread������̂ŁA
//lua�̑S�Ă̏�����EmuThread�ł�点�����̂ŁA
//���̂��߂Ƀ��b�Z�[�W�L���[���Ǘ�����B
//MainThread����EmuThread�œ��������������݂̂�post����B
//MainThread�ł�肽���̂́AmainThread�ɂ���Ȃ炻�̏�ŌĂׂ΂����B
//EmuThread����MainThread�ł�肽���ꍇ��SendMessage/PostMessage����΂����B

#ifndef LUAMESSAGE_H
#define LUAMESSAGE_H

typedef void (*LuaMessageCallback)(void);

void postLuaMessage(LuaMessageCallback callback);
void processLuaMessages();

#endif
