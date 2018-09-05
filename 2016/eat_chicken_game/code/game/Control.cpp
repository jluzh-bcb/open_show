#include "Control.h"

//初始化游戏元素
Control::Control() {
	die=false;
	s.ateIt=true;
	handle=GetStdHandle(STD_OUTPUT_HANDLE);

}
void Control::getControl(const char *fname,int h,int w) {
	height=h;
	width=w;
	map=new MapCavel(fname,h,w);
	setPicArray();
	//初始蛇
	map->setWall();
	map->setTrace(2,2);
	map->setTrace(3,2);
	map->setTrace(4,2);


	//初始化随机数
	//地图打印
	setSence();
	//coord为后台蛇在数组的位置信息
	coord.X=2;
	coord.Y=2;
	COORD t=coord;
	t.X=array_x[coord.X];
	SetConsoleCursorPosition(handle,t);
}
void Control::getControl(int h,int w) {
	height=h;
	width=w;
	map=new MapCavel(h,w);
	setPicArray();
	//初始蛇
	map->setWall();
	map->setTrace(2,2);
	map->setTrace(3,2);
	map->setTrace(4,2);


	//初始化随机数
	//地图打印
	setSence();
	//coord为后台蛇在数组的位置信息
	coord.X=2;
	coord.Y=2;
	COORD t=coord;
	t.X=array_x[coord.X];
	SetConsoleCursorPosition(handle,t);
}
//校正显示数组
/*
coord.X=0 1 2 3  4   5 6...
array_x[i]=2 4 6 8 10 12  14..
*/
void Control::setPicArray() {
	for(int i=0; i<width; i++) {
		array_x[i]=i*2;
	}
}
//场景设置
void Control::setSence() {
	for(int i=0; i<height; i++) {
		for(int j=0; j<width; j++) {
			if(map->getE(j,i)==3) {
				SetConsoleTextAttribute(handle,
				                        0xc7);
				printf("  ");
				SetConsoleTextAttribute(handle,
				                        0x7);
			}
			if(map->getE(j,i)==1) {
				showBody();
			}

			if(map->getE(j,i)==0) {
				SetConsoleTextAttribute(handle,
				                        0x7);
				printf("  ");
			}

		}
		printf("\n");
	}
}
//出现食物
void Control::showFood(int x,int y) {
	COORD m;
	m.Y=y;
	m.X=x;
	COORD t=m;
	t.X=array_x[m.X];
	SetConsoleCursorPosition(handle,t);
	printf("鸡");
	m.X=2;
	m.Y=0;
	SetConsoleCursorPosition(handle,m);
	printf("吃鸡%d只",s.getlen());
}
//随机生成食物
void Control::randomCreateFood() {
	int x,y;
	srand((unsigned)time(NULL));
	while(true) {
		x=(rand()%(width-1))+1;
		y=(rand()%(height-1))+1;
		if(!map->isTrueWay(x,y))
			continue;
		//printf("(x=%d y=%d)\n ",x,y);
		s.createFood(x,y);
		map->setFoodPosition(x,y);
		showFood(x,y);
		break;
	}
}
//隐藏光标
void Control::hideTheCursor() {
	GetConsoleCursorInfo(handle,&cci);
	cci.bVisible=false;
	SetConsoleCursorInfo(handle,&cci);
}
//显示光标
void Control::showTheCursor() {
	GetConsoleCursorInfo(handle,&cci);
	cci.bVisible=true;
	SetConsoleCursorInfo(handle,&cci);
}
//移动光标
void Control::moveTheCci(int keycode) {
	coord.X=s.head->x;
	coord.Y=s.head->y;
	switch(keycode) {
		case 72:
		case 119://up
			coord.Y--;
			break;
		case 80:
		case 115://down
			coord.Y++;
			break;
		case 77:
		case 100://right
			coord.X+=1;
			break;
		case 75:
		case 97://left
			coord.X-=1;
			break;
	}
}
//是否是可行的路径
bool Control::isAWay(int x,int y) {
	if(s.head->next->x!=x||s.head->next->y!=y)
		return true;
	return false;
}
//咬到自己
bool Control::eatYourSelf(int x,int y) {
	if(map->isBody(x,y))
		return true;
	return false;
}
//碰墙
bool Control::heatWall(int x,int y) {
	if(map->iswall(x,y))
		return true;
	return false;
}
//移动
bool Control::autorun(int key) {

	if(s.ateIt) {
		randomCreateFood();
		s.ateIt=false;
	}
	COORD temp;
	COORD t;
	temp.X=s.tail->x;
	temp.Y=s.tail->y;
	moveTheCci(key);
	Position p;
	p.x=coord.X;
	p.y=coord.Y;
	bool way=isAWay(p.x,p.y);
	bool getFood=map->isFood(p.x,p.y);
	if(getFood) {
		s.eatFood();
		t=coord;
		t.X=array_x[coord.X];
		SetConsoleCursorPosition(handle,t);

		showBody();

		map->setTrace(p.x,p.y);
		s.ateIt=true;
		PlaySound(".\\sound\\eatchicken.wav",NULL, SND_FILENAME | SND_ASYNC);

		return true;
	}
	if(eatYourSelf(p.x,p.y)) {
		die=true;
		youdie();
		return false;
	}
	s.moveStep(&p);
	if(heatWall(p.x,p.y)) {
		die=true;
		youdie();

		return false;
	}
	map->setTrace(p.x,p.y);

	t=coord;
	t.X=array_x[coord.X];
	SetConsoleCursorPosition(handle,t);

	showBody();

	t=temp;
	t.X=array_x[temp.X];
	SetConsoleCursorPosition(handle,t);
	map->resetTrace(temp.X,temp.Y);
	printf("  ");
	return true;
}
void Control::youdie() {
	system("cls");
	mciSendString("close bgsound",NULL,0,NULL);
	PlaySound(".\\sound\\die.wav" ,NULL, SND_FILENAME | SND_ASYNC);
	printf("\n\n           游戏结束！吃鸡%d只,身长%d\n",s.getlen(),s.getlen()+3);
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("   +#   ##                       #  #           \n");
	printf("   +#   ##                       #  #            \n");
	printf("    ## ##                        #       ####   \n");
	printf("     ###    #####  #   #     #####  #  .#####   \n");
	printf("      ##   ##   #  #   #     #   #  #  ##   #   \n");
	printf("      #    ##   #  #   #     #   #  #  ######   \n");
	printf("      #    ##   #  #  ##     #   #  #  ##       \n");
	printf("      #    ######  #####     #####  #  ##   #   \n");
	printf("      #      ###   ### #      ####  #   ####    \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	printf("	                                                \n");
	system("pause");
	system("cls");
//	map->printAll();
	return;
}
//
void Control::showBody() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xb3);
	printf("  ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
bool Control::gameover() {
	if(die)
		return true;
	return false;
}
//析构
Control::~Control() {
	delete map;
}
