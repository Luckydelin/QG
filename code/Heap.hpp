#pragma once
#pragma once

template<typename T>
class Heap
{

public:

    //排序
    virtual Status Sort()=0;

    //插入
    virtual bool Insert(T x) = 0;

    //删除
    virtual Status Delete(T x) = 0;

    //得到顶部指针
    virtual T GetTop() = 0;

    //遍历
    virtual Status vist() = 0;
};


