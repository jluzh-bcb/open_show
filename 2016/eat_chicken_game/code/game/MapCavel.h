#ifndef MAPCAVEL_H
#define MAPCAVEL_H
#include<stdio.h>
//#include <stdlib.h>
class MapCavel {
	private:
		int height;
		int width;
		int **map;
	public:
		MapCavel(const char* path,int height,int width);
		MapCavel(int height,int width); //40X25
		void setTrace(int x,int y);//设置走过的路径
		void resetTrace(int x,int y);//恢复途径空白
		bool isTrueWay(int x,int y);//是否为可行路径
		bool iswall(int x,int y);
		void setFoodPosition(int x,int y);//设置食物的位置
		bool isFood(int x,int y);
		void setWall();
		void printAll();
		int getE(int x,int y);
		bool isBody(int x,int y);
		~MapCavel();
};

#endif
