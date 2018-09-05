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
		void setTrace(int x,int y);//�����߹���·��
		void resetTrace(int x,int y);//�ָ�;���հ�
		bool isTrueWay(int x,int y);//�Ƿ�Ϊ����·��
		bool iswall(int x,int y);
		void setFoodPosition(int x,int y);//����ʳ���λ��
		bool isFood(int x,int y);
		void setWall();
		void printAll();
		int getE(int x,int y);
		bool isBody(int x,int y);
		~MapCavel();
};

#endif
