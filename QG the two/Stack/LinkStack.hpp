#ifndef LINKSTACK_H
#define LINKSTACK_H
#include<iostream>
using namespace std;

typedef enum class Status:int//��������״̬ö��
{
    ERROR =0, 
	SUCCESS=1
} Status;

template<typename T>
struct StackNode//������ݽṹ
{
public:
	T data;
	StackNode<T>* next;
};


template<typename T>
class LinkStack//��ջ��
{
public:
	//��ջ
	LinkStack();//��ʼ��ջ
	~LinkStack();
	Status isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��
	Status getTopLStack( T& e);//�õ�ջ��Ԫ��
	Status clearLStack();//���ջ
	Status destroyLStack();//����ջ
	Status pushLStack();//��ջ
	Status popLStack(T& data);//��ջ
	Status LStackLength(int& length);//���ջ���� 
	void   CreateLStack();//������ջ
	Status TraverseLinkStack();//������ջ

public:
	StackNode<T>* top;
	int	count;
};
//��ջ

//��ʼ��ջ
template<typename T>
LinkStack<T>::LinkStack()//Ĭ�Ϲ��캯��
{
	top = nullptr;
	count = -1;//������Ϊ-1��˵����ջ��û����������Ϊ0��˵����ջΪ��
}


template<typename T>
void LinkStack<T>::CreateLStack()//������ջ
{
	count = 0;//��Ϊ��ʼ����ջ��topָ��Ϊ��ָ�룬���Ըı䳤�ȼ���
	cout << "��ջ�����ɹ���" << endl;
}


template<typename T>
LinkStack<T>::~LinkStack()//��������
{
	while (Status::ERROR == isEmptyLStack())//����count�ı仯��Ϊѭ������
	{
		StackNode<T>* ptemp = top;
		top->next;
		delete(ptemp);//�������������
		count--;//����count�ı仯��Ϊѭ������
	}
}

//�ж�ջ�Ƿ�Ϊ��
template<typename T>
Status LinkStack<T>::isEmptyLStack()//������ջ�Ƿ�Ϊ�յ�״̬
{
	if (count == 0)//���ݳ���ֵ����
		return Status::SUCCESS;
	return Status::ERROR;
}

//�õ�ջ��Ԫ��
template<typename T>
Status LinkStack<T>::getTopLStack(T& e)
{
	if (count == -1)
	{
		cout << "ջ�����ڣ�" << endl;
		return Status::ERROR;
	}
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "ջΪ�գ�" << endl;
		return Status::ERROR;
	}
	e = top->data;//����Ԫ�ظ�������
	cout << "����ջ��Ԫ�سɹ�����ǰջ����Ϊ��" << count << endl;
	cout << "Ԫ��Ϊ��" << e << endl;
	return Status::SUCCESS;
}

//���ջ
template<typename T>
Status LinkStack<T>::clearLStack()
{
	if (count == -1)
	{
		cout << "ջ�����ڣ�" << endl;
		return Status::ERROR;
	}
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "ջ�Ѿ�Ϊ�գ�����Ҫ��գ�" << endl;
		return Status::ERROR;
	}
	while (Status::ERROR == isEmptyLStack())
	{
		StackNode<T>* ptemp = top;
		top->next;
		delete(ptemp);//�������������ƣ���ͷָ�벻�ϱ��������������
		count--;//ͬʱҪ�ı���ջ����ֵ
	}
	cout << "���ջ�ɹ�����ǰջ����Ϊ��" << count << endl;
	return Status::SUCCESS;
}

//����ջ
template<typename T>
Status LinkStack<T>::destroyLStack()
{
	if (count == -1)
	{
		cout << "ջ�Ѿ������ڣ�����Ҫ���٣�" << endl;
		return Status::ERROR;
	}
	LinkStack::~LinkStack();//������������һ�����������������Լ����õģ���������Ҫ�Լ�����
	cout << "�ݻ�ջ�ɹ���" << endl;
	return Status::SUCCESS;
}


//��ջ
template<typename T>
Status LinkStack<T>::pushLStack()
{
	if (count == -1)
	{
		cout << "ջ�����ڣ�" << endl;
		return Status::ERROR;
	}
	StackNode<T>* ptemp = new StackNode<T>;//���������ڴ�
	if (ptemp == nullptr)
		return Status::ERROR;
	T elem;
	cout << "��������ջ�����ݣ�" << endl;
	cin >> elem;
	ptemp->data = elem;
	ptemp->next = this->top;//��ͷָ���������
	this->top = ptemp;//�ı�ͷָ��ָ��
	count++;//ͬʱ�޸���ջ�ĳ���ֵ
	char c = getchar();//����'\n',����ᱻmenu�����ڵ�getline�������գ�������'\n'��atoi�������ܷ���ת����ֻ��Ĭ�ϸ�0���������Ҫ����
	cout << "��ջ�ɹ�����ǰջ����Ϊ��" << count << endl;
	return Status::SUCCESS;
}

//��ջ
template<typename T>
Status LinkStack<T>::popLStack(T& data)
{
	if (count == -1)
	{
		cout << "ջ�����ڣ�" << endl;
		return Status::ERROR;
	}
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "ջΪ�գ�" << endl;
		return Status::ERROR;
	}
	cout << "��ջԪ��Ϊ��" << endl;
	cout << top->data << endl;
	data = top->data;
	StackNode<T>* ptemp = top;//��ָ��ɾ����������
	top = top->next;
	delete ptemp;
	count--;//ͬʱ�޸���ջ�ĳ���ֵ
	cout << "��ջ�ɹ�����ǰջ����Ϊ��" << count << endl;
	return Status::SUCCESS;
}

template<typename T>
Status LinkStack<T>::LStackLength(int& length)//������ջ����
{
	length = count;
	return Status::SUCCESS;
}

template<typename T>
Status LinkStack<T>::TraverseLinkStack()//������ջ
{
	if (count == -1)
	{
		cout << "ջ�����ڣ�" << endl;
		return Status::ERROR;
	}
	if (Status::SUCCESS == isEmptyLStack())
	{
		cout << "ջΪ�գ�" << endl;
		return Status::ERROR;
	}
	cout << "�����ɹ���" << endl;
	cout << "Ԫ�����£�" << endl;
	StackNode<T>* ptemp = top;
	while (ptemp != nullptr)//��ͷָ�������������
	{
		cout << ptemp->data;
		ptemp = ptemp->next;
		if (ptemp != nullptr)
			cout << "<-";
	}
	cout << endl;
	cout << "��ǰ��ջ����Ϊ��" << count << endl;//�����䳤��
	return Status::SUCCESS;
}

#endif 
