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
	cout<<setw(8)<<"ͨѶ¼ϵͳ"<<endl
		<<"0.���"<<endl
		<<"1.���"<<endl
		<<"2.��ѯ"<<endl
		<<"3.ɾ��"<<endl
		<<"4.����"<<endl
		<<"5.�˳�"<<endl;
	cout<<"���ѡ����"<<endl;
	int order=0;
	cin>>order;
	return order;
}
void insert(List* pList)
{
	Node newperson;
	person person; 
	cout<<"�밴��˳������ѧ��,����,�Ա�,����,�ֻ���"<<endl; 
	cin>>person.id>>person.name>>person.sex>>person.age>>person.phone;
	newperson.data=person;
	pList->ListInsertTail(&newperson);

}
void getelem(List* pList)
{
	person *newperson=new person;
	cout<<"��������Ҫ��ѯ��������ѧ��:"<<endl;
	cin>>newperson->name>>newperson->id;
	pList->GetElem(newperson->name,newperson->id);
	delete newperson;
}
void deleteplay(List* pList)
{
	string id;
	cout<<"��������Ҫɾ������Ϣ��ѧ��: "<<endl;
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
		case 0:cout<<"���Ĳ����� ���"<<endl;
			pList->ListTraverse();
			break;
		case 1:cout<<"���Ĳ����� ���"<<endl;
			insert(pList);
			break;
		case 2:cout<<"���Ĳ����� ��ѯ"<<endl;
			   getelem(pList);
			   break;
		case 3:cout<<"���Ĳ����� ɾ��"<<endl;
			   deleteplay(pList);
			   break;
		case 4:cout<<"���Ĳ����� ����"<<endl;
				cout<<"�����ļ���:";
				cin>>nnd;
				pList->ListTeaverse1(nnd);
			   break;
		case 5:cout<<"���Ĳ����� �˳�"<<endl;
			   under=5;
			   break;	
		default :cout<<"�������"<<endl;
}
	delete pList;
	pList=NULL;
	
	
	
}
	return 0;
}
