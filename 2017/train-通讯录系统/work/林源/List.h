#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include<string>
class List
{
	public:
		List();
		~List();
		void ClearList();
		bool GetElem(string pname,string pid);
		void ListTraverse();	
		bool ListDelete(string pid);
		bool ListSertHead(Node* pNode);
		bool ListInsertTail(Node *pNode);
		void ListTeaverse1(char a[]);
		Node* m_pList;
};

#endif
