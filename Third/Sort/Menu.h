#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include"Sort.h"
#include<map>

#include"Sort.h"
class Menu
{
public:
	Menu();
	//---��ʾ�˵�
	void ShowMenu();

	//---�˵����Ⱥ���
	void menu();

	//---������������
	void Data_Test1(Sort cat);

	//---������������--��ʱ������������
	void SpendTime(vector<int>v1, Sort cat);

	//---����С����������
	void Data_Test2(Sort cat);

	//---���ؼ�¼������ȡ�ļ���
	void ShowRecord();

	//---��ʾ��¼
	void LoadRecord();

private:

	bool FileIsEmpty;//�ļ�״̬�Ƿ�Ϊ��

	map<int, vector<string>> Record;//�����ȡ�ļ�������
};
	
#endif
