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
	cout<<"序号："<<count<<endl;
	t.setstudent_id();
	for(it=per.begin() ;it!=per.end() ;it++)//重名判断 
	{
		if(!((it->getstudent_id()).compare(t.getstudent_id() )))
		{
			cout<<"与已有联系人重复ID，请重新输入！"<<endl;
			count--;
			goto loop;
		}
	}
	t.setname() ;
	for(it=per.begin() ;it!=per.end() ;it++)//重名判断 
	{
		if(!((it->getname()).compare(t.getname() )))
		{
			cout<<"与已有联系人重名，请重新输入！"<<endl;
			count--;
			goto loop;
		}
	}
	t.setage();
	t.setsex();
	t.setphone() ;
	t.id=count;
	
	per.push_back(t);
	
	cout<<"是否继续添加 1.是 2.否 ：";
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
		cout<<"通讯录内暂无联系人！"<<endl;
	}else
	{
loop:
		int t=0;
		int num=0;
		string _id;
		string _name;
		int flag=0;
		
		cout<<"查询方式：1.ID 2.姓名 3.序号"<<endl;
		cin>>t;
		if(1==t)
		{
			cout<<"请输入要查询的ID:";
			cin>>_id;
			for(it=per.begin() ;it!=per.end() ;it++)
			{
				if(!((it->getstudent_id()).compare(_id)))
				{
					flag=1;
					cout<<"你要查询的联系人为："<<endl
						<<"序号："<<it->Getid()<<endl
						<<"id："<<it->getstudent_id()<<endl
						<<"name："<<it->getname()<<endl
						<<"age："<<it->getage()<<endl
						<<"sex："<<it->getsex()<<endl
						<<"phone："<<it->getphone()<<endl<<endl;
				}
			}
		}
		else if(2==t)
		{
			cout<<"请输入要查询的姓名:";
			cin>>_name;
			for(it=per.begin() ;it!=per.end() ;it++)
			{
				if(!((it->getname()).compare(_name)))
				{
					flag=1;
					cout<<"你要查询的联系人为："<<endl
						<<"序号："<<it->Getid()<<endl
						<<"id："<<it->getstudent_id()<<endl
						<<"name："<<it->getname()<<endl
						<<"age："<<it->getage()<<endl
						<<"sex："<<it->getsex()<<endl
						<<"phone："<<it->getphone()<<endl<<endl;
				}
			}
		}
		else if(3==t)
		{
			cout<<"请输入要查询的序号:";
			cin>>num;
			for(it=per.begin() ;it!=per.end() ;it++)
			{
				if(it->Getid()==num)
				{
					flag=1;
					cout<<"你要查询的联系人为："<<endl
					<<"序号："<<it->Getid()<<endl
					<<"id："<<it->getstudent_id()<<endl
					<<"name："<<it->getname()<<endl
					<<"age："<<it->getage()<<endl
					<<"sex："<<it->getsex()<<endl
					<<"phone："<<it->getphone()<<endl<<endl;
				}
			}
		}
		else
		{
			cout<<"查询方式错误，请重试！"<<endl;
			goto loop;
		}
		
		if(0==flag)
		{
			cout<<"无法找到此联系人！"<<endl;
		}else
		{
			cout<<"查询成功！"<<endl;
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
		cout<<"通讯录内暂无联系人！"<<endl;
	}
	else
	{
loop:
		string _id;
		int flag=0;
		cout<<"请输入要删除的ID："; 
		cin>>_id;
		for(it=per.begin() ;it!=per.end() ;it++)
		{
			if(!((it->getstudent_id()).compare(_id)))
			{
				flag=1;
				cout<<"你要删除的联系人为："<<endl
				<<"序号："<<it->Getid()<<endl
				<<"id："<<it->getstudent_id()<<endl
				<<"name："<<it->getname()<<endl
				<<"age："<<it->getage()<<endl
				<<"sex："<<it->getsex()<<endl
				<<"phone："<<it->getphone()<<endl<<endl;
				
				cout<<"确认删除？ 1.是 2.否:"<<endl;
				int a;
				cin>>a;
				if(1==a)
				{
					it=per.erase(it);
				}else
				{
					cout<<"已取消！"<<endl;
					flag=2;
				}
			}
		}
		if(1==flag)
		{
			cout<<"删除成功！"<<endl;
		}else if(0==flag)
		{
			cout<<"找不到此联系人！"<<endl;
		}
	}
	system("pause");
}

void Cj::output()
{
	vector<Cj>::iterator it;
	ofstream out;
	char filename[50];
	cout<<"请输入要导出的文件名:";
	cin>>filename;
	out.open(filename);
	if(out.is_open() )
	{
		for(it=per.begin() ;it!=per.end() ;it++)
		{
			out <<"序号："<<it->Getid()<<endl
				<<"id："<<it->getstudent_id()<<endl
				<<"name："<<it->getname()<<endl
				<<"age："<<it->getage()<<endl
				<<"sex："<<it->getsex()<<endl
				<<"phone："<<it->getphone()<<endl<<endl;
		}
		cout<<"导出完成！"<<endl;
		out.close() ;
	} 
	system("pause");
}

void Cj::choose() 
{
	int a;
	Cj t;
	cout<<"你的选择是:";
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
			cout<<"输入错误，请重新输入！"<<endl;
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
		cout<<"通讯录内暂无联系人！"<<endl;
	}else
	{
		for(it = per.begin() ;it != per.end() ;it++)
		{
			cout<<"序号："<<it->Getid()<<endl
				<<"id："<<it->getstudent_id()<<endl
				<<"name："<<it->getname()<<endl
				<<"age："<<it->getage()<<endl
				<<"sex："<<it->getsex()<<endl
				<<"phone："<<it->getphone()<<endl<<endl;
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
	cout<<"   |         通讯录系统         |"<<endl;
	cout<<"   |            By CJ           |"<<endl;
	cout<<"   |          0.浏览            |"<<endl;
	cout<<"   |          1.添加            |"<<endl;
	cout<<"   |          2.查询            |"<<endl;
	cout<<"   |          3.删除            |"<<endl;
	cout<<"   |          4.导出            |"<<endl;
	cout<<"   |          5.退出            |"<<endl;
	cout<<"   |****************************|"<<endl;
}
