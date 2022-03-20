#include"DoubleList.h"
#include<stdio.h>
using namespace std;
#include <iostream>
DoubleList::DoubleList()
{
	head = new DNode;
	head->data = 0;
	head->next = NULL;
	head->prev = NULL;
	size = 0;
}
DoubleList::~DoubleList()
{
	delete head;
}
Status DoubleList::Create_List()
{
	cout << "�����봴���Ľ����" << endl;
	int num;
	cin >> num;
	if (num < 0)
	{
		cout << "����!" << endl;
		return ERROR;
	}
	DNode* ptemp = NULL;
	DNode* pnew = NULL;
	this->size = num;
	ptemp = this->head;
	for (int i = 0; i < num; i++)
	{
		pnew = new DNode;
		pnew->next = NULL;
		pnew->prev = NULL;

		if (pnew == NULL)
			cout << "�ڴ���䲻�ɹ���" << endl;

		cout << "�������" << i + 1 << "����������:" << endl;//----------------------����β�巨------------------------
		cin >> pnew->data;
		ptemp->next = pnew;
		pnew->prev = ptemp;
		ptemp = pnew;
	}
	cout << "˫�������ɹ�!" << endl;
	return SUCCESS;
}
Status DoubleList::Destroy_List()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	DNode* ptemp = head->next;
	while (ptemp && ptemp->next)
	{
		
		head = ptemp->next;
		free(ptemp);
		ptemp = head->next;
	}
	this->size = 0;
	cout << "�������ٳɹ���" << endl;
	return SUCCESS;
}
Status DoubleList::Insert_List()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	cout << "��������Ҫ�����ǰ��㣺" << endl;
	int num;
	cin >> num;
	if (num > this->size)
	{
		cout << "��������" << endl;
		return ERROR;
	}
	DNode* pnew = new DNode;
	if (pnew == NULL)
		cout << "�ڴ���䲻�ɹ���" << endl;
	pnew->next = NULL;
	cout << "���������������ݣ�" << endl;
	cin >> pnew->data;

	if (num == 0)//------------------------ͷָ������---------------------------------------
	{
		pnew->next = head->next;
		head->next = pnew;
		pnew->prev = head;
	}
	else
	{
		DNode* ptemp;
		ptemp = head->next;
		for (int i = 1; i < num; i++)//------------------------�ҵ�����ǰ���---------------------------
		{
			ptemp = ptemp->next;
		}
		pnew->next = ptemp->next;//--------------------------------Ϊ�½ڵ����ǰ��ָ��----------------------------
		pnew->prev = ptemp;
		ptemp->next = pnew;
	}
	this->size++;
	cout << "����ɹ���" << endl;
	return SUCCESS;
}
Status DoubleList::Delete_List()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	cout << "��������Ҫɾ���Ľ�㣺" << endl;
	int num;
	cin >> num;
	if (num == 0 || num > this->size)
	{
		cout << "��������" << endl;
		return ERROR;
	}
	DNode* ptemp = head->next;
	if (num == 1)//-----------------------ɾ�����������������1Ϊһ�����ʱ��2Ϊ����㣬3Ϊ�в����---------------------
	{
		head->next = ptemp->next;
		free(ptemp);
	}
	else if (num == this->size)
	{
		for (int i = 1; i < num; i++)
		{
			ptemp = ptemp->next;
		}
		ptemp->prev->next = NULL;
		free(ptemp);
	}
	else
	{
		for (int i = 1; i < num; i++)
		{
			ptemp = ptemp->next;
		}
		ptemp->prev->next = ptemp->next;
		ptemp->next->prev = ptemp->prev;
		free(ptemp);
	}
	this->size--;
	cout << "ɾ���ɹ���" << endl;
	return SUCCESS;
}
Status DoubleList::Show_List()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	cout << "�����������£�" << endl;
	DNode* ptemp;
	ptemp = head->next;
	for (int i = 1; ptemp && i <= this->size; i++)
	{
		cout << ptemp->data;
		if (ptemp = ptemp->next)
			cout << "->";
	}
	cout << endl;
	return SUCCESS;
}
int  DoubleList::CallBack_MidNode()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return NULL;
	}
	if (this->size < 3)//-----------------------------������������������м��-------------------------------
	{
		cout << "�������м���" << endl;
		return 0;
	}
	DNode* low, * high;
	low = high = this->head->next;
	int site=1;//----------------------------����ֵ---Ϊ�м�λ��-----------------------------------
	while (high && high->next)
	{
		high = high->next;
		if (high->next)
		{
			high = high->next;
			low = low->next;
			site;
		}
	}
	cout << "�м��������Ϊ" << endl;
	if (low && low->next)
	{
		cout << low->data << endl;
		if (this->size % 2 == 0)///---------------------------------���Ϊż��--�������------------------------------
		{
			low = low->next;
			cout << low->data << endl;
		}
	}
	return site;
}
Status DoubleList::Reverse_List()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	DNode* pt1 = head->next;//--------------------���þ͵ط�ת��-------------------------------
	DNode* pt2, * pt3;
	head->next = NULL;
	pt2 = pt1->next;
	pt3 = pt2->next;
	pt1->next = NULL;
	while (pt3)
	{
		pt2->next = pt1;
		if (pt3->next)
		{
			pt1 = pt2;
			pt2 = pt3;
			pt3 = pt3->next;
		}
		else
		{
			pt3->next = pt2;
			break;
		}
	}
	head->next = pt3;
	cout << "��ת�ɹ���" << endl;
	return SUCCESS;
}
Status DoubleList::Odd_Even_Swap()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	DNode* pt1 = this->head->next, * pt2 = pt1->next;
	while (pt1 && pt2)
	{
		swap(pt1->data, pt2->data);//-----------------������-----pt1/pt2��Ҫ����---------------
		pt1 = pt1->next->next;
		pt2 = pt1->next;
	}
	cout << "�����ɹ���" << endl;
	return SUCCESS;
}
Status DoubleList::TF_Circle()
{

	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	DNode* low, * high;
	low = high = this->head->next;
	while (high && high->next)
	{
		high = high->next;
		if (high->next)
		{
			high = high->next;//-----------------------------highΪ��ָ��--------------------
			low = low->next;//----------------------------------lowΪ��ָ��-----------------------
		}
		if (low == high)
		{
			cout << "����Ϊ��" << endl;
			return SUCCESS;
		}
	}
	cout << "����Ϊ��" << endl;
	return ERROR;

}
Status DoubleList::Create_Circle_List()
{
	cout << "�����봴���Ľ����" << endl;
	int num;
	cin >> num;
	if (num < 0)
	{
		cout << "����!" << endl;
		return ERROR;
	}
	DNode* ptemp = NULL;
	DNode* pnew = NULL;
	this->size = num;
	ptemp = this->head;
	for (int i = 0; i < num; i++)
	{
		pnew = new DNode;
		pnew->next = NULL;
		pnew->prev = NULL;

		if (pnew == NULL)
			cout << "�ڴ���䲻�ɹ���" << endl;

		cout << "�������" << i + 1 << "����������:" << endl;
		cin >> pnew->data;
		ptemp->next = pnew;//--------------------------------------------����β�巨---------------------;
		pnew->prev = ptemp;
		ptemp = pnew;
	}
	this->head->prev = ptemp;//------------------------------��β����next����head���---head��prev����β���--------------------------------
	ptemp->next = head;
	cout << "˫��ѭ�������ɹ�!" << endl;
	return SUCCESS;
}
Status DoubleList::Seek_List()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
	int data;
	cin >> data;
	DNode* ptemp;
	ptemp = head->next;
	for (int i = 1; ptemp && i <= this->size; i++)
	{

		if (ptemp->data == data)
		{
			cout << "���ڸ�Ԫ��" << endl;
			cout << "Ϊ��" << i << "�����" << endl;
			return SUCCESS;
		}
		ptemp = ptemp->next;
	}
	cout << "�����ڸ�Ԫ��" << endl;
	return ERROR;
}