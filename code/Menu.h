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
	//一级菜单显示
	void ShowMenu();
	//一级菜单
	void menu();
	//二级菜单--堆
	void HeapShow();
	//二级菜单--堆显示
	int HeapMenu(Heap<int>& H);
	//实现堆多态
	void _Heap(Heap<int>& H,int num);
	//二级菜单--树显示
	void TreeShow();
	//二级菜单--树
	int  TreeMenu(Tree<int>& T);
	//多态实现--树
	void _Tree(Tree<int>& T,int num);
	//是否为数字，不是返回-1，是则返回对应数字
	int ISNumber(char* s);
	//判断是否为整形
	bool ISInt(string& str);
};
