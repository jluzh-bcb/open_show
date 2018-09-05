#ifndef POSITION_H
#define POSITION_H
#include<stdlib.h>//NULL
class Position {

	public:
		int x;
		int y;
		Position *next;
		Position *pre;

		Position();
		Position(int x, int y);
		void setXY(int x, int y);

		//swap the xy's data
		void swapXY(Position const *p);
};

#endif
