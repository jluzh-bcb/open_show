#include "Position.h"
Position::Position() {
	x=0;
	y=0;
}
Position::Position(int x, int y) {
	this->x=x;
	this->y=y;
	next=NULL;
}
void 	Position::setXY(int x, int y) {
	this->x=x;
	this->y=y;
}

//swap the xy's data
void 	Position::swapXY(Position const *p) {
	x=p->x;
	y=p->y;
	//	cout<<"suceessful swap"<<endl;
}

