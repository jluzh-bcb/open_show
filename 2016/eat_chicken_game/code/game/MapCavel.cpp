#include "MapCavel.h"
MapCavel::MapCavel(const char* path,int height,int width) {
	char ch;
	this->height=height;
	this->width=width;
	FILE *getData=fopen(path,"r");
	map=new int*[height+1];

	for(int i=0; i<=height; i++) {
		map[i]=new int[width+1];
		for(int j=0; j<=width; j++) {
			ch=fgetc(getData);
			if(ch=='\n')
				continue;
			//printf("%d",(ch-'0'));
			map[i][j]=ch-'0';
		}
		//	printf("\n");
	}
	fclose(getData);
}

MapCavel::MapCavel(int height,int width) {
	this->height=height;
	this->width=width;
	map=new int*[height+1];
	for(int i=0; i<height; i++) {
		map[i]=new int[width+1];
		for(int j=0; j<width; j++) {
			map[i][j]=0;
			//cout<<map[i][j];
		}
		//cout<<endl;
	}
	//cout<<endl;
};
void MapCavel::setTrace(int x,int y) {
	map[y][x]=1;
}
void MapCavel::resetTrace(int x,int y) {
	map[y][x]=0;
}
void MapCavel::printAll() {
	for(int i=0; i<height; i++) {
		for(int j=0; j<width; j++) {
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
}
bool MapCavel::isTrueWay(int x,int y) {
	if(map[y][x]==0)
		return true;
	return false;
}
bool MapCavel::iswall(int x,int y) {
	if(map[y][x]==3)
		return true;
	return false;
}
void MapCavel::setFoodPosition(int x,int y) {
	map[y][x]=2;
}
bool MapCavel::isFood(int x,int y) {
	if(map[y][x]==2)
		return true;
	return false;
}
void MapCavel::setWall() {
	for(int i=1; i<width; i++)
		map[1][i]=3;
	for(int i=1; i<width; i++)
		map[height-1][i]=3;
	for(int i=1; i<height; i++)
		map[i][1]=3;
	for(int i=1; i<height; i++)
		map[i][width-1]=3;
}
int MapCavel::getE(int x,int y) {
	return map[y][x];
}
bool MapCavel::isBody(int x,int y) {
	if(map[y][x]==1)
		return true;
	return false;
}
MapCavel::~MapCavel() {
	for(int i=0; i<height; i++) {
		delete []map[i];
	}
	delete []map;
}

