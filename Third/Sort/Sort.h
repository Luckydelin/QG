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

	//��������
	//--����
	void Insert_FallSoft(vector<int>& v1);
	//--����
	void Insert_SoarSoft(vector<int>& v1);

	//�鲢����
	//--�ݹ�ϲ�����
	void MergeArray(vector<int>& v1, vector<int>& v2, int i, int mid, int len);
	//--�ݹ�鲢
	void MergeSort_Recursion(vector<int>& v1, vector<int>& v2, int low, int high);
	//--�ǵݹ�ϲ�����
	void MergePass(vector<int>& v1, vector<int>& v2, int k, int len);
	//--�ǵݹ�鲢
	void MergeSort(vector<int>& v1, int len);

	//��������
	//--������
	int Partition(vector<int>& v1, int low, int high);
	//--�ݹ����
	void QuickSort_Recursion(vector<int>& v1, int low, int high);
	//--�ǵݹ����
	void QuickSort(vector<int>& v1, int low, int high);

	//��������
	vector<int> CountSort(vector<int>& v1);

	//��������
	//--�������λ��
	int Max_Digit(vector<int>& v1);
	//--��������
	void RadixCountSort(vector<int>& v1);

	//ϣ������
	//--����
	void Shell_FallSort(vector<int>& v1);
	//--����
	void Shell_SoarSort(vector<int>& v1);

	//������
	//--�ѵ���
	void Heap_FallAdjust(vector<int>& v1, int i, int len);
	//--����
	void Heap_FallSort(vector<int>& v1);
	//--�ѵ���
	void Heap_SoarAdjust(vector<int>& v1, int i, int len);
	//--����
	void Heap_SoarSort(vector<int>& v1);


	//Ӧ����1--��ɫ����
	void ColorSort();
	//Ӧ����2--��kС/��Ԫ��
	void Test2();
	//Ӧ����2--��kС/��Ԫ�ص�������

	int QuickSort_FindK(vector<int>& v1, int low, int high, int k);
	//�ж��Ƿ���int��
	bool ISInt(string& str);
	//�ж��Ƿ�Ϊ����������֡����򷵻ض��ڵ����֣����򷵻�-1
	int ISNumber(char* s);
	//���ڷ�Χfor�������ȫ������
	void Print(const vector<int>& v1);
	
};

#endif