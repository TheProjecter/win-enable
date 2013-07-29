///////////////
// WinEnable //
///////////////


This app can switch a enable of the window.
Functions
1. Switch a window Enable / Disable.
2. Switch a window Show / Hide.
3. Execute a program.
4. Wait until find a window.
5. Sleep.
6. You can combine these features.


===How to use===
Write some commands in config.ini , Execute a WinEnable.exe .
This app run in order to some sections written in config.ini.


===Example command===

---Show Notepad---
Action    =Display
ClassName =Notepad
Display   =1

---Hide Notepad---
Action    =Display
ClassName =Notepad
Display   =0

---Enable Notepad---
Action    =Enable
ClassName =Notepad
Enable    =1

---Disable Notepad---
Action    =Enable
ClassName =Notepad
Enable    =0

---Run notepad---
Action    =Cmd
Cmd       =C:\Windows\system32\notepad.exe

---This app will wait title entitled "Untitled - Notepad" until find---
Action    =Find
Text      =Untitled - Notepad
ClassName =Notepad

---Wait a sec---
Action    =Sleep
Sleep     =1000


===blog===
http://ameblo.jp/gizagizamax/
===SVN===
https://code.google.com/p/win-enable/
