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

		getline(cin, select);//ʹ��getline����������տո�
		while (!TFInt(select))//������int�����֣�Ҫ������������
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
		case 1:cat->CreateLStack(); break;
		case 2:cat->pushLStack(); break;
		case 3:cat->popLStack(PopElem); break;
		case 4:cat->getTopLStack(TopElem); break;
		case 5:cat->clearLStack(); break;
		case 6:cat->destroyLStack(); break;
		case 7:cat->TraverseLinkStack(); break;	
		default:cout << "�����������������룡" << endl; break;
		}
		system("pause");//�������������
		system("cls");
	}
}
bool Menu::TFInt(string & str)//�ж��Ƿ�Ϊint������
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i]>'9')
		{
			cout << "���벻Ϊ int�� ���֣�";//������int�����֣�ֱ�ӷ���false
			cout << "���������룡" << endl;
			return false;
		}
	}
	return true;
}
void Menu::MenuShow()//�˵�չʾ����
{
	cout << endl << endl;
	cout << "\t\t-----------------------****************------------------------" << endl;
	cout << "\t\t=======================**ϵͳ�˵�����**========================" << endl;
	cout << "\t\t-----------------------****************------------------------" << endl;
	cout << "\t\t -1.�˳�ϵͳ" ;
	cout << "\t 1.����ջ";
	cout << "\t\t 2.��ջ" << endl;;
	cout << "\t\t 3.��ջ" ;
	cout << "\t\t\t 4.����ջ��Ԫ��" ;
	cout << "\t\t 5.���ջ" << endl;
	cout << "\t\t 6.����ջ" ;
	cout << "\t\t 7.����ջ" << endl;
	cout << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t===============================================================" << endl;

}