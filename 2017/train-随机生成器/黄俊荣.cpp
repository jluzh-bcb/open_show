#include<iostream>
#include<time.h>
#include<stdlib.h> 
#include<conio.h>
#include<windows.h>
using namespace std;
int main()
{
	int ac;	
	
	while(1)
	{
	srand((unsigned)time(NULL));
		ac=rand()%21+1;
		
		cout<<ac<<",";
Sleep(1000);

	}
	return 0;
}

