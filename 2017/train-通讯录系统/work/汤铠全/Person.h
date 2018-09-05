
class Person{
	protected:
		string StuId;
		char Name[20];
		char Sex[10];
		string Age;
		string Tel;
		Person *next;
	public:
	    Person(string ID,char *Name,char *Sex,string Age,string Tel)
		{
	    	 strcpy(this->Name,Name);
             strcpy(this->Sex,Sex);
             this->Tel=Tel;
             this->StuId=ID;
             this->Age=Age;
		}
		friend class Manage;
};

class Manage{
	public:
		Manage()
		{
			person=0;
			Load();
		}
		~Manage()
		{
			Person *p;
			p=person;
			while(p)
			{
				p=p->next;
				delete person;
				person=p;
			}
			person=0;
		}
	    void Find(string ID);
		void Find(char Name[20]);
	    void Add();
	    void Delete();
	    void Query();
	    void Load();
	    void Look();
	    void DesTory();
	    void Exit();
	    void Output(Person *p)
	    {
	    	cout<<"\t\tѧ��: "<<p->StuId<<endl;
			cout<<"\t\t����: "<<p->Name<<endl;
			cout<<"\t\t�Ա�: "<<p->Sex<<endl;
			cout<<"\t\t����: "<<p->Age<<endl;  
            cout<<"\t\t�ֻ���: "<<p->Tel<<endl;
            cout<<endl; 
		}
	private:
	    Person *person;
};

