
#ifndef LQUEUE_H
#define LQUEUE_H
#include<iostream>
using namespace std;

typedef enum class status :int
{
    FALSE = 0, TRUE = 1
} status;

template<typename T>
struct Node//结点结构
{
public:
    int  data;                   //数据域指针
    Node* next;            //指向当前结点的下一结点
};

template<typename T>
class LQueue//队列类
{

public:
    LQueue();
    ~LQueue();
    status DestoryLQueue();//销毁队列
    status IsEmptyLQueue();//判断队列是否为空
    status GetHeadLQueue(T&  e);//得到队头元素
    int LengthLQueue();//获取队列的长度
    status EnLQueue();//进队
    status DeLQueue();//出队
    status ClearLQueue();//清空队列
    status TraverseLQueue();//遍历队列
    void CreateLQueue();//创建队列
private:
  
    Node<T> *front;                   //队头
    Node<T> *rear;                    //队尾
    int length;            //队列长度
}; 


template<typename T>
LQueue<T>::LQueue()//默认构造函数
{
	Node<T>* ptemp = new Node<T>;//给头指针和尾指针申请内存
	ptemp->next = nullptr;
	front = rear = ptemp;
	length = -1;//长度初始化为-1，意味着队列未创建，若为0，则队列已经创建
}


template<typename T>
LQueue<T>::~LQueue()//析构函数
{
	while (front != rear)//将堆区的数据清除
	{
		Node<T>* ptemp1;
		ptemp1 = front;
		front = front->next;//用头指针遍历
		delete ptemp1;
	}
	delete front;
	front = rear = nullptr;
}


template<typename T>
void LQueue<T>::CreateLQueue()//创建队列
{
	length = 0;
	cout << "队列创建成功！" << endl;//头尾指针已经有内存，长度改为0即可
}


template<typename T>
status LQueue<T>::DestoryLQueue()//销毁队列
{
	if (length == -1)
	{
		cout << "队列已经不存在！无需要销毁！" << endl;
		return status::FALSE;
	}

	while (front != rear)
	{
		Node<T>* ptemp1;
		ptemp1 = front;
		front = front->next;//和析构函数类似，用头指针遍历
		delete ptemp1;
	}
	delete front;
	front = rear = nullptr;
	length = -1;//长度修改为队列未创建状态
	cout << "队列销毁成功！" << endl;
	return status::TRUE;
}

template<typename T>
status LQueue<T>::IsEmptyLQueue()//检查队列是否为空
{
	if (front == rear||length==0)//用两种方式检查，一为头尾指针相遇，二是队列长度
		return status::TRUE;
	else
		return status::FALSE;
}

template<typename T>
status LQueue<T>::GetHeadLQueue(T& e)//得到队头元素
{
	if (length == -1)
	{
		cout << "队列不存在！" << endl;
		return status::FALSE;
	}
	if (status::TRUE == IsEmptyLQueue())
	{
		cout << "队列为空！" << endl;
		return status::FALSE;
	}
	e = front->next->data;//返回队头元素赋给其引用
	cout << "返回队头成功！" << endl;
	cout << "元素为：" << front->next->data << endl;
	cout << "当前队列长度为：" << length << endl;
	return status::TRUE;
}


template<typename T>
int LQueue<T>::LengthLQueue()//返回队列长度
{

	length = 0;
	Node<T>* ptemp = front;//遍历得到队列长度
	while (ptemp != rear)
	{
		ptemp = ptemp->next;
		length++;
	}
	return length;
}


template<typename T>
status LQueue<T>::EnLQueue()//进队
{
	if (length == -1)
	{
		cout << "队列不存在！" << endl;
		return status::FALSE;
	}
	cout << "请输入进队的数据！" << endl;
	T elem;
	cin >> elem;
	Node<T>* ptemp = new Node<T>;//进队操作由尾指针的后指针来接受新结点，然后把尾指针指向新节点
	ptemp->data = elem;
	ptemp->next = nullptr;
	rear->next = ptemp;
	rear = ptemp;
	length++;//进队后长度改变
	cout << "数据进队成功！" << endl;
	cout << "当前队列长度为：" << length << endl;
	char c = getchar();
	return status::TRUE;
}
template<typename T>
status LQueue<T>::DeLQueue()//出队
{
	if (length == -1)
	{
		cout << "队列不存在！" << endl;
		return status::FALSE;
	}
	if (status::TRUE == IsEmptyLQueue())
	{
		cout << "队列为空！" << endl;
		return status::FALSE;
	}
	cout << "出队成功！" << endl;
	cout << "出队元素为：" << front->next->data << endl;
	Node<T>* ptemp;
	ptemp = front->next;//队头元素为头指针和第二结点的中间，所以借用其他指针ptemp
	front->next = ptemp->next;
	delete ptemp;//堆区数据清除
	length--;//出队后长度改变
	cout << "当前队列长度为：" << length << endl;
	return status::TRUE;
}


template<typename T>
status LQueue<T>::ClearLQueue()//清空队列
{
	if (length == -1)
	{
		cout << "队列不存在！" << endl;
		return status::FALSE;
	}
	if (status::TRUE == IsEmptyLQueue())
	{
		cout << "队列已经为空！无需再清空！" << endl;
		return status::FALSE;
	}
	while (front != rear)//清空跟销毁队列和析构函数部分类似，也是用头指针遍历
	{
		Node<T>* ptemp1;
		ptemp1 = front;
		front = front->next;
		delete ptemp1;
	}
	length = 0;//长度发生改变
	cout << "队列清空成功！" << endl;
	return status::TRUE;
}
template<typename T>
status LQueue<T>::TraverseLQueue()//遍历队列
{
	if (length == -1)
	{
		cout << "队列不存在！" << endl;
		return status::FALSE;
	}
	if (status::TRUE == IsEmptyLQueue())
	{
		cout << "队列为空！" << endl;
		return status::FALSE;
	}
	cout << "遍历成功！" << endl;
	cout << "元素如下：" << endl;
	Node<T>* ptemp = front->next;
	while (ptemp != nullptr)//逐个遍历即可
	{
		cout << ptemp->data;
		ptemp = ptemp->next;
		if (ptemp != nullptr)
			cout << "<-";
	}
	cout << endl;
	cout <<"当前队列长度为："<<length<< endl;//并返回其长度
	return status::TRUE;
}



#endif


