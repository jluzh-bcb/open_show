#include <iostream>
#include<windows.h>
#include<conio.h>
#include <stdlib.h> 
#include<ctime>
using namespace std;

int main()
{
	while(1)
	{
		srand((int)time(0));
		for(int n=1;n<=21;n++)
		{
			cout<<(rand()%21)+1<<endl;
			Sleep(80);
			if(kbhit())
				system("Pause");
			system("Cls");	
		}
	}
	return 0; 
}
