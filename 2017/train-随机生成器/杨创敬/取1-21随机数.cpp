#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
#if(0)   
	int i;
	for(i=1;i<=21;i++)
	{
		cout<<rand()%21+1<<endl;//每次启动程序产生随机数一样 
	}
#endif

#if(1) 
	int i;
	srand((unsigned)time(NULL));//时间做种子，产生随机数不一样 
	for(i=1;i<=21;i++)
	{
		cout<<rand()%21+1<<endl;
	}
#endif	
	return 0;
}
