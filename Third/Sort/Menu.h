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
	//---显示菜单
	void ShowMenu();

	//---菜单调度函数
	void menu();

	//---大数据量排序
	void Data_Test1(Sort cat);

	//---大数据量排序--计时和运行排序函数
	void SpendTime(vector<int>v1, Sort cat);

	//---大量小数据量排序
	void Data_Test2(Sort cat);

	//---加载记录（即读取文件）
	void ShowRecord();

	//---显示记录
	void LoadRecord();

private:

	bool FileIsEmpty;//文件状态是否为空

	map<int, vector<string>> Record;//保存读取文件的数据
};
	
#endif
