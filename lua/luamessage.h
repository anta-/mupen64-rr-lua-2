//���C���̃X���b�h(�E�B���h�E�֘A)�Ƃ͕ʂ�EmuThread������̂ŁA
//lua�ł͑S�Ă̏�����(�N�����Ă���Ȃ�)EmuThread�ł�点�����̂ŁA
//���̂��߂Ƀ��b�Z�[�W�L���[���Ǘ�����

#ifndef LUAMESSAGE_H
#define LUAMESSAGE_H

typedef void (*LuaMessageCallback)(void);

void postLuaMessage(LuaMessageCallback callback) ;
void processLuaMessage(void) ;

#endif
