#include"Menu.h"
#include<string>
#include<cmath>
#include<fstream>
Menu::Menu()
{
	FileIsEmpty = true;
}
//---��ʾ�˵�
void  Menu::ShowMenu()
{
	cout << endl << endl << endl << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t======================**һ���˵�ϵͳ**=========================" << endl;
	cout << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t-1.�˳�ϵͳ"<<endl;
	cout << "\t\t\t\t\t1.������������" << endl;
	cout << "\t\t\t\t\t2.����С����������" << endl;
	cout << "\t\t\t\t\t3.��һ��Ӧ����" << endl;
	cout << "\t\t\t\t\t4.�ڶ���Ӧ����" << endl;
	cout << "\t\t\t\t\t5.�������������¼" << endl;
	cout << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t===============================================================" << endl;
	cout << "\t\t---------------------------------------------------------------" << endl;
}
//---�˵����Ⱥ���

void Menu::menu()
{
	Sort cat;
	while (true)
	{
		ShowMenu();//��ʾ�˵�

		string select;
		getline(cin, select);//����getline�������տո�
		while (!cat.ISInt(select))//�ж��Ƿ�Ϊint������
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
		case 1:Data_Test1(cat); break;
		case 2:Data_Test2(cat); break;
		case 3:cat.ColorSort(); break;
		case 4:cat.Test2(); break;
		case 5:ShowRecord(); break;
		default:cout << "�����������������룡" << endl; 
			system("pause");
			system("cls");
			break;

		}
		
	}
}
//---������������
void Menu::Data_Test1(Sort cat)
{
	vector<int> v1;
	char select[100];
	cout << "��������Ҫ���ԵĲ�Σ�levelȡ0��3����" << endl;
	cout << "level=";
	int level;
	cin >> select;
	if ((level = cat.ISNumber(select)) == -1)
	{
		cout << "��������" << endl;
		while (getchar() != '\n')
		{
			;
		}
		system("pause");
		system("cls");
		return;
	}
	cout << endl;

	//����ѡ���Σ�ѡ��ͬ����������������
	if (level == 0)
	{

		for (int i = 0; i < 500; i++)
		{
			int num = (rand() % 100001);
			v1.push_back(num);
		}
		SpendTime(v1, cat);
	}
	else if (level == 1)
	{
	
		for (int i = 0; i < 10000; i++)
		{
			int num = (rand() % 100001);
			v1.push_back(num);
		}
		SpendTime(v1, cat);
	}
	else if (level == 2)
	{

		for (int i = 0; i < 50000; i++)
		{
			int num = (rand() % 500001);
			v1.push_back(num);
		}
		SpendTime(v1, cat);
		
	}
	else if (level == 3)
	{

		for (int i = 0; i < 200000; i++)
		{
			int num = (rand() % 2000001);
			v1.push_back(num);
		}
		SpendTime(v1, cat);
	}
	else
	{
		cout << "��������" << endl;
		return;
	}
	while (getchar() != '\n')
	{
		;
	}
	system("pause");
	system("cls");
	
}
//---������������--��ʱ������������
void Menu::SpendTime(vector<int>v1, Sort cat)
{
	vector<int> v2 = v1, v3 = v1, v4 = v1, v5 = v1, v6 = v1, v7 = v1, v8 = v1, v9 = v1, v10 = v1;

	double s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0, s10 = 0;//��������ȫ���������ʱ

	clock_t begin, end;//beginΪ��ʼʱ�䣬endΪ������ʱ��
	srand(time(NULL));//���������


	//�����ǽ��и������������ʱ
	begin = clock();
	cat.Insert_SoarSoft(v2);
	end = clock();
	s2 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "�������������ݣ�" << endl;
		cat.Print(v2);
	}
	
	cout << "����������ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.MergeSort_Recursion(v3, v3, 0, v3.size()-1);
	end = clock();
	s3 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "�鲢���������ݣ�" << endl;
		cat.Print(v3);
	}
	cout << "�鲢���򣨵ݹ飩��ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.MergeSort(v4, v4.size());
	end = clock();
	s4 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "�鲢���ǵݹ飩���������ݣ�" << endl;
		cat.Print(v4);
	}
	cout << "�鲢���򣨷ǵݹ飩��ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.QuickSort_Recursion(v5, 0, v5.size()-1);
	end = clock();
	s5 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "�������������ݣ�" << endl;
		cat.Print(v5);
	}
	cout << "�������򣨵ݹ飩��ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.QuickSort(v6, 0, v6.size()-1);
	end = clock();
	s6 += (double)(end - begin);
	if (v1.size() ==500)
	{
		cout << "���٣��ǵݹ飩���������ݣ�" << endl;
		cat.Print(v6);
	}
	cout << "�������򣨷ǵݹ飩��ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.CountSort(v7);
	end = clock();
	s7 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "�������������ݣ�" << endl;
		cat.Print(v7);
	}
	cout << "����������ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.RadixCountSort(v8);
	end = clock();
	s8 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "�������������ݣ�" << endl;
		cat.Print(v8);
	}
	cout << "����������ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.Shell_SoarSort(v9);
	end = clock();
	s9 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "ϣ�����������ݣ�" << endl;
		cat.Print(v9);
	}
	cout << "ϣ��������ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.Heap_SoarSort(v10);
	end = clock();
	s10 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "�����������ݣ�" << endl;
		cat.Print(v10);
		cout << endl;
	}
	cout << "��������ʱ��" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ�  -- д�ļ�

	//������д�뵽�ļ���
	double Spend[] = { s2,s3,s4,s5,s6,s7,s8,s9,s10 };
	ofs << "1" << ",";
	for (int i = 0; i < 9; i++)
	{
		ofs << Spend[i] << ",";
	}
	ofs << endl;


	//�ر��ļ�
	ofs.close();
	this->FileIsEmpty = false;
}
//---����С����������
void Menu::Data_Test2(Sort cat)
{

	vector<int> v1;
	
	char select[100];
	cout << "��������Ҫ���ԵĲ��(100^k��kȡ1��3)��" << endl;
	cout << "k=";
	int k;
	cin >> select;
	if ((k = cat.ISNumber(select)) == -1)
	{
		cout << "��������" << endl;
		while (getchar() != '\n')
		{
			;
		}
		system("pause");
		system("cls");
		return;
	}
	cout << endl;

	if (k != 1 && k != 2 && k != 3)
	{
		cout << "��������" << endl;
		return;
	}

	double count=pow(100, k);//pow����Ϊ�ݺ�������cmathͷ�ļ�������һΪ������������Ϊ����
	double s2 =0, s3=0, s4=0, s5 =0, s6=0, s7=0, s8=0 , s9=0 , s10=0;//��������ȫ���������ʱ
	while (count)
	{
		for (int i = 0; i < 100; i++)
		{
			int num = (rand() % 100001);
			v1.push_back(num);
		}
		vector<int> v2 = v1, v3 = v1, v4 = v1, v5 = v1, v6 = v1, v7 = v1, v8 = v1, v9 = v1, v10 = v1;

		clock_t begin, end;//beginΪ��ʼʱ�䣬endΪ������ʱ��
		srand(time(NULL));

		begin = clock();
		cat.Insert_SoarSoft(v2);
		end = clock();
		s2 +=end - begin;
		if (count == 4)
		{
			cout << "�������������ݣ�" << endl;
			cat.Print(v2);
			cout << endl;
		}

		begin = clock();
		cat.MergeSort_Recursion(v3, v3, 0, v3.size() - 1);
		end = clock();
		s3 += end - begin;
		if (count == 4)
		{
			cout << "�鲢���������ݣ�" << endl;
			cat.Print(v3);
			cout << endl;
		}

		begin = clock();
		cat.MergeSort(v4, v4.size());
		end = clock();
		s4 += end - begin;
		if (count == 4)
		{
			cout << "�鲢���ǵݹ飩���������ݣ�" << endl;
			cat.Print(v4);
			cout << endl;
		}

		begin = clock();
		cat.QuickSort_Recursion(v5, 0, v5.size() - 1);
		end = clock();
		s5 += end - begin;
		if (count == 4)
		{
			cout << "�������������ݣ�" << endl;
			cat.Print(v5);
			cout << endl;
		}

		begin = clock();
		cat.QuickSort(v6, 0, v6.size() - 1);
		end = clock(); 
		s6 += end - begin;
		if (count == 4)
		{
			cout << "���٣��ǵݹ飩���������ݣ�" << endl;
			cat.Print(v6);
			cout << endl;
		}

		begin = clock();
		cat.CountSort(v7);
		end = clock();
		s7 += end - begin;
		if (count == 4)
		{
			cout << "�������������ݣ�" << endl;
			cat.Print(v7);
			cout << endl;
		}

		begin = clock();
		cat.RadixCountSort(v8);
		end = clock();
		s8 += end - begin;
		if (count == 4)
		{
			cout << "�������������ݣ�" << endl;
			cat.Print(v8);
			cout << endl;
		}

		begin = clock();
		cat.Shell_SoarSort(v9);
		end = clock();
		s9 += end - begin;
		if (count== 4)
		{
			cout << "ϣ�����������ݣ�" << endl;
			cat.Print(v9);
			cout << endl;
		}

		begin = clock();
		cat.Heap_SoarSort(v10);
		end = clock();
		s10 += end - begin;
		if (v1.size() == 1000)
		{
			cout << "�����������ݣ�" << endl;
			cat.Print(v10);
			cout << endl;
		}

		count--;//countΪ100^k�Ĵ�����ÿ��ѭ�����һ��
		v1.resize(0);
	}
	//---�����ʱ
	cout << "����������ʱ��" << s2<< "ms" << endl;
	cout << endl;

	cout << "�鲢���򣨵ݹ飩��ʱ��" << s3 << "ms" << endl;
	cout << endl;

	cout << "�鲢���򣨷ǵݹ飩��ʱ��" << s4 << "ms" << endl;
	cout << endl;

	cout << "�������򣨵ݹ飩��ʱ��" << s5 << "ms" << endl;
	cout << endl;

	cout << "�������򣨷ǵݹ飩��ʱ��" << s6 << "ms" << endl;
	cout << endl;

	cout << "����������ʱ��" << s7<< "ms" << endl;
	cout << endl;

	cout << "����������ʱ��" << s8 << "ms" << endl;
	cout << endl;

	cout << "ϣ��������ʱ��" << s9 << "ms" << endl;
	cout << endl;

	cout << "��������ʱ��" << s10 << "ms" << endl;
	cout << endl;
	//---�����ʱ

	//---�������ݵ��ļ�
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ�  -- д�ļ�

	//������д�뵽�ļ���
	double Spend[] = { s2,s3,s4,s5,s6,s7,s8,s9,s10 };
	ofs << "2" << ",";
	for (int i=0;i<9;i++)
	{
		ofs <<Spend[i] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();
	this->FileIsEmpty = false;
	//---�������ݵ��ļ�

	while (getchar() != '\n')//���ջ��ڻ��������ַ�
	{
		;
	}
	system("pause");
	system("cls");
}
//---���ؼ�¼������ȡ�ļ���
 void Menu::LoadRecord()
{
	ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�

	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		this->FileIsEmpty = true;
		return ;
	}
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		ifs.close();
		this->FileIsEmpty = true;
		return ;
		
	}
	this->FileIsEmpty = false;
	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string> v1;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string temp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			v1.push_back(temp);
			start = pos + 1;
		}
		Record.insert(make_pair(index, v1));
		index++;
	}
	ifs.close();

}
 //---��ʾ��¼
void Menu::ShowRecord()
{
	if (this->FileIsEmpty == true)//����ļ�Ϊ�գ�����ȡ�ļ�
	{
		cout << "�ļ������ڣ����¼Ϊ��" << endl;
		return;
	}

	LoadRecord();//�ļ���Ϊ�գ���ȡ�ļ�

	//---�����ʾ��¼
	string s1 = { "����������ʱ��"};
	string s2 = { "�鲢���򣨵ݹ飩��ʱ��" };
	string s3 = {"�鲢���򣨷ǵݹ飩��ʱ��"};
	string s4 = {"�������򣨵ݹ飩��ʱ��"};
	string s5 = {"�������򣨷ǵݹ飩��ʱ��"};
	string s6 = {"����������ʱ��"};
	string s7 = { "����������ʱ��"};
	string s8= {"ϣ��������ʱ��"};
	string s9 = {"��������ʱ��"};
	vector<string> v2={s1,s2,s3,s4,s5,s6,s7,s8,s9};
	//---�����ʾ��¼
	

	int flag1 = 1;//������������ ������־
	int flag2 = 1;//����С������ ������־
	for(int i=0;i<Record.size(); i++)
	{
		if (Record[i][0] == "1")
		{
			cout << "��"<<flag1<<"�β�ͬ�����ݵĲ��Լ�¼���£�" << endl;
			flag1++;//������һ
		}
		if (Record[i][0] == "2")
		{
			cout << "��" << flag2 << "�β�ͬС���ݵĴ������Լ�¼���£�" << endl;
			flag2++;//������һ
		}
		cout  <<v2[0] << Record[i][1]<< "ms" << endl<< endl;
		cout << v2[1] << Record[i][2] << "ms" << endl << endl;
		cout << v2[2] << Record[i][3] << "ms" << endl << endl;
		cout << v2[3] << Record[i][4] << "ms" << endl << endl;
		cout << v2[4] << Record[i][5] << "ms" << endl << endl;
		cout << v2[5] << Record[i][6] << "ms" << endl << endl;
		cout << v2[6] << Record[i][7] << "ms" << endl << endl;
		cout << v2[7] << Record[i][8] << "ms" << endl << endl;
		cout << v2[8] << Record[i][9] << "ms" << endl << endl;
	}
	system("pause");
	system("cls");
}