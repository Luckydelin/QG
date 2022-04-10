#include"Menu.h"
void Menu::ShowMenu()
{
	cout << endl << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t===============**һ���˵�**===============" << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t\t\t-1.�˳�ϵͳ" << endl;
	cout << "\t\t\t\t\t\t1.����������" << endl;
	cout << "\t\t\t\t\t\t2.AVL��" << endl;
	cout << "\t\t\t\t\t\t3.�󶥶�" << endl;
	cout << "\t\t\t\t\t\t4.С����" << endl;
	cout << "\t\t\t\t------------------------------------------" << endl;
	cout << "\t\t\t\t==========================================" << endl;
}
void Menu::menu()//һ���˵�
{
	MaxHeap<int> cat1;

	MinHeap<int> cat2;

	AVLTree<int> dog2;

	BinarySortTree<int> dog1;
	while (true)
	{
		ShowMenu();//��ʾ�˵�

		string select;
		getline(cin, select);//����getline�������տո�
		while (!ISInt(select))//�ж��Ƿ�Ϊint������
		{
			cout << "��������";
			cout << "���������룡" << endl;
			getline(cin, select);
		}

		int num = atoi(select.c_str());//��int�͵��ַ���ȫ��Ϊ���֣���c_str����������string����ת��Ϊconst char* �ͣ��ٽ�����atoi()������const char*����ת��Ϊint��

		switch (num)
		{

		case -1:
		{
			cout << "��ӭ���´�ʹ�ã�ף��������죡�ټ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		case 1:
		{
			system("cls");
			if (TreeMenu(dog1) == -1)
			{
				cout << "��ӭ���´�ʹ�ã�ף��������죡�ټ���" << endl;
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
				cout << "��ӭ���´�ʹ�ã�ף��������죡�ټ���" << endl;
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
				cout << "��ӭ���´�ʹ�ã�ף��������죡�ټ���" << endl;
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
				cout << "��ӭ���´�ʹ�ã�ף��������죡�ټ���" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
				break;
		}
		default:cout << "�����������������룡" << endl;
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
	cout << "\t\t\t\t===============**�����˵�**===============" << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t\t\t-1.�˳�ϵͳ" << endl;
	cout << "\t\t\t\t\t\t1.������" << endl;
	cout << "\t\t\t\t\t\t2.����ĳԪ��" << endl;
	cout << "\t\t\t\t\t\t3.ɾ��ĳԪ��" << endl;
	cout << "\t\t\t\t\t\t4.�õ��Ѷ�Ԫ��" << endl;
	cout << "\t\t\t\t\t\t5.������" << endl;
	cout << "\t\t\t\t\t\t6.�ϼ��˵�" << endl;
	cout << "\t\t\t\t------------------------------------------" << endl;
	cout << "\t\t\t\t==========================================" << endl;
}
int Menu::HeapMenu(Heap<int>& H)//�����˵�
{
	while (true)
	{
		
		HeapShow();//��ʾ�˵�

		string select;
		getline(cin, select);//����getline�������տո�
		while (!ISInt(select))//�ж��Ƿ�Ϊint������
		{
			cout << "��������";
			cout << "���������룡" << endl;
			getline(cin, select);
		}

		int num = atoi(select.c_str());//��int�͵��ַ���ȫ��Ϊ���֣���c_str����������string����ת��Ϊconst char* �ͣ��ٽ�����atoi()������const char*����ת��Ϊint��

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
		default:cout << "�����������������룡" << endl;
			break;

		}
		system("pause");
		system("cls");
	}
}
void Menu::_Heap(Heap<int>& H,int num)//ʵ�ֶ�̬
{
	switch (num)
	{
	case 1:
	{
		if (!H.Sort())
		{
			cout << "��Ϊ�գ�" << endl;
			break;
		}
		cout << "����������Ϊ��" << endl;
		H.vist();
		break;
	}
	case 2:
	{
		cout << "��������Ҫ�����Ԫ�أ�" << endl;
		char str[100];
		cin >> str;

		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			H.Insert(num);
			cout << "����ɹ���" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
		else
		{
			cout << "��������" << endl;
			while (getchar() != '\n')
			{
				;
			}	
			break;
		}
	
	}
	case 3:

	{
		cout << "��������Ҫɾ����Ԫ�أ�" << endl;
		char str[100];
		cin >> str;

		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			if (!H.Delete(num))
			{
				cout << "�����ڸ�Ԫ�أ�" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
			else
			{
				cout << "ɾ���ɹ�!" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
				
		}
		else
		{
			cout << "��������" << endl;
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
			cout << "��Ϊ�գ�" << endl;
			break;
		}
		else
			cout << "�Ѷ�Ԫ��Ϊ��" << H.GetTop() << endl;;
		break;
	}
	case 5:
	{
		
		if (!H.vist())
		{
			cout << "��Ϊ�գ�" << endl;
		}

		break;
	}
	}
}
void Menu::TreeShow()
{
	cout << endl << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t===============**�����˵�**===============" << endl;
	cout << "\t\t\t\t---------------************---------------" << endl;
	cout << "\t\t\t\t\t\t-1.�˳�ϵͳ" << endl;
	cout << "\t\t\t\t\t\t1.����" << endl;
	cout << "\t\t\t\t\t\t2.����" << endl;
	cout << "\t\t\t\t\t\t3.ɾ��" << endl;
	cout << "\t\t\t\t\t\t4.ǰ�����" << endl;
	cout << "\t\t\t\t\t\t5.�������" << endl;
	cout << "\t\t\t\t\t\t6.�������" << endl;
	cout << "\t\t\t\t\t\t7.ǰ��������ǵݹ飩" << endl;
	cout << "\t\t\t\t\t\t8.����������ǵݹ飩" << endl;
	cout << "\t\t\t\t\t\t9.����������ǵݹ飩" << endl;
	cout << "\t\t\t\t\t\t10.�������" << endl;
	cout << "\t\t\t\t\t\t11.��һ���˵�" << endl;
	cout << "\t\t\t\t------------------------------------------" << endl;
	cout << "\t\t\t\t==========================================" << endl;
}
int Menu::TreeMenu(Tree<int>& T )//�����˵�
{
	while (true)
	{

		TreeShow();//��ʾ�˵�

		string select;
		getline(cin, select);//����getline�������տո�
		while (!ISInt(select))//�ж��Ƿ�Ϊint������
		{
			cout << "��������";
			cout << "���������룡" << endl;
			getline(cin, select);
		}

		int num = atoi(select.c_str());//��int�͵��ַ���ȫ��Ϊ���֣���c_str����������string����ת��Ϊconst char* �ͣ��ٽ�����atoi()������const char*����ת��Ϊint��

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
		default:cout << "�����������������룡" << endl;
			break;

		}
		system("pause");
		system("cls");
	}
}
void Menu::_Tree(Tree<int>& T, int num)//ʵ�ֶ�̬
{
	
	switch (num)
	{
	case 1:
	{
		cout << "��������Ҫ���ҵ�Ԫ�أ�" << endl;
		char str[100];
		cin >> str;
		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			BiTNode2<int>* p;
			if (T.Search(T.Root, num, nullptr, &p))
			{
				cout << "���ڸ�Ԫ�أ�" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
			else
			{
				cout << "�����ڸ�Ԫ��" << endl;
				while (getchar() != '\n')
				{
					;
				}	
				break;
			}
		}
		else
		{
			cout << "��������" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
	}
	case 2:
	{
		cout << "��������Ҫ�����Ԫ�أ�" << endl;
		char str[100];
		cin >> str;

		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			T.Insert(&T.Root,num);
			cout << "����ɹ���" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
		else
		{
			cout << "��������" << endl;
			while (getchar() != '\n')
			{
				;
			}
			break;
		}
			
	}
	case 3:

	{
		cout << "��������Ҫɾ����Ԫ�أ�" << endl;
		char str[100];
		cin >> str;

		int num;
		if (ISNumber(str) != -1)
		{
			num = ISNumber(str);
			if (!T.Delete(&T.Root,num))
			{
				cout << "�����ڸ�Ԫ�أ�" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
			else
			{
				cout << "ɾ���ɹ�!" << endl;
				while (getchar() != '\n')
				{
					;
				}
				break;
			}
				
		}
		else
		{
			cout << "��������" << endl;
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
			cout << "��Ϊ�գ�" << endl;
		cout << endl;
		break;
	}
	case 5:
	{
		if(!T.InOrder(T.Root))
			cout << "��Ϊ�գ�" << endl;
		cout << endl;
		break;
	}
	case 6:
	{
		if (!T.PostOrder(T.Root))
			cout << "��Ϊ�գ�" << endl;
		cout << endl;
		break;
	}
	case 7:
	{
		if (!T.PreOrder2(T.Root))
			cout << "��Ϊ�գ�" << endl;
		cout << endl;
		break;
	}
	case 8:
	{ 
		if (!T.InOrder2(T.Root))
			cout << "��Ϊ�գ�" << endl;
		cout << endl;
		break;
	}
	case 9:
	{
		if (!T.PostOrder2(T.Root))
			cout << "��Ϊ�գ�" << endl;
		cout << endl;
		break;
	}
	case 10:
	{
		if (!T.LevelOrder(T.Root))
			cout << "��Ϊ�գ�" << endl;
		cout << endl;
		break;
	}

	}
}
bool Menu::ISInt(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')//������������ѭ��
			continue;
		if (str[i] < '0' || str[i]>'9')//��ΪӢ�Ļ����
		{
			return false;
		}
	}
	return true;
}
//------�ж��Ƿ��Ǵ��ڵ���0�����֣������򷵻�-1�����򷵻ض�Ӧ������
int Menu::ISNumber(char* s)//------------------------------------------------------�ж������Ƿ�Ϊ����----�����򷵻ض�Ӧ������--------���򷵻�-1----------------------
{
	int p = -1, i = 0, flag = 0;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] > '9' || s[i] < '0')
			flag = 1;
	if (flag == 1)//-------------------------------------�����s[i]��һ��Ӣ�Ļ���ţ�˵���������֣�����-1--------------------------- 
	{
		return p;
	}
	else//------------------------------------------���򷵻ض�Ӧ������------��תΪint ���� --------------------------
	{
		p++;
		for (i = 0; s[i] != '\0'; i++)
		{
			if (flag == 0)
				p += s[i] - '0';//------------------------------��һ��������ӵ�p-------------------------------- 
			else
			{
				p *= 10;//----------------------------------����λ�������10�ټ��ϸ�λ---------------------------------- 
				p += s[i] - '0';
			}
			flag++;
		}
		return (p);
	}
}