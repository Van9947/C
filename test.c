#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void frist_print()
{
	printf("\t\t********************************\n\n"); //��ӭ��Ϣ
	printf("\t\t\t��ӭ����ѧ���ɼ�ϵͳ\n");
}
void menu()
{
	printf("\n\t\t********************************\n"); //�����˵�
	printf("\t\t==\t1.¼��ѧ���ɼ�\n\t\t+\n");
	printf("\t\t==\t2.��ʾѧ���ɼ�\n\t\t+\n");
	printf("\t\t==\t3.��ѯѧ���ɼ�\n\t\t+\n");
	printf("\t\t==\t4.����ѧ���ɼ�\n\t\t+\n");
	printf("\t\t==\t5.�޸�ѧ���ɼ�\n\t\t+\n");
	printf("\t\t==\t6.ɾ��ѧ���ɼ�\n\t\t+\n");
	printf("\t\t==\t7.���ҳ��\n\t\t+\n");
	printf("\t\t==\t8.�˳�ϵͳ\n");
	printf("\t\t********************************\n");
	printf("please choise 1--8:\t");
	putchar(10);
}
struct MM // �ṹ�嶨�����
{
	char num[20];
	char name[10];
	float pay;
	int many;
}mm;
void scanf_1() //��һ��������Ϣ���������ļ���
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
		printf("������ɼ���--���:\t");
		getchar();
		gets(mm.num);
		printf("����:\t");
		gets(mm.name);
		printf("�ɼ�:\t");
		scanf("%f",&mm.pay);
		printf("ѧ��:\t");
		scanf("%d",&mm.many);
		if(fwrite(&mm,sizeof(struct MM),1,fp)!=1)
		{
			printf("file write error\n");
			exit(0);
		}
		printf("�Ƿ��������y or n ?\t");
		getchar();
		ch=getchar();
	}while(ch=='y'||ch=='Y');
	fclose(fp);
}
void find() //��ѯ�ɼ�����Ϣ
{ int a,b=0;
char ch[20];
FILE *fp;
if((fp=fopen("dd.dat","rb"))==NULL)
{
	printf("cannot open file\n");
	exit(0);
}
printf("������Ҫ��ѯ�ĳɼ��ķ�ʽ\n\t1.��� 2.����:\n\t��ѡ�� 1 or 2 \t");
scanf("%d",&a);
if(a==1)
{ getchar();
printf("������ɼ��ı��:\t");
gets(ch);
while(fread(&mm,sizeof(struct MM),1,fp)==1)
if(strcmp(mm.num,ch)==0)
{
	b++;
	printf("���\t����\t�۸�\t\tѧ��\n");
	printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
}
if(b==0) printf("�Բ���û���ҵ������Ϣ��\n");
}
else if(a==2)
{ printf("������ɼ�������:\t");
getchar();
gets(ch);
while(fread(&mm,sizeof(struct MM),1,fp)==1)
if(strcmp(mm.name,ch)==0)
{
	b++;
	printf("���\t����\t�۸�\t\tѧ��\n");
	printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
}
if(b==0) printf("input error!\n");
}
fclose(fp);
}
void scanf_2() //�ڶ���������Ϣ���������ļ���
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
		printf("������Ҫ���ӳɼ���--���:\t");
		getchar();
		gets(mm.num);
		printf("����:\t");
		gets(mm.name);
		printf("�۸�:\t");
		scanf("%f",&mm.pay);
		printf("ѧ��:\t");
		scanf("%d",&mm.many);
		if(fwrite(&mm,sizeof(struct MM),1,fp)!=1)
		{
			printf("file write error\n");
			exit(0);
		}
		printf("�Ƿ��������y or n ?\t");
		getchar();
		ch=getchar();
	}while(ch=='y'||ch=='Y');
	fclose(fp);
}
void print() //����ĵ��е���Ϣ
{
	FILE *fp;
	if((fp=fopen("dd.dat","rb"))==NULL)
	{
		printf("cannot open file\n");
		return ;
	}
	printf("���\t����\t�۸�\t\tѧ��\n");
	while(fread(&mm,sizeof(struct MM),1,fp)==1)
		printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
	fclose(fp);
}
void change()
{ //�޸���Ϣ�ĺ�����������һ���ļ�����Ҫ�޸ĵ���Ϣ�ŵ����ļ���
	struct XX //Ȼ����������Ϣ���Ƶ����ļ��У����Ѹ��ļ���������Ϊԭ������
	{ //��ԭ�����ļ��Ƴ���
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
		printf("������Ҫ�޸ĳɼ��ı��:\t");
		scanf("%s",ch);
		n++;
		while(fread(&mm,sizeof(struct MM),1,fp)==1)
		{
			if((strcmp(mm.num,ch)==0))
			{
				b++; //b��ֵ���һֱû�иı�˵����û���ҵ���ص���Ϣ��
				printf("���\t����\t�۸�\t\tѧ��\n");
				printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
				getchar();
				printf("������ɼ����±��:\t");
				gets(xx.num);
				printf("������ɼ���������:\t");
				gets(xx.name);
				printf("������ɼ����¼۸�:\t");
				scanf("%f",&xx.pay);
				printf("������ɼ���ѧ��:\t");
				scanf("%d",&xx.many);
				getchar();
				fwrite(&xx,sizeof(struct XX),1,fp2);
			}
			if(strcmp(mm.num,ch)!=0)
				fwrite(&mm,sizeof(struct MM),1,fp2);
		}
		if(b==0)
		{
			printf("\tû���ҵ������Ϣ��\n");
			getchar();
		}
		rewind(fp); //���Ҫ�����޸ĵĻ���Ҫ�ѱ�Ƿ��ص��ļ��Ŀ�ͷ��
		printf("�Ƿ�����޸ģ�enter 'y' or 'n' \t");
		ck=getchar();
		fclose(fp);
		fclose(fp2);
		remove("dd.dat");
		rename("temp.dat","dd.dat");
	}while(ck=='y'||ck=='Y');
	if(b!=0) //���û���ҵ������Ϣ�Ͳ������
		printf("\t�޸ĳɹ���\n");
}
void del()
{ //ɾ���������޸ĺ�����
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
		printf("������Ҫɾ���ɼ��ı��:\t");
		scanf("%s",ch);
		n++;
		while(fread(&mm,sizeof(struct MM),1,fp)==1)
		{
			if((strcmp(mm.num,ch)==0))
			{
				b++; //b��ֵ���һֱû�иı�˵����û���ҵ���ص���Ϣ��
				printf("���\t����\t�۸�\t\tѧ��\n");
				printf("%s\t%s\t%.3f\t\t%d\n",mm.num,mm.name,mm.pay,mm.many);
			}
			else if(strcmp(mm.num,ch)!=0)
				fwrite(&mm,sizeof(struct MM),1,fp2);
		}
		if(b==0)
		{
			printf("\tû���ҵ������Ϣ��\n");
			getchar();
		}
		rewind(fp);
		getchar();
		getchar();
		printf("ɾ���ɹ���");
		getchar(); //���Ҫ�����޸ĵĻ���Ҫ�ѱ�Ƿ��ص��ļ��Ŀ�ͷ��
		printf("�Ƿ����ɾ����enter 'y' or 'n' \t");
		ck=getchar();
		fclose(fp);
		fclose(fp2);
		remove("dd.dat");
		rename("temp.dat","dd.dat");
	}while(ck=='y'||ck=='Y');
	if(b!=0) //���û���ҵ������Ϣ�Ͳ������
		printf("\t����ɹ���\n");
}
void myexit()
{
	int a;
	char ch;
	printf("\t�Ƿ�ȷ���˳�����ѡ�� y or n: ");
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
		else printf("������󣡣������������룺\t");
		printf("\t�������������\n");
		getch();
		menu();
	}
	getch();
}