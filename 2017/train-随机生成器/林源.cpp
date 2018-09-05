#include<iostream>
using namespace std;
#include<stdlib.h>
#include<conio.h>
#include<ctime>
int main()
{	int k,a; 
	char input;
	srand(unsigned(time(NULL)));
	while(1)
	{
	if(!_kbhit())
	{
		k=rand()%21+1;
		cout<<k;
	}
	else 
	{
		input=getch();
		if(input=='\40')
		break;
	}system("cls");
} cout<<k;
 } 
