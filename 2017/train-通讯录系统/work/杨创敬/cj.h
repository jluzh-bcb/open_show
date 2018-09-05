#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class Cj{
	private:
		int id;
		string student_id;
		string name;
		string sex;
		string age;
		string phone;
	public:
		static int count;//计数
		void choose();   //选择
		void show();     //浏览 
		void add();      //添加 
		void search();   //查询
		void del();      //删除 
		void output();   //导出 
		void face();     //界面 
		int Getid();
		void setname();
		string getname() const;
		void setphone();
		string getphone() const;
		void setstudent_id();
		string getstudent_id() const;
		void setsex();
		string getsex() const;
		void setage();
		string getage() const;
};
