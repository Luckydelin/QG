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
	cout << "请输入创建的结点数" << endl;
	int num;
	cin >> num;
	if (num < 0)
	{
		cout << "有误!" << endl;
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
			cout << "内存分配不成功！" << endl;

		cout << "请输入第" << i + 1 << "个结点的数据:" << endl;//----------------------采用尾插法------------------------
		cin >> pnew->data;
		ptemp->next = pnew;
		pnew->prev = ptemp;
		ptemp = pnew;
	}
	cout << "双链表创建成功!" << endl;
	return SUCCESS;
}
Status DoubleList::Destroy_List()
{
	if (this->size == 0)
	{
		cout << "链表为空!" << endl;
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
	cout << "链表销毁成功！" << endl;
	return SUCCESS;
}
Status DoubleList::Insert_List()
{
	if (this->size == 0)
	{
		cout << "链表为空!" << endl;
		return ERROR;
	}
	cout << "请输入你要插入的前结点：" << endl;
	int num;
	cin >> num;
	if (num > this->size)
	{
		cout << "输入有误" << endl;
		return ERROR;
	}
	DNode* pnew = new DNode;
	if (pnew == NULL)
		cout << "内存分配不成功！" << endl;
	pnew->next = NULL;
	cout << "请输入插入结点的数据：" << endl;
	cin >> pnew->data;

	if (num == 0)//------------------------头指针后插入---------------------------------------
	{
		pnew->next = head->next;
		head->next = pnew;
		pnew->prev = head;
	}
	else
	{
		DNode* ptemp;
		ptemp = head->next;
		for (int i = 1; i < num; i++)//------------------------找到插入前结点---------------------------
		{
			ptemp = ptemp->next;
		}
		pnew->next = ptemp->next;//--------------------------------为新节点分配前后指针----------------------------
		pnew->prev = ptemp;
		ptemp->next = pnew;
	}
	this->size++;
	cout << "插入成功！" << endl;
	return SUCCESS;
}
Status DoubleList::Delete_List()
{
	if (this->size == 0)
	{
		cout << "链表为空!" << endl;
		return ERROR;
	}
	cout << "请输入你要删除的结点：" << endl;
	int num;
	cin >> num;
	if (num == 0 || num > this->size)
	{
		cout << "输入有误" << endl;
		return ERROR;
	}
	DNode* ptemp = head->next;
	if (num == 1)//-----------------------删除操作分三种情况，1为一个结点时，2为最后结点，3为中部结点---------------------
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
	cout << "删除成功！" << endl;
	return SUCCESS;
}
Status DoubleList::Show_List()
{
	if (this->size == 0)
	{
		cout << "链表为空!" << endl;
		return ERROR;
	}
	cout << "链表数据如下：" << endl;
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
		cout << "链表为空!" << endl;
		return NULL;
	}
	if (this->size < 3)//-----------------------------定义两个结点以下无中间点-------------------------------
	{
		cout << "不存在中间结点" << endl;
		return 0;
	}
	DNode* low, * high;
	low = high = this->head->next;
	int site=1;//----------------------------返回值---为中间位置-----------------------------------
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
	cout << "中间结点的数据为" << endl;
	if (low && low->next)
	{
		cout << low->data << endl;
		if (this->size % 2 == 0)///---------------------------------结点为偶数--输出两个------------------------------
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
		cout << "链表为空!" << endl;
		return ERROR;
	}
	DNode* pt1 = head->next;//--------------------采用就地翻转法-------------------------------
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
	cout << "翻转成功！" << endl;
	return SUCCESS;
}
Status DoubleList::Odd_Even_Swap()
{
	if (this->size == 0)
	{
		cout << "链表为空!" << endl;
		return ERROR;
	}
	DNode* pt1 = this->head->next, * pt2 = pt1->next;
	while (pt1 && pt2)
	{
		swap(pt1->data, pt2->data);//-----------------交换后-----pt1/pt2都要迭代---------------
		pt1 = pt1->next->next;
		pt2 = pt1->next;
	}
	cout << "交换成功！" << endl;
	return SUCCESS;
}
Status DoubleList::TF_Circle()
{

	if (this->size == 0)
	{
		cout << "链表为空!" << endl;
		return ERROR;
	}
	DNode* low, * high;
	low = high = this->head->next;
	while (high && high->next)
	{
		high = high->next;
		if (high->next)
		{
			high = high->next;//-----------------------------high为快指针--------------------
			low = low->next;//----------------------------------low为慢指针-----------------------
		}
		if (low == high)
		{
			cout << "链表为环" << endl;
			return SUCCESS;
		}
	}
	cout << "链表不为环" << endl;
	return ERROR;

}
Status DoubleList::Create_Circle_List()
{
	cout << "请输入创建的结点数" << endl;
	int num;
	cin >> num;
	if (num < 0)
	{
		cout << "有误!" << endl;
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
			cout << "内存分配不成功！" << endl;

		cout << "请输入第" << i + 1 << "个结点的数据:" << endl;
		cin >> pnew->data;
		ptemp->next = pnew;//--------------------------------------------采用尾插法---------------------;
		pnew->prev = ptemp;
		ptemp = pnew;
	}
	this->head->prev = ptemp;//------------------------------把尾结点的next连接head结点---head的prev连接尾结点--------------------------------
	ptemp->next = head;
	cout << "双链循环表创建成功!" << endl;
	return SUCCESS;
}
Status DoubleList::Seek_List()
{
	if (this->size == 0)
	{
		cout << "链表为空!" << endl;
		return ERROR;
	}
	cout << "请输入你要查找的元素：" << endl;
	int data;
	cin >> data;
	DNode* ptemp;
	ptemp = head->next;
	for (int i = 1; ptemp && i <= this->size; i++)
	{

		if (ptemp->data == data)
		{
			cout << "存在该元素" << endl;
			cout << "为第" << i << "个结点" << endl;
			return SUCCESS;
		}
		ptemp = ptemp->next;
	}
	cout << "不存在该元素" << endl;
	return ERROR;
}