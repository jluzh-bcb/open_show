#include "Person.h"
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


void Manage::Add()
{
	system("cls");
	Person *p,*p2;
	string StuId,Age,Tel;
	char Name[20],Sex[10];
	char c;
	cout<<"\n\t\t\t\t** 新增学生通讯录 **\n\n";
	cout<<"输入学号：\t";
	cin>>StuId;
	cout<<endl;
	{
		Person *p1;
		p1=person;
		while(p1)
		{
			if(p1->StuId==StuId)
			{
				break;
			}
			else
			{
				p1=p1->next;
			}
		}
		if(p1!=NULL)
		{
			cout<<"该学号已存在，\n"<<endl;  
            cout<<"该学生信息为: \n"<<endl;  
            Find(StuId);  
            cout<<endl;  
            cout<<"\n请重新输入(Y/N):"<<endl;  
            cin>>c;  
            if(toupper(c)=='Y') 
            {  
                Add();  
                return;  
            }  
            else  
                return;  
        }  
    }
    cout<<"输入姓名:\t";
    cin>>Name;
    cout<<endl;
    cout<<"输入性别:\t";
    cin>>Sex;
    cout<<endl;
    cout<<"输入年龄:\t";
    cin>>Age;
    cout<<endl;
    cout<<"输入手机号:\t";
    cin>>Tel;
    cout<<endl;
    p=new Person(StuId,Name,Sex,Age,Tel);
    p->next=0;
    if(person)
    {
    	p2=person;
    	while(p2->next)
    	{
    		p2=p2->next;
		}
    	p2->next=p;
	}
	else
	{
		person=p;
	}
	cout<<"\t\t\t ****添加成功***\n"<<endl;
    cout<<"是否继续添加?(Y/N)"<<endl;
    cin>>c;
    if(toupper(c)=='Y')
    {  
        Add();
        return;
    }  
    else
        return;
}

void Manage::Load()
{
    ifstream fPerson;
    Person *p=person;
    string StuId,Age,Tel;
    char Name[20],Sex[10];
    fPerson.open("person.txt",ios::in);
    fPerson>>StuId>>Name>>Sex>>Age>>Tel;
    while(fPerson.good())
    {
        p=new Person(StuId,Name,Sex,Age,Tel);
        p->next=0;
        if(person)
        {
            Person *p2;
            p2=person;
            while(p2->next)
            {
                p2=p2->next;
            }
            p2->next=p;
        }
        else
        {
            person=p; 
        }
        fPerson>>StuId>>Name>>Sex>>Age>>Tel;  
    }
    fPerson.close();
}

void Manage::Find(string ID) 
{  
    Person *p1;
    p1=person;
    while(p1)
    { 
        if(p1->StuId==ID||p1->Tel==ID)  
        break;  
        else  
        {  
            p1=p1->next;  
        }  
    }
    if(p1!=NULL)
    {
        Output(p1);
    }
    else
        {  
            cout<<"未找到该学生!"<<endl;  
        }
}

void Manage::Find(char Name[20])
{
    Person *p1;
    int count=0; 
    p1=person; 
    while(p1)
    { 
        if(strcmp(p1->Name,Name)==0)
        {
            count++;
            Output(p1);
        }
            p1=p1->next;
    }
    if(count)
    {
        cout<<"\t查询成功!!!\t"<<endl;
    }
    else
        {cout<<"\n\t\t未找到该学生!!!\n"<<endl;}
}

void Manage::Query()
{
    char c;
    string ID;
    char Name[20];
    do{
        cout<<"1.按学号查找  2.按名字查找  3.退出查找"<<endl;
        cin>>c;
        cout<<endl;
        switch(c)
        {
            case '1':{
                cout<<"输入学号 ID:  ";
                cin>>ID;
                Find(ID);
                    };
				break;
            case '2':{
                cout<<"输入姓名 Name:  ";
                cin>>Name;
                Find(Name);
                    };
				break;
            case '3':break;
            default: cout<<"输入有误 请重新输入!\n"<<endl;
        }
    }while(c!='1'&&c!='2'&&c!='3');
    cout<<"\t\t\t  ***查找成功***\n"<<endl;
    cout<<"\t是否继续查找（Y/N）?\n";
    cin>>c;
    if(toupper(c)=='Y')
        {
            system("cls");
            Query();
            return ;
        }
    else
        return ;
        system("pause");
}

void Manage::Look()
{
    system("cls");
    Person *p1;
    int count=0;
    char c;
    p1=person;
    while(p1)
    {
        cout<<"ID: "<<p1->StuId<<"\t姓名: "<<p1->Name<<endl;
        count++;
        p1=p1->next;
    }
    if(count!=0)
    {
        cout<<"查询详细信息(Y/N): ";
        cin>>c;
        if(toupper(c)=='Y')
        {
            Query();
            return;
        }
        else  
            return;
    }
    else 
    {
        cout<<"尚未创建通讯录,是否创建(Y/N)"<<endl;
        cin>>c;
        if(toupper(c)=='Y')
        {
            Add();
            return;
        }
        else
            return;
    }
}

void Manage::DesTory()
{
    char c;
    system("cls");
    cout<<"\n\t\t\t** 删除信息 **\n";
    cout<<"是否删除通讯录信息(Y/N):  "<<endl;
    cin>>c;
    if(toupper(c)!='Y')
        return;
    cout<<"请再次确认(Y/N)"<<endl;
    cin>>c;
    if(toupper(c)!='Y')
        return;
    else
    {
        Person *p;
        p=person;
        while(p)
        {
            p=p->next;
            delete person;
            person=p;
        }
        person=0;
    }
    system("pause");
}

void Manage::Exit()
{  
    cout<<"\n";
    for(int i=0;i<20;i++)
            {
                printf("·");
                Sleep(100);
            }
            system("cls");
    puts("\n\t\t\t\t已退出 \n");  
    exit(0);
}


