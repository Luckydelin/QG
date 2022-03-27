
#ifndef LQUEUE_H
#define LQUEUE_H
#include<iostream>
using namespace std;

typedef enum class status :int
{
    FALSE = 0, TRUE = 1
} status;

template<typename T>
struct Node//���ṹ
{
public:
    int  data;                   //������ָ��
    Node* next;            //ָ��ǰ������һ���
};

template<typename T>
class LQueue//������
{

public:
    LQueue();
    ~LQueue();
    status DestoryLQueue();//���ٶ���
    status IsEmptyLQueue();//�ж϶����Ƿ�Ϊ��
    status GetHeadLQueue(T&  e);//�õ���ͷԪ��
    int LengthLQueue();//��ȡ���еĳ���
    status EnLQueue();//����
    status DeLQueue();//����
    status ClearLQueue();//��ն���
    status TraverseLQueue();//��������
    void CreateLQueue();//��������
private:
  
    Node<T> *front;                   //��ͷ
    Node<T> *rear;                    //��β
    int length;            //���г���
}; 


template<typename T>
LQueue<T>::LQueue()//Ĭ�Ϲ��캯��
{
	Node<T>* ptemp = new Node<T>;//��ͷָ���βָ�������ڴ�
	ptemp->next = nullptr;
	front = rear = ptemp;
	length = -1;//���ȳ�ʼ��Ϊ-1����ζ�Ŷ���δ��������Ϊ0��������Ѿ�����
}


template<typename T>
LQueue<T>::~LQueue()//��������
{
	while (front != rear)//���������������
	{
		Node<T>* ptemp1;
		ptemp1 = front;
		front = front->next;//��ͷָ�����
		delete ptemp1;
	}
	delete front;
	front = rear = nullptr;
}


template<typename T>
void LQueue<T>::CreateLQueue()//��������
{
	length = 0;
	cout << "���д����ɹ���" << endl;//ͷβָ���Ѿ����ڴ棬���ȸ�Ϊ0����
}


template<typename T>
status LQueue<T>::DestoryLQueue()//���ٶ���
{
	if (length == -1)
	{
		cout << "�����Ѿ������ڣ�����Ҫ���٣�" << endl;
		return status::FALSE;
	}

	while (front != rear)
	{
		Node<T>* ptemp1;
		ptemp1 = front;
		front = front->next;//�������������ƣ���ͷָ�����
		delete ptemp1;
	}
	delete front;
	front = rear = nullptr;
	length = -1;//�����޸�Ϊ����δ����״̬
	cout << "�������ٳɹ���" << endl;
	return status::TRUE;
}

template<typename T>
status LQueue<T>::IsEmptyLQueue()//�������Ƿ�Ϊ��
{
	if (front == rear||length==0)//�����ַ�ʽ��飬һΪͷβָ�����������Ƕ��г���
		return status::TRUE;
	else
		return status::FALSE;
}

template<typename T>
status LQueue<T>::GetHeadLQueue(T& e)//�õ���ͷԪ��
{
	if (length == -1)
	{
		cout << "���в����ڣ�" << endl;
		return status::FALSE;
	}
	if (status::TRUE == IsEmptyLQueue())
	{
		cout << "����Ϊ�գ�" << endl;
		return status::FALSE;
	}
	e = front->next->data;//���ض�ͷԪ�ظ���������
	cout << "���ض�ͷ�ɹ���" << endl;
	cout << "Ԫ��Ϊ��" << front->next->data << endl;
	cout << "��ǰ���г���Ϊ��" << length << endl;
	return status::TRUE;
}


template<typename T>
int LQueue<T>::LengthLQueue()//���ض��г���
{

	length = 0;
	Node<T>* ptemp = front;//�����õ����г���
	while (ptemp != rear)
	{
		ptemp = ptemp->next;
		length++;
	}
	return length;
}


template<typename T>
status LQueue<T>::EnLQueue()//����
{
	if (length == -1)
	{
		cout << "���в����ڣ�" << endl;
		return status::FALSE;
	}
	cout << "��������ӵ����ݣ�" << endl;
	T elem;
	cin >> elem;
	Node<T>* ptemp = new Node<T>;//���Ӳ�����βָ��ĺ�ָ���������½�㣬Ȼ���βָ��ָ���½ڵ�
	ptemp->data = elem;
	ptemp->next = nullptr;
	rear->next = ptemp;
	rear = ptemp;
	length++;//���Ӻ󳤶ȸı�
	cout << "���ݽ��ӳɹ���" << endl;
	cout << "��ǰ���г���Ϊ��" << length << endl;
	char c = getchar();
	return status::TRUE;
}
template<typename T>
status LQueue<T>::DeLQueue()//����
{
	if (length == -1)
	{
		cout << "���в����ڣ�" << endl;
		return status::FALSE;
	}
	if (status::TRUE == IsEmptyLQueue())
	{
		cout << "����Ϊ�գ�" << endl;
		return status::FALSE;
	}
	cout << "���ӳɹ���" << endl;
	cout << "����Ԫ��Ϊ��" << front->next->data << endl;
	Node<T>* ptemp;
	ptemp = front->next;//��ͷԪ��Ϊͷָ��͵ڶ������м䣬���Խ�������ָ��ptemp
	front->next = ptemp->next;
	delete ptemp;//�����������
	length--;//���Ӻ󳤶ȸı�
	cout << "��ǰ���г���Ϊ��" << length << endl;
	return status::TRUE;
}


template<typename T>
status LQueue<T>::ClearLQueue()//��ն���
{
	if (length == -1)
	{
		cout << "���в����ڣ�" << endl;
		return status::FALSE;
	}
	if (status::TRUE == IsEmptyLQueue())
	{
		cout << "�����Ѿ�Ϊ�գ���������գ�" << endl;
		return status::FALSE;
	}
	while (front != rear)//��ո����ٶ��к����������������ƣ�Ҳ����ͷָ�����
	{
		Node<T>* ptemp1;
		ptemp1 = front;
		front = front->next;
		delete ptemp1;
	}
	length = 0;//���ȷ����ı�
	cout << "������ճɹ���" << endl;
	return status::TRUE;
}
template<typename T>
status LQueue<T>::TraverseLQueue()//��������
{
	if (length == -1)
	{
		cout << "���в����ڣ�" << endl;
		return status::FALSE;
	}
	if (status::TRUE == IsEmptyLQueue())
	{
		cout << "����Ϊ�գ�" << endl;
		return status::FALSE;
	}
	cout << "�����ɹ���" << endl;
	cout << "Ԫ�����£�" << endl;
	Node<T>* ptemp = front->next;
	while (ptemp != nullptr)//�����������
	{
		cout << ptemp->data;
		ptemp = ptemp->next;
		if (ptemp != nullptr)
			cout << "<-";
	}
	cout << endl;
	cout <<"��ǰ���г���Ϊ��"<<length<< endl;//�������䳤��
	return status::TRUE;
}



#endif


