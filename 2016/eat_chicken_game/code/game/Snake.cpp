#include "Snake.h"
Snake::Snake() {
	//init the first snake body,its length is three;
	body[0].setXY(2,2);
	body[1].setXY(3,2);
	body[2].setXY(4,2);
	body[0].next=NULL;
	body[0].pre=&body[1];
	body[1].next=&body[0];
	body[1].pre=&body[2];
	body[2].next=&body[1];
	body[2].pre=NULL;
	//point out the head and the tail
	head=&body[2];
	tail=&body[0];
	len=0;
	ateIt=false;
}
void Snake::showall() {
	Position *temp=head;
	while(temp!=NULL) {
		temp=temp->next;
	}
}
//move one step
void Snake::moveStep(Position const *position) {
	Position *temp_tail=tail;

	while(temp_tail->pre!=NULL) {
		temp_tail->swapXY(temp_tail->pre);
		temp_tail=temp_tail->pre;
	}
	temp_tail->swapXY(position);
}
void Snake::eatFood() {
	afood->next=head;
	head->pre=afood;
	afood->pre=NULL;
	head=afood;
	len++;
	ateIt=true;
}
void Snake::createFood(int x,int y) {
	afood=new Position;
	if(afood==NULL)
		return ;
	afood->x=x;
	afood->y=y;
}
int Snake::getlen() {
	return len;
}
Snake::~Snake() {
	Position *temp=head;
	for(int i=0; i<len-3; i++) {
		head=head->next;
		delete temp;
		temp=head;
	}
}

