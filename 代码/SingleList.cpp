#include"SingleList.h"
#include<stdio.h>
using namespace std;
#include <iostream>
 SingleList::SingleList()
{
	head = new Node;
	head->data = 0;
	head->next = NULL;
	size = 0;
}
 SingleList::~SingleList()
{
	delete head;
}
 Status SingleList:: Create_List()
{
	cout << "�����봴���Ľ����" << endl;
	int num;
	cin >> num;
	if (num < 0)
	{
		cout << "����!" << endl;
		return ERROR;
	}
	Node* ptemp = NULL;
	Node* pnew = NULL;
	this->size = num;
	ptemp = this->head;
	for (int i = 0; i < num; i++)
	{
		pnew = new Node;
		pnew->next = NULL;

		if (pnew == NULL)
			cout << "�ڴ���䲻�ɹ���" << endl;

		cout << "�������" << i + 1 << "����������:" << endl;
		cin >> pnew->data;
		ptemp->next = pnew;
		ptemp = pnew;
	}
	cout << "���������ɹ�!" << endl;
	return SUCCESS;
}
 Status SingleList::Destroy_List()
{
	if (this->size==0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	Node* ptemp= head->next;
	while (ptemp&&ptemp->next)
	{
		head=ptemp->next;
		free(ptemp);
		ptemp= head->next;
	}
	this->size = 0;
	cout << "�������ٳɹ���" << endl;
	return SUCCESS;
}
 Status SingleList::Insert_List()
{
	if (this->size==0)
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
	Node* pnew = new Node;
	if (pnew == NULL)
		cout << "�ڴ���䲻�ɹ���"<<endl;
	pnew->next = NULL;
	cout << "���������������ݣ�" << endl;
	cin >> pnew->data;

	if (num == 0)
	{
		pnew->next=head->next;
		head->next = pnew;
	}
	else
	{
		Node* ptemp;
		ptemp = head->next;
		for (int i = 1; i < num; i++)
		{
			ptemp = ptemp->next;
		}
		pnew->next=ptemp->next;
		ptemp->next = pnew;
	}
	this->size++;
	cout << "����ɹ���" << endl;
	return SUCCESS;
}
 Status SingleList::Delete_List()
{
	if (this->size==0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	cout << "��������Ҫɾ���Ľ�㣺" << endl;
	int num;
	cin >> num;
	if (num==0||num > this->size)
	{
		cout << "��������" << endl;
		return ERROR;
	}
	Node* ptemp=head->next;
	if (num == 1)
	{
		head->next = ptemp->next;
		free(ptemp);
	}
	else
	{
		for (int i = 1;i<num-1; i++)
		{
			ptemp = ptemp->next;
		}
		Node* p1 = ptemp->next;
		ptemp->next = p1->next;
		free(p1);
	}
	cout << "ɾ���ɹ���" << endl;
	return SUCCESS;
}
 Status SingleList::Show_List()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	cout << "�����������£�" << endl;
	Node* ptemp;
	ptemp = head->next;
	for (int i = 1; ptemp&&i <= this->size; i++)
	{
		cout << ptemp->data ;
		if (ptemp = ptemp->next)
			cout << "->";
	}
	cout << endl;
	return SUCCESS;
}
 int SingleList::CallBack_MidNode()
{
	if(this->size==0)
	{
		cout << "����Ϊ��!" << endl;
		return NULL;
	}
	if (this->size < 3)
	{
		cout << "�������м���" << endl;
		return 0;
	}
	Node* low,*high;
	low=high = this->head->next;
	int site=1;
	while (high&&high->next)
	{
		high = high->next;
		if (high->next)
		{
			high = high->next;
			low = low->next;
			site++;
		}
	}
	cout << "�м��������Ϊ" << endl;
	if (low&&low->next)
	{
		cout << low->data << endl;
		if (this->size % 2 == 0)
		{
			low=low->next;
			cout << low->data << endl;
		}	
	}
	return site;
}
 Status SingleList::Reverse_List()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	Node* pt1 = head->next;
	Node* pt2,* pt3;
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
		//pt2 = pt1->next;
		//pt3 = pt2->next;
	}
	head->next = pt3;
	cout << "��ת�ɹ���" << endl;
	return SUCCESS;
}
 Status SingleList::Odd_Even_Swap()
{
	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	Node* pt1= this->head->next, *pt2=pt1->next;
	while (pt1&&pt2)
	{
		swap(pt1->data, pt2->data);
		pt1 = pt1->next->next;
		pt2 = pt1->next;
	}
	cout << "�����ɹ���" << endl;
	return SUCCESS;
}
 Status SingleList::TF_Circle()
{

	if (this->size == 0)
	{
		cout << "����Ϊ��!" << endl;
		return ERROR;
	}
	Node* low, * high;
	low = high = this->head->next;
	while (high && high->next)
	{
		high = high->next;
		if (high->next)
		{
			high = high->next;
			low = low->next;
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
 Status SingleList::Create_Circle_List()
 {
	 cout << "�����봴���Ľ����" << endl;
	 int num;
	 cin >> num;
	 if (num < 0)
	 {
		 cout << "����!" << endl;
		 return ERROR;
	 }
	 Node* ptemp = NULL;
	 Node* pnew = NULL;
	 this->size = num;
	 ptemp = this->head;
	 for (int i = 0; i < num; i++)//---------------------------����β�巨-------------------------------------------
	 {
		 pnew = new Node;
		 pnew->next = NULL;

		 if (pnew == NULL)
			 cout << "�ڴ���䲻�ɹ���" << endl;

		 cout << "�������" << i + 1 << "����������:" << endl;
		 cin >> pnew->data;
		 ptemp->next = pnew;
		 ptemp = pnew;
	 }
	 ptemp->next = head;//------------------------------��β����next����head���-----------------------------------
	 cout << "����ѭ�������ɹ�!" << endl;
	 return SUCCESS;
 }
 Status SingleList::Seek_List()
 {
	 if (this->size == 0)
	 {
		 cout << "����Ϊ��!" << endl;
		 return ERROR;
	 }
	 cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
	 int data;
	 cin >> data;
	 Node* ptemp;
	 ptemp = head->next;
	 for (int i = 1; ptemp && i <= this->size; i++)
	 {
		 
		 if (ptemp->data == data)
		 {
			cout << "���ڸ�Ԫ��" << endl;
			cout << "Ϊ��" << i << "�����" << endl;
			return SUCCESS;
		 }
		 ptemp=ptemp->next;
	 }
	 cout << "�����ڸ�Ԫ��" << endl;
	 return ERROR;
 }