#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include<ostream>
using namespace std;
class person
{
	friend ostream &operator <<(ostream& out,person& Person);
	public:
		string name;
		string phone;
		string id;
		string age;
		string sex;
		person &operator=(person &Person);
		bool operator==(person &Person);
		
};

#endif
