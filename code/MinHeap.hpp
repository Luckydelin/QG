#pragma once
#include"Heap.hpp"
#include<vector>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
template<typename T>
class MinHeap :public Heap<T>
{
public:

    MinHeap()
    {
        v1.reserve(10);
        count = -1;
    }

    MinHeap(MinHeap& other)
    {
        v1 = other.v1;
    }

    ~MinHeap()
    {

    }
public:
    void Adjust(int last, int len);

    //-----堆排序 升序


    //判断堆是不是空的
    bool isEmpty();

    int Length();
public:
    //排序
    virtual Status Sort();
    //获取整个最小堆的头部指针
    virtual T GetTop();
    //插入
    virtual bool Insert(T x);
    //删除
    virtual Status Delete(T x);
    //遍历
    virtual Status vist();



private:
    //申请堆空间
    vector<T> v1;
    int count;
};


template<typename T>
//-----堆排序 降序的堆调整
void MinHeap<T>::Adjust(int last, int len)
{
    int j;
    int temp = v1[last];
    for (j = 2 * last; j < len; j *= 2)//---2i为最尾双亲左孩子，2i+1为最尾双亲右孩子
    {
        if (j+1<len && v1[j]>v1[j + 1])
            j++;
        if (temp <= v1[j])
            break;
        v1[last] = v1[j];
        last = j;
    }
    v1[last] = temp;
}


//-----堆排序 升序
template<typename T>
Status MinHeap<T>::Sort()
{
    if (isEmpty() == true)
        return FALSE;
    else
    {
        for (int i = v1.size() / 2; i >= 0; i--)//n个数据，n/2为最尾双亲
        {
            Adjust(i, v1.size());//调整堆
        }

        for (int i = v1.size() - 1; i > 1; i--)//将最大的数与堆顶交换，并调整堆
        {
            swap(v1[0], v1[i]);
            Adjust(0, i - 1);
        }
    }

}

//判断堆是不是空的
template<typename T>
bool MinHeap<T>::isEmpty()
{
    if (count == -1)
        return true;
    else
        return false;
}

//获取整个最小堆的头部指针
template<typename T>
T MinHeap<T>::GetTop()
{
    if (isEmpty() == true)//因为无法返回false，所以返回一个大的数目
        return 1000000000;
    return v1[0];
}

template<typename T>
bool MinHeap<T>::Insert(T x)
{

    v1.push_back(x);

    for (int i = v1.size() / 2; i >= 0; i--)//n个数据，n/2为最尾双亲
    {
        Adjust(i, v1.size());//调整堆
    }
    Length();//修改类内大小

    return true;
}

template<typename T>
Status MinHeap<T>::Delete(T x)
{
    if (isEmpty() == true)
        return FALSE;
    else
    {
        int i;
        for ( i = 0; i < v1.size(); i++)//当容器为1大小时的处理
        {
            if (v1[i] == x)
            {
                if (v1.size() == 1)
                {
                    v1.reserve(10);
                    count = -1;
                    return TRUE;
                }
                for (; i < v1.size() - 1; i++)//采用向前移动的方法
                {
                    v1[i] = v1[i + 1];
                }
                v1.resize(v1.size() - 1);//重置容器大小
            }
        }
        for (int i = v1.size() / 2; i >= 0; i--)//n个数据，n/2为最尾双亲
        {
            Adjust(i, v1.size());//调整堆
        }

        Length();//修改类内的大小
    }

}

template<typename T>
Status MinHeap<T>::vist()
{
    if (isEmpty() == true)
        return FALSE;
    else
    {
        cout << "堆的数据为：" << endl;
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
    }
}

template<typename T>
int MinHeap<T>::Length()
{
    count = v1.size();
    return count;
}