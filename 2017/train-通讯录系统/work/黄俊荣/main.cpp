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
void browse(void)/*浏览*/ 
{
	student *flag1;
	flag1=head;
	while(1)
	{
		if(flag1==NULL)/*判断是否有学生信息*/ 
		{
			cout<<"none"<<endl;
			break;
		}
		cout<<"学号:"<<flag1->id<<endl<<"名字:"<<flag1->name<<endl<<"性别:"<<flag1->sex<<endl<<"年龄:"<<flag1->age<<endl<<"手机号:"<<flag1->phone<<endl<<endl;
		if(flag1->next==NULL)
		{
			break;
		}
		flag1=flag1->next;
	}
}
void add(void)/*添加*/ 
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
		for(int n=0;n<acco;n++)/*判断学号是否重复*/ 
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
			cout<<"学号已被输入"<<endl;
			system("pause");
			return;
		}
		cin>>p1->name>>p1->sex>>p1->age>>p1->phone;
		p1->next=NULL;
		acco++;
	}
}
void query(void)/*查询*/ 
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
			cout<<"学号:"<<flag2->id<<endl<<"名字:"<<flag2->name<<endl<<"性别:"<<flag2->sex<<endl<<"年龄:"<<flag2->age<<endl<<"手机号:"<<flag2->phone<<endl;
			break;
		}
		else if(flag2->next==NULL)/*判断输入学号是否存在*/ 
		{
		    cout<<"没有此人，请输入正确学号"<<endl;
		    break;
	    }
		flag2=flag2->next;
	}
}
void delet(void)/*删除*/ 
{
	student *flag4,*flag5,*flag6;
	string need;
	flag4=flag5=flag6=head;
	cin>>need;
	while(1)
	{
		if(flag4==NULL)/*判断是否存在此学生信息*/ 
		{
			cout<<"没有此人，请输入正确学号"<<endl;
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
            cout<<"没有此人，请输入正确学号"<<endl;
            system("pause");
		    break;
		}
		flag4=flag4->next;
	}
}
void puto(void)/*导出*/ 
{
	student *flag3;
	string need;
	fstream file;
	string name;
	cout<<"请输入文件名:"<<endl; 
	cin>>name;
	cout<<"请输入学号:"<<endl;
	cin>>need;
	flag3=head;
	while(1)
	{
		if(flag3->id==need)
		{
			file.open(name.c_str(),ios_base::out);
		    file<<"名字："<<flag3->id<<endl<<"学号:"<<flag3->name<<endl<<"性别:"<<flag3->sex<<endl<<"年龄:"<<flag3->age<<endl<<"手机号:"<<flag3->phone<<endl;
		    file.close();
		    if(file)
		    cout<<"OK"<<endl;
			break;
		}
	    else if(flag3->next==NULL)/*判断是否存在此学生信息*/ 
		{
		    cout<<"没有此人，请输入正确学号"<<endl;
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
		cout<<"              通讯录系统                      "<<endl;
		cout<<"              0.浏览                          "<<endl;
		cout<<"              1.添加                          "<<endl;
		cout<<"              2.查询                          "<<endl;
		cout<<"              3.删除                          "<<endl;
		cout<<"              4.导出                          "<<endl;
		cout<<"              5.退出                          "<<endl;
		cout<<"______________________________________________"<<endl;
		cin>>choose;
		system("cls");
		if(choose==5)
			break;
		else if(choose==0)
		{
			cout<<"主界面->浏览"<<endl;
			browse();
			system("pause");
		}
		else if(choose==1)
		{
			cout<<"主界面->添加"<<endl<<"请输入学生信息"<<endl; 
			cout<<"学号、名字、性别、年龄、手机号(请逐个输入)"<<endl;
			add();
		}
		else if(choose==2)
		{
			query();
			system("pause");
		}
		else if(choose==3)
		{
			cout<<"主界面->删除"<<endl<<"请输入学号:"<<endl;
			delet();
		}
		else if(choose==4)
		{
			cout<<"主界面->导出"<<endl; 
			puto();
			system("pause");
		}
		system("cls");
	}
	return 0;
}

