#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
using namespace std;
int acco=0;
struct student
{
	string name;
	string id;
	string sex;
	int age;
	string phone;
	student *next;
};
student *head=NULL;
student *p1;
void browse(void)/*���*/ 
{
	student *flag1;
	flag1=head;
	while(1)
	{
		if(flag1==NULL)/*�ж��Ƿ���ѧ����Ϣ*/ 
		{
			cout<<"none"<<endl;
			break;
		}
		cout<<"ѧ��:"<<flag1->id<<endl<<"����:"<<flag1->name<<endl<<"�Ա�:"<<flag1->sex<<endl<<"����:"<<flag1->age<<endl<<"�ֻ���:"<<flag1->phone<<endl<<endl;
		if(flag1->next==NULL)
		{
			break;
		}
		flag1=flag1->next;
	}
}
void add(void)/*���*/ 
{
	bool same=0;
	string id_num;
	student *p2;
	if(acco==0)
	{
		p1=head=new student;
		cin>>p1->id;
		cin>>p1->name>>p1->sex>>p1->age>>p1->phone;
		p1->next=NULL;
		acco++;
	}
	else
	{
		p1->next=new student;
		p1=p1->next;
		cin>>p1->id;
		id_num=p1->id;
		p2=head;
		for(int n=0;n<acco;n++)/*�ж�ѧ���Ƿ��ظ�*/ 
		{
			if(p2->id==id_num)
			{
				same=1;
				break;
			}
			p2=p2->next;
		}
		if(same==1)
		{
			cout<<"ѧ���ѱ�����"<<endl;
			system("pause");
			return;
		}
		cin>>p1->name>>p1->sex>>p1->age>>p1->phone;
		p1->next=NULL;
		acco++;
	}
}
void query(void)/*��ѯ*/ 
{
	string need;
	student *flag2;
	cin>>need;
	system("cls");
	flag2=head;
	while(1)
	{
		
		if(flag2->id==need)
		{
			cout<<"ѧ��:"<<flag2->id<<endl<<"����:"<<flag2->name<<endl<<"�Ա�:"<<flag2->sex<<endl<<"����:"<<flag2->age<<endl<<"�ֻ���:"<<flag2->phone<<endl;
			break;
		}
		else if(flag2->next==NULL)/*�ж�����ѧ���Ƿ����*/ 
		{
		    cout<<"û�д��ˣ���������ȷѧ��"<<endl;
		    break;
	    }
		flag2=flag2->next;
	}
}
void delet(void)/*ɾ��*/ 
{
	student *flag4,*flag5,*flag6;
	string need;
	flag4=flag5=flag6=head;
	cin>>need;
	while(1)
	{
		if(flag4==NULL)/*�ж��Ƿ���ڴ�ѧ����Ϣ*/ 
		{
			cout<<"û�д��ˣ���������ȷѧ��"<<endl;
			system("pause");
		    break;
		}
		if((flag4->next)->id==need)
		{
			flag5=flag4->next;
			if(flag5->next==NULL)
			{
				flag4->next=NULL;
				delete flag5;
			}
			else
			{
				flag6=flag5->next;
				flag4->next=flag6;
				delete flag5;
			}
			break;
		}
		else if((flag4->next)->next==NULL)
		{
            cout<<"û�д��ˣ���������ȷѧ��"<<endl;
            system("pause");
		    break;
		}
		flag4=flag4->next;
	}
}
void puto(void)/*����*/ 
{
	student *flag3;
	string need;
	fstream file;
	string name;
	cout<<"�������ļ���:"<<endl; 
	cin>>name;
	cout<<"������ѧ��:"<<endl;
	cin>>need;
	flag3=head;
	while(1)
	{
		if(flag3->id==need)
		{
			file.open(name.c_str(),ios_base::out);
		    file<<"���֣�"<<flag3->id<<endl<<"ѧ��:"<<flag3->name<<endl<<"�Ա�:"<<flag3->sex<<endl<<"����:"<<flag3->age<<endl<<"�ֻ���:"<<flag3->phone<<endl;
		    file.close();
		    if(file)
		    cout<<"OK"<<endl;
			break;
		}
	    else if(flag3->next==NULL)/*�ж��Ƿ���ڴ�ѧ����Ϣ*/ 
		{
		    cout<<"û�д��ˣ���������ȷѧ��"<<endl;
		    break;	
		}
		flag3=flag3->next;
	}
	
}
int main()
{
	int choose=-1;
	while(1)
	{
		cout<<"______________________________________________"<<endl;
		cout<<"              ͨѶ¼ϵͳ                      "<<endl;
		cout<<"              0.���                          "<<endl;
		cout<<"              1.���                          "<<endl;
		cout<<"              2.��ѯ                          "<<endl;
		cout<<"              3.ɾ��                          "<<endl;
		cout<<"              4.����                          "<<endl;
		cout<<"              5.�˳�                          "<<endl;
		cout<<"______________________________________________"<<endl;
		cin>>choose;
		system("cls");
		if(choose==5)
			break;
		else if(choose==0)
		{
			cout<<"������->���"<<endl;
			browse();
			system("pause");
		}
		else if(choose==1)
		{
			cout<<"������->���"<<endl<<"������ѧ����Ϣ"<<endl; 
			cout<<"ѧ�š����֡��Ա����䡢�ֻ���(���������)"<<endl;
			add();
		}
		else if(choose==2)
		{
			query();
			system("pause");
		}
		else if(choose==3)
		{
			cout<<"������->ɾ��"<<endl<<"������ѧ��:"<<endl;
			delet();
		}
		else if(choose==4)
		{
			cout<<"������->����"<<endl; 
			puto();
			system("pause");
		}
		system("cls");
	}
	return 0;
}

