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
	//��ջ
	//��ʼ��ջ
	LinkStack();
	~LinkStack();
	Status isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��
	Status getTopLStack( T& e);//�õ�ջ��Ԫ��
	Status pushLStack(T elem);//��ջ
	Status popLStack(T& data);//��ջ


public:
	StackNode<T>* top;
	int	count;
};


//��ջ

//��ʼ��ջ
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

//�ж�ջ�Ƿ�Ϊ��
template<typename T>
Status LinkStack<T>::isEmptyLStack()
{
	if (count == 0)
		return Status::SUCCESS;
	return Status::ERROR;
}

//�õ�ջ��Ԫ��
template<typename T>
Status LinkStack<T>::getTopLStack(T& e)
{
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "ջΪ�գ�" << endl;
		return Status::ERROR;
	}
	e = top->data;
	return Status::SUCCESS;
}



//��ջ
template<typename T>
Status LinkStack<T>::pushLStack(T elem)
{
	if (count == -1)
	{
		cout << "ջ�����ڣ�" << endl;
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

//��ջ
template<typename T>
Status LinkStack<T>::popLStack(T& data)
{
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "ջΪ�գ�" << endl;
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
