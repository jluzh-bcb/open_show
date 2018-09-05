#include "MyMap.h"

MyMap::MyMap(int height,int width) {
	char ch;
	map=new int*[height+1];
	ifstream getData(path.c_str());
	for(int i=0; i<height; i++) {
		map[i]=new int[width+1];
		for(int j=0; j<width; j++) {
			getData>>ch;
			map[i][j]=ch-'0';
			cout<<map[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<endl;
}
MyMap::~MyMap() {
	for(int i=0; i<height; i++) {
		delete []map[i];
	}
	delete []map;
}
