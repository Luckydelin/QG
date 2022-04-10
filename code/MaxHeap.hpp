#pragma once
#include"Heap.hpp"
#include<vector>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
template<typename T>
class MaxHeap:public Heap<T>
{
public:

    MaxHeap()
    {
        v1.reserve(10);
        count = -1;
    }

    MaxHeap(MaxHeap& other)
    {
        v1 = other.v1;
    }

    ~MaxHeap()
    {

    }
public:
    //�ѵ���
    void Adjust(int last, int len);

    
    //�ж϶��ǲ��ǿյ�
    bool isEmpty();
    //��ȡ����
    int Length();
public:
    //����
    virtual Status Sort();
    //��ȡ������С�ѵ�ͷ��ָ��
    virtual T GetTop();
    //����
    virtual bool Insert(T x);
   //ɾ��
    virtual Status Delete(T x);
    //����
    virtual Status vist();

private:
    //�洢���ݵ�����
    vector<T> v1;
    //����
    int count;
};


template<typename T>
//-----������ ����Ķѵ���
void MaxHeap<T>::Adjust(int last, int len)
{
    int j;
    int temp = v1[last];
    for (j = 2 * last; j < len; j *= 2)//---2iΪ��β˫�����ӣ�2i+1Ϊ��β˫���Һ���
    {
        if (j +1< len && v1[j] < v1[j + 1])
            j++;
        if (temp >= v1[j])
            break;
        v1[last] = v1[j];
        last = j;
    }
    v1[last] = temp;
}

//-----������ ����
template<typename T>
Status MaxHeap<T>::Sort()
{
    if (isEmpty() == true)
        return FALSE;
    else
    {
        for (int i = v1.size() / 2; i >= 0; i--)//n�����ݣ�n/2Ϊ��β˫��
        {
           Adjust(i, v1.size());//������
        }

        for (int i = v1.size() - 1; i > 1; i--)//����������Ѷ���������������
        {
            swap(v1[0], v1[i]);
            Adjust( 0, i - 1);
        }
    }
   
}

//�ж϶��ǲ��ǿյ�
template<typename T>
bool MaxHeap<T>::isEmpty()
{
    if (count == -1)
        return true;
    else
        return false;
}

//��ȡ������С�ѵ�ͷ��ָ��
template<typename T>
T MaxHeap<T>::GetTop()
{
    if (isEmpty() == true)
        return 1000000000;
    return v1[0];
}

template<typename T>
bool MaxHeap<T>::Insert(T x)
{
    
    v1.push_back(x);
 
    for (int i = v1.size() / 2; i >= 0; i--)//n�����ݣ�n/2Ϊ��β˫��
    {
        Adjust(i, v1.size());//������
    }
    Length();
    
    return true;
}

template<typename T>
Status MaxHeap<T>::Delete(T x)
{
    if (isEmpty() == true)
        return FALSE;
    else
    {
        int i;
        for (i = 0; i < v1.size(); i++)
        {
            if (v1[i] == x)
            {
                if (v1.size() == 1)//������Ϊ1��Сʱ�Ĵ���
                {
                    v1.reserve(10);
                    count = -1;
                    return TRUE;
                }
                for (; i < v1.size() - 1; i++)//������ǰ�ƶ��ķ���
                {
                    v1[i] = v1[i + 1];
                }
                v1.resize(v1.size() - 1);//���ô�С
            }

        }
        for (int i = v1.size() / 2; i >= 0; i--)//n�����ݣ�n/2Ϊ��β˫��
        {
            Adjust(i, v1.size());//������
        }
        Length();
    }
    
}

template<typename T>
Status MaxHeap<T>::vist()
{
    if (isEmpty() == true)
        return FALSE;
    else
    {
        cout << "�ѵ�����Ϊ��" << endl;
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
    }
}

template<typename T>
int MaxHeap<T>::Length()
{
    count = v1.size();
    return count;
}