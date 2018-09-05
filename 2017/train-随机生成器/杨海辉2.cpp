#include<iostream>
#include<stdlib.h>
#include <time.h>
#include<conio.h> 
using namespace std;
int main()
{
	char fuck;
	srand((unsigned)time(NULL));
	for(int i;;)
	{
		system("color 0B");
		cout<<rand()%21+1;
		{
			cout<<endl;
			if(i==1)
			system("color 0A");
			else
			system("color 0B");
			i=1-i;
		}
		fuck=1;
		while(kbhit())
		{
			system("pause");
		}
		system("cls");		
	}
}
