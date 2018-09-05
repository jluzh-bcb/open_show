#include <iostream>
#include "List.h"
#include <string>
#include <stdlib.h> 
#include <iomanip>
#include <fstream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu()
{
	cout<<setw(8)<<"通讯录系统"<<endl
		<<"0.浏览"<<endl
		<<"1.添加"<<endl
		<<"2.查询"<<endl
		<<"3.删除"<<endl
		<<"4.导出"<<endl
		<<"5.退出"<<endl;
	cout<<"你的选择是"<<endl;
	int order=0;
	cin>>order;
	return order;
}
void insert(List* pList)
{
	Node newperson;
	person person; 
	cout<<"请按照顺序输入学号,姓名,性别,年龄,手机号"<<endl; 
	cin>>person.id>>person.name>>person.sex>>person.age>>person.phone;
	newperson.data=person;
	pList->ListInsertTail(&newperson);

}
void getelem(List* pList)
{
	person *newperson=new person;
	cout<<"请输入您要查询的姓名和学号:"<<endl;
	cin>>newperson->name>>newperson->id;
	pList->GetElem(newperson->name,newperson->id);
	delete newperson;
}
void deleteplay(List* pList)
{
	string id;
	cout<<"请输入您要删除的信息的学号: "<<endl;
	cin>>id;
	pList->ListDelete(id);
}
int main(int argc, char** argv) 
{
	List *pList=new List();
	char nnd[100];
	int under=0;
	while(under!=5)
	{
	under=menu();
	switch(under)
	{
		case 0:cout<<"您的操作是 浏览"<<endl;
			pList->ListTraverse();
			break;
		case 1:cout<<"您的操作是 添加"<<endl;
			insert(pList);
			break;
		case 2:cout<<"您的操作是 查询"<<endl;
			   getelem(pList);
			   break;
		case 3:cout<<"您的操作是 删除"<<endl;
			   deleteplay(pList);
			   break;
		case 4:cout<<"您的操作是 导出"<<endl;
				cout<<"输入文件名:";
				cin>>nnd;
				pList->ListTeaverse1(nnd);
			   break;
		case 5:cout<<"您的操作是 退出"<<endl;
			   under=5;
			   break;	
		default :cout<<"输入错误"<<endl;
}
	delete pList;
	pList=NULL;
	
	
	
}
	return 0;
}
