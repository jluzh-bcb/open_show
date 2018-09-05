#include<iostream>
#include<stdlib.h>
#include <time.h>
#include<conio.h> 
#include<string>
using namespace std;
int main()
{
	char fuck;
	string a[]={"color 0A","color 3C","color 5B","color 4D","color 1D","color 5E"};
	srand((unsigned)time(NULL));
	for(int i=0;;i++)
	{
		system("color 0B");
		cout<<rand()%21+1;
		if(i==6)
		i=1;
		system(a[i].c_str());
		fuck=1;
		while(kbhit())
		{
			cout<<endl;
			system("pause");
		}
		system("cls");		
	}
}
