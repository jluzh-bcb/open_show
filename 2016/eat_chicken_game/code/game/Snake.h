#ifndef SNAKE_H
#define SNAKE_H
#include"Position.h"
//#include<stdlib.h> 
class Snake {
	private:
		int len;
	public:
		Position *head;
		Position *tail;
		Position body[3];
		Position *afood;
		bool ateIt;
		Snake();
		void showall();
		void moveStep(Position const *position);
		void eatFood();
		void createFood(int x,int y); 
		int getlen();
		~Snake();
};

#endif
