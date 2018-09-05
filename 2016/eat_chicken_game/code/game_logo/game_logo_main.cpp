
#include <graphics.h>
#include<string.h>
#include<stdio.h>

int speed=200;
int gm=0;
char level[20]= {"默认模式"};
char mode[100];
char cmd[50];
void picshow(){
		PIMAGE srcImage[3];
			for(int i=0; i<3; i++) {
		srcImage[i]=newimage();
	}
	getimage(srcImage[0],".\\png\\tree.png");
	getimage(srcImage[1],".\\png\\snake.png");
	getimage(srcImage[2],".\\png\\rooster.png");
	putimage(50,80,srcImage[0]);
	putimage(50,250,srcImage[1]);
	putimage(250,250,srcImage[2]);
}
//动态选项

int yourchoice(int h) {
	
	setfont(40,0,"宋体");
	setcolor(RGB(0x84,0xdb,0x39));
	outtextxy(160,100,"我爱吃鸡");
	picshow();
	setcolor(RGB(0xf0,0xf0,0xf0));
	setfont(15,0,"雅黑");
	sprintf(mode,"游戏模式:【模式-%s,减速-%d】",level,speed);
	outtextxy(90,10,mode);
	setfont(18,0,"雅黑");
	setviewport(170,360,170+100,360+100);
	setcolor(RGB(0xff,0x80,0x80));

	outtextxy(0,0," Play game ");
	outtextxy(0,20," Set speed ");
	outtextxy(0,40," Set level ");
	outtextxy(0,60," Exit game ");
	setfontbkcolor(EGERGB(0xff, 0xFF, 0x0));
	switch(h) {
		case 1:
			outtextxy(0,0," Play game ");
			break;
		case 2:
			outtextxy(0,20," Set speed ");
			break;
		case 3:
			outtextxy(0,40," Set level ");
			break;
		case 4:
			outtextxy(0,60," Exit game ");
			break;
	}
	setfontbkcolor(EGERGB(0x0, 0x0, 0x0));
		setviewport(0, 0, getwidth(), getheight(), 1);
}

//游戏模式选择
int  gamemode() {
	cleardevice();
	setfont(20,0,"雅黑");
	setcolor(RGB(0xf0,0xf0,0xf0));
	outtextxy(180,10,"模式设置");
	
	PIMAGE resizeImageArr[3];
	PIMAGE srcImage[3];
	char title[3][20]= {"默认模式","简单模式","困难模式"};
	setfont(18,0,"雅黑");
	for(int i=0; i<3; i++) {
		srcImage[i]=newimage();
	}
	getimage(srcImage[0],".\\png\\default.png");
	getimage(srcImage[1],".\\png\\simple.png");
	getimage(srcImage[2],".\\png\\difficult.png");
	//缩小
	for(int i=0; i<3; i++) {
		resizeImageArr[i]=newimage(getwidth(srcImage[i])/4,getheight(srcImage[i])/4);
		putimage(resizeImageArr[i],0,0,getwidth(resizeImageArr[i]),getheight(resizeImageArr[i]),
		         srcImage[i],0,0,getwidth(srcImage[i]),getheight(srcImage[i]));
		delimage(srcImage[i]);
		putimage(40,i*(getheight(resizeImageArr[i])+80)+50,resizeImageArr[i]);
		outtextxy(180,i*(getheight(resizeImageArr[i])+80)+50+(getheight(resizeImageArr[i]))/2,title[i]);

	}

	int k,yc=0;
	PIMAGE img,resizeImg;

	img = newimage();
	getimage(img,".\\png\\handpoint.png");
	resizeImg=newimage(getwidth(img)/4,getheight(img)/4);

	putimage(resizeImg,0,0,getwidth(resizeImg),getheight(resizeImg),
	         img,0,0,getwidth(img),getheight(img));
	delimage(img);
	putimage(140,yc*(getheight(resizeImageArr[yc])+80)+50+(getheight(resizeImageArr[yc]))/2,resizeImg);
	while(k!=13) {
		k=getch();
		int y_t=yc*(getheight(resizeImageArr[yc])+80)+50+(getheight(resizeImageArr[yc]))/2;
		if(k==294&&yc-1>=0) {
			bar(140,y_t,140+getwidth(resizeImg),y_t+getheight(resizeImg));
			yc--;
		}
		if(k==296&&yc+1<3) {
			bar(140,y_t,140+getwidth(resizeImg),y_t+getheight(resizeImg));
			yc++;
		}
		putimage(140,yc*(getheight(resizeImageArr[yc])+80)+50+(getheight(resizeImageArr[yc]))/2,resizeImg);
	}
	strncpy(level,title[yc],20);
	return yc;
	
}

//事件处理
void runChoice(int c) {
	cleardevice();
	int k;//键值
	int yc=c;//选择
	while(k!=13) {
		yourchoice(yc);
		k=getch();
		//k=getkey();
		if(k==294&&yc-1>0)
			yc--;
		if(k==296&&yc+1<5)
			yc++;
	}

	switch(yc) {
		case 1:
			sprintf(cmd,"game_snake.bin %d %d",speed,gm);
			closegraph();
			system(cmd);
			
			break;
		case 2:
		char str[5];
			getkey();
			inputbox_getline("请输入速度(40-200)", "回车确认", str, 4);
			
			if(atoi(str)>=40&&atoi(str)<=200){
				speed=atoi(str);
			}
			runChoice(yc);
			break;
		case 3:
		    gm=gamemode();
			runChoice(yc);
			break;
		case 5:
			break;
		default:
			return;
	}
}
int main() {
	initgraph(420,680,INIT_RENDERMANUAL);
	runChoice(1);
	return 0;
}
