///////////////
// WinEnable //
///////////////


このアプリはウィンドウの有効 / 無効を切り替えることができます。
機能
1. ウィンドウの有効 / 無効を切り替えます。
2. ウィンドウの表示 / 非表示を切り替えます。
3. プログラムを実行します。
4. ウィンドウが見つかるまで待機します。
5. 待機します。
6. これらの機能を組み合わせることができます。


===使用方法===
config.iniにコマンドを記載し、WinEnable.exeを実行してください。
config.iniに書かれたSectionを順番に実行します。


===コマンド例===

---Notepadを表示します---
Action    =Display
ClassName =Notepad
Display   =1

---Notepadを非表示にします---
Action    =Display
ClassName =Notepad
Display   =0

---Notepadを有効にします---
Action    =Enable
ClassName =Notepad
Enable    =1

---Notepadを無効にします---
Action    =Enable
ClassName =Notepad
Enable    =0

---メモ帳を起動します---
Action    =Cmd
Cmd       =C:\Windows\system32\notepad.exe

---無題 - メモ帳 というタイトルの Notepad が見つかるまで待機します---
Action    =Find
Text      =無題 - メモ帳
ClassName =Notepad

---1秒待機します---
Action    =Sleep
Sleep     =1000


===ブログ===
http://ameblo.jp/gizagizamax/
===SVN===
https://code.google.com/p/win-enable/
