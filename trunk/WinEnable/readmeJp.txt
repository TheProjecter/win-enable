///////////////
// WinEnable //
///////////////


���̃A�v���̓E�B���h�E�̗L�� / ������؂�ւ��邱�Ƃ��ł��܂��B
�@�\
1. �E�B���h�E�̗L�� / ������؂�ւ��܂��B
2. �E�B���h�E�̕\�� / ��\����؂�ւ��܂��B
3. �v���O���������s���܂��B
4. �E�B���h�E��������܂őҋ@���܂��B
5. �ҋ@���܂��B
6. �����̋@�\��g�ݍ��킹�邱�Ƃ��ł��܂��B


===�g�p���@===
config.ini�ɃR�}���h���L�ڂ��AWinEnable.exe�����s���Ă��������B
config.ini�ɏ����ꂽSection�����ԂɎ��s���܂��B


===�R�}���h��===

---Notepad��\�����܂�---
Action    =Display
ClassName =Notepad
Display   =1

---Notepad���\���ɂ��܂�---
Action    =Display
ClassName =Notepad
Display   =0

---Notepad��L���ɂ��܂�---
Action    =Enable
ClassName =Notepad
Enable    =1

---Notepad�𖳌��ɂ��܂�---
Action    =Enable
ClassName =Notepad
Enable    =0

---���������N�����܂�---
Action    =Cmd
Cmd       =C:\Windows\system32\notepad.exe

---���� - ������ �Ƃ����^�C�g���� Notepad ��������܂őҋ@���܂�---
Action    =Find
Text      =���� - ������
ClassName =Notepad

---1�b�ҋ@���܂�---
Action    =Sleep
Sleep     =1000


===�u���O===
http://ameblo.jp/gizagizamax/
===SVN===
https://code.google.com/p/win-enable/
