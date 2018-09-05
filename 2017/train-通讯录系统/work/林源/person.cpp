#include "person.h"
ostream &operator <<(stream& out,person& Person)
{
	out <<"id:"<<Person.id<<endl<<"name:"<<Person.name<<endl<<"age:"<<Person.age<<endl<<"sex:"<<Person.sex<<endl<<"phone:"<<Person.phone<<endl;
	return out;
}
person &operator=(person &Person)
{
	this->name=Person.name;
	this->id=Person.id;
	this->age=Person.age;
	this->sex=Person.sex;
	this->phone=Person.phone;
	return *this;
}
bool operator==(person &Person)
{
	if(this->name==Person.name&&this->id==Person.id&&this->age==Person.age&&this->sex==Person.sex&&this->phone==Person.phone)
	return true;
	else return false;
}

