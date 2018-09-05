/*编程部程序设计作业1：通讯录系统 
  by邹家豪 04170415  2018.1        */ 
#include<iostream> 
#include<fstream> 
using namespace std;
class Student  
{public:  
    void setName();  
    string getName();  
    void setId();  
    string getId();  
    void setAge();  
    unsigned int getAge();  
    void setSex();  
    string getSex();    
    void setPhone();  
    string getPhone();  
  private:  
    string name;  
    string  id;   
	char sex[5];   
    char phone[20]; 
    unsigned int  age; 
};  
void Student::setId()  
{  
  cout<<"Id:";  
  cin>>id;  
}   
string Student::getId()  
{  
  return id;  
}  
void Student::setName()  
{  
  cout<<"Name:";  
  cin>>name;  
}  
string Student::getName()  
{  
  return name;  
}  
void Student::setAge()  
{  
  cout<<"Age:";  
  cin>>age;  
}   
unsigned int Student::getAge()  
{  
  return age;  
}   

void Student::setSex()  
{  
  cout<<"Sex:";  
  cin>>sex;  
}  
string Student::getSex() 
{  
  return sex;  
}  

void Student::setPhone()
{  
  cout<<"Phone:";  
  cin>>phone;  
}  
string Student::getPhone()  
{  
  return phone;  
}  
 
