/*��̲����������ҵ1��ͨѶ¼ϵͳ 
  by�޼Һ� 04170415  2018.1    
  ʧ��Ʒ��δ��ɣ�����
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� �� �ģߡġ� �ģߡ�
                       ��(���৥��)? ;;;)���ࣩ
                       ��/�ġ� /�� ?��?/
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
  ʧ��Ʒ��δ��ɣ����� 
   

��໣� �� �ܩc/��
��໣����� ��_ ��
��໣�����('��';):.
������ ,��'�Ф�.j�ߩc
���� �Ρ�,.��'����c/
����������������i! /
   
          */ 
  
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib> 
#include <cassert>
#include <string>
#include"book.h"
int count=0; 
using namespace std;
void Read();
void Search();
void Exit();
void Add();
int Export();
void Delete();
void ShowInputAgian();
void ShowInput(); 
void SearchStd();
void SearchId();
//���˵� 
void ShowInput(){
	cout<<endl; 
	cout<<"����������������������������������"<<endl;
	cout<<setw(10)<<"ͨѶ¼ϵͳ Address Book  Bate1.0" <<endl;
	cout<<endl; 
	cout<<setw(20)<<"0.���"<<endl;
	cout<<setw(20)<<"1.��ѯ"<<endl;
	cout<<setw(20)<<"2.���"<<endl;
	cout<<setw(20)<<"3.ɾ��"<<endl;
	cout<<setw(20)<<"4.����"<<endl;
	cout<<setw(20)<<"5.�˳�"<<endl; 
	cout<<endl;
	cout<<"����������������������������������"<<endl;
    cout<<"Input number��" ; 
	int num;
	cin>>num;
	switch(num){
		case 0:Read();
		case 1:Search();
		case 2:Add();
		case 3:Delete();
		case 4:Export(); 
		case 5:Exit(); 
	}
}
//���˵� 
void ShowInputAgian(){
	cout<<endl; 
	cout<<"����������������������������������"<<endl;
	cout<<setw(10)<<"ͨѶ¼ϵͳ Address Book  Bate1.0" <<endl;
	cout<<endl; 
	cout<<setw(20)<<"0.�������˵�"<<endl;
	cout<<setw(20)<<"1.�˳�����"<<endl;
	cout<<endl;
	cout<<"����������������������������������"<<endl;
    cout<<"Input number��" ; 
	int num;
	cin>>num;
	switch(num){
		case 0:ShowInput();
		case 1:Exit();
	}
}
//���ģ�� 
void Add(){
	Student newStd;
	string name;
	cout<<"����������������������������������"<<endl;
	cout<<"����������Ϣ�� "<<endl;
	newStd.setId();
	newStd.setName();
	newStd.setAge();
	newStd.setSex();
	newStd.setPhone();	
	cout<<"����������������������������������"<<endl;
	cout<<endl;
	ofstream add("D:\\data.txt",ios::app);
	if(!add){
        cout << "������˼��(���n��) ����Error ��ʱ�޷��������\n";
        exit(0);
    }
   else{
    add<<endl; 
    add<<count<<endl; 
    add<<"Id:"<<newStd.getId()<<endl;
    add<<"Name:"<<newStd.getName()<<endl;
	add<<"Age:"<<newStd.getAge()<<endl;
	add<<"Sex:"<<newStd.getSex()<<endl;
	add<<"Phone:"<<newStd.getPhone()<<endl; 
    add.close();
    cout<<"��ϲ��?(��ţ�) ��ӳɹ�"<<endl;
    count++;
    return ShowInputAgian();
}
}
//����ģ�� 
void Example(){
	ofstream ex("D:\\data.txt",ios::app);
	ex<<"Example"<<endl; 
	ex<<"0"<<endl;
    ex<<"Id:04170415"<<endl;
    ex<<"Name:�޼Һ�"<<endl;
	ex<<"Age:18"<<endl;
	ex<<"Sex:��"<<endl;
	ex<<"Phone:13543038201"<<endl;
	ex.close(); 
}
int Export()  
{   int i = 1;
    string temp;
    ifstream infile;
    ofstream outfile0;
    ofstream outfile1;
    cout<<endl; 
    cout<<"����������������������������������"<<endl;
    cout<<endl;
	cout<<"�ѳɹ�������λ��D:\\ͨѶ¼����.txt "<<endl;  
    cout<<endl;
	cout<<"����������������������������������"<<endl;
    infile.open("D:\\data.txt", ios::in);
    outfile0.open("D:\\ͨѶ¼����.txt" ,ios::app);
    outfile1.open("D:\\ͨѶ¼����.txt" ,ios::app);
    while (!infile.eof()) {
        getline(infile, temp, '\n');
        i++;
        if (i%2) outfile1 << temp << endl;
        else     outfile0 << temp << endl;
    }
    infile.close();
    outfile0.close();
    outfile1.close();
    ShowInputAgian();
}  

//ɾ��ģ�� 
void Delete(){
    cout<<"����������������������������������"<<endl;
    cout<<endl;
	cout<<"��Ǹ�רr(�s���t)�q�˹�����δ����"<<endl;
	cout<<endl;
	cout<<"����������������������������������"<<endl;
    ShowInputAgian();
}
//���ģ�� 
void Read(){
	cout<<"����������������������������������"<<endl;
    fstream read;
	read.open("D:\\data.txt",ios::in);  
    cout<<endl;
    char s[256];
    while(!read.eof()){
    	read.getline(s,256);
    	cout<<s<<endl;
	}
    cout<<"����������������������������������"<<endl;
    read.close();
    ShowInputAgian();
}
//�˳�ģ�� 
void Exit(){
	cout<<endl<<"ͨѶ¼����������"<<endl;
    fclose(fopen("D:\\data.txt", "w"));
	cout<<"Bye~~�ڴ���һ���������(*^__^*) ��������"<<endl;
	exit(1); 
}
//����ģ�� 
void Search(){
	cout<<endl; 
	cout<<"����������������������������������"<<endl;
	cout<<setw(10)<<"ͨѶ¼ϵͳ Address Book  Bate1.0" <<endl;
	cout<<endl;  
	cout<<setw(20)<<"0.ͨ��������ѯ"<<endl;
	cout<<setw(20)<<"1.ͨ��ѧ�Ų�ѯ"<<endl;
	cout<<setw(20)<<"2.�������˵�"<<endl;
	cout<<setw(20)<<"3.�˳�����"<<endl;
	cout<<endl;
	cout<<"����������������������������������"<<endl;
    cout<<"Input number��" ; 
	int num;
	cin>>num;
	switch(num){
		case 0:SearchStd();
		case 1:SearchId();
		case 2:ShowInput();
		case 3:Exit(); 
	}
}
//����ģ�� by ���� 
void SearchStd(){
	int i;
	string tmp;
	fstream seekStd;
	seekStd.open("D:\\data.txt",ios::in);  
    cout<<"����������������������������������"<<endl;
    cout<<endl;
    cout<<"�r(�s���t)�q���޷�֧�ִ˷�����ѯ"<<endl;
    cout<<"������ͨ����Ų�ѯ"<<endl;
	cout<<"���������֣���1��ʼ����"<<endl;
	cin>>i;
	int n=i+1;
	char c[256];
	string z;
	while(!seekStd.eof())
	{seekStd.getline(c,256);
	string t=c;
	cout<<t;
	for(int j=0;j<=256;j++)
	if(t[j]='i'&&t[j]!='n')
	{t[j]=z[j];
	}
	for(int j=0;j<=256;j++){
		cout<<z[j];
	}}
    cout<<"����������������������������������"<<endl;
    seekStd.close();
}
//����ģ�� byѧ�� 
void SearchId(){
	SearchStd();
}
int main(){
	Example();
	ShowInput();
    return 0;
}


