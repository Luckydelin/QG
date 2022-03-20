#pragma once
typedef int ElemType;
typedef int Status;
#define  ERROR 0  ;
#define SUCCESS  1;

class List
{
public:
	virtual Status Create_List() = 0;
	virtual Status Destroy_List() = 0;
	virtual Status Insert_List() = 0;
	virtual Status Delete_List() = 0;
	virtual Status Show_List() = 0;
	virtual int CallBack_MidNode()=0;
	virtual Status Reverse_List() = 0;
	virtual Status Odd_Even_Swap() = 0;
	virtual Status TF_Circle() = 0;
	virtual Status Create_Circle_List()=0;
	virtual Status Seek_List()=0;

};