#include"Menu.h"
using namespace std;
void Menu::menu()
{
	while (true)
	{
		MenuShow();
		string select;
		getline(cin, select);//利用getline函数吸收空格
		while (!TFInt(select))//判断是否为int型数字
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
		case 1:Computer(); break;
		default:cout << "输入有误！请重新输入！" << endl; break;
		}
		system("pause");
		system("cls");
	}
}
bool Menu::TFInt(string & str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i]>'9')
		{
			cout << "输入不为 int型 数字！";
			cout << "请重新输入！" << endl;
			return false;
		}
	}
	return true;
}
void Menu::MenuShow()
{
	cout << endl << endl;
	cout << "\t\t-----------------------********************------------------------" << endl;
	cout << "\t\t=======================***欢迎使用计算器***========================" << endl;
	cout << "\t\t-----------------------********************------------------------" << endl;
	cout << "\t\t -1.退出系统" ;
	cout << "\t 1.使用计算器" << endl;
	cout << "\t\t-------------------------------------------------------------------" << endl;
	cout << "\t\t===================================================================" << endl;

}
string Menu::Computer()
{
	LinkStack<char> s1;//将中缀转化为后缀所需要的栈
	LinkStack<int> s2;//将后缀表达式进行运算所需要的栈

	string str1, str2;//str1为中缀表达式，str2为后缀表达式
	cout << "请输入运算表达式(按enter启动运算):(备注：数字不能超过9)" << endl;
	getline(cin, str1);
	str2.clear();
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] >= '0' && str1[i] <= '9')//若为数字直接插入str2中
			str2.push_back(str1[i]);
		else
		{
			if (str1[i] == '(' || s1.isEmptyLStack() == Status::SUCCESS)//若为左括号或链栈为空则入栈
				s1.pushLStack(str1[i]);
			else
			{
				if (str1[i] == ')')//遇到右括号则将与左括号匹配的运算符入栈，而左右括号运算符则丢弃
				{
					while (s1.count)
					{
						char tmp;
						s1.popLStack(tmp);
						if (tmp == '(')
							break;
						else
							str2.push_back(tmp);
					}
				}
				else//两两比较运算符优先级
				{
					char temp1;
					s1.getTopLStack(temp1);
					if (temp1 == '*' || temp1 == '/')
					{
						if (str1[i] == '*' || str1[i] == '/')//若高于栈顶的运算符优先级则入栈
							s1.pushLStack(str1[i]);
						else
						{
							while (s1.count)//若低于栈中运算符优先级则把栈中所有的运算符出栈
							{
								char temp;
								s1.popLStack(temp);
								str2.push_back(temp);
							}
							s1.pushLStack(str1[i]);
						}
					}
					else
					{
						s1.pushLStack(str1[i]);//同为加或减，入栈
					}
				}
			}
		}
	}
	if (s1.count)//将栈内剩余的运算符出栈
	{
		while (s1.count)
		{
			char tmp;
			s1.popLStack(tmp);
			str2.push_back(tmp);
		}
	}
	cout <<"后缀表达式为："<< str2 << endl;

	//-------------------------将后缀表达式进行运算-------------------------------------------------
	int temp1, temp2, temp3=0;
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] >= '0' && str2[i] <= '9')//将char型转化为int
		{
			int t = str2[i] -48;
			s2.pushLStack(t);
		}
		else
		{
			if (s2.count >= 2)//-----------------------------------有两个数字则将栈顶两个数字进行运算
			{
				s2.popLStack(temp1);
				s2.popLStack(temp2);
				switch (str2[i])
				{
				case'+':temp3 = temp2 + temp1; break;
				case'-':temp3 = temp2 - temp1; break;
				case'*':temp3 = temp2 * temp1; break;
				case'/':temp3 = temp2 / temp1; break;
				}
			}
			s2.pushLStack(temp3);//运算后再次压栈
		}
	}
	int result;
	s2.getTopLStack(result);//栈顶即为最后结果
	cout << "结果为：" << result << endl;

	return str2;
}