/*编程部程序设计作业1：通讯录系统 
  by邹家豪 04170415  2018.1    
  失败品，未完成！！！
  失败品，未完成！！！ 
  失败品，未完成！！！ 
  失败品，未完成！！！ 
  失败品，未完成！！！ 
  失败品，未完成！！！ 
  失败品，未完成！！！ 
  失败品，未完成！！！ ≡ ∧＿∧　 ∧＿∧
                       ≡(＃｀Д′)? ;;;)Д｀）
                       ≡/つ　 /　 ?　?/
  失败品，未完成！！！ 
  失败品，未完成！！！ 
  失败品，未完成！！！ 
  失败品，未完成！！！ 
  失败品，未完成！！！ 
   

　嗷！ 　 ＼ヽ/／
　嗷！　　 ∧_ ∧
　嗷！　　('Д';):.
　　　 ,ｒ'⌒と.jミヽ
　　 ノ　,.ィ'　｀ヽ/
　／　　　　　　i! /
   
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
//主菜单 
void ShowInput(){
	cout<<endl; 
	cout<<"—————————————————"<<endl;
	cout<<setw(10)<<"通讯录系统 Address Book  Bate1.0" <<endl;
	cout<<endl; 
	cout<<setw(20)<<"0.浏览"<<endl;
	cout<<setw(20)<<"1.查询"<<endl;
	cout<<setw(20)<<"2.添加"<<endl;
	cout<<setw(20)<<"3.删除"<<endl;
	cout<<setw(20)<<"4.导出"<<endl;
	cout<<setw(20)<<"5.退出"<<endl; 
	cout<<endl;
	cout<<"—————————————————"<<endl;
    cout<<"Input number：" ; 
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
//副菜单 
void ShowInputAgian(){
	cout<<endl; 
	cout<<"—————————————————"<<endl;
	cout<<setw(10)<<"通讯录系统 Address Book  Bate1.0" <<endl;
	cout<<endl; 
	cout<<setw(20)<<"0.返回主菜单"<<endl;
	cout<<setw(20)<<"1.退出程序"<<endl;
	cout<<endl;
	cout<<"—————————————————"<<endl;
    cout<<"Input number：" ; 
	int num;
	cin>>num;
	switch(num){
		case 0:ShowInput();
		case 1:Exit();
	}
}
//添加模块 
void Add(){
	Student newStd;
	string name;
	cout<<"—————————————————"<<endl;
	cout<<"请输入新信息： "<<endl;
	newStd.setId();
	newStd.setName();
	newStd.setAge();
	newStd.setSex();
	newStd.setPhone();	
	cout<<"—————————————————"<<endl;
	cout<<endl;
	ofstream add("D:\\data.txt",ios::app);
	if(!add){
        cout << "不好意思亲(＞﹏＜) 出现Error 暂时无法完成任务\n";
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
    cout<<"恭喜亲?(′ε｀) 添加成功"<<endl;
    count++;
    return ShowInputAgian();
}
}
//导出模块 
void Example(){
	ofstream ex("D:\\data.txt",ios::app);
	ex<<"Example"<<endl; 
	ex<<"0"<<endl;
    ex<<"Id:04170415"<<endl;
    ex<<"Name:邹家豪"<<endl;
	ex<<"Age:18"<<endl;
	ex<<"Sex:男"<<endl;
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
    cout<<"—————————————————"<<endl;
    cout<<endl;
	cout<<"已成功导出，位于D:\\通讯录导出.txt "<<endl;  
    cout<<endl;
	cout<<"—————————————————"<<endl;
    infile.open("D:\\data.txt", ios::in);
    outfile0.open("D:\\通讯录导出.txt" ,ios::app);
    outfile1.open("D:\\通讯录导出.txt" ,ios::app);
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

//删除模块 
void Delete(){
    cout<<"—————————————————"<<endl;
    cout<<endl;
	cout<<"抱歉亲╮(╯▽╰)╭此功能暂未开放"<<endl;
	cout<<endl;
	cout<<"—————————————————"<<endl;
    ShowInputAgian();
}
//浏览模块 
void Read(){
	cout<<"—————————————————"<<endl;
    fstream read;
	read.open("D:\\data.txt",ios::in);  
    cout<<endl;
    char s[256];
    while(!read.eof()){
    	read.getline(s,256);
    	cout<<s<<endl;
	}
    cout<<"—————————————————"<<endl;
    read.close();
    ShowInputAgian();
}
//退出模块 
void Exit(){
	cout<<endl<<"通讯录数据已重置"<<endl;
    fclose(fopen("D:\\data.txt", "w"));
	cout<<"Bye~~期待下一次与您相见(*^__^*) 嘻嘻……"<<endl;
	exit(1); 
}
//查找模块 
void Search(){
	cout<<endl; 
	cout<<"—————————————————"<<endl;
	cout<<setw(10)<<"通讯录系统 Address Book  Bate1.0" <<endl;
	cout<<endl;  
	cout<<setw(20)<<"0.通过姓名查询"<<endl;
	cout<<setw(20)<<"1.通过学号查询"<<endl;
	cout<<setw(20)<<"2.返回主菜单"<<endl;
	cout<<setw(20)<<"3.退出程序"<<endl;
	cout<<endl;
	cout<<"—————————————————"<<endl;
    cout<<"Input number：" ; 
	int num;
	cin>>num;
	switch(num){
		case 0:SearchStd();
		case 1:SearchId();
		case 2:ShowInput();
		case 3:Exit(); 
	}
}
//查找模块 by 姓名 
void SearchStd(){
	int i;
	string tmp;
	fstream seekStd;
	seekStd.open("D:\\data.txt",ios::in);  
    cout<<"—————————————————"<<endl;
    cout<<endl;
    cout<<"╮(╯▽╰)╭暂无法支持此方法查询"<<endl;
    cout<<"您可以通过序号查询"<<endl;
	cout<<"请输入数字（从1开始）："<<endl;
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
    cout<<"—————————————————"<<endl;
    seekStd.close();
}
//查找模块 by学号 
void SearchId(){
	SearchStd();
}
int main(){
	Example();
	ShowInput();
    return 0;
}


