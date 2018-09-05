#ifndef CONTROL_H
#define CONTROL_H
#include <windows.h>
#include<mmsystem.h>
#include"Snake.h"
#include"Position.h"
#include"MapCavel.h"
#include<stdio.h>
#include<time.h>
class Control {
	private:
		bool die;
		MapCavel *map;
		int height,width;
		COORD coord;//光标坐标
		CONSOLE_CURSOR_INFO cci;//光标信息
		HANDLE handle;
		int array_x[25];//数组数据
	public:
		Snake s;
		Control();
		void getControl(const char *fname,int h,int w);
		void getControl(int h,int w);
		void hideTheCursor();
		void showTheCursor();
		void moveTheCci(int keycode);
		void randomCreateFood();
		bool isAWay(int x,int y);
		bool eatYourSelf(int x,int y);
		void setSence();
		bool heatWall(int x,int y);
		void showFood(int x,int y);
		void showBody();
		void setPicArray();
		bool autorun(int key);
		void youdie();
		bool gameover();
		~Control();
};

#endif
