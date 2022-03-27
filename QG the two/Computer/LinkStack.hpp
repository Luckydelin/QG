#ifndef LINKSTACK_H
#define LINKSTACK_H
#include<iostream>
#include<string> 
using namespace std;
typedef enum class Status:int
{
    ERROR =0, 
	SUCCESS=1
} Status;
template<typename T>
struct StackNode
{
	T data;
	StackNode<T>* next;
};
template<typename T>
class LinkStack
{
public:
	//链栈
	//初始化栈
	LinkStack();
	~LinkStack();
	Status isEmptyLStack();//判断栈是否为空
	Status getTopLStack( T& e);//得到栈顶元素
	Status pushLStack(T elem);//入栈
	Status popLStack(T& data);//出栈


public:
	StackNode<T>* top;
	int	count;
};


//链栈

//初始化栈
template<typename T>
LinkStack<T>::LinkStack()
{
	top = nullptr;
	count = 0;
}
template<typename T>
LinkStack<T>::~LinkStack()
{
	while (Status::ERROR == isEmptyLStack())
	{
		StackNode<T>* ptemp = top;
		top->next;
		delete(ptemp);
		count--;
	}
}

//判断栈是否为空
template<typename T>
Status LinkStack<T>::isEmptyLStack()
{
	if (count == 0)
		return Status::SUCCESS;
	return Status::ERROR;
}

//得到栈顶元素
template<typename T>
Status LinkStack<T>::getTopLStack(T& e)
{
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "栈为空！" << endl;
		return Status::ERROR;
	}
	e = top->data;
	return Status::SUCCESS;
}



//入栈
template<typename T>
Status LinkStack<T>::pushLStack(T elem)
{
	if (count == -1)
	{
		cout << "栈不存在！" << endl;
		return Status::ERROR;
	}
	StackNode<T>* ptemp = new StackNode<T>;
	if (ptemp == nullptr)
		return Status::ERROR;
	ptemp->data = elem;
	ptemp->next = this->top;
	this->top = ptemp;
	count++;
	return Status::SUCCESS;
}

//出栈
template<typename T>
Status LinkStack<T>::popLStack(T& data)
{
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "栈为空！" << endl;
		return Status::ERROR;
	}
	data = top->data;
	StackNode<T>* ptemp = top;
	top = top->next;
	delete ptemp;
	count--;
	return Status::SUCCESS;
}


#endif 
