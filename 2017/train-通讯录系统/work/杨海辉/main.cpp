#include<fstream>
#include<string>
#include<iostream>
using namespace std;
void fun0()//��� 
{
	string snumber,name,tel,sex,age;
	fstream f("d:\\ddata.txt",ios_base::in);
	if(!f.is_open())
	{
		cout<<"fuck"<<endl;
	}
	else
	{
		while(f>>snumber>>name>>tel>>sex>>age)
		{			
			cout<<"ѧ��:"<<snumber<<endl<<"����:"<<name<<endl<<"�绰:"<<tel<<endl<<"�Ա�:"<<sex<<endl<<"����:"<<age<<endl;
		}		
		f.close();
		cout<<"ok"<<endl;
	}
}
void fun1()//��� 
{	for(;;)
	{
		string snumber,name,tel,sex,age;
		cout<<"���粻��������������quit������������ѧ�ţ�";
		cin>>snumber;
		if(snumber=="quit")
		{cout<<endl;break;}		
		cout<<"������������";
		cin>>name;
		cout<<endl;
		cout<<"������绰��";
		cin>>tel;
		cout<<endl; 
		cout<<"�������Ա�";
		cin>>sex;
		cout<<endl;
		cout<<"���������䣺";
		cin>>age;
		cout<<endl;
			fstream f("d:\\ddata.txt",ios_base::out|ios_base::app);
			f<<snumber<<" "<<name<<" "<<tel<<" "<<sex<<" "<<age<<endl;
			f.close();
		cout<<"OK!��¼��ϡ�"<<endl;
	}	 
}
void fun2()//��ѯ 
{
	string snumber,name,tel,sex,age;
	string sorn;
	cout<<"��������������Զ�ʶ�𲢲�ѯ:";
	cin>>sorn;
	cout<<endl;
	fstream f("d:\\ddata.txt",ios_base::in);
	if(!f.is_open())
	{
		cout<<"fuck"<<endl;
	}
	else
	{
		while(f>>snumber>>name>>tel>>sex>>age)
		{
			if(sorn==snumber)
			{
				cout<<"ѧ��:"<<snumber<<endl<<"����:"<<name<<endl<<"�绰:"<<tel<<endl<<"�Ա�:"<<sex<<endl<<"����:"<<age<<endl;//��������ͬѧ�� 
				break;
			}			
			if(sorn==name)
				cout<<"ѧ��:"<<snumber<<endl<<"����:"<<name<<endl<<"�绰:"<<tel<<endl<<"�Ա�:"<<sex<<endl<<"����:"<<age<<endl;//�п���ͬ��
			if(sorn==tel)
				cout<<"ѧ��:"<<snumber<<endl<<"����:"<<name<<endl<<"�绰:"<<tel<<endl<<"�Ա�:"<<sex<<endl<<"����:"<<age<<endl;
			if(sorn==sex)
				cout<<"ѧ��:"<<snumber<<endl<<"����:"<<name<<endl<<"�绰:"<<tel<<endl<<"�Ա�:"<<sex<<endl<<"����:"<<age<<endl;
			if(sorn==age)
				cout<<"ѧ��:"<<snumber<<endl<<"����:"<<name<<endl<<"�绰:"<<tel<<endl<<"�Ա�:"<<sex<<endl<<"����:"<<age<<endl;
		}
	}	
}
void fun3()//ɾ�� 
{
	string snumber,name,tel,sex,age;
	string temp,tempp;
	string xuehao;
	cout<<"������ѧ�ţ�";
	cin>>xuehao;
	cout<<endl;
	int size=34;
	int i=0;
	fstream f("d:\\ddata.txt",ios_base::in);
	if(!f.is_open())
	{
		cout<<"fuck"<<endl;
	}
	else
	{
	int count=0;
 	while(f>>snumber>>name>>tel>>sex>>age)
	{		
		count++;
		if(xuehao!=snumber)
		{tempp+=(snumber+" "+name+" "+tel+" "+sex+" "+age+'\n');}
		else
		{i=count;break;}
	}
	f.seekg(34*i);
	while(f>>snumber>>name>>tel>>sex>>age)
	{
		temp+=(snumber+" "+name+" "+tel+" "+sex+" "+age+'\n');
	}
	f.close();
	fstream f("d:\\ddata.txt",ios_base::out);
	f<<tempp<<temp;
	f.close();
	}
	cout<<"OK!"<<endl;
}
void fun4()//���� 
{
	string snumber,name,tel,sex,age;
	string a;
	cin>>a;
	fstream f("d:\\ddata.txt",ios_base::in);
	fstream wenjian(a.c_str(),ios_base::out|ios_base::app);
	if(!f.is_open())
	{
		cout<<"fuck"<<endl;
	}
	else
	{
		while(f>>snumber>>name>>tel>>sex>>age)
		{			
			wenjian<<"id:"<<snumber<<endl;
			wenjian<<"����:"<<name<<endl;
			wenjian<<"�绰����:"<<tel<<endl;
			wenjian<<"�Ա�:"<<sex<<endl;
			wenjian<<"����:"<<age<<endl;
		}		

		cout<<"ok"<<endl;
	}
	f.close();
	wenjian.close();
}
int main()
{
	int select;
	for(;;)
{
	cout<<"\t\t"<<"ͨѶ¼ϵͳ"<<endl;
	cout<<"\t\t"<<"0 ���"<<endl;
	cout<<"\t\t"<<"1 ���"<<endl;
	cout<<"\t\t"<<"2 ��ѯ"<<endl;
	cout<<"\t\t"<<"3 ɾ��"<<endl;
	cout<<"\t\t"<<"4 ����"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<"���ѡ���ǣ�";
	cin>>select;
	cout<<endl;
	if(select==0)
	fun0();
	if(select==1)
	fun1();
	if(select==2)
	fun2();
	if(select==3)
	fun3();
	if(select==4)
	{
	fstream wenjian("d:\\mytest.txt",ios_base::trunc|ios_base::out);
	wenjian<<"";
	wenjian.close();
	fun4();
	}	
	if(select==5)
	break;
}
	cout<<"BYE"<<endl;	
}
