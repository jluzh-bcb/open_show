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
		static int count;//����
		void choose();   //ѡ��
		void show();     //��� 
		void add();      //��� 
		void search();   //��ѯ
		void del();      //ɾ�� 
		void output();   //���� 
		void face();     //���� 
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
