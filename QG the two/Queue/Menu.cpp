#include"Menu.h"
using namespace std;
void Menu::menu()
{
	LQueue<int>* dog = new LQueue<int>;
	int e=1;
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
		case 1:dog->CreateLQueue(); break;
		case 2:dog->EnLQueue(); break;
		case 3:dog->DeLQueue(); break;
		case 4:dog->GetHeadLQueue(e); break;
		case 5:dog->TraverseLQueue(); break;
		case 6:dog->ClearLQueue(); break;
		case 7:dog->DestoryLQueue(); break;
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
		if (str[i] < '0' || str[i]>'9')//������int�����֣�ֱ�ӷ���false
		{
			cout << "���벻Ϊ int�� ���֣�";
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
	cout << "\t\t\t -1.�˳�ϵͳ" ;
	cout << "\t\t 1.��������" << endl;;
	cout << "\t\t\t 2.���";
	cout << "\t\t\t\t 3.����" << endl;;
	cout << "\t\t\t 4.���ض�ͷԪ��";
	cout << "\t\t\t 5.��������"<< endl;
	cout << "\t\t\t 6.��ն���" ;
	cout << "\t\t\t 7.���ٶ���" << endl;;
	
	cout << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t===============================================================" << endl;

}