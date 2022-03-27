#include"Menu.h"

using namespace std;
void Menu::menu()
{

	LinkStack<int>* cat = new LinkStack<int>;
	int TopElem, PopElem;
	while (true)
	{
		MenuShow();
		string select;

		getline(cin, select);//使用getline函数方便接收空格
		while (!TFInt(select))//若不是int型数字，要求其重新输入
		{
			cout << "请重新输入！" << endl;
			getline(cin, select);
		}

		int num = atoi(select.c_str());//将int型的字符串全化为数字，用c_str（）函数将string类型转化为const char* 型，再将其用atoi()函数由const char*类型转化为int型

		switch (num)
		{

		case -1:
		{
			cout << "欢迎你下次使用！祝你生活愉快！再见！" << endl;
			system("pause");
			system("cls");
			return;
		}
		case 1:cat->CreateLStack(); break;
		case 2:cat->pushLStack(); break;
		case 3:cat->popLStack(PopElem); break;
		case 4:cat->getTopLStack(TopElem); break;
		case 5:cat->clearLStack(); break;
		case 6:cat->destroyLStack(); break;
		case 7:cat->TraverseLinkStack(); break;	
		default:cout << "输入有误！请重新输入！" << endl; break;
		}
		system("pause");//定格和清屏操作
		system("cls");
	}
}
bool Menu::TFInt(string & str)//判断是否为int型数字
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i]>'9')
		{
			cout << "输入不为 int型 数字！";//若不是int型数字，直接返回false
			cout << "请重新输入！" << endl;
			return false;
		}
	}
	return true;
}
void Menu::MenuShow()//菜单展示界面
{
	cout << endl << endl;
	cout << "\t\t-----------------------****************------------------------" << endl;
	cout << "\t\t=======================**系统菜单界面**========================" << endl;
	cout << "\t\t-----------------------****************------------------------" << endl;
	cout << "\t\t -1.退出系统" ;
	cout << "\t 1.创建栈";
	cout << "\t\t 2.入栈" << endl;;
	cout << "\t\t 3.出栈" ;
	cout << "\t\t\t 4.返回栈顶元素" ;
	cout << "\t\t 5.清空栈" << endl;
	cout << "\t\t 6.销毁栈" ;
	cout << "\t\t 7.遍历栈" << endl;
	cout << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t===============================================================" << endl;

}