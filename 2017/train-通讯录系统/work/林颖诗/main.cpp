#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 
#include"stdio.h"
struct record 
{ 
char id[10]; 
char name[20]; 
char phone[20]; 
char adress[40]; 
char postcode[10]; 
char e_mail[30]; 
}student[500]; 
int num=0;
FILE *fp; 
void mainmenu();
void newrecord(); 
void searchmenu();
void searchbyid();
void searchbyname();
void searchbyphone();
void deletemenu();
void deleteall();
void deleteone();
void showall();
void readfromfile();
void writetofile();
void deletebyid();
void deletebyname();
void listbyid();
void listbyname();
void listmenu();
int main() 
{ 
readfromfile(); 
while (1) 
{ 
mainmenu(); 
} 
} 
void readfromfile() 
{ 
if((fp=fopen("student.bin","rb"))==NULL) 
{ 
printf("\n\t\tͨѶ¼�ļ�������"); 
if ((fp=fopen("student.bin","wb"))==NULL) 
{ 
printf("\n\t\t����ʧ��"); 
exit(0); 
} 
else 
{ 
printf("\n\t\tͨѶ¼�ļ��ѽ���"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
exit(0); 
} 
fseek(fp,0,2); 
if (ftell(fp)>0)
{ 
rewind(fp);
for (num=0;!feof(fp) && fread(&student[num],sizeof(struct record),1,fp);num++); 
printf("\n\t\t�ļ�����ɹ�"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
printf("\n\t\t�ļ�����ɹ�"); 
printf("\n\t\tͨѶ¼�ļ������κμ�¼"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
void mainmenu()
{ 
char choic; 
system("cls"); 
printf("\n\t\t���˵�"); 
printf("\n\t\t 1-�����¼ 2-��ѯ�˵� "); 
printf("\n\t\t 3-ɾ���˵� 4-��¼���� "); 
printf("\n\t\t 5-�����˳� 6-�������˳�"); 
printf("\n\t\t                        "); 
printf("\n\t\t��ѡ��"); 
choic=getch(); 
switch (choic) 
{ 
case '1':newrecord();break; 
case '2':searchmenu();break; 
case '3':deletemenu();break; 
case '4':listmenu();break; 
case '5':writetofile();break; 
case '6':exit(0); 
default:mainmenu(); 
} 
} 
void searchmenu()
{ 
char choic; 
system("cls"); 
printf("\n\t\t ��ѯ�˵� "); 
printf("\n\t\t 1-��ʾ���� 2-��ѧ�Ų�ѯ "); 
printf("\n\t\t 3-��������ѯ4-���绰��ѯ "); 
printf("\n\t\t* 5-�������˵� ************"); 
printf("\n\t\t      "); 
printf("\n\t\t��ѡ��"); 
choic=getch(); 
switch (choic) 
{ 
case '1':showall();break; 
case '2':searchbyid();break; 
case '3':searchbyname();break; 
case '4':searchbyphone();break; 
case '5':mainmenu();break; 
} 
} 
void deletemenu()
{ 
char choic; 
if(num==0) 
{ 
printf("\n\t\t�Բ����ļ������κμ�¼"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
system("cls"); 
printf("\n\t\t ɾ���˵� "); 
printf("\n\t\t 1-ɾ������ 2-ɾ������ "); 
printf("\n\t\t 3-�������˵� "); 
printf("\n\t\t     "); 
printf("\n\t\t��ѡ��"); 
choic=getch(); 
switch (choic) 
{ 
case '1':deleteall();break; 
case '2':deleteone();break; 
case '3':mainmenu();break; 
default:mainmenu();break; 
} 
} 
void deleteall()
{ 
printf("\n\t\tȷ��ɾ��?(y/n)"); 
if (getch()=='y') 
{ 
fclose(fp); 
if ((fp=fopen("student.bin","wb"))==NULL) 
{ 
printf("\n\t\t���ܴ��ļ���ɾ��ʧ��"); 
readfromfile(); 
} 
num=0; 
printf("\n\t\t��¼��ɾ������������������˵�"); 
getch(); 
return; 
} 
else 
return; 
} 
void deletebyname()
{ 
int a=0; 
int findmark=0; 
int j; 
int deletemark=0; 
int i; 
char name[20]; 
printf("\n\t\t������Ҫɾ��ѧ��������"); 
scanf("%s",name); 
for (i=a;i<num;i++) 
{ 
if (strcmp(student[i].name,name)==NULL) 
{ 
printf("\n\t\t��������Ҫɾ����ѧ����¼��"); 
findmark++; 
printf("\n\t\t________________________________"); 
printf("\n\t\tѧ�ţ� %s",student[i].id); 
printf("\n\t\t������ %s",student[i].name); 
printf("\n\t\t�绰�� %s",student[i].phone); 
printf("\n\t\t��ַ�� %s",student[i].adress); 
printf("\n\t\te-mail��%s",student[i].e_mail); 
printf("\n\t\t________________________________"); 
printf("\n\t\t�Ƿ�ɾ��?(y/n)"); 
if (getch()=='y') 
{ 
for (j=i;j<num-1;j++) 
student[j]=student[j+1]; 
num--; 
deletemark++; 
printf("\n\t\tɾ���ɹ�"); 
if((i+1)<num) 
{ 
printf("\n\t\t�Ƿ����ɾ����ͬ������ͬѧ��Ϣ?(y/n)"); 
if (getch()=='y') 
{ 
a=i; 
continue; 
} 
} 
printf("\n\t\t�Ƿ����ɾ��?(y/n)"); 
if (getch()=='y') 
deletebyname(); 
return; 
} 
if((i+1)<num) 
{ 
printf("\n\t\t�Ƿ����ɾ����ͬ������ͬѧ��Ϣ?(y/n)"); 
if (getch()=='y') 
{ 
a=i; 
continue; 
} 
} 
} 
else 
continue; 
} 
if ((deletemark==0)&&(findmark==0)) 
{ 
printf("\n\t\tû�и�ͬѧ�ļ�¼"); 
printf("\n\t\t�Ƿ����ɾ��?(y/n)"); 
if (getch()=='y') 
deletebyid(); 
return; 
return; 
} 
else if (findmark!=0) 
{ 
printf("\n\t\tû��������Ϣ"); 
printf("\n\t\tû�и�ͬѧ�ļ�¼"); 
printf("\n\t\t�Ƿ����ɾ��?(y/n)"); 
if (getch()=='y') 
deletebyid(); 
return; 
return; 
} 
} 
void deletebyid()
{ 
int i,j; 
int deletemark=0; 
char id[20]; 
printf("\n\t\t������Ҫɾ��ѧ��ѧ�ţ�"); 
scanf("%s",id); 
if(num==0) 
{ 
printf("\n\t\t�Բ����ļ������κμ�¼"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
for (i=0;i<num;i++) 
{ 
if (strcmp(student[i].id,id)==NULL) 
{ 
printf("\n\t\t��������Ҫɾ����ѧ����¼��"); 
printf("\n\t\tѧ�ţ� %s",student[i].id); 
printf("\n\t\t������ %s",student[i].name); 
printf("\n\t\t�绰�� %s",student[i].phone); 
printf("\n\t\t��ַ�� %s",student[i].adress); 
printf("\n\t\te-mail��%s",student[i].e_mail); 
printf("\n\t\t�Ƿ�ɾ��?(y/n)"); 
if (getch()=='y') 
{ 
for (j=i;j<num-1;j++) 
student[j]=student[j+1]; 
num--; 
deletemark++; 
printf("\n\t\tɾ���ɹ�"); 
printf("\n\t\t�Ƿ����ɾ��?(y/n)"); 
if (getch()=='y') 
deletebyid(); 
return; 
} 
else 
return; 
} 
continue; 
} 
if (deletemark==0) 
{ 
printf("\n\t\tû�и�ͬѧ�ļ�¼"); 
printf("\n\t\t�Ƿ����ɾ��?(y/n)"); 
if (getch()=='y') 
deletebyid(); 
return; 
} 
} 
void newrecord() 
{ 
printf("\n\t\t ������ѧ����Ϣ \n"); 
printf("\n\t\t����ѧ��:"); 
scanf("%s",&student[num].id); 
printf("\n\t\t��������:"); 
scanf("%s",&student[num].name); 
printf("\n\t\t����绰����:"); 
scanf("%s",&student[num].phone); 
printf("\n\t\t�����ַ:"); 
scanf("%s",&student[num].adress); 
printf("\n\t\t�����ʱ�:"); 
scanf("%s",&student[num].postcode); 
printf("\n\t\t����e-mail:"); 
scanf("%s",&student[num].e_mail); 
num++; 
printf("\n\t\t�Ƿ�������?(Y/N):"); 
if (getch()=='y') 
newrecord(); 
return; 
} 
void showall() 
{ 
int i; 
system("cls"); 
if(num!=0) 
{ 
printf("\n\t\t ����ΪͨѶ¼������Ϣ"); 
for (i=0;i<num;i++) 
{ 
printf("\n\t\tѧ�ţ� %s",student[i].id); 
printf("\n\t\t������ %s",student[i].name); 
printf("\n\t\t�绰�� %s",student[i].phone); 
printf("\n\t\t��ַ�� %s",student[i].adress); 
printf("\n\t\t�ʱࣺ %s",student[i].postcode); 
printf("\n\t\te-mail��%s",student[i].e_mail); 
printf("\t\t"); 
if (i+1<num) 
{ 
printf("\n\t\t__________________________"); 
system("pause"); 
} 
} 
printf("\n\t\t        "); 
} 
else 
printf("\n\t\tͨѶ¼�����κμ�¼"); 
printf("\n\t\t��������������˵���"); 
getch(); 
return; 
} 

void searchbyphone() 
{ 
int mark=0; 
int i; 
int a=0; 
printf("\n\t\t ���绰���� "); 
char phone[10]; 
printf("\n\t\t������ѧ��:"); 
scanf("%s",phone); 
for(i=0;i<num;i++) 
{ 
if (strcmp(student[i].phone,phone)==0) 
{ 
printf("\n\t\t �����������ҵ�ѧ����Ϣ "); 
printf("\n\t\tѧ�ţ� %s",student[i].id); 
printf("\n\t\t������ %s",student[i].name); 
printf("\n\t\t�绰�� %s",student[i].phone); 
printf("\n\t\t��ַ�� %s",student[i].adress); 
printf("\n\t\te-mail��%s",student[i].e_mail); 
printf("\n\t\t        "); 
printf("\n\t\t��������������˵���"); 
mark++; 
getch(); 
return; 
} 
} 
if (mark==0) 
{ 
printf("\n\t\tû�и�ѧ������Ϣ"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
} 
void searchbyname()
{ 
int mark=0; 
int i; 
int a=0; 
printf("\n\t\t ���������� "); 
char name[20]; 
printf("\n\t\t����������:"); 
scanf("%s",name); 
for(i=a;i<num;i++) 
{ 
if (strcmp(student[i].name,name)==0) 
{ 
printf("\n\t\t �����������ҵ�ѧ����Ϣ "); 
printf("\n\t\tѧ�ţ� %s",student[i].id); 
printf("\n\t\t������ %s",student[i].name); 
printf("\n\t\t�绰�� %s",student[i].phone); 
printf("\n\t\t��ַ�� %s",student[i].adress); 
printf("\n\t\te-mail��%s",student[i].e_mail); 
printf("\n\t\t        "); 
mark++; 
if ((i+1)<num) 
{ 
printf("\n\t\t�Ƿ����������ͬ���ֵ�ѧ����Ϣ��(y/n)"); 
if (getch()=='y') 
{ 
a=i; 
continue; 
} 
else 
return; 
} 
else 
{ 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
} 
} 
if(mark!=0) 
{ 
printf("\n\t\tû����ͬ������ѧ����¼"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
else 
{ 
printf("\n\t\tû����ͬ������ѧ����¼"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
} 
void searchbyid()
{ 
int mark=0; 
int i; 
int a=0; 
printf("\n\t\t  ��ѧ�Ų��� \n"); 
char id[10]; 
printf("\n\t\t������ѧ��:"); 
scanf("%s",id); 
for(i=0;i<num;i++) 
{ 
if (strcmp(student[i].id,id)==0) 
{ 
printf("\n\t\t �����������ҵ�ѧ����Ϣ "); 
printf("\n\t\tѧ�ţ� %s",student[i].id); 
printf("\n\t\t������ %s",student[i].name); 
printf("\n\t\t�绰�� %s",student[i].phone); 
printf("\n\t\t��ַ�� %s",student[i].adress); 
printf("\n\t\te-mail��%s",student[i].e_mail); 
printf("\n\t\t        "); 
printf("\n\t\t��������������˵���"); 
mark++; 
getch(); 
return; 
} 
} 
if (mark==0) 
{ 
printf("\n\t\tû�и�ѧ������Ϣ"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
} 
void writetofile()
{ 
int i; 
if ((fp=fopen("student.bin","wb"))==NULL) 
{ 
printf("\n\t\t�ļ���ʧ��"); 
} 
for (i=0;i<num;i++) 
{ 
if (fwrite(&student[i],sizeof(struct record),1,fp)!=1) 
{ 
printf("\n\t\tд���ļ�����!\n"); 
} 
} 
fclose(fp); 
printf("\n\t\tͨѶ¼�ļ��ѱ���"); 
printf("\n\t\t��������˳�����\n\t\t"); 
exit(0); 
} 
void deleteone()
{ 
char choic; 
printf("\n\t\t1-��ѧ��ɾ�� 2-������ɾ��"); 
printf("\n\t\t��ѡ��"); 
choic=getch(); 
switch (choic) 
{ 
case '1':deletebyid();break; 
case '2':deletebyname();break; 
} 
} 
void listbyname() 
{ 
int i,j; 
struct record tmp; 
for (i=1;i<num;i++) 
{ 
if(strcmp(student[i].name,student[i-1].name)<0) 
{ 
tmp=student[i]; 
j=i-1; 
do 
{ 
student[j+1]=student[j]; 
j--; 
}while ((strcmp(tmp.name,student[j].name)<0&&j>=0)); 
student[j+1]=tmp; 
} 
} 
printf("\n\t\t����ɹ�,�Ƿ���ʾ?(y/n)"); 
if (getch()=='y') 
showall(); 
return; 
} 
void listbyid() 
{ 
int i,j; 
struct record tmp; 
for (i=1;i<num;i++) 
{ 
if(strcmp(student[i].id,student[i-1].id)<0) 
{ 
tmp=student[i]; 
j=i-1; 
do 
{ 
student[j+1]=student[j]; 
j--; 
}while ((strcmp(tmp.id,student[j].id)<0)&&j>=0); 
student[j+1]=tmp; 
} 
} 
printf("\n\t\t����ɹ�,�Ƿ���ʾ?(y/n)"); 
if (getch()=='y') 
showall(); 
return; 
} 
void listmenu()
{ 
char choic; 
if(num==0) 
{ 
printf("\n\t\t�Բ����ļ������κμ�¼"); 
printf("\n\t\t��������������˵�"); 
getch(); 
return; 
} 
system("cls"); 
printf("\n\t\t ����˵� "); 
printf("\n\t\t 1-��ѧ������ 2-���������� "); 
printf("\n\t\t 3-�������˵� "); 
printf("\n\t\t        "); 
printf("\n\t\t��ѡ��"); 
choic=getch(); 
switch(choic) 
{ 
case '1':listbyid();break; 
case '2':listbyname();break; 
case '3':mainmenu();break; 
default:mainmenu();break; 
} 


FILE*fp1;
FILE*fp2;
char text[1024];
fp1=fopen("d:\\a.txt","r");
fp2=fopen("d:\\b.txt","w");
while(fgets(text,1024,fp1)!=NULL)
{
	puts(text);
	fputs(text,fp2);
	fclose(fp1);
	fclose(fp2);
}
}
