#ifndef LINKSTACK_H
#define LINKSTACK_H
#include<iostream>
using namespace std;

typedef enum class Status:int//函数返回状态枚举
{
    ERROR =0, 
	SUCCESS=1
} Status;

template<typename T>
struct StackNode//结点数据结构
{
public:
	T data;
	StackNode<T>* next;
};


template<typename T>
class LinkStack//链栈类
{
public:
	//链栈
	LinkStack();//初始化栈
	~LinkStack();
	Status isEmptyLStack();//判断栈是否为空
	Status getTopLStack( T& e);//得到栈顶元素
	Status clearLStack();//清空栈
	Status destroyLStack();//销毁栈
	Status pushLStack();//入栈
	Status popLStack(T& data);//出栈
	Status LStackLength(int& length);//检测栈长度 
	void   CreateLStack();//创建链栈
	Status TraverseLinkStack();//遍历链栈

public:
	StackNode<T>* top;
	int	count;
};
//链栈

//初始化栈
template<typename T>
LinkStack<T>::LinkStack()//默认构造函数
{
	top = nullptr;
	count = -1;//若长度为-1，说明链栈还没创建，长度为0，说明链栈为空
}


template<typename T>
void LinkStack<T>::CreateLStack()//创建链栈
{
	count = 0;//因为初始化链栈，top指针为空指针，所以改变长度即可
	cout << "链栈创建成功！" << endl;
}


template<typename T>
LinkStack<T>::~LinkStack()//析构函数
{
	while (Status::ERROR == isEmptyLStack())//根据count的变化作为循环条件
	{
		StackNode<T>* ptemp = top;
		top->next;
		delete(ptemp);//清除堆区的数据
		count--;//根据count的变化作为循环条件
	}
}

//判断栈是否为空
template<typename T>
Status LinkStack<T>::isEmptyLStack()//返回链栈是否为空的状态
{
	if (count == 0)//根据长度值返回
		return Status::SUCCESS;
	return Status::ERROR;
}

//得到栈顶元素
template<typename T>
Status LinkStack<T>::getTopLStack(T& e)
{
	if (count == -1)
	{
		cout << "栈不存在！" << endl;
		return Status::ERROR;
	}
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "栈为空！" << endl;
		return Status::ERROR;
	}
	e = top->data;//返回元素给其引用
	cout << "返回栈顶元素成功！当前栈长度为：" << count << endl;
	cout << "元素为：" << e << endl;
	return Status::SUCCESS;
}

//清空栈
template<typename T>
Status LinkStack<T>::clearLStack()
{
	if (count == -1)
	{
		cout << "栈不存在！" << endl;
		return Status::ERROR;
	}
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "栈已经为空！不需要清空！" << endl;
		return Status::ERROR;
	}
	while (Status::ERROR == isEmptyLStack())
	{
		StackNode<T>* ptemp = top;
		top->next;
		delete(ptemp);//与析构函数类似，用头指针不断遍历清除堆区数据
		count--;//同时要改变链栈长度值
	}
	cout << "清空栈成功！当前栈长度为：" << count << endl;
	return Status::SUCCESS;
}

//销毁栈
template<typename T>
Status LinkStack<T>::destroyLStack()
{
	if (count == -1)
	{
		cout << "栈已经不存在！不需要销毁！" << endl;
		return Status::ERROR;
	}
	LinkStack::~LinkStack();//跟析构函数的一样，析构函数是类自己调用的，所以我们要自己调用
	cout << "摧毁栈成功！" << endl;
	return Status::SUCCESS;
}


//入栈
template<typename T>
Status LinkStack<T>::pushLStack()
{
	if (count == -1)
	{
		cout << "栈不存在！" << endl;
		return Status::ERROR;
	}
	StackNode<T>* ptemp = new StackNode<T>;//建立堆区内存
	if (ptemp == nullptr)
		return Status::ERROR;
	T elem;
	cout << "请输入入栈的数据：" << endl;
	cin >> elem;
	ptemp->data = elem;
	ptemp->next = this->top;//用头指针接收数据
	this->top = ptemp;//改变头指针指向
	count++;//同时修改链栈的长度值
	char c = getchar();//吸收'\n',否则会被menu函数内的getline函数吸收，而对于'\n'，atoi函数不能发生转换，只能默认赋0；因此我们要避免
	cout << "入栈成功！当前栈长度为：" << count << endl;
	return Status::SUCCESS;
}

//出栈
template<typename T>
Status LinkStack<T>::popLStack(T& data)
{
	if (count == -1)
	{
		cout << "栈不存在！" << endl;
		return Status::ERROR;
	}
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "栈为空！" << endl;
		return Status::ERROR;
	}
	cout << "出栈元素为：" << endl;
	cout << top->data << endl;
	data = top->data;
	StackNode<T>* ptemp = top;//用指针删除堆区数据
	top = top->next;
	delete ptemp;
	count--;//同时修改链栈的长度值
	cout << "出栈成功！当前栈长度为：" << count << endl;
	return Status::SUCCESS;
}

template<typename T>
Status LinkStack<T>::LStackLength(int& length)//返回链栈长度
{
	length = count;
	return Status::SUCCESS;
}

template<typename T>
Status LinkStack<T>::TraverseLinkStack()//遍历链栈
{
	if (count == -1)
	{
		cout << "栈不存在！" << endl;
		return Status::ERROR;
	}
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "栈为空！" << endl;
		return Status::ERROR;
	}
	cout << "遍历成功！" << endl;
	cout << "元素如下：" << endl;
	StackNode<T>* ptemp = top;
	while (ptemp != nullptr)//用头指针逐个遍历即可
	{
		cout << ptemp->data;
		ptemp = ptemp->next;
		if (ptemp != nullptr)
			cout << "<-";
	}
	cout << endl;
	cout << "当前链栈长度为：" << count << endl;//返回其长度
	return Status::SUCCESS;
}

#endif 
