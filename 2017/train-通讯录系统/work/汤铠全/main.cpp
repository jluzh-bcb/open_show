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
    puts("\n\n\n\n\n\n\n\t\t\t\t ��ӭ����ͨ��¼ ");
    do
	{
    system("cls");
    cout<<"\n";
    cout<<"\t\t    ͨѶ¼ϵͳ   "<<endl;  
    cout<<"\t\t    0.���       "<<endl;
    cout<<"\t\t    1.���       "<<endl;
    cout<<"\t\t    2.��ѯ       "<<endl;
    cout<<"\t\t    3.ɾ��       "<<endl;
    cout<<"\t\t    4.����       "<<endl;
    cout<<"\t\t    5.�˳�       "<<endl; 
    cout<<"\t\t_________________"<<endl;
    cout<<"���ѡ���ǣ� ";  
                            
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
