#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE  1000

typedef struct pCON {
char name[20]; //����
char sex[20];  //�Ա�
char tel[20];   //�绰
char add[200]; //סַ
char email[50];//����
}pCon;

typedef struct CONTACT
{
	struct pCON data[MAX_SIZE];    //�洢�������
	int  size;           //��ǰ�洢����
}Con;

void Init(Con* pcon);  //��ʼ��
void Insert(Con* pcon);  //����
void Delete(Con* pcon);  //ɾ��
void Search(Con* pcon);  //����
void Change(Con* pcon);   //����
void Show(Con* pcon);  //��ӡ
void Clear(Con* pcon);   //���
void Sort(Con* pcon); //����������

void Init(Con* pcon)  //��ʼ��
{
	if (pcon == NULL)
	{
		printf("�Ƿ����룡\n");
		return;
	}
	pcon->size = 0;
}

int find(Con* pcon, char* name)   //������������λ��
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

void Insert(Con* pcon)   //����   
{
	int i = 0;	
	if (pcon->size == MAX_SIZE)
	{
		printf("ͨѶ¼�Ѿ����ˣ�\n");
		return;
	}
	printf("���������֣�");
	char name[20];
	scanf_s("%s", name, 18);
	for (i = 0; i < pcon->size; i++)
	{
		if (strcmp(name, pcon->data[i].name) == 0)
		{
			printf("�����ظ�¼��");
			return;
		}
	}
	printf("�뿪ʼ¼��\n");
	printf("���������֣�");
	scanf_s("%s", (pcon->data[pcon->size]).name, 20);
	printf("�������Ա�");
	scanf_s("%s", (pcon->data[pcon->size]).sex, 20);
	printf("���������䣺");
	scanf_s("%s", (pcon->data[pcon->size]).email, 20);
	printf("������绰��");
	scanf_s("%s", (pcon->data[pcon->size]).tel, 20);
	printf("�������ַ��");
	scanf_s("%s", (pcon->data[pcon->size]).add, 100);
	pcon->size++;
}

void Delete(Con* pcon)   //ɾ��
{
	char name[20];
	int ret = 0;
	printf("������Ҫɾ���˵�����:");
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
		printf("��ɾ������ϵ��\n");
	}
	else
	{
		printf("���˲����ڣ�ɾ��ʧ�ܣ�\n");
	}
}

void Search(Con* pcon)    //������Ϣ
{
	char name[20];
	int ret = 0;
	printf("��������ϵ������\n");
	scanf_s("%s", name, 20);
	ret = find(pcon, name);
	if (ret != -1)
	{
		printf("������%s  �Ա� %s  ���� ��%s  �绰��%s  ��ַ�� %s \n",
			pcon->data[ret].name, pcon->data[ret].sex,
			pcon->data[ret].email, pcon->data[ret].tel,
			pcon->data[ret].add);
	}
	else
	{
		printf("û���ҵ�\n");
	}
}

void Change(Con* pcon)    //�޸�
{
	char name[20];
	int ret = 0;
	printf("��������ϵ������:\n");
	scanf_s("%s", name, 20);
	ret = find(pcon, name);
	if (ret != -1)
	{
		printf("�������޸ĺ����֣�");
		scanf_s("%s", (pcon->data[ret]).name, 20);
		printf("�������޸ĺ��Ա�");
		scanf_s("%s", (pcon->data[ret]).sex, 20);
		printf("�������޸ĺ����䣺");
		scanf_s("%s", (pcon->data[ret]).email, 20);
		printf("�������޸ĺ�绰��");
		scanf_s("%s", (pcon->data[ret]).tel, 20);
		printf("�������޸ĺ��ַ��");
		scanf_s("%s", (pcon->data[ret]).add, 20);
		printf("�Ѿ��޸�\n");
	}
}

void Show(Con* pcon)   //��ʾ
{
	if (pcon->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		printf("������%s  �Ա� %s  ���� ��%s  �绰��%s  ��ַ�� %s \n",
			pcon->data[i].name, pcon->data[i].sex,
			pcon->data[i].email, pcon->data[i].tel,
			pcon->data[i].add
		);
	}
}

void Clear(Con* pcon)    //���
{
	pcon->size = 0;
}

void Sort(Con* pcon)   //����������
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

void print()            //��ʾ����
{
	printf("***********ͨѶ¼************\n");
	printf("****1.   �����ϵ����Ϣ******\n");
	printf("****2.   ɾ��ָ����ϵ����Ϣ**\n");
	printf("****3.   ����ָ����ϵ����Ϣ**\n");
	printf("****4.   �޸�ָ����ϵ����Ϣ**\n");
	printf("****5.   ��ʾ������ϵ����Ϣ**\n");
	printf("****6.   ���������ϵ��******\n");
	printf("****7.   ����������������ϵ��\n");
	printf("****8.   �˳�ͨѶ¼\n********\n");
	printf("\n");
	printf("������Ҫ��������ţ�\n");
}

int main()
{
	Con pcon;
	int choice = 1;
	Init(&pcon);
	while (choice)
	{
		print();
		printf("��ѡ��>");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			Insert(&pcon);        //����
			system("cls");         //����
			break;
		case 2:
			Delete(&pcon);   //ɾ��
			system("cls");
			break;
		case 3:
			Search(&pcon);   //����
			break;
		case 4:
			Change(&pcon);    //�޸�
			system("cls");
			break;
		case 5:
			Show(&pcon);     //��ӡ
			break;
		case 6:
			Clear(&pcon);
			break;   //���
		case 7:
			Sort(&pcon);  // ����������
			break;
		case 8:
			exit(0);    //�˳�
		default:
			printf("�����������������룡\n"); break;

		}
		printf("\n");

	}
	return 0;
}









