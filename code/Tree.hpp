#pragma once
#pragma once



#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


#define LH +1 // 左高 
#define EH 0  //  等高
#define RH -1 //  右高 

typedef int Status;	//Status是函数的类型, 其值是函数结果状态代码，如OK等
#include <iostream>
using namespace std;

//二叉树的二叉链表结点类定义 
template<typename Q>
class BiTNode2	// 结点结构 
{
public:
	Q data;	// 结点数据 
	int bf; //  结点的平衡因子 
	BiTNode2<Q>* lchild, * rchild;	// 左右孩子指针
};

template<typename Q>
class Tree
{
public:
	//查找
	virtual Status Search(BiTNode2<Q>* T, Q key, BiTNode2<Q>* f, BiTNode2<Q>** p) = 0;
	//插入
	virtual Status Insert(BiTNode2<Q>** Root, Q key) = 0;
	//删除
	virtual Status Delete(BiTNode2<Q>** Root, Q key) = 0;
	//先序遍历
	virtual Status PreOrder(BiTNode2<Q>* T) = 0;
	//中序遍历
	virtual Status InOrder(BiTNode2<Q>* T) = 0;
	//后序遍历
	virtual Status PostOrder(BiTNode2<Q>* T) = 0;
	//层次遍历
	virtual Status LevelOrder(BiTNode2<Q>* T) = 0;
	//先序遍历（非递归）
	virtual Status PreOrder2(BiTNode2<Q>* T) = 0;
	//中序遍历（非递归）
	virtual Status InOrder2(BiTNode2<Q>* T) = 0;
	//后序遍历（非递归）
	virtual Status PostOrder2(BiTNode2<Q>* T) = 0;
public:
	BiTNode2<Q>* Root;
};
