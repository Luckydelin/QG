#pragma once
#pragma once



#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


#define LH +1 // ��� 
#define EH 0  //  �ȸ�
#define RH -1 //  �Ҹ� 

typedef int Status;	//Status�Ǻ���������, ��ֵ�Ǻ������״̬���룬��OK��
#include <iostream>
using namespace std;

//�������Ķ����������ඨ�� 
template<typename Q>
class BiTNode2	// ���ṹ 
{
public:
	Q data;	// ������� 
	int bf; //  ����ƽ������ 
	BiTNode2<Q>* lchild, * rchild;	// ���Һ���ָ��
};

template<typename Q>
class Tree
{
public:
	//����
	virtual Status Search(BiTNode2<Q>* T, Q key, BiTNode2<Q>* f, BiTNode2<Q>** p) = 0;
	//����
	virtual Status Insert(BiTNode2<Q>** Root, Q key) = 0;
	//ɾ��
	virtual Status Delete(BiTNode2<Q>** Root, Q key) = 0;
	//�������
	virtual Status PreOrder(BiTNode2<Q>* T) = 0;
	//�������
	virtual Status InOrder(BiTNode2<Q>* T) = 0;
	//�������
	virtual Status PostOrder(BiTNode2<Q>* T) = 0;
	//��α���
	virtual Status LevelOrder(BiTNode2<Q>* T) = 0;
	//����������ǵݹ飩
	virtual Status PreOrder2(BiTNode2<Q>* T) = 0;
	//����������ǵݹ飩
	virtual Status InOrder2(BiTNode2<Q>* T) = 0;
	//����������ǵݹ飩
	virtual Status PostOrder2(BiTNode2<Q>* T) = 0;
public:
	BiTNode2<Q>* Root;
};
