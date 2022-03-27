#include<string>
#include"LinkStack.hpp"
#include<iostream>
using namespace std;
class Menu
{
public:
	void menu();//菜单与各种函数调度的函数
	bool TFInt(string & str);//判断是否int型数字
	void MenuShow();//菜单展示界面
};