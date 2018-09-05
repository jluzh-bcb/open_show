#include "List.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
List::List()
{
	m_pList=new Node;
	m_pList->data=0;
	m_pList->next=NULL;
}

bool List::GetElem(string pname,string pid)
{
	Node *currNode=m_pList->next;
	while(currNode->next!=NULL)
	{
		if(currNode->data.name==pname && currNode->data.id==pid)
		{
			cout<<currNode->data;
			return true;
		}
		currNode=currNode->next;
	}
	return false;
}
void List::ClearList()
{
	Node *currp=m_pList->next;
	while(currp!=NULL)
	{
		Node *hod=currp->next;
		delete currp;
		currp=hod;
	}
	m_pList->next=NULL;
}
List::~List()
{
	ClearList();
	delete m_pList;
	m_pList=NULL;
}
bool List::ListSertHead(Node* pNode)
{
	Node* head=m_pList->next;
	Node* newNode=new Node;
	if(newNode==NULL)
	return false;
	newNode->data=pNode->data;
	m_pList->next=newNode;
	newNode->next=head;
	return true;
	
 } 
 bool List::ListInsertTail(Node *pNode)
 { 
 	Node* head=m_pList->next;
	while(head->next!=NULL)
	{
		head=head->next;
	}
	Node* newNode=new Node;
	if(newNode==NULL)
	return false;
	newNode->data=pNode->data;
	newNode->next=NULL;
	head->next=newNode;
	return true;
 }
 bool List::ListDelete(string pid)
 {
 	Node* currNode=m_pList->next;
 	while(currNode->next!=NULL)
 	{
 		if(currNode->data.id==pid)
 		{
 			Node *deleteNode=currNode;
 			currNode=currNode->next;
 			delete deleteNode;
 			deleteNode=NULL;
 			return true;
		 }
	 }
	 return false;
 }
 void List::ListTraverse()
 {
 	Node *currNode=m_pList->next;
 	while(currNode!=NULL)
 	{
 		cout<<currNode->data<<endl;
 		currNode=currNode->next;
	 }
}
void List::ListTeaverse1(char a[])
 {
 	ofstream outfile;
 	outfile.open(a);
	 
 	Node *currNode=m_pList->next;
 	while(currNode!=NULL)
 	{
 		outfile<<currNode->data;
 		currNode=currNode->next;
	 }
}
