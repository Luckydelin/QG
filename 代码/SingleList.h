#pragma once
#include"List.h"
typedef class Node
{
public:
	ElemType data;
	Node* next;
}Node;

class SingleList :public List
{
public:
	SingleList();
	~SingleList();

	virtual Status Create_List();
	virtual Status Destroy_List();
	virtual Status Insert_List();
	virtual Status Delete_List();
	virtual Status Show_List();
	virtual int CallBack_MidNode();
	virtual Status Reverse_List();
	virtual Status Odd_Even_Swap();
	virtual Status TF_Circle();
	virtual Status Create_Circle_List();
	virtual Status Seek_List();

	Node* head;
	int size;
};