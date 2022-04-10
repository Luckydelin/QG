#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */
#include"Tree.hpp"
#include <iostream>
using namespace std;
#include<stack>
#include<queue>
typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

template<typename Q>
class BinarySortTree:public Tree<Q>
{


public:
	//删除结点
	Status Delete_Node(BiTNode2<Q>** p);

public:
	//查找
	virtual Status Search(BiTNode2<Q>* T, Q key, BiTNode2<Q>* f, BiTNode2<Q>** p) ;
	//插入
	virtual Status Insert(BiTNode2<Q>** Root, Q key);
	//删除
	virtual Status Delete(BiTNode2<Q>** Root, Q key) ;
	//先序遍历
	virtual Status PreOrder(BiTNode2<Q>* T) ;
	//中序遍历
	virtual Status InOrder(BiTNode2<Q>* T) ;
	//后序遍历
	virtual Status PostOrder(BiTNode2<Q>* T);
	//层次遍历
	virtual Status LevelOrder(BiTNode2<Q>* T) ;
	//先序遍历（非递归）
	virtual Status PreOrder2(BiTNode2<Q>* T) ;
	//中序遍历（非递归）
	virtual Status InOrder2(BiTNode2<Q>* T) ;
	//后序遍历（非递归）
	virtual Status PostOrder2(BiTNode2<Q>* T);


};




/* 递归查找二叉排序树T中是否存在key, */
/* 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
template<typename Q>
Status BinarySortTree<Q>::Search(BiTNode2<Q>* T,Q key, BiTNode2<Q>* f, BiTNode2<Q>** p)
{
	if (T==nullptr)	/*  查找不成功 */
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data) /*  查找成功 */
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
		return Search(T->lchild, key, T, p);  /*  在左子树中继续查找 */
	else
		return Search(T->rchild, key, T, p);  /*  在右子树中继续查找 */
}


/*  当二叉排序树T中不存在关键字等于key的数据元素时， */
/*  插入key并返回TRUE，否则返回FALSE */
template<typename Q>
Status BinarySortTree<Q>::Insert(BiTNode2<Q>** Root,Q key)
{
	BiTNode2<Q>* p=nullptr, * s=nullptr;
	if (!Search(*Root, key, nullptr, &p)) /* 查找不成功 */
	{
		s = new BiTNode2<Q>;
		s->data = key;
		s->lchild = s->rchild = nullptr;
		if (p==nullptr)//当树没有数据时
			*Root = s;			/*  插入s为新的根结 */
		else if (key < p->data)
			p->lchild = s;	/*  插入s为左孩子 */
		else
			p->rchild = s;  /*  插入s为右孩子 */
		return TRUE;
	}
	else
		return FALSE;  /*  树中已有关键字相同的结点，不再插入 */
}


template<typename Q>
/* 从二叉排序树中删除结点p，并重接它的左或右子树。 */
Status BinarySortTree<Q>::Delete_Node(BiTNode2<Q>** p)
{
	BiTNode2<Q>* q,* s;
	if ((*p)->rchild == NULL) /* 右子树空则只需重接它的左子树（待删结点是叶子也走此分支) */
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if ((*p)->lchild == NULL) /* 只需重接它的右子树 */
	{
		q = *p; *p = (*p)->rchild; free(q);
	}
	else /* 左右子树均不空 */
	{
		q = *p; s = (*p)->lchild;
		while (s->rchild) /* 转左，然后向右到尽头（找待删结点的前驱） */
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data; /*  s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值） */
		if (q != *p)
			q->rchild = s->lchild; /*  重接q的右子树 */
		else
			q->lchild = s->lchild; /*  重接q的左子树 */
		free(s);
	}
	return TRUE;
}

/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点, */
/* 并返回TRUE；否则返回FALSE。 */
template<typename Q>
Status BinarySortTree<Q>::Delete(BiTNode2<Q>** Root,Q key)
{
	if (!*Root) /* 不存在关键字等于key的数据元素 */
		return FALSE;
	else
	{
		if (key == (*Root)->data) /* 找到关键字等于key的数据元素 */
			return Delete_Node(Root);
		else if (key < (*Root)->data)
			return Delete(&(*Root)->lchild, key);
		else
			return Delete(&(*Root)->rchild, key);

	}
}

//前序遍历
template<typename Q>
Status BinarySortTree<Q>::PreOrder(BiTNode2<Q>* T)
{
	int flag = 0;
	if (T == nullptr && flag == 0)
	{
		return FALSE;
	}
	else
	{
		cout << T->data << " ";
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		flag = 1;
		return TRUE;
	}

}

//中序遍历
template<typename Q>
Status BinarySortTree<Q>::InOrder(BiTNode2<Q>* T)
{
	int flag = 0;
	if (T == nullptr && flag == 0)
	{
		return FALSE;

	}
	else
	{
		InOrder(T->lchild);
		cout << T->data << " ";
		InOrder(T->rchild);
		flag = 1;
		return TRUE;
	}

}


//后序遍历
template<typename Q>
Status BinarySortTree<Q>::PostOrder(BiTNode2<Q>* T)
{
	int flag = 0;
	if (T == nullptr && flag == 0)
	{
		return FALSE;
	}
	else
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << " ";
		flag = 1;
		return TRUE;
	}

}




template<typename Q>
Status BinarySortTree<Q>::PreOrder2(BiTNode2<Q>* Root)//前序遍历的非递归实现
{
	stack<BiTNode2<Q>*> s1;
	if (Root != nullptr)//先将二叉树的根节点push进栈
	{
		s1.push(Root);
	}
	else
		return FALSE;
	while (!s1.empty())//栈不为空的条件下，执行一个循环
	{
		BiTNode2<Q>* top = s1.top();//先对top->_right进行判断是否入栈，再对top->_left进行判断是否入栈
		s1.pop();
		cout << top->data << " ";
		if (top->rchild != nullptr)
			s1.push(top->rchild);
		if (top->lchild != nullptr)
			s1.push(top->lchild);
	}
	return TRUE;
}



template<typename Q>
Status BinarySortTree<Q>::InOrder2(BiTNode2<Q>* Root )//中序遍历的非递归实现
{
	if (Root == nullptr)//先判断根节点是否为空
	{
		return FALSE;
	}
	stack<BiTNode2<Q>*> s2;
	while (Root != nullptr || !s2.empty())
	{
		while (Root != nullptr)
		{
			s2.push(Root);
			Root = Root->lchild;//栈顶节点：先保存该节点
		}
		BiTNode2<Q>* top = s2.top();
		cout << top->data << " ";
		s2.pop();
		Root = top->rchild;
	}
	return TRUE;
}




template<typename Q>
Status BinarySortTree<Q>::PostOrder2(BiTNode2<Q>* Root)//后序遍历的非递归实现
{
	if (Root == nullptr)//判断根节点是否为空
	{
		return FALSE;
	}
	stack<BiTNode2<Q>*> s3;
	BiTNode2<Q>* lastVisited = nullptr;
	while (Root != nullptr || !s3.empty())
	{
		while (Root != nullptr)//先让根节点进栈
		{
			s3.push(Root);
			Root = Root->lchild;
		}
		BiTNode2<Q>* top = s3.top();//保存最靠近输出一个的节点
		if (top->rchild == nullptr || lastVisited == top->rchild)
		{
			s3.pop();
			cout << top->data << " ";
			lastVisited = top;
		}
		else
			Root = top->rchild;
	}
	return TRUE;
}

template<typename Q>
Status BinarySortTree<Q>::LevelOrder(BiTNode2<Q>* Root)
{
	if (Root == nullptr)
	{
		return FALSE;
	}
	BiTNode2<Q>* tree = Root;

	//队列  
	queue<BiTNode2<Q>*> q1;

	//根节点入队  
	q1.push(tree);

	//队列不空循环  
	while (!q1.empty()) 
	{

		//输出队头元素 
		tree = q1.front();

		//访问队头指向的结点数据
		cout<<tree->data<<" ";

		//队头出队
		q1.pop();

		//左子树不为空，将左子树入队  
		if (tree->lchild != nullptr) 
		{
			q1.push(tree->lchild);
		}

		//右子树不空，将右子树入队  
		if (tree->rchild != nullptr) 
		{
			q1.push(tree->rchild);
		}
	}
	return TRUE;
}
