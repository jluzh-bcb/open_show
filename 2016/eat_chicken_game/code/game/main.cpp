#include "Snake.h"
#include<conio.h>
#include"MapCavel.h"
#include "Control.h"
#include<string.h>
#include<process.h>
HANDLE hMutex;
HANDLE handle;
HANDLE handle2;
int speed;
int initspeed;
Control c;
int key=77;

void readFile(const char *filename) {
	FILE *fpRead=fopen(filename,"r");
	char c;
	while(EOF != (c=fgetc(fpRead))) {
		if(c=='#'||c=='@'||c=='*') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),42);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		} else if(c=='='||c==':'||c=='.'||c=='%') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),59);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		} else if(c=='+'||c=='-') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),226);
			printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		} else
			printf("%c", c);
	}
	fclose(fpRead);
}
void gamelogo(int arg,char*args[]) {
	system("mode con cols=51 lines=42");
	system("color 0");
	c.hideTheCursor();
	
	//关于文件
	readFile(".\\content\\about.txt");
	system("pause");
	system("cls");
	 
	//游戏加载
	readFile(".\\content\\firstRun.dat");
	
	//进度条
	Sleep(500);printf(">>>>");
	Sleep(500);printf(">>>>>>>>");
	Sleep(500);printf(">>>>>>>>>>>>>>>>");
	Sleep(500);system("cls");
	speed=initspeed=200;
	if (arg>=2) {
		if(atoi(args[1])<=200&&atoi(args[1])>=40)
			speed=initspeed=atoi(args[1]);
	}
	if(arg==3) {
		switch(atoi(args[2])) {
			case 1:
				c.getControl(".\\map\\case1.dat",40,25);
				break;
			case 2:
				c.getControl(".\\map\\case2.dat",40,25);
				break;
			default:
				c.getControl(40,25);
		}
	}
};

unsigned WINAPI Func(void *arg) {
	c.hideTheCursor();
	mciSendString("open .\\sound\\bg.wav alias bgsound",NULL,0,NULL);//最后关闭是在，control.cpp的youdie()的函数里
	char statu[20];
	while(!c.gameover()) {
		WaitForSingleObject(hMutex,INFINITE);
		if(c.autorun(key)) {
			Sleep(speed);
		} else {
			break;
		}
		ReleaseMutex(hMutex);
		mciSendString("status bgsound mode",statu,20,NULL);
		if(strcmp(statu,"stopped")==0) {//strcmp比较指令，若为零则相同
			mciSendString("play bgsound from 0",NULL,0,NULL);
			memset(statu,0,20);
		}
	}
	return 0;
}
 
unsigned WINAPI Func2(void *arg) {
	int first=0;
	while(!c.gameover()&&(first=getch())!=27) {
		if(first!=224)
			continue;
		int temp=getch();
		if((key-temp==8)||(key-temp==-8)||(key-temp==2)||(key-temp==-2)||key==temp)
			continue;

		WaitForSingleObject(hMutex,INFINITE);
		key=temp;
		if(initspeed-c.s.getlen()*4>=40)
			speed=initspeed-c.s.getlen()*4;
		ReleaseMutex(hMutex);
	}
	return 0;
}
int main(int arg,char*args[]) {
	//窗口大小固定
	SetWindowLongPtr(GetConsoleWindow(),
	                 GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
	SetWindowPos(GetConsoleWindow(),NULL,
	             0,0,//起始位置
	             0,0,//width,height
	             SWP_HIDEWINDOW|SWP_NOSIZE);//隐藏黑窗口
	int id=MessageBox(GetConsoleWindow(),
	                  "游戏操作方式：方向键盘，退出esc","游戏即将开始，确定继续？",
	                  MB_ICONASTERISK|MB_YESNO);
	switch(id) {
		case IDYES:
			SetWindowPos(GetConsoleWindow(),
			             NULL,
			             0,0,//起始位置
			             0,0,//width,height
			             SWP_SHOWWINDOW|SWP_NOSIZE);//显示
			break;
		case IDNO:
			SetWindowPos(GetConsoleWindow(),
			             NULL,
			             0,0,//起始位置
			             0,0,//width,height
			             SWP_HIDEWINDOW|SWP_NOSIZE);//隐藏
			return 0;
	}

	gamelogo(arg,&args[0]);
	
//双线程，互斥量同步
	hMutex=CreateMutex(NULL,FALSE,NULL);
	handle =(HANDLE)_beginthreadex(NULL,0,Func,NULL,0,NULL);
	handle2 =(HANDLE)_beginthreadex(NULL,0,Func2,NULL,0,NULL);

//	WaitForSingleObject(handle,INFINITE);
	WaitForSingleObject(handle2,INFINITE);

	CloseHandle(hMutex);
	CloseHandle(handle);
	CloseHandle(handle2);
	SetWindowPos(GetConsoleWindow(),
	             NULL,
	             0,0,//起始位置
	             0,0,//width,height
	             SWP_HIDEWINDOW|SWP_NOSIZE);//隐藏
	system("Rungame.exe");
	return 0;
}
