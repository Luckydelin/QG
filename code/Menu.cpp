#include"Menu.h"
void Menu::ShowMenu()
{
	cout << endl << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t===============**一级菜单**===============" << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t\t\t-1.退出系统" << endl;
	cout << "\t\t\t\t\t\t1.二叉排序数" << endl;
	cout << "\t\t\t\t\t\t2.AVL树" << endl;
	cout << "\t\t\t\t\t\t3.大顶堆" << endl;
	cout << "\t\t\t\t\t\t4.小顶堆" << endl;
	cout << "\t\t\t\t------------------------------------------" << endl;
	cout << "\t\t\t\t==========================================" << endl;
}
void Menu::menu()//一级菜单
{
	MaxHeap<int> cat1;

	MinHeap<int> cat2;

	AVLTree<int> dog2;

	BinarySortTree<int> dog1;
	while (true)
	{
		ShowMenu();//显示菜单

		string select;
		getline(cin, select);//利用getline函数吸收空格
		while (!ISInt(select))//判断是否为int型数字
		{
			cout << "输入有误！";
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
		case 1:
		{
			system("cls");
			if (TreeMenu(dog1) == -1)
			{
				cout << "欢迎你下次使用！祝你生活愉快！再见！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
				break;
		}
		case 2:
		{
			system("cls");
			if (TreeMenu(dog2) == -1)
			{
				cout << "欢迎你下次使用！祝你生活愉快！再见！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
				break;
		}
		case 3:
		{
			system("cls");
			if (HeapMenu(cat1) == -1)
			{
				cout << "欢迎你下次使用！祝你生活愉快！再见！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
				break;
		}
		case 4:
		{
			system("cls");
			if (HeapMenu(cat2) == -1)
			{
				cout << "欢迎你下次使用！祝你生活愉快！再见！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
				break;
		}
		default:cout << "输入有误！请重新输入！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}
void Menu::HeapShow()
{
	cout << endl << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t===============**二级菜单**===============" << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t\t\t-1.退出系统" << endl;
	cout << "\t\t\t\t\t\t1.堆排序" << endl;
	cout << "\t\t\t\t\t\t2.插入某元素" << endl;
	cout << "\t\t\t\t\t\t3.删除某元素" << endl;
	cout << "\t\t\t\t\t\t4.得到堆顶元素" << endl;
	cout << "\t\t\t\t\t\t5.遍历堆" << endl;
	cout << "\t\t\t\t\t\t6.上级菜单" << endl;
	cout << "\t\t\t\t------------------------------------------" << endl;
	cout << "\t\t\t\t==========================================" << endl;
}
int Menu::HeapMenu(Heap<int>& H)//二级菜单
{
	while (true)
	{
		
		HeapShow();//显示菜单

		string select;
		getline(cin, select);//利用getline函数吸收空格
		while (!ISInt(select))//判断是否为int型数字
		{
			cout << "输入有误！";
			cout << "请重新输入！" << endl;
			getline(cin, select);
		}

		int num = atoi(select.c_str());//将int型的字符串全化为数字，用c_str（）函数将string类型转化为const char* 型，再将其用atoi()函数由const char*类型转化为int型

		switch (num)
		{

		case -1:
		{
			return -1;
		}
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:_Heap(H, num); break;
		case 6:return 0;
		default:cout << "输入有误！请重新输入！" << endl;
			break;

		}
		system("pause");
		system("cls");
	}
}
void Menu::_Heap(Heap<int>& H,int num)//实现多态
{
	switch (num)
	{
	case 1:
	{
		if (!H.Sort())
		{
			cout << "堆为空！" << endl;
			break;
		}
		cout << "排序后的数据为：" << endl;
		H.vist();
		break;
	}
	case 2:
	{
		cout << "请输入你要插入的元素：" << endl;
		char str[100];
		cin >> str;

		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			H.Insert(num);
			cout << "插入成功！" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
		else
		{
			cout << "输入有误" << endl;
			while (getchar() != '\n')
			{
				;
			}	
			break;
		}
	
	}
	case 3:

	{
		cout << "请输入你要删除的元素：" << endl;
		char str[100];
		cin >> str;

		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			if (!H.Delete(num))
			{
				cout << "不存在该元素！" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
			else
			{
				cout << "删除成功!" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
				
		}
		else
		{
			cout << "输入有误" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
	}
	case 4:
	{
		if (H.GetTop() == 1000000000)
		{
			cout << "堆为空！" << endl;
			break;
		}
		else
			cout << "堆顶元素为：" << H.GetTop() << endl;;
		break;
	}
	case 5:
	{
		
		if (!H.vist())
		{
			cout << "堆为空！" << endl;
		}

		break;
	}
	}
}
void Menu::TreeShow()
{
	cout << endl << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t===============**二级菜单**===============" << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t\t\t-1.退出系统" << endl;
	cout << "\t\t\t\t\t\t1.查找" << endl;
	cout << "\t\t\t\t\t\t2.插入" << endl;
	cout << "\t\t\t\t\t\t3.删除" << endl;
	cout << "\t\t\t\t\t\t4.前序遍历" << endl;
	cout << "\t\t\t\t\t\t5.中序遍历" << endl;
	cout << "\t\t\t\t\t\t6.后序遍历" << endl;
	cout << "\t\t\t\t\t\t7.前序遍历（非递归）" << endl;
	cout << "\t\t\t\t\t\t8.中序遍历（非递归）" << endl;
	cout << "\t\t\t\t\t\t9.后序遍历（非递归）" << endl;
	cout << "\t\t\t\t\t\t10.层序遍历" << endl;
	cout << "\t\t\t\t\t\t11.上一级菜单" << endl;
	cout << "\t\t\t\t------------------------------------------" << endl;
	cout << "\t\t\t\t==========================================" << endl;
}
int Menu::TreeMenu(Tree<int>& T )//二级菜单
{
	while (true)
	{

		TreeShow();//显示菜单

		string select;
		getline(cin, select);//利用getline函数吸收空格
		while (!ISInt(select))//判断是否为int型数字
		{
			cout << "输入有误！";
			cout << "请重新输入！" << endl;
			getline(cin, select);
		}

		int num = atoi(select.c_str());//将int型的字符串全化为数字，用c_str（）函数将string类型转化为const char* 型，再将其用atoi()函数由const char*类型转化为int型

		switch (num)
		{

		case -1:
		{
			return -1;
		}
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:_Tree(T, num); break;
		case 11:return 0;
		default:cout << "输入有误！请重新输入！" << endl;
			break;

		}
		system("pause");
		system("cls");
	}
}
void Menu::_Tree(Tree<int>& T, int num)//实现多态
{
	
	switch (num)
	{
	case 1:
	{
		cout << "请输入你要查找的元素：" << endl;
		char str[100];
		cin >> str;
		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			BiTNode2<int>* p;
			if (T.Search(T.Root, num, nullptr, &p))
			{
				cout << "存在该元素！" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
			else
			{
				cout << "不存在该元素" << endl;
				while (getchar() != '\n')
				{
					;
				}	
				break;
			}
		}
		else
		{
			cout << "输入有误" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
	}
	case 2:
	{
		cout << "请输入你要插入的元素：" << endl;
		char str[100];
		cin >> str;

		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			T.Insert(&T.Root,num);
			cout << "插入成功！" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
		else
		{
			cout << "输入有误" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
			
	}
	case 3:

	{
		cout << "请输入你要删除的元素：" << endl;
		char str[100];
		cin >> str;

		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			if (!T.Delete(&T.Root,num))
			{
				cout << "不存在该元素！" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
			else
			{
				cout << "删除成功!" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
				
		}
		else
		{
			cout << "输入有误" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
			
	}
	case 4:
	{
		if (!T.PreOrder(T.Root))
			cout << "树为空！" << endl;
		cout << endl;
		break;
	}
	case 5:
	{
		if(!T.InOrder(T.Root))
			cout << "树为空！" << endl;
		cout << endl;
		break;
	}
	case 6:
	{
		if (!T.PostOrder(T.Root))
			cout << "树为空！" << endl;
		cout << endl;
		break;
	}
	case 7:
	{
		if (!T.PreOrder2(T.Root))
			cout << "树为空！" << endl;
		cout << endl;
		break;
	}
	case 8:
	{ 
		if (!T.InOrder2(T.Root))
			cout << "树为空！" << endl;
		cout << endl;
		break;
	}
	case 9:
	{
		if (!T.PostOrder2(T.Root))
			cout << "树为空！" << endl;
		cout << endl;
		break;
	}
	case 10:
	{
		if (!T.LevelOrder(T.Root))
			cout << "树为空！" << endl;
		cout << endl;
		break;
	}

	}
}
bool Menu::ISInt(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')//负号跳过本次循环
			continue;
		if (str[i] < '0' || str[i]>'9')//若为英文或符号
		{
			return false;
		}
	}
	return true;
}
//------判断是否是大于等于0的数字，不是则返回-1，是则返回对应的数字
int Menu::ISNumber(char* s)//------------------------------------------------------判断输入是否为数字----若是则返回对应的数字--------否则返回-1----------------------
{
	int p = -1, i = 0, flag = 0;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] > '9' || s[i] < '0')
			flag = 1;
	if (flag == 1)//-------------------------------------如果是s[i]有一个英文或符号，说明不是数字，返回-1--------------------------- 
	{
		return p;
	}
	else//------------------------------------------否则返回对应的数字------并转为int 类型 --------------------------
	{
		p++;
		for (i = 0; s[i] != '\0'; i++)
		{
			if (flag == 0)
				p += s[i] - '0';//------------------------------第一个数字相加到p-------------------------------- 
			else
			{
				p *= 10;//----------------------------------其他位数则乘以10再加上个位---------------------------------- 
				p += s[i] - '0';
			}
			flag++;
		}
		return (p);
	}
}