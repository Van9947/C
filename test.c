#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void frist_print()
{
	printf("\t\t********************************\n\n"); //欢迎信息
	printf("\t\t\t欢迎进入学生成绩系统\n");
}
void menu()
{
	printf("\n\t\t********************************\n"); //管理菜单
	printf("\t\t==\t1.录入学生成绩\n\t\t+\n");
	printf("\t\t==\t2.显示学生成绩\n\t\t+\n");
	printf("\t\t==\t3.查询学生成绩\n\t\t+\n");
	printf("\t\t==\t4.添加学生成绩\n\t\t+\n");
	printf("\t\t==\t5.修改学生成绩\n\t\t+\n");
	printf("\t\t==\t6.删除学生成绩\n\t\t+\n");
	printf("\t\t==\t7.清空页面\n\t\t+\n");
	printf("\t\t==\t8.退出系统\n");
	printf("\t\t********************************\n");
	printf("please choise 1--8:\t");
	putchar(10);
}
struct MM // 结构体定义变量
{
	char num[20];
	char name[10];
	float pay;
	int many;
}mm;
void scanf_1() //第一次输入信息并保存在文件中
{
	char ch;
	FILE *fp;
	if((fp=fopen("dd.dat","wb+"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	do
	{
		printf("请输入成绩的--编号:\t");
		getchar();
		gets(mm.num);
		printf("姓名:\t");
		gets(mm.name);
		printf("成绩:\t");
		scanf("%f",&mm.pay);
		printf("学号:\t");
		scanf("%d",&mm.many);
		if(fwrite(&mm,sizeof(struct MM),1,fp)!=1)
		{
			printf("file write error\n");
			exit(0);
		}
		printf("是否继续输入y or n ?\t");
		getchar();
		ch=getchar();
	}while(ch=='y'||ch=='Y');
	fclose(fp);
}
void find() //查询成绩的信息
{ int a,b=0;
char ch[20];
FILE *fp;
if((fp=fopen("dd.dat","rb"))==NULL)
{
	printf("cannot open file\n");
	exit(0);
}
printf("请输入要查询的成绩的方式\n\t1.编号 2.姓名:\n\t请选择 1 or 2 \t");
scanf("%d",&a);
if(a==1)
{ getchar();
printf("请输入成绩的编号:\t");
gets(ch);
while(fread(&mm,sizeof(struct MM),1,fp)==1)
if(strcmp(mm.num,ch)==0)
{
	b++;
	printf("编号\t姓名\t价格\t\t学号\n");
	printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
}
if(b==0) printf("对不起！没有找到相关信息：\n");
}
else if(a==2)
{ printf("请输入成绩的姓名:\t");
getchar();
gets(ch);
while(fread(&mm,sizeof(struct MM),1,fp)==1)
if(strcmp(mm.name,ch)==0)
{
	b++;
	printf("编号\t姓名\t价格\t\t学号\n");
	printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
}
if(b==0) printf("input error!\n");
}
fclose(fp);
}
void scanf_2() //第二次输入信息并保存在文件中
{
	char ch;
	FILE *fp;
	if((fp=fopen("dd.dat","ab"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	do
	{
		printf("请输入要添加成绩的--编号:\t");
		getchar();
		gets(mm.num);
		printf("姓名:\t");
		gets(mm.name);
		printf("价格:\t");
		scanf("%f",&mm.pay);
		printf("学号:\t");
		scanf("%d",&mm.many);
		if(fwrite(&mm,sizeof(struct MM),1,fp)!=1)
		{
			printf("file write error\n");
			exit(0);
		}
		printf("是否继续输入y or n ?\t");
		getchar();
		ch=getchar();
	}while(ch=='y'||ch=='Y');
	fclose(fp);
}
void print() //输出文档中的信息
{
	FILE *fp;
	if((fp=fopen("dd.dat","rb"))==NULL)
	{
		printf("cannot open file\n");
		return ;
	}
	printf("编号\t姓名\t价格\t\t学号\n");
	while(fread(&mm,sizeof(struct MM),1,fp)==1)
		printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
	fclose(fp);
}
void change()
{ //修改信息的函数，定义另一个文件，把要修改的信息放到该文件中
	struct XX //然后把其余的信息复制到该文件中；并把该文件从新命名为原来的名
	{ //把原来的文件移除；
		char num[20];
		char name[10];
		float pay;
		int many;
	}xx;
	FILE *fp2;
	int a,b=0,c=0,n=0;
	char ch[20],ck;
	FILE *fp;
	do{
		if((fp=fopen("dd.dat","rb"))==NULL)
		{
			printf("cannot open file\n");
			exit(0);
		}
		if((fp2=fopen("temp.dat","wb"))==NULL)
		{
			printf("cannot open file\n");
			exit(0);
		}
		printf("请输入要修改成绩的编号:\t");
		scanf("%s",ch);
		n++;
		while(fread(&mm,sizeof(struct MM),1,fp)==1)
		{
			if((strcmp(mm.num,ch)==0))
			{
				b++; //b的值如果一直没有改变说明，没有找到相关的信息；
				printf("编号\t姓名\t价格\t\t学号\n");
				printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
				getchar();
				printf("请输入成绩的新编号:\t");
				gets(xx.num);
				printf("请输入成绩的新姓名:\t");
				gets(xx.name);
				printf("请输入成绩的新价格:\t");
				scanf("%f",&xx.pay);
				printf("请输入成绩新学号:\t");
				scanf("%d",&xx.many);
				getchar();
				fwrite(&xx,sizeof(struct XX),1,fp2);
			}
			if(strcmp(mm.num,ch)!=0)
				fwrite(&mm,sizeof(struct MM),1,fp2);
		}
		if(b==0)
		{
			printf("\t没有找到相关信息！\n");
			getchar();
		}
		rewind(fp); //如果要继续修改的话，要把标记返回到文件的开头；
		printf("是否继续修改？enter 'y' or 'n' \t");
		ck=getchar();
		fclose(fp);
		fclose(fp2);
		remove("dd.dat");
		rename("temp.dat","dd.dat");
	}while(ck=='y'||ck=='Y');
	if(b!=0) //如果没有找到相关信息就不能输出
		printf("\t修改成功：\n");
}
void del()
{ //删除函数和修改很相似
	FILE *fp2;
	int a,b=0,c=0,n=0;
	char ch[20],ck;
	FILE *fp;
	do {
		if((fp=fopen("dd.dat","rb"))==NULL)
		{
			printf("cannot open file\n");
			exit(0);
		}
		if((fp2=fopen("temp.dat","wb"))==NULL)
		{
			printf("cannot open file\n");
			exit(0);
		}
		printf("请输入要删除成绩的编号:\t");
		scanf("%s",ch);
		n++;
		while(fread(&mm,sizeof(struct MM),1,fp)==1)
		{
			if((strcmp(mm.num,ch)==0))
			{
				b++; //b的值如果一直没有改变说明，没有找到相关的信息；
				printf("编号\t姓名\t价格\t\t学号\n");
				printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
			}
			else if(strcmp(mm.num,ch)!=0)
				fwrite(&mm,sizeof(struct MM),1,fp2);
		}
		if(b==0)
		{
			printf("\t没有找到相关信息！\n");
			getchar();
		}
		rewind(fp);
		getchar();
		getchar();
		printf("删除成功！");
		getchar(); //如果要继续修改的话，要把标记返回到文件的开头；
		printf("是否继续删除？enter 'y' or 'n' \t");
		ck=getchar();
		fclose(fp);
		fclose(fp2);
		remove("dd.dat");
		rename("temp.dat","dd.dat");
	}while(ck=='y'||ck=='Y');
	if(b!=0) //如果没有找到相关信息就不能输出
		printf("\t保存成功：\n");
}
void myexit()
{
	int a;
	char ch;
	printf("\t是否确定退出？请选择 y or n: ");
	getchar();
	ch=getchar();
	if(ch=='y'||ch=='Y') exit(0);
	else
		menu();
}
int main()
{
	int a;
	frist_print();
	menu();
	while(1)
	{
		scanf("%d",&a);
		if(a==1)
			scanf_1();
		else if(a==2)
			print();
		else if(a==3)
			find();
		else if(a==4)
			scanf_2();
		else if(a==5)
			change();
		else if(a==6)
			del();
		else if(a==7)
			system("cls");
		else if(a==8)
			myexit();
		else printf("输入错误！！！请重新输入：\t");
		printf("\t按任意键继续！\n");
		getch();
		menu();
	}
	getch();
}