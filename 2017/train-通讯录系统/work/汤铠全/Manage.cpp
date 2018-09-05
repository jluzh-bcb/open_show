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
	cout<<"\n\t\t\t\t** ����ѧ��ͨѶ¼ **\n\n";
	cout<<"����ѧ�ţ�\t";
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
			cout<<"��ѧ���Ѵ��ڣ�\n"<<endl;  
            cout<<"��ѧ����ϢΪ: \n"<<endl;  
            Find(StuId);  
            cout<<endl;  
            cout<<"\n����������(Y/N):"<<endl;  
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
    cout<<"��������:\t";
    cin>>Name;
    cout<<endl;
    cout<<"�����Ա�:\t";
    cin>>Sex;
    cout<<endl;
    cout<<"��������:\t";
    cin>>Age;
    cout<<endl;
    cout<<"�����ֻ���:\t";
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
	cout<<"\t\t\t ****��ӳɹ�***\n"<<endl;
    cout<<"�Ƿ�������?(Y/N)"<<endl;
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
            cout<<"δ�ҵ���ѧ��!"<<endl;  
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
        cout<<"\t��ѯ�ɹ�!!!\t"<<endl;
    }
    else
        {cout<<"\n\t\tδ�ҵ���ѧ��!!!\n"<<endl;}
}

void Manage::Query()
{
    char c;
    string ID;
    char Name[20];
    do{
        cout<<"1.��ѧ�Ų���  2.�����ֲ���  3.�˳�����"<<endl;
        cin>>c;
        cout<<endl;
        switch(c)
        {
            case '1':{
                cout<<"����ѧ�� ID:  ";
                cin>>ID;
                Find(ID);
                    };
				break;
            case '2':{
                cout<<"�������� Name:  ";
                cin>>Name;
                Find(Name);
                    };
				break;
            case '3':break;
            default: cout<<"�������� ����������!\n"<<endl;
        }
    }while(c!='1'&&c!='2'&&c!='3');
    cout<<"\t\t\t  ***���ҳɹ�***\n"<<endl;
    cout<<"\t�Ƿ�������ң�Y/N��?\n";
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
        cout<<"ID: "<<p1->StuId<<"\t����: "<<p1->Name<<endl;
        count++;
        p1=p1->next;
    }
    if(count!=0)
    {
        cout<<"��ѯ��ϸ��Ϣ(Y/N): ";
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
        cout<<"��δ����ͨѶ¼,�Ƿ񴴽�(Y/N)"<<endl;
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
    cout<<"\n\t\t\t** ɾ����Ϣ **\n";
    cout<<"�Ƿ�ɾ��ͨѶ¼��Ϣ(Y/N):  "<<endl;
    cin>>c;
    if(toupper(c)!='Y')
        return;
    cout<<"���ٴ�ȷ��(Y/N)"<<endl;
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
                printf("��");
                Sleep(100);
            }
            system("cls");
    puts("\n\t\t\t\t���˳� \n");  
    exit(0);
}


