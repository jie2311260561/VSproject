#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define N 100

struct employee
{
	int num;
	char name[10];
	char sex;  
	int age;
	char doc[30];
	int wage;
	char days[30];
	long int tel;
}em[100];        /*定义一个结构体*/

void menu();
void input();
void save(int);
void display();
void del();
void add();
void search();
void search_num();
void search_doc();
void search_tel();
void modify();  /*定义各函数*/

void menu()   /*菜单函数*/
{
    printf("\n");
	printf("        ******************欢迎进入病人信息管理系统****************\n");
	printf("           1.录入病人信息");
	printf("           2.浏览病人信息\n");
	printf("           3.查询病人信息");
	printf("           4.删除病人信息\n");
	printf("           5.添加病人信息");
	printf("           6.修改病人信息\n");
	printf("           7.退出\n");
	printf("        ********************谢谢使用******************\n");
	printf("\n");
	printf("\n"); 

}

int main()
{   
	menu();  /*调用菜单函数*/
	int n,flag;
	char a;
	do
	{
		printf("请选择你需要操作的步骤(1--7):\n");
		scanf("%d",&n);
		if(n>=1&&n<=7)
		{
			flag=1;
			break;
		}
		else
		{
			flag=0;
			printf("您输入有误，请重新选择!");
		}
	}
    while(flag==0);
    while(flag==1)
	{	
		switch(n)
		{
			case 1:printf("              ◆◆◆输入病人信息◆◆◆\n");printf("\n");input();break;
			case 2:printf("              ◆◆◆浏览病人信息◆◆◆\n");printf("\n");display();break;
			case 3:printf("              ◆◆◆按病人床号查询病人信息◆◆◆\n");printf("\n");search();break; 
			case 4:printf("              ◆◆◆删除病人信息◆◆◆\n");printf("\n");del();break;
			case 5:printf("              ◆◆◆添加病人信息◆◆◆\n");printf("\n");add();break;
			case 6:printf("              ◆◆◆修改病人信息◆◆◆\n");printf("\n");modify();break;
			case 7:exit(0);break;
			default :break;
		}
	getchar();
	printf("\n");
	printf("是否继续进行(y or n):\n");
	scanf("%c",&a);
	if(a=='y')
	{
		flag=1;
		system("cls");  /*清屏*/
		menu(); /*调用菜单函数*/
		printf("请再次选择你需要操作的步骤(1--6):\n");
		scanf("%d",&n);
		printf("\n");
	}
	else 
		exit(0);
}
}
 
void input()   /*录入函数*/
{
	int i,m;
	printf("请输入需要创建信息的病人人数(1--100):\n");
	scanf("%d",&m);
	for (i=0;i<m;i++)
	{
		printf("病人床号： ");
		srand((int)time(0));
		em[i].num=rand()%10000+20000000;
		if(em[i].num!=em[i-1].num)
		printf("%8d ",em[i].num);
		printf("\n");
		printf("请输入姓名:  ");
		scanf("%s",em[i].name);
		getchar();
		printf("请输入性别(f--女  m--男):  ");
		scanf("%c",&em[i].sex);
		printf("请输入年龄:  ");
		scanf("%d",&em[i].age);
		printf("请输入主治医生:  ");
		scanf("%s",em[i].doc);
		printf("请输入护理级别:  ");
		scanf("%d",&em[i].wage);
		printf("请输入入住日期:  ");
		scanf("%s",em[i].days);
		printf("请输入电话:  ");
		scanf("%d",&em[i].tel); 
		printf("\n");
	}
	printf("\n创建完毕!\n");
	save(m);
}
void save(int m)  /*保存文件函数*/
{
	int i;
	FILE*fp;
	if ((fp=fopen("employee.txt","w"))==NULL)  /*创建文件并判断是否能打开*/
	{
		printf ("cannot open file\n");
		exit(0);
	}
	for (i=0;i<m;i++) /*将内存中病人的信息输出到磁盘文件中去*/
	if (fwrite(&em[i],sizeof(struct employee),1,fp)!=1)
		printf("file write error\n");
	fclose(fp);
}
int load() /*导入函数*/
{
	FILE*fp;
	int i=0;
	if((fp=fopen("employee.txt","r"))==NULL)
	{
		printf ("cannot open file\n");
		exit(0);
	}
	else 
	{
		do 
		{
			fread(&em[i],sizeof(struct employee),1,fp);
			i++;
		}
	while(feof(fp)==0);
	}
	fclose(fp);
	return(i-1);
}
void display()  /*浏览函数*/
{
	int i;
	int m=load();
	printf("\n  病人床号\t姓名\t性别\t年龄\t主治医生\t护理级别\t入住日期\t电话   \n");
	for(i=0;i<m;i++) /*m为输入部分的病人人数*/
		printf("\n  %d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n",em[i].num,em[i].name,em[i].sex,em[i].age,em[i].doc,em[i].wage,em[i].days,em[i].tel);  
}
void del()   /*删除函数*/
{
	int m=load();
	int i,j,n,t,flag;
	char name[20];
	printf("\n 原来的病人信息:\n");
	display();   /* 调用浏览函数*/
	printf("\n");
	printf("请输入要删除的病人的姓名:\n");
	scanf("%s",name);
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(em[i].name,name)==0)
		{
			printf("\n已找到此人，原始记录为：\n");
			printf("\n病人床号\t姓名\t性别\t年龄\t主治医生\t护理级别\t入住日期\t电话   \n");
			printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n",em[i].num,em[i].name,em[i].sex,em[i].age,em[i].doc,em[i].wage,em[i].days,em[i].tel);  
			printf("\n确实要删除此人信息请按1,不删除请按0\n");
			scanf("%d",&n);
           	if(n==1)   /*如果删除，则其他的信息都往上移一行*/
			{
				for(j=i;j<m-1;j++)
				{
					strcpy(em[j].name,em[j+1].name);
					em[j].num=em[j+1].num;
					em[j].sex=em[j+1].sex;
					em[j].age=em[j+1].age;
					strcpy(em[j].doc,em[j+1].doc);
					em[j].wage=em[j+1].wage;  
					strcpy(em[j].days,em[j+1].days);
					em[j].tel=em[j+1].tel;
				}
				flag=0;
			}
		}
	}
	if(!flag)
	m=m-1;
	else
	printf("\n对不起，查无此人!\n");
	printf("\n 浏览删除后的所有病人信息:\n");
	save(m);     /*调用保存函数*/
	display();  /*调用浏览函数*/
	printf("\n继续删除请按1，不再删除请按0\n");
	scanf("%d",&t);
	switch(t)
	{
	    case 1:del();break;
	    case 0:break;
	    default :break;
	}
}
void add()/*添加函数*/
{
	FILE*fp;
	int n;
    int count=0;
    int i;
    int m=load();
    printf("\n 原来的病人信息:\n");
    display();   /* 调用浏览函数*/
    printf("\n");
    fp=fopen("employee.txt","a");
    printf("请输入想增加的病人数:\n");
	scanf("%d",&n);
	for (i=m;i<(m+n);i++)
	{
		printf("\n 请输入新增加病人的信息:\n");
		printf("请输入病人床号:  ");
		srand((int)time(0));
		em[i].num=rand()%10000+20000000;
		if(em[i].num!=em[i-1].num)
		printf("%8d ",em[i].num);
		printf("\n");
		printf("请输入姓名:  ");
		scanf("%s",em[i].name);
		getchar();
		printf("请输入性别(f--女  m--男):  ");
		scanf("%c",&em[i].sex);
		printf("请输入年龄:  ");
		scanf("%d",&em[i].age);
		printf("请输入主治医生:  ");
		scanf("%s",em[i].doc);
		printf("请输入护理级别:  ");
		scanf("%d",&em[i].wage);
		printf("请输入入住日期:  ");
		scanf("%s",em[i].days);
		printf("请输入电话:  ");
		scanf("%d",&em[i].tel);
		printf("\n");
		count=count+1;
		printf("已增加的人数:\n");
		printf("%d\n",count);
	}
    printf("\n添加完毕!\n"); 
	m=m+count;
	printf("\n浏览增加后的所有病人信息:\n");
	printf("\n");
	save(m);
    display();
	fclose(fp);
}
void search()/*查询函数*/
{
    int t,flag;
	do
	{
		printf("\n按病人床号查询请按1 ; 按主治医生查询请按2 ; 按电话号码查询请按3,进入主函数按4\n");
		scanf("%d",&t);
		if(t>=1&&t<=4)
		{
			flag=1;
			break;
		}
		else
		{
			flag=0;
			printf("您输入有误，请重新选择!");
		}
	}
	    while(flag==0);
	    while(flag==1)
		{
			switch(t)
			{ 
				case 1:printf("按病人床号查询\n");search_num();break;
				case 2:printf("按主治医生查询\n");search_doc();break;
				case 3:printf("按电话号码查询\n");search_tel();break;
				case 4:main();break;
				default:break;
			}
		}
}
void search_num()
{
	int num;
	int i,t;
	int m=load();
	printf("请输入要查找的病人床号(20001111---20009999):\n");
	scanf("%d",&num);
	for(i=0;i<m;i++)
		if(num==em[i].num)
		{  
			printf("\n已找到此人，其记录为：\n");
			printf("\n病人床号\t\t姓名\t性别\t年龄\t主治医生\t护理级别\t入住日期\t电话   \n");
			printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n",em[i].num,em[i].name,em[i].sex,em[i].age,em[i].doc,em[i].wage,em[i].days,em[i].tel);  
			break;
		}
		if(i==m)  
			printf("\n查询结束\n");
			printf("\n");
		printf("返回查询函数请按1,继续查询病人床号请按2\n");
		scanf("%d",&t);
		switch(t)
		{ 
			case 1:search();break;
			case 2: break;
			default:break;
		}
}
void search_doc()
{
	char doc[30];
	int i,t;
	int m=load();
	printf("请输入要查找的主治医生:\n");
	scanf("%s",doc);
	for(i=0;i<m;i++)
	if(strcmp(em[i].doc,doc)==0)
	{
		printf("\n已找到，其记录为：\n");
		printf("\n病人床号\t\t姓名\t性别\t年龄\t主治医生\t护理级别\t入住日期\t电话   \n");
		printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n",em[i].num,em[i].name,em[i].sex,em[i].age,em[i].doc,em[i].wage,em[i].days,em[i].tel);  
	}
	if(i==m) 
		printf("\n查询结束\n");
		printf("\n");
	printf("返回查询函数请按1,继续查询主治医生请按2\n");
	scanf("%d",&t);
	switch(t)
	{ 
		case 1:search();break;
		case 2:break;
		default :break;
	}
}
void search_tel()
{
	long int tel;
	int i, t;
	int m=load();
	printf("请输入要查找的电话号码:\n");
	scanf("%ld",&tel);
	for(i=0;i<m;i++)
		if(tel==em[i].tel)
		{  
			printf("\n已找到此人，其记录为：\n");
			printf("\n病人床号\t\t姓名\t性别\t年龄\t主治医生\t护理级别\t入住日期\t电话   \n");
			printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n",em[i].num,em[i].name,em[i].sex,em[i].age,em[i].doc,em[i].wage,em[i].days,em[i].tel);  
			break;
		}
		if(i==m)  
			printf("\n查询结束\n");
			printf("\n");
		printf("返回查询函数请按1,继续查询电话号码请按2\n");
		scanf("%d",&t);
		switch(t)
		{ 
			case 1:search();break;
			case 2:break;
			default :break;
		}
}
void modify() /*修改函数*/
{
	int num;
	char name[10];
	char sex;  
	int age;
	char doc[30];
	int wage;
	char days[30];
	long int tel;
	int b,c,i,n,t,flag; 
	int m=load(); /*导入文件内的信息*/
	printf("\n 原来的病人信息:\n");
	display();   /* 调用浏览函数*/
	printf("\n");
    printf("请输入要修改的病人的姓名:\n");
	scanf("%s",name);
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(em[i].name,name)==0)
		{
			printf("\n已找到此人，原始记录为：\n");
	        printf("\n病人床号\t\t姓名\t性别\t年龄\t主治医生\t护理级别\t入住日期\t电话   \n");
			printf("\n%d\t%s\t%c\t%d\t%s\t%d\t%s\t%ld\n",em[i].num,em[i].name,em[i].sex,em[i].age,em[i].doc,em[i].wage,em[i].days,em[i].tel);  
	        printf("\n确实要修改此人信息请按1 ; 不修改请按0\n");
			scanf("%d",&n);
	        if(n==1)
			{
				printf("\n需要进行修改的选项\n 1.病人床号 2.姓名 3.性别 4.年龄 5.主治医生 6.护理级别 7.入住日期 8.电话\n");  
				printf("请输入你想修改的那一项序号:\n");  
				scanf("%d",&c);  
				if(c>8||c<1)  
					printf("\n选择错误，请重新选择!\n");  
			}
			flag=0;	
		} 
	}
    if(flag==1)
		printf("\n查询结束\n");  
    do  
	{
		switch(c)      /*因为当找到第i个病人时,for语句后i自加了1,所以下面的应该把改后的信息赋值给第i-1个人*/
		{  
			case 1:printf("病人床号改为: "); scanf("%d",&num);
					em[i-1].num=num; break;
			case 2:printf("姓名改为: "); scanf("%s",name);
				strcpy(em[i-1].name,name); break; 
			case 3:printf("性别改为: "); getchar();scanf("%c",&sex);
			    	em[i-1].sex=sex; break;
			case 4:printf("年龄改为: "); scanf("%d",&age);
					em[i-1].age=age; break;
			case 5:printf("主治医生改为: "); scanf("%s",doc);
					strcpy(em[i-1].doc,doc); break;   
			case 6:printf("护理级别改为: "); scanf("%d",wage); break; 
			case 7:printf("入住日期改为: "); scanf("%s",days);
					strcpy(em[i-1].days,days); break;  
			case 8:printf("电话改为: "); scanf("%ld",&tel); em[i-1].tel=tel; break;  
		} 

        printf("\n");
		printf("\n是否确定所修改的信息 \n 是 请按1 ; 不,重新修改 请按2:  \n"); 
        scanf("%d",&b);
	}  
	while(b==2);
		printf("\n浏览修改后的所有病人信息:\n");
		printf("\n");
	save(m);
	display();
	printf("\n继续修改请按1，不再修改请按0\n");
	scanf("%d",&t);
	switch(t)
	{
	    case 1:modify();break;
	    case 0:break;
	    default :break;
	}
}

