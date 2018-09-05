#include<iostream>
#include<windows.h>
#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<conio.h>
using namespace std;
#include"Person.h"
#include"Manage.cpp" 
string ID;
int main(void)
{
    Manage m;
    int c;
    puts("\n\n\n\n\n\n\n\t\t\t\t 欢迎进入通信录 ");
    do
	{
    system("cls");
    cout<<"\n";
    cout<<"\t\t    通讯录系统   "<<endl;  
    cout<<"\t\t    0.浏览       "<<endl;
    cout<<"\t\t    1.添加       "<<endl;
    cout<<"\t\t    2.查询       "<<endl;
    cout<<"\t\t    3.删除       "<<endl;
    cout<<"\t\t    4.导出       "<<endl;
    cout<<"\t\t    5.退出       "<<endl; 
    cout<<"\t\t_________________"<<endl;
    cout<<"你的选择是： ";  
                            
    cin>>c;  
    switch(c)  
    {  
    case 0: m.Look(); break;
    case 1: m.Add(); break;
    case 2: {
    system("cls");
    m.Query();
      }; break;
    case 3: m.Delete(); break;
    case 4: m.Load(); break;  
    default:m.Exit(); break;
    }  
        }while(c!=5);
    system("cls");
    return 0;
}
