#include<fstream>
#include<string>
#include<iostream>
using namespace std;
void fun0()//浏览 
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
			cout<<"学号:"<<snumber<<endl<<"姓名:"<<name<<endl<<"电话:"<<tel<<endl<<"性别:"<<sex<<endl<<"年龄:"<<age<<endl;
		}		
		f.close();
		cout<<"ok"<<endl;
	}
}
void fun1()//添加 
{	for(;;)
	{
		string snumber,name,tel,sex,age;
		cout<<"您如不想继续添加请输入quit，否则请输入学号：";
		cin>>snumber;
		if(snumber=="quit")
		{cout<<endl;break;}		
		cout<<"请输入姓名：";
		cin>>name;
		cout<<endl;
		cout<<"请输入电话：";
		cin>>tel;
		cout<<endl; 
		cout<<"请输入性别：";
		cin>>sex;
		cout<<endl;
		cout<<"请输入年龄：";
		cin>>age;
		cout<<endl;
			fstream f("d:\\ddata.txt",ios_base::out|ios_base::app);
			f<<snumber<<" "<<name<<" "<<tel<<" "<<sex<<" "<<age<<endl;
			f.close();
		cout<<"OK!记录完毕。"<<endl;
	}	 
}
void fun2()//查询 
{
	string snumber,name,tel,sex,age;
	string sorn;
	cout<<"请输入任意词条自动识别并查询:";
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
				cout<<"学号:"<<snumber<<endl<<"姓名:"<<name<<endl<<"电话:"<<tel<<endl<<"性别:"<<sex<<endl<<"年龄:"<<age<<endl;//不可能相同学号 
				break;
			}			
			if(sorn==name)
				cout<<"学号:"<<snumber<<endl<<"姓名:"<<name<<endl<<"电话:"<<tel<<endl<<"性别:"<<sex<<endl<<"年龄:"<<age<<endl;//有可能同名
			if(sorn==tel)
				cout<<"学号:"<<snumber<<endl<<"姓名:"<<name<<endl<<"电话:"<<tel<<endl<<"性别:"<<sex<<endl<<"年龄:"<<age<<endl;
			if(sorn==sex)
				cout<<"学号:"<<snumber<<endl<<"姓名:"<<name<<endl<<"电话:"<<tel<<endl<<"性别:"<<sex<<endl<<"年龄:"<<age<<endl;
			if(sorn==age)
				cout<<"学号:"<<snumber<<endl<<"姓名:"<<name<<endl<<"电话:"<<tel<<endl<<"性别:"<<sex<<endl<<"年龄:"<<age<<endl;
		}
	}	
}
void fun3()//删除 
{
	string snumber,name,tel,sex,age;
	string temp,tempp;
	string xuehao;
	cout<<"请输入学号：";
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
void fun4()//导出 
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
			wenjian<<"姓名:"<<name<<endl;
			wenjian<<"电话号码:"<<tel<<endl;
			wenjian<<"性别:"<<sex<<endl;
			wenjian<<"年龄:"<<age<<endl;
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
	cout<<"\t\t"<<"通讯录系统"<<endl;
	cout<<"\t\t"<<"0 浏览"<<endl;
	cout<<"\t\t"<<"1 添加"<<endl;
	cout<<"\t\t"<<"2 查询"<<endl;
	cout<<"\t\t"<<"3 删除"<<endl;
	cout<<"\t\t"<<"4 导出"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<"你的选择是：";
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
