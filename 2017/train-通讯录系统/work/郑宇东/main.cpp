#include<iostream>
#include<fstream>
#include<windows.h>
#include<iomanip>
using namespace std;
struct stu
{
	
		string name;
		int stu_id;
		string sex;
		int age;
		int phone_number;
		stu*next;
};
class  mainPage
{
	private:
		stu *first;
		stu*end;
		stu*constOfFirst;
		
	public:
		void check();
		
		int scan_it();
		
		int add();
		
		void Delete();
		
		void Export();
		
		mainPage()
		{
			first=NULL;
			constOfFirst=NULL;
			end=NULL;
		}
		
		int main_page()
		{
			int choice;
			system("cls");
			cout<<setw(30)<<"通讯录系统"<<endl 
				<<setw(30)<<"0.浏览"<<endl
				<<setw(30)<<"1.添加"<<endl
				<<setw(30)<<"2.查询"<<endl
				<<setw(30)<<"3.删除"<<endl
				<<setw(30)<<"4.导出"<<endl
				<<setw(30)<<"5.退出"<<endl
				<<"----------------------------------------------------"
				<<endl<<"你的选择是:";
			cin>>choice;
			while(choice<0||choice>5)
				{
					cout<<"请输入有效数字"<<endl
						<<"你的选择是:";
					cin>>choice;
				}
					
			switch(choice)
			{
				case 0:scan_it();break;
				case 1:add();break;
				case 2:check();break;
				case 3:Delete();break;
				case 4:Export();break;
				default:exit(1);	
			}
			return 0;
		}	 
};

//00浏览 
int mainPage::scan_it()
{
	system("cls");
	
	if(first==NULL)
	{
		int choice;
		cout<<"系统内没有添加学生资料"<<endl
			<<"正在返回主页面..."<<endl; 
		Sleep(5000);
		main_page();	
	}
	
	else
	{
		while(first)
		{
			cout<<"姓名："<<first->name<<endl
				<<"性别："<<first->sex<<endl
				<<"年龄："<<first->age<<endl
				<<"学号："<<first->stu_id<<endl
				<<"电话号码："<<first->phone_number<<endl;
				first=first->next;
		}
		first=constOfFirst;	
	}
		
	cout<<endl<<"输入1则返回主界面，0则退出"<<endl;
	
	int choiceGoOrExit;
	cin>>choiceGoOrExit;
	
	while(choiceGoOrExit!=1&&choiceGoOrExit!=0)
	{
		cout<<"请输入有效数字！"<<endl
			<<"请输入:";
		cin>>choiceGoOrExit;	
	}
	
	if(choiceGoOrExit)
		{
			main_page();
		}

	else
	{
		exit(1);	
	}	
	return 0;
}

//01添加  
int mainPage::add()
{
	int num;
	system("cls");
	stu*newone=new stu;
	
 	if(newone==NULL)
 	{
 		cout<<"error!!!"<<endl;
		Sleep(3000);
		main_page(); 	
	} 
	
	if(first==NULL)
	{
		
		cout<<"请填写相关信息:"<<endl;
		cout<<"姓名：";
		cin>>newone->name;
		cout<<endl<<"性别：";
		cin>>newone->sex;
		cout<<endl<<"年龄:";
		cin>>newone->age;
		cout<<endl<<"学号：";
		cin>>newone->stu_id;
		cout<<endl<<"电话号码：";
		cin>>newone->phone_number;
		first=newone;
		end=newone;
		constOfFirst=newone;
		end->next=NULL;
	}
	else
	{
		cout<<"请填写相关信息:"<<endl;
		cout<<"姓名：";
		cin>>newone->name;
		cout<<endl<<"性别：";
		cin>>newone->sex;
		cout<<endl<<"年龄:";
		cin>>newone->age;
		cout<<endl<<"学号：";
		cin>>newone->stu_id;
		cout<<endl<<"电话号码：";
		cin>>newone->phone_number;
		end->next=newone;
		end=newone;
		end->next=NULL;
	}
	system("cls");
	cout<<"添加成功\n"<<"正在返回主页面。。。"<<endl;
	Sleep(3000);
	main_page();
	return 0; 
}

//02查 
void mainPage::check()
{
	system("cls");
	int checkTo;
	bool flag=false;
	cout<<"请输入学号进行查询：";
	cin>>checkTo;
	first=constOfFirst;
	for(;first!=NULL;first=first->next)
	{
		if(first->stu_id!=checkTo)
		{
			flag=false;
			continue;
		}
		
		else
		{
			flag=true;
			break;
		}	
	}
	
	if(flag==true)
	{
		cout<<"姓名："<<first->name<<endl
			<<"性别："<<first->sex<<endl
			<<"年龄："<<first->age<<endl
			<<"学号："<<first->stu_id<<endl
			<<"电话号码："<<first->phone_number<<endl;	
			cout<<endl<<"输入1则返回主界面，0则退出"<<endl;
	
		first=constOfFirst;
		int choiceGoOrExit;
		cin>>choiceGoOrExit;
	
		while(choiceGoOrExit!=1&&choiceGoOrExit!=0)
		{
			cout<<"请输入有效数字！"<<endl
				<<"请输入:";
			cin>>choiceGoOrExit;	
		}
	
		if(choiceGoOrExit)
			{
				main_page();
			}
		
		else
		{
			exit(1);	
		}
			
	} 
	
	else
	{
		cout<<"查无此人"<<endl
			<<"5秒后返回主界面";
			first=constOfFirst;
		Sleep(5000);
		main_page();	
	}
	
}

//03删除 
void mainPage::Delete()
{
	system("cls");
	int input;
	stu*deletnode;
	stu*lastnode=first;
	bool Check=false;
	
	if(first==NULL)
	{
		cout<<"该系统内目前无学生资料"<<endl
			<<"正在返回主界面。。。";
		Sleep(3000);
		main_page();	
	}
	cout<<"请输入你要删除的那个学生的学号:";
	cin>>input;
	for(;lastnode!=NULL;lastnode=lastnode->next)
	{
		if(lastnode->stu_id==input)
		{
			Check=true;
			deletnode=lastnode->next;
			first=deletnode;
			constOfFirst=deletnode;
			delete lastnode;
			
			cout<<endl<<"删除成功";
			cout<<endl<<"正在返回主页面...";
			Sleep(3000);
			main_page();
		}
		if(lastnode->next->stu_id==input)
		{
			Check=true;
			deletnode=lastnode->next;
			lastnode->next=deletnode->next;
			delete deletnode;
			
			cout<<endl<<"删除成功";
			cout<<endl<<"正在返回主页面...";
			Sleep(3000);
			main_page();
		}
	}
	
	
	
	while(Check==false)//判断输入 
	{
		cout<<endl<<"请重新输入有效学号或者输入0返回主页面：";
		cin>>input;
		lastnode=first;
		
		if(input==0)
		{
			main_page();
		}
		
	for(;lastnode!=NULL;lastnode=lastnode->next)
	{
		if(lastnode->stu_id==input)
		{
			Check=true;
			deletnode=lastnode->next;
			first=deletnode;
			delete lastnode;
			
			cout<<endl<<"删除成功";
			cout<<endl<<"正在返回主页面...";
			Sleep(3000);
			main_page();
		}
		if(lastnode->next->stu_id==input)
		{
			Check=true;
			deletnode=lastnode->next;
			lastnode->next=deletnode->next;
			delete deletnode;
			
			cout<<endl<<"删除成功";
			cout<<endl<<"正在返回主页面...";
			Sleep(3000);
			main_page();
		}
	}
			
	}
	
	//lastnode->next=deletnode->next;
//	delete deletnode;
//	cout<<endl<<"删除成功";
//	cout<<endl<<"正在返回主页面...";
//	Sleep(3000);
	
//	main_page();		
} 

//04导出
void mainPage::Export()
{
	system("cls");
	char dataname[20];
	cout<<"主界面->导出"<<endl
		<<"请输入要导出的文件名(包括后缀名)（若没有则在程序位置下创建文件）" 
		<<endl<<"<如果文件内有数据则会覆盖，请谨慎使用>:"<<endl;
	getchar();
	gets(dataname);
	fstream file;
	file.open(dataname,ios_base::out|ios_base::trunc);
	
	if(!file.is_open())
	{
		cout<<"文件创建或打开失败。"<<endl;
		Sleep(2000);
		cout<<"正在返回主界面...";
		main_page();
	}
	first=constOfFirst;
	for(;first!=NULL;first=first->next)
	{
		file<<"姓名："<<first->name<<endl
			<<"性别："<<first->sex<<endl
			<<"年龄:"<<first->age<<endl
			<<"学号:"<<first->stu_id<<endl
			<<"电话号码:"<<first->phone_number<<endl;
	}
	
	cout<<"以保存到"<<dataname<<endl
		<<"返回主界面...";
	Sleep(2000);
	main_page();	
} 
int main()
{
	mainPage one;
	one.main_page();
	getchar();getchar();
	return 0;
}
