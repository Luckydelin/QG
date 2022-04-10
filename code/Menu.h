#pragma once

#include<iostream>
using namespace std;
#include <string>

#include"Tree.hpp"
#include"AVLTree.hpp"
#include"BinarySortTree.hpp"
#include"Heap.hpp"
#include"MaxHeap.hpp"
#include"MinHeap.hpp"


class Menu
{
public:
	//һ���˵���ʾ
	void ShowMenu();
	//һ���˵�
	void menu();
	//�����˵�--��
	void HeapShow();
	//�����˵�--����ʾ
	int HeapMenu(Heap<int>& H);
	//ʵ�ֶѶ�̬
	void _Heap(Heap<int>& H,int num);
	//�����˵�--����ʾ
	void TreeShow();
	//�����˵�--��
	int  TreeMenu(Tree<int>& T);
	//��̬ʵ��--��
	void _Tree(Tree<int>& T,int num);
	//�Ƿ�Ϊ���֣����Ƿ���-1�����򷵻ض�Ӧ����
	int ISNumber(char* s);
	//�ж��Ƿ�Ϊ����
	bool ISInt(string& str);
};
