#pragma once
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */
#include"Tree.hpp"
#include <iostream>
using namespace std;
#include<stack>
#include<queue>
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

template<typename Q>
class BinarySortTree:public Tree<Q>
{


public:
	//ɾ�����
	Status Delete_Node(BiTNode2<Q>** p);

public:
	//����
	virtual Status Search(BiTNode2<Q>* T, Q key, BiTNode2<Q>* f, BiTNode2<Q>** p) ;
	//����
	virtual Status Insert(BiTNode2<Q>** Root, Q key);
	//ɾ��
	virtual Status Delete(BiTNode2<Q>** Root, Q key) ;
	//�������
	virtual Status PreOrder(BiTNode2<Q>* T) ;
	//�������
	virtual Status InOrder(BiTNode2<Q>* T) ;
	//�������
	virtual Status PostOrder(BiTNode2<Q>* T);
	//��α���
	virtual Status LevelOrder(BiTNode2<Q>* T) ;
	//����������ǵݹ飩
	virtual Status PreOrder2(BiTNode2<Q>* T) ;
	//����������ǵݹ飩
	virtual Status InOrder2(BiTNode2<Q>* T) ;
	//����������ǵݹ飩
	virtual Status PostOrder2(BiTNode2<Q>* T);


};




/* �ݹ���Ҷ���������T���Ƿ����key, */
/* ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
/* �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE */
/* ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE */
template<typename Q>
Status BinarySortTree<Q>::Search(BiTNode2<Q>* T,Q key, BiTNode2<Q>* f, BiTNode2<Q>** p)
{
	if (T==nullptr)	/*  ���Ҳ��ɹ� */
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data) /*  ���ҳɹ� */
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
		return Search(T->lchild, key, T, p);  /*  ���������м������� */
	else
		return Search(T->rchild, key, T, p);  /*  ���������м������� */
}


/*  ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� */
/*  ����key������TRUE�����򷵻�FALSE */
template<typename Q>
Status BinarySortTree<Q>::Insert(BiTNode2<Q>** Root,Q key)
{
	BiTNode2<Q>* p=nullptr, * s=nullptr;
	if (!Search(*Root, key, nullptr, &p)) /* ���Ҳ��ɹ� */
	{
		s = new BiTNode2<Q>;
		s->data = key;
		s->lchild = s->rchild = nullptr;
		if (p==nullptr)//����û������ʱ
			*Root = s;			/*  ����sΪ�µĸ��� */
		else if (key < p->data)
			p->lchild = s;	/*  ����sΪ���� */
		else
			p->rchild = s;  /*  ����sΪ�Һ��� */
		return TRUE;
	}
	else
		return FALSE;  /*  �������йؼ�����ͬ�Ľ�㣬���ٲ��� */
}


template<typename Q>
/* �Ӷ�����������ɾ�����p�����ؽ���������������� */
Status BinarySortTree<Q>::Delete_Node(BiTNode2<Q>** p)
{
	BiTNode2<Q>* q,* s;
	if ((*p)->rchild == NULL) /* ����������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧) */
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if ((*p)->lchild == NULL) /* ֻ���ؽ����������� */
	{
		q = *p; *p = (*p)->rchild; free(q);
	}
	else /* �������������� */
	{
		q = *p; s = (*p)->lchild;
		while (s->rchild) /* ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ���� */
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data; /*  sָ��ɾ����ֱ��ǰ��������ɾ���ǰ����ֵȡ����ɾ����ֵ�� */
		if (q != *p)
			q->rchild = s->lchild; /*  �ؽ�q�������� */
		else
			q->lchild = s->lchild; /*  �ؽ�q�������� */
		free(s);
	}
	return TRUE;
}

/* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ��, */
/* ������TRUE�����򷵻�FALSE�� */
template<typename Q>
Status BinarySortTree<Q>::Delete(BiTNode2<Q>** Root,Q key)
{
	if (!*Root) /* �����ڹؼ��ֵ���key������Ԫ�� */
		return FALSE;
	else
	{
		if (key == (*Root)->data) /* �ҵ��ؼ��ֵ���key������Ԫ�� */
			return Delete_Node(Root);
		else if (key < (*Root)->data)
			return Delete(&(*Root)->lchild, key);
		else
			return Delete(&(*Root)->rchild, key);

	}
}

//ǰ�����
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

//�������
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


//�������
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
Status BinarySortTree<Q>::PreOrder2(BiTNode2<Q>* Root)//ǰ������ķǵݹ�ʵ��
{
	stack<BiTNode2<Q>*> s1;
	if (Root != nullptr)//�Ƚ��������ĸ��ڵ�push��ջ
	{
		s1.push(Root);
	}
	else
		return FALSE;
	while (!s1.empty())//ջ��Ϊ�յ������£�ִ��һ��ѭ��
	{
		BiTNode2<Q>* top = s1.top();//�ȶ�top->_right�����ж��Ƿ���ջ���ٶ�top->_left�����ж��Ƿ���ջ
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
Status BinarySortTree<Q>::InOrder2(BiTNode2<Q>* Root )//��������ķǵݹ�ʵ��
{
	if (Root == nullptr)//���жϸ��ڵ��Ƿ�Ϊ��
	{
		return FALSE;
	}
	stack<BiTNode2<Q>*> s2;
	while (Root != nullptr || !s2.empty())
	{
		while (Root != nullptr)
		{
			s2.push(Root);
			Root = Root->lchild;//ջ���ڵ㣺�ȱ���ýڵ�
		}
		BiTNode2<Q>* top = s2.top();
		cout << top->data << " ";
		s2.pop();
		Root = top->rchild;
	}
	return TRUE;
}




template<typename Q>
Status BinarySortTree<Q>::PostOrder2(BiTNode2<Q>* Root)//��������ķǵݹ�ʵ��
{
	if (Root == nullptr)//�жϸ��ڵ��Ƿ�Ϊ��
	{
		return FALSE;
	}
	stack<BiTNode2<Q>*> s3;
	BiTNode2<Q>* lastVisited = nullptr;
	while (Root != nullptr || !s3.empty())
	{
		while (Root != nullptr)//���ø��ڵ��ջ
		{
			s3.push(Root);
			Root = Root->lchild;
		}
		BiTNode2<Q>* top = s3.top();//����������һ���Ľڵ�
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

	//����  
	queue<BiTNode2<Q>*> q1;

	//���ڵ����  
	q1.push(tree);

	//���в���ѭ��  
	while (!q1.empty()) 
	{

		//�����ͷԪ�� 
		tree = q1.front();

		//���ʶ�ͷָ��Ľ������
		cout<<tree->data<<" ";

		//��ͷ����
		q1.pop();

		//��������Ϊ�գ������������  
		if (tree->lchild != nullptr) 
		{
			q1.push(tree->lchild);
		}

		//���������գ������������  
		if (tree->rchild != nullptr) 
		{
			q1.push(tree->rchild);
		}
	}
	return TRUE;
}
