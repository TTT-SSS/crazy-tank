#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE  1000

typedef struct pCON {
char name[20]; //姓名
char sex[20];  //性别
char tel[20];   //电话
char add[200]; //住址
char email[50];//邮箱
}pCon;

typedef struct CONTACT
{
	struct pCON data[MAX_SIZE];    //存储最大容量
	int  size;           //当前存储容量
}Con;

void Init(Con* pcon);  //初始化
void Insert(Con* pcon);  //插入
void Delete(Con* pcon);  //删除
void Search(Con* pcon);  //查找
void Change(Con* pcon);   //更改
void Show(Con* pcon);  //打印
void Clear(Con* pcon);   //清除
void Sort(Con* pcon); //以姓名排序

void Init(Con* pcon)  //初始化
{
	if (pcon == NULL)
	{
		printf("非法输入！\n");
		return;
	}
	pcon->size = 0;
}

int find(Con* pcon, char* name)   //根据姓名查找位置
{
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		if (strcmp(name, pcon->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void Insert(Con* pcon)   //插入   
{
	int i = 0;	
	if (pcon->size == MAX_SIZE)
	{
		printf("通讯录已经满了！\n");
		return;
	}
	printf("请输入名字：");
	char name[20];
	scanf_s("%s", name, 18);
	for (i = 0; i < pcon->size; i++)
	{
		if (strcmp(name, pcon->data[i].name) == 0)
		{
			printf("请勿重复录入");
			return;
		}
	}
	printf("请开始录入\n");
	printf("请输入名字：");
	scanf_s("%s", (pcon->data[pcon->size]).name, 20);
	printf("请输入性别：");
	scanf_s("%s", (pcon->data[pcon->size]).sex, 20);
	printf("请输入邮箱：");
	scanf_s("%s", (pcon->data[pcon->size]).email, 20);
	printf("请输入电话：");
	scanf_s("%s", (pcon->data[pcon->size]).tel, 20);
	printf("请输入地址：");
	scanf_s("%s", (pcon->data[pcon->size]).add, 100);
	pcon->size++;
}

void Delete(Con* pcon)   //删除
{
	char name[20];
	int ret = 0;
	printf("请输入要删除人的名字:");
	scanf_s("%s", &name, 20);
	ret = find(pcon, name);
	if (ret != -1)
	{
		int i = 0;
		for (i = ret; i < pcon->size - 1; i++)
		{
			pcon->data[ret] = pcon->data[ret + 1];
		}
		pcon->size--;
		printf("已删除该联系人\n");
	}
	else
	{
		printf("此人不存在，删除失败！\n");
	}
}

void Search(Con* pcon)    //查找信息
{
	char name[20];
	int ret = 0;
	printf("请输入联系人姓名\n");
	scanf_s("%s", name, 20);
	ret = find(pcon, name);
	if (ret != -1)
	{
		printf("姓名：%s  性别： %s  邮箱 ：%s  电话：%s  地址： %s \n",
			pcon->data[ret].name, pcon->data[ret].sex,
			pcon->data[ret].email, pcon->data[ret].tel,
			pcon->data[ret].add);
	}
	else
	{
		printf("没有找到\n");
	}
}

void Change(Con* pcon)    //修改
{
	char name[20];
	int ret = 0;
	printf("请输入联系人姓名:\n");
	scanf_s("%s", name, 20);
	ret = find(pcon, name);
	if (ret != -1)
	{
		printf("请输入修改后名字：");
		scanf_s("%s", (pcon->data[ret]).name, 20);
		printf("请输入修改后性别：");
		scanf_s("%s", (pcon->data[ret]).sex, 20);
		printf("请输入修改后邮箱：");
		scanf_s("%s", (pcon->data[ret]).email, 20);
		printf("请输入修改后电话：");
		scanf_s("%s", (pcon->data[ret]).tel, 20);
		printf("请输入修改后地址：");
		scanf_s("%s", (pcon->data[ret]).add, 20);
		printf("已经修改\n");
	}
}

void Show(Con* pcon)   //显示
{
	if (pcon->size == 0)
	{
		printf("通讯录为空！\n");
	}
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		printf("姓名：%s  性别： %s  邮箱 ：%s  电话：%s  地址： %s \n",
			pcon->data[i].name, pcon->data[i].sex,
			pcon->data[i].email, pcon->data[i].tel,
			pcon->data[i].add
		);
	}
}

void Clear(Con* pcon)    //清除
{
	pcon->size = 0;
}

void Sort(Con* pcon)   //以名字排序
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pcon->size - 1; i++)
	{
		for (j = 0; j < pcon->size - i - 1; j++)
		{
			if (strcmp(pcon->data[j].name, pcon->data[j + 1].name) > 0)
			{
				pCon tmp;
				tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
			}
		}
	}
}

void print()            //显示界面
{
	printf("***********通讯录************\n");
	printf("****1.   添加联系人信息******\n");
	printf("****2.   删除指定联系人信息**\n");
	printf("****3.   查找指定联系人信息**\n");
	printf("****4.   修改指定联系人信息**\n");
	printf("****5.   显示所有联系人信息**\n");
	printf("****6.   清空所有联系人******\n");
	printf("****7.   以名字排序所有联系人\n");
	printf("****8.   退出通讯录\n********\n");
	printf("\n");
	printf("请输入要操作的序号：\n");
}

int main()
{
	Con pcon;
	int choice = 1;
	Init(&pcon);
	while (choice)
	{
		print();
		printf("请选择：>");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			Insert(&pcon);        //插入
			system("cls");         //清屏
			break;
		case 2:
			Delete(&pcon);   //删除
			system("cls");
			break;
		case 3:
			Search(&pcon);   //查找
			break;
		case 4:
			Change(&pcon);    //修改
			system("cls");
			break;
		case 5:
			Show(&pcon);     //打印
			break;
		case 6:
			Clear(&pcon);
			break;   //清除
		case 7:
			Sort(&pcon);  // 以姓名排序
			break;
		case 8:
			exit(0);    //退出
		default:
			printf("输入有误请重新输入！\n"); break;

		}
		printf("\n");

	}
	return 0;
}









