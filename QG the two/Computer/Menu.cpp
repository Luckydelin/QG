#include"Menu.h"
using namespace std;
void Menu::menu()
{
	while (true)
	{
		MenuShow();
		string select;
		getline(cin, select);//����getline�������տո�
		while (!TFInt(select))//�ж��Ƿ�Ϊint������
		{
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
		case 1:Computer(); break;
		default:cout << "�����������������룡" << endl; break;
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
			cout << "���벻Ϊ int�� ���֣�";
			cout << "���������룡" << endl;
			return false;
		}
	}
	return true;
}
void Menu::MenuShow()
{
	cout << endl << endl;
	cout << "\t\t-----------------------********************------------------------" << endl;
	cout << "\t\t=======================***��ӭʹ�ü�����***========================" << endl;
	cout << "\t\t-----------------------********************------------------------" << endl;
	cout << "\t\t -1.�˳�ϵͳ" ;
	cout << "\t 1.ʹ�ü�����" << endl;
	cout << "\t\t-------------------------------------------------------------------" << endl;
	cout << "\t\t===================================================================" << endl;

}
string Menu::Computer()
{
	LinkStack<char> s1;//����׺ת��Ϊ��׺����Ҫ��ջ
	LinkStack<int> s2;//����׺���ʽ������������Ҫ��ջ

	string str1, str2;//str1Ϊ��׺���ʽ��str2Ϊ��׺���ʽ
	cout << "������������ʽ(��enter��������):(��ע�����ֲ��ܳ���9)" << endl;
	getline(cin, str1);
	str2.clear();
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] >= '0' && str1[i] <= '9')//��Ϊ����ֱ�Ӳ���str2��
			str2.push_back(str1[i]);
		else
		{
			if (str1[i] == '(' || s1.isEmptyLStack() == Status::SUCCESS)//��Ϊ�����Ż���ջΪ������ջ
				s1.pushLStack(str1[i]);
			else
			{
				if (str1[i] == ')')//��������������������ƥ����������ջ���������������������
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
				else//�����Ƚ���������ȼ�
				{
					char temp1;
					s1.getTopLStack(temp1);
					if (temp1 == '*' || temp1 == '/')
					{
						if (str1[i] == '*' || str1[i] == '/')//������ջ������������ȼ�����ջ
							s1.pushLStack(str1[i]);
						else
						{
							while (s1.count)//������ջ����������ȼ����ջ�����е��������ջ
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
						s1.pushLStack(str1[i]);//ͬΪ�ӻ������ջ
					}
				}
			}
		}
	}
	if (s1.count)//��ջ��ʣ����������ջ
	{
		while (s1.count)
		{
			char tmp;
			s1.popLStack(tmp);
			str2.push_back(tmp);
		}
	}
	cout <<"��׺���ʽΪ��"<< str2 << endl;

	//-------------------------����׺���ʽ��������-------------------------------------------------
	int temp1, temp2, temp3=0;
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] >= '0' && str2[i] <= '9')//��char��ת��Ϊint
		{
			int t = str2[i] -48;
			s2.pushLStack(t);
		}
		else
		{
			if (s2.count >= 2)//-----------------------------------������������ջ���������ֽ�������
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
			s2.pushLStack(temp3);//������ٴ�ѹջ
		}
	}
	int result;
	s2.getTopLStack(result);//ջ����Ϊ�����
	cout << "���Ϊ��" << result << endl;

	return str2;
}