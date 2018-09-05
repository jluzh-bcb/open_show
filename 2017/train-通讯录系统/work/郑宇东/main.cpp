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
			cout<<setw(30)<<"ͨѶ¼ϵͳ"<<endl 
				<<setw(30)<<"0.���"<<endl
				<<setw(30)<<"1.���"<<endl
				<<setw(30)<<"2.��ѯ"<<endl
				<<setw(30)<<"3.ɾ��"<<endl
				<<setw(30)<<"4.����"<<endl
				<<setw(30)<<"5.�˳�"<<endl
				<<"----------------------------------------------------"
				<<endl<<"���ѡ����:";
			cin>>choice;
			while(choice<0||choice>5)
				{
					cout<<"��������Ч����"<<endl
						<<"���ѡ����:";
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

//00��� 
int mainPage::scan_it()
{
	system("cls");
	
	if(first==NULL)
	{
		int choice;
		cout<<"ϵͳ��û�����ѧ������"<<endl
			<<"���ڷ�����ҳ��..."<<endl; 
		Sleep(5000);
		main_page();	
	}
	
	else
	{
		while(first)
		{
			cout<<"������"<<first->name<<endl
				<<"�Ա�"<<first->sex<<endl
				<<"���䣺"<<first->age<<endl
				<<"ѧ�ţ�"<<first->stu_id<<endl
				<<"�绰���룺"<<first->phone_number<<endl;
				first=first->next;
		}
		first=constOfFirst;	
	}
		
	cout<<endl<<"����1�򷵻������棬0���˳�"<<endl;
	
	int choiceGoOrExit;
	cin>>choiceGoOrExit;
	
	while(choiceGoOrExit!=1&&choiceGoOrExit!=0)
	{
		cout<<"��������Ч���֣�"<<endl
			<<"������:";
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

//01���  
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
		
		cout<<"����д�����Ϣ:"<<endl;
		cout<<"������";
		cin>>newone->name;
		cout<<endl<<"�Ա�";
		cin>>newone->sex;
		cout<<endl<<"����:";
		cin>>newone->age;
		cout<<endl<<"ѧ�ţ�";
		cin>>newone->stu_id;
		cout<<endl<<"�绰���룺";
		cin>>newone->phone_number;
		first=newone;
		end=newone;
		constOfFirst=newone;
		end->next=NULL;
	}
	else
	{
		cout<<"����д�����Ϣ:"<<endl;
		cout<<"������";
		cin>>newone->name;
		cout<<endl<<"�Ա�";
		cin>>newone->sex;
		cout<<endl<<"����:";
		cin>>newone->age;
		cout<<endl<<"ѧ�ţ�";
		cin>>newone->stu_id;
		cout<<endl<<"�绰���룺";
		cin>>newone->phone_number;
		end->next=newone;
		end=newone;
		end->next=NULL;
	}
	system("cls");
	cout<<"��ӳɹ�\n"<<"���ڷ�����ҳ�档����"<<endl;
	Sleep(3000);
	main_page();
	return 0; 
}

//02�� 
void mainPage::check()
{
	system("cls");
	int checkTo;
	bool flag=false;
	cout<<"������ѧ�Ž��в�ѯ��";
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
		cout<<"������"<<first->name<<endl
			<<"�Ա�"<<first->sex<<endl
			<<"���䣺"<<first->age<<endl
			<<"ѧ�ţ�"<<first->stu_id<<endl
			<<"�绰���룺"<<first->phone_number<<endl;	
			cout<<endl<<"����1�򷵻������棬0���˳�"<<endl;
	
		first=constOfFirst;
		int choiceGoOrExit;
		cin>>choiceGoOrExit;
	
		while(choiceGoOrExit!=1&&choiceGoOrExit!=0)
		{
			cout<<"��������Ч���֣�"<<endl
				<<"������:";
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
		cout<<"���޴���"<<endl
			<<"5��󷵻�������";
			first=constOfFirst;
		Sleep(5000);
		main_page();	
	}
	
}

//03ɾ�� 
void mainPage::Delete()
{
	system("cls");
	int input;
	stu*deletnode;
	stu*lastnode=first;
	bool Check=false;
	
	if(first==NULL)
	{
		cout<<"��ϵͳ��Ŀǰ��ѧ������"<<endl
			<<"���ڷ��������档����";
		Sleep(3000);
		main_page();	
	}
	cout<<"��������Ҫɾ�����Ǹ�ѧ����ѧ��:";
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
			
			cout<<endl<<"ɾ���ɹ�";
			cout<<endl<<"���ڷ�����ҳ��...";
			Sleep(3000);
			main_page();
		}
		if(lastnode->next->stu_id==input)
		{
			Check=true;
			deletnode=lastnode->next;
			lastnode->next=deletnode->next;
			delete deletnode;
			
			cout<<endl<<"ɾ���ɹ�";
			cout<<endl<<"���ڷ�����ҳ��...";
			Sleep(3000);
			main_page();
		}
	}
	
	
	
	while(Check==false)//�ж����� 
	{
		cout<<endl<<"������������Чѧ�Ż�������0������ҳ�棺";
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
			
			cout<<endl<<"ɾ���ɹ�";
			cout<<endl<<"���ڷ�����ҳ��...";
			Sleep(3000);
			main_page();
		}
		if(lastnode->next->stu_id==input)
		{
			Check=true;
			deletnode=lastnode->next;
			lastnode->next=deletnode->next;
			delete deletnode;
			
			cout<<endl<<"ɾ���ɹ�";
			cout<<endl<<"���ڷ�����ҳ��...";
			Sleep(3000);
			main_page();
		}
	}
			
	}
	
	//lastnode->next=deletnode->next;
//	delete deletnode;
//	cout<<endl<<"ɾ���ɹ�";
//	cout<<endl<<"���ڷ�����ҳ��...";
//	Sleep(3000);
	
//	main_page();		
} 

//04����
void mainPage::Export()
{
	system("cls");
	char dataname[20];
	cout<<"������->����"<<endl
		<<"������Ҫ�������ļ���(������׺��)����û�����ڳ���λ���´����ļ���" 
		<<endl<<"<����ļ�����������Ḳ�ǣ������ʹ��>:"<<endl;
	getchar();
	gets(dataname);
	fstream file;
	file.open(dataname,ios_base::out|ios_base::trunc);
	
	if(!file.is_open())
	{
		cout<<"�ļ��������ʧ�ܡ�"<<endl;
		Sleep(2000);
		cout<<"���ڷ���������...";
		main_page();
	}
	first=constOfFirst;
	for(;first!=NULL;first=first->next)
	{
		file<<"������"<<first->name<<endl
			<<"�Ա�"<<first->sex<<endl
			<<"����:"<<first->age<<endl
			<<"ѧ��:"<<first->stu_id<<endl
			<<"�绰����:"<<first->phone_number<<endl;
	}
	
	cout<<"�Ա��浽"<<dataname<<endl
		<<"����������...";
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
