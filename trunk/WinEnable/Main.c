#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <WinUser.h>

///////////////
// struct
///////////////

//config.ini
struct WESection{
	int   _Index;
	TCHAR _Section   [0xFF];
	TCHAR _Text      [0xFF];
	TCHAR _ClassName [0xFF];
	TCHAR _Action    [0xFF];
	TCHAR _Enable    [0xFF];
	TCHAR _Display   [0xFF];
	TCHAR _Find      [0xFF];
	TCHAR _Sleep     [0xFF];
	TCHAR _Cmd       [0xFF];
};
struct WEConfig{
	       int       _Length;
	       int       _CurrentIndex;
	struct WESection _WESection[0xFF];
};

///////////////
// Member
///////////////
struct WEConfig     _WEConfig;     //config.ini
       BOOL         _Found;        //Find

///////////////
// Method
///////////////
void ReadConfig(){
	int i;
	TCHAR strCurrentDirectory [0xFF];
	TCHAR strFullPath         [0xFF];
	TCHAR strAppName          [0xFF];

	// 実行パス
	GetCurrentDirectory( 0xFF, strCurrentDirectory);
	sprintf_s(strFullPath, 0xFF, "%s\\%s", strCurrentDirectory, "config.ini");

	// コンフィグ読み込み
	for(i = 0 ; i < 0xFF ; i++){
		_WEConfig._WESection[i]._Index = i;

		sprintf_s(strAppName, 0xFF, "Section%d", i);

		GetPrivateProfileString(strAppName, "Text"      , "" , _WEConfig._WESection[i]._Text      , 0x0FF , strFullPath);
		GetPrivateProfileString(strAppName, "ClassName" , "" , _WEConfig._WESection[i]._ClassName , 0x0FF , strFullPath);
		GetPrivateProfileString(strAppName, "Action"    , "" , _WEConfig._WESection[i]._Action    , 0x0FF , strFullPath);
		GetPrivateProfileString(strAppName, "Enable"    , "" , _WEConfig._WESection[i]._Enable    , 0x0FF , strFullPath);
		GetPrivateProfileString(strAppName, "Display"   , "" , _WEConfig._WESection[i]._Display   , 0x0FF , strFullPath);
		GetPrivateProfileString(strAppName, "Sleep"     , "" , _WEConfig._WESection[i]._Sleep     , 0x0FF , strFullPath);
		GetPrivateProfileString(strAppName, "Cmd"       , "" , _WEConfig._WESection[i]._Cmd       , 0x0FF , strFullPath);

		// Enable
		if ( strncmp(_WEConfig._WESection[i]._Action   , _T("Enable") , 0xFF) == 0 &&
			(strncmp(_WEConfig._WESection[i]._Enable   , _T("1")      , 0xFF) == 0 ||
			 strncmp(_WEConfig._WESection[i]._Enable   , _T("0")      , 0xFF) == 0)) {

			printf("[%s]\n"          , strAppName);
			printf("Action    =%s\n" , _WEConfig._WESection[i]._Action);
			printf("Enable    =%s\n" , _WEConfig._WESection[i]._Enable);
			printf("\n");

			_WEConfig._Length = i + 1;
			continue;
		}

		// Display
		if ( strncmp(_WEConfig._WESection[i]._Action  , _T("Display") , 0xFF) == 0 &&
			(strncmp(_WEConfig._WESection[i]._Display , _T("1")       , 0xFF) == 0 ||
			 strncmp(_WEConfig._WESection[i]._Display , _T("0")       , 0xFF) == 0)) {

			printf("[%s]\n"          , strAppName);
			printf("Action    =%s\n" , _WEConfig._WESection[i]._Action);
			printf("Display   =%s\n" , _WEConfig._WESection[i]._Display);
			printf("\n");

			_WEConfig._Length = i + 1;
			continue;
		}

		// Find
		if ( strncmp(_WEConfig._WESection[i]._Action    , _T("Find")     , 0xFF) == 0 &&
			(strncmp(_WEConfig._WESection[i]._Text      , _T("")        , 0xFF) != 0 ||
			 strncmp(_WEConfig._WESection[i]._ClassName , _T("")        , 0xFF) != 0)) {

			printf("[%s]\n"          , strAppName);
			printf("Action    =%s\n" , _WEConfig._WESection[i]._Action);
			printf("Text      =%s\n" , _WEConfig._WESection[i]._Text);
			printf("ClassName =%s\n" , _WEConfig._WESection[i]._ClassName);
			printf("\n");

			_WEConfig._Length = i + 1;
			continue;
		}

		// Sleep
		if ( strncmp(_WEConfig._WESection[i]._Action    , _T("Sleep")   , 0xFF) == 0 &&
			 strncmp(_WEConfig._WESection[i]._Sleep     , _T("")        , 0xFF) != 0) {

			printf("[%s]\n"          , strAppName);
			printf("Action    =%s\n" , _WEConfig._WESection[i]._Action);
			printf("Sleep     =%s\n" , _WEConfig._WESection[i]._Sleep);
			printf("\n");

			_WEConfig._Length = i + 1;
			continue;
		}

		// Cmd
		if ( strncmp(_WEConfig._WESection[i]._Action  , _T("Cmd")     , 0xFF) == 0 &&
			 strncmp(_WEConfig._WESection[i]._Cmd     , _T("")        , 0xFF) != 0 ) {

			printf("[%s]\n"          , strAppName);
			printf("Action    =%s\n" , _WEConfig._WESection[i]._Action);
			printf("Cmd       =%s\n" , _WEConfig._WESection[i]._Cmd);
			printf("\n");

			_WEConfig._Length = i + 1;
			continue;
		}

		// Error
		if (strncmp(_WEConfig._WESection[i]._Text      , _T("")        , 0xFF) != 0 ||
			strncmp(_WEConfig._WESection[i]._ClassName , _T("")        , 0xFF) != 0 ||
			strncmp(_WEConfig._WESection[i]._Action    , _T("")        , 0xFF) != 0 ||
			strncmp(_WEConfig._WESection[i]._Enable    , _T("")        , 0xFF) != 0 ||
			strncmp(_WEConfig._WESection[i]._Display   , _T("")        , 0xFF) != 0 ||
			strncmp(_WEConfig._WESection[i]._Sleep     , _T("")        , 0xFF) != 0 ||
			strncmp(_WEConfig._WESection[i]._Cmd       , _T("")        , 0xFF) != 0 ) {

			printf("Can not understand a Section .\n");
			printf("[%s]\n"          , strAppName);
			printf("Action    =%s\n" , _WEConfig._WESection[i]._Action);
			printf("Text      =%s\n" , _WEConfig._WESection[i]._Text);
			printf("ClassName =%s\n" , _WEConfig._WESection[i]._ClassName);
			printf("Enable    =%s\n" , _WEConfig._WESection[i]._Enable);
			printf("Display   =%s\n" , _WEConfig._WESection[i]._Display);
			printf("Sleep     =%s\n" , _WEConfig._WESection[i]._Sleep);
			printf("Cmd       =%s\n" , _WEConfig._WESection[i]._Cmd);
		}

		break;
	}
};

BOOL ValidateConfig(){
	if(_WEConfig._Length == 0){
		printf("Can not read a config.ini .");
		return FALSE;
	}

	return TRUE;
}

BOOL CALLBACK ExecEnable(HWND hwnd, LPARAM lParam){
	TCHAR strText[0xFF];
	TCHAR strClassName[0xFF];

	//Window
	GetWindowText(hwnd , strText      , 0xFF);
	GetClassName( hwnd , strClassName , 0xFF);

	if(	(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Text      , _T("")       , 0xFF) == 0 ||
		 strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Text      , strText      , 0xFF) == 0 ) &&
		(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._ClassName , _T("")       , 0xFF) == 0 ||
		 strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._ClassName , strClassName , 0xFF) == 0 ) ){

		if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Enable  , _T("1") , 0xFF) == 0){ EnableWindow(hwnd , TRUE   );}
		if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Enable  , _T("0") , 0xFF) == 0){ EnableWindow(hwnd , FALSE  );}
	}

	return TRUE;
};

BOOL CALLBACK ExecDisplay(HWND hwnd, LPARAM lParam){
	TCHAR strText[0xFF];
	TCHAR strClassName[0xFF];

	//Window
	GetWindowText(hwnd , strText      , 0xFF);
	GetClassName( hwnd , strClassName , 0xFF);

	if(	(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Text      , _T("")       , 0xFF) == 0 ||
		 strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Text      , strText      , 0xFF) == 0 ) &&
		(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._ClassName , _T("")       , 0xFF) == 0 ||
		 strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._ClassName , strClassName , 0xFF) == 0 ) ){

		if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Display , _T("1") , 0xFF) == 0){ ShowWindow  (hwnd , SW_SHOW);}
		if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Display , _T("0") , 0xFF) == 0){ ShowWindow  (hwnd , SW_HIDE);}
	}

	return TRUE;
};

BOOL CALLBACK ExecFind(HWND hwnd, LPARAM lParam){
	TCHAR strText[0xFF];
	TCHAR strClassName[0xFF];

	//Window
	GetWindowText(hwnd , strText      , 0xFF);
	GetClassName( hwnd , strClassName , 0xFF);

	if(	(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Text      , _T("")       , 0xFF) == 0 ||
		 strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Text      , strText      , 0xFF) == 0 ) &&
		(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._ClassName , _T("")       , 0xFF) == 0 ||
		 strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._ClassName , strClassName , 0xFF) == 0 ) ){

		_Found = TRUE;
		return FALSE;
	}

	return TRUE;
};

void ExecSleep(){
	Sleep(_ttoi(_WEConfig._WESection[_WEConfig._CurrentIndex]._Sleep));
};

void ExecCmd(){
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pi;

	CreateProcess(
		NULL,
		_WEConfig._WESection[_WEConfig._CurrentIndex]._Cmd,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi);
};

void Execute(){
	if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Action , _T("Enable")   , 0xFF) == 0){
		EnumWindows(ExecEnable, 0);
		return;
	}

	if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Action , _T("Display")  , 0xFF) == 0){
		EnumWindows(ExecDisplay, 0);
		return;
	}

	if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Action , _T("Find")     , 0xFF) == 0){
		_Found = FALSE;
		while(TRUE){
			EnumWindows(ExecFind, 0);
			if(_Found == TRUE){
				break;
			}else{
				Sleep(1);
			}
		}
		return;
	}

	if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Action , _T("Sleep")    , 0xFF) == 0){
		ExecSleep();
		return;
	}

	if(strncmp(_WEConfig._WESection[_WEConfig._CurrentIndex]._Action , _T("Cmd")      , 0xFF) == 0){
		ExecCmd();
		return;
	}
}

void main(){
	ReadConfig();

	if(ValidateConfig() == FALSE){
		return;
	}

	for(_WEConfig._CurrentIndex = 0 ; _WEConfig._CurrentIndex < _WEConfig._Length ; _WEConfig._CurrentIndex++){
		printf("start - %s\n" , _WEConfig._WESection[_WEConfig._CurrentIndex]._Action);
		Execute();
		printf("end   - %s\n" , _WEConfig._WESection[_WEConfig._CurrentIndex]._Action);
	}
}
