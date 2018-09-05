#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int i;
	srand((int)time(0));
	i=1+rand()%21;
	cout<<i;
	return 0; 
} 
