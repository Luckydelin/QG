#pragma once
#pragma once

template<typename T>
class Heap
{

public:

    //����
    virtual Status Sort()=0;

    //����
    virtual bool Insert(T x) = 0;

    //ɾ��
    virtual Status Delete(T x) = 0;

    //�õ�����ָ��
    virtual T GetTop() = 0;

    //����
    virtual Status vist() = 0;
};


