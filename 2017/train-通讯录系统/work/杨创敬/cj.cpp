#include "cj.h"

vector<Cj> per;
int Cj::count = 0;

int Cj::Getid()
{
	return id;
}

void Cj::setstudent_id()
{
	cout<<"id:";
	cin>>student_id;
}
string Cj::getstudent_id() const
{
	string t=student_id;
	return t;
}

void Cj::setage()
{
	cout<<"age:";
	cin>>age;
}
string Cj::getage() const
{
	string t=age;
	return t;
}

void Cj::setsex()
{
	cout<<"sex:";
	cin>>sex;
}
string Cj::getsex() const
{
	string t=sex;
	return t;
}

void Cj::setname()
{
	cout<<"name:";
	cin>>name;
}
string Cj::getname() const
{
	string t=name;
	return t;
}

void Cj::setphone()
{
	cout<<"phone:";
	cin>>phone;
}
string Cj::getphone() const
{
	string t=phone;
	return t;
}

void Cj::add()
{
	Cj t;
	vector<Cj>::iterator it;
loop:
	count++;
	cout<<"��ţ�"<<count<<endl;
	t.setstudent_id();
	for(it=per.begin() ;it!=per.end() ;it++)//�����ж� 
	{
		if(!((it->getstudent_id()).compare(t.getstudent_id() )))
		{
			cout<<"��������ϵ���ظ�ID�����������룡"<<endl;
			count--;
			goto loop;
		}
	}
	t.setname() ;
	for(it=per.begin() ;it!=per.end() ;it++)//�����ж� 
	{
		if(!((it->getname()).compare(t.getname() )))
		{
			cout<<"��������ϵ�����������������룡"<<endl;
			count--;
			goto loop;
		}
	}
	t.setage();
	t.setsex();
	t.setphone() ;
	t.id=count;
	
	per.push_back(t);
	
	cout<<"�Ƿ������� 1.�� 2.�� ��";
	int a;
	cin>>a;
	if(1==a)
	{
		goto loop;
	 } 
	 
}

void Cj::search()
{
	vector<Cj>::iterator it;
	if(per.empty() )
	{
		cout<<"ͨѶ¼��������ϵ�ˣ�"<<endl;
	}else
	{
loop:
		int t=0;
		int num=0;
		string _id;
		string _name;
		int flag=0;
		
		cout<<"��ѯ��ʽ��1.ID 2.���� 3.���"<<endl;
		cin>>t;
		if(1==t)
		{
			cout<<"������Ҫ��ѯ��ID:";
			cin>>_id;
			for(it=per.begin() ;it!=per.end() ;it++)
			{
				if(!((it->getstudent_id()).compare(_id)))
				{
					flag=1;
					cout<<"��Ҫ��ѯ����ϵ��Ϊ��"<<endl
						<<"��ţ�"<<it->Getid()<<endl
						<<"id��"<<it->getstudent_id()<<endl
						<<"name��"<<it->getname()<<endl
						<<"age��"<<it->getage()<<endl
						<<"sex��"<<it->getsex()<<endl
						<<"phone��"<<it->getphone()<<endl<<endl;
				}
			}
		}
		else if(2==t)
		{
			cout<<"������Ҫ��ѯ������:";
			cin>>_name;
			for(it=per.begin() ;it!=per.end() ;it++)
			{
				if(!((it->getname()).compare(_name)))
				{
					flag=1;
					cout<<"��Ҫ��ѯ����ϵ��Ϊ��"<<endl
						<<"��ţ�"<<it->Getid()<<endl
						<<"id��"<<it->getstudent_id()<<endl
						<<"name��"<<it->getname()<<endl
						<<"age��"<<it->getage()<<endl
						<<"sex��"<<it->getsex()<<endl
						<<"phone��"<<it->getphone()<<endl<<endl;
				}
			}
		}
		else if(3==t)
		{
			cout<<"������Ҫ��ѯ�����:";
			cin>>num;
			for(it=per.begin() ;it!=per.end() ;it++)
			{
				if(it->Getid()==num)
				{
					flag=1;
					cout<<"��Ҫ��ѯ����ϵ��Ϊ��"<<endl
					<<"��ţ�"<<it->Getid()<<endl
					<<"id��"<<it->getstudent_id()<<endl
					<<"name��"<<it->getname()<<endl
					<<"age��"<<it->getage()<<endl
					<<"sex��"<<it->getsex()<<endl
					<<"phone��"<<it->getphone()<<endl<<endl;
				}
			}
		}
		else
		{
			cout<<"��ѯ��ʽ���������ԣ�"<<endl;
			goto loop;
		}
		
		if(0==flag)
		{
			cout<<"�޷��ҵ�����ϵ�ˣ�"<<endl;
		}else
		{
			cout<<"��ѯ�ɹ���"<<endl;
		}
	}
	cout<<endl<<endl;
	system("pause");
}

void Cj::del()
{
	vector<Cj>::iterator it;
	if(per.empty() )
	{
		cout<<"ͨѶ¼��������ϵ�ˣ�"<<endl;
	}
	else
	{
loop:
		string _id;
		int flag=0;
		cout<<"������Ҫɾ����ID��"; 
		cin>>_id;
		for(it=per.begin() ;it!=per.end() ;it++)
		{
			if(!((it->getstudent_id()).compare(_id)))
			{
				flag=1;
				cout<<"��Ҫɾ������ϵ��Ϊ��"<<endl
				<<"��ţ�"<<it->Getid()<<endl
				<<"id��"<<it->getstudent_id()<<endl
				<<"name��"<<it->getname()<<endl
				<<"age��"<<it->getage()<<endl
				<<"sex��"<<it->getsex()<<endl
				<<"phone��"<<it->getphone()<<endl<<endl;
				
				cout<<"ȷ��ɾ���� 1.�� 2.��:"<<endl;
				int a;
				cin>>a;
				if(1==a)
				{
					it=per.erase(it);
				}else
				{
					cout<<"��ȡ����"<<endl;
					flag=2;
				}
			}
		}
		if(1==flag)
		{
			cout<<"ɾ���ɹ���"<<endl;
		}else if(0==flag)
		{
			cout<<"�Ҳ�������ϵ�ˣ�"<<endl;
		}
	}
	system("pause");
}

void Cj::output()
{
	vector<Cj>::iterator it;
	ofstream out;
	char filename[50];
	cout<<"������Ҫ�������ļ���:";
	cin>>filename;
	out.open(filename);
	if(out.is_open() )
	{
		for(it=per.begin() ;it!=per.end() ;it++)
		{
			out <<"��ţ�"<<it->Getid()<<endl
				<<"id��"<<it->getstudent_id()<<endl
				<<"name��"<<it->getname()<<endl
				<<"age��"<<it->getage()<<endl
				<<"sex��"<<it->getsex()<<endl
				<<"phone��"<<it->getphone()<<endl<<endl;
		}
		cout<<"������ɣ�"<<endl;
		out.close() ;
	} 
	system("pause");
}

void Cj::choose() 
{
	int a;
	Cj t;
	cout<<"���ѡ����:";
	cin>>a;
	
	switch(a)
	{
		case 0:
		{ 
			t.show() ;
			t.face() ;
			choose() ;
			break;
		} 
		case 1:
		{ 
			t.add() ;
			t.face() ;
			choose();
			break;
		}
		case 2:
		{
			t.search();
			t.face() ;
			choose();
		}	
		case 3:
		{
			t.del();
			t.face() ;
			choose();
		}
		case 4:
		{
			t.output();
			t.face();
			choose();
		}	
		case 5:
		{
			exit(1);
		}
		default :
		{
			cout<<"����������������룡"<<endl;
			choose();
			break; 
		} 
	}
}

void Cj::show()
{
	vector<Cj>::iterator it;
	if(per.empty() )
	{
		cout<<"ͨѶ¼��������ϵ�ˣ�"<<endl;
	}else
	{
		for(it = per.begin() ;it != per.end() ;it++)
		{
			cout<<"��ţ�"<<it->Getid()<<endl
				<<"id��"<<it->getstudent_id()<<endl
				<<"name��"<<it->getname()<<endl
				<<"age��"<<it->getage()<<endl
				<<"sex��"<<it->getsex()<<endl
				<<"phone��"<<it->getphone()<<endl<<endl;
		}
	}
	cout<<endl<<endl;
	system("pause");
}

void Cj::face() 
{
	system("cls");
	cout<<endl<<endl;
	 
	cout<<"   |****************************|"<<endl;
	cout<<"   |         ͨѶ¼ϵͳ         |"<<endl;
	cout<<"   |            By CJ           |"<<endl;
	cout<<"   |          0.���            |"<<endl;
	cout<<"   |          1.���            |"<<endl;
	cout<<"   |          2.��ѯ            |"<<endl;
	cout<<"   |          3.ɾ��            |"<<endl;
	cout<<"   |          4.����            |"<<endl;
	cout<<"   |          5.�˳�            |"<<endl;
	cout<<"   |****************************|"<<endl;
}
