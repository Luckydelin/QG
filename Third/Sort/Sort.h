#pragma once
#ifndef _SORT_H_
#define _SORT_H_
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<ctime>

class Sort
{
public:

	//插入排序
	//--降序
	void Insert_FallSoft(vector<int>& v1);
	//--升序
	void Insert_SoarSoft(vector<int>& v1);

	//归并排序
	//--递归合并数组
	void MergeArray(vector<int>& v1, vector<int>& v2, int i, int mid, int len);
	//--递归归并
	void MergeSort_Recursion(vector<int>& v1, vector<int>& v2, int low, int high);
	//--非递归合并数组
	void MergePass(vector<int>& v1, vector<int>& v2, int k, int len);
	//--非递归归并
	void MergeSort(vector<int>& v1, int len);

	//快速排序
	//--找驱轴
	int Partition(vector<int>& v1, int low, int high);
	//--递归快排
	void QuickSort_Recursion(vector<int>& v1, int low, int high);
	//--非递归快排
	void QuickSort(vector<int>& v1, int low, int high);

	//计数排序
	vector<int> CountSort(vector<int>& v1);

	//基数排序
	//--返回最大位数
	int Max_Digit(vector<int>& v1);
	//--基数排序
	void RadixCountSort(vector<int>& v1);

	//希尔排序
	//--降序
	void Shell_FallSort(vector<int>& v1);
	//--升序
	void Shell_SoarSort(vector<int>& v1);

	//堆排序
	//--堆调整
	void Heap_FallAdjust(vector<int>& v1, int i, int len);
	//--降序
	void Heap_FallSort(vector<int>& v1);
	//--堆调整
	void Heap_SoarAdjust(vector<int>& v1, int i, int len);
	//--升序
	void Heap_SoarSort(vector<int>& v1);


	//应用题1--颜色排序
	void ColorSort();
	//应用题2--找k小/大元素
	void Test2();
	//应用题2--找k小/大元素的排序函数

	int QuickSort_FindK(vector<int>& v1, int low, int high, int k);
	//判断是否是int型
	bool ISInt(string& str);
	//判断是否为大于零的数字。是则返回对于的数字，否则返回-1
	int ISNumber(char* s);
	//基于范围for输出容器全部数据
	void Print(const vector<int>& v1);
	
};

#endif