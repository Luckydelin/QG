#include"Menu.h"
#include<string>
#include<cmath>
#include<fstream>
Menu::Menu()
{
	FileIsEmpty = true;
}
//---显示菜单
void  Menu::ShowMenu()
{
	cout << endl << endl << endl << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t======================**一级菜单系统**=========================" << endl;
	cout << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t-1.退出系统"<<endl;
	cout << "\t\t\t\t\t1.大数据量排序" << endl;
	cout << "\t\t\t\t\t2.大量小数据量排序" << endl;
	cout << "\t\t\t\t\t3.第一道应用题" << endl;
	cout << "\t\t\t\t\t4.第二道应用题" << endl;
	cout << "\t\t\t\t\t5.大量数据排序记录" << endl;
	cout << "\t\t---------------------------------------------------------------" << endl;
	cout << "\t\t===============================================================" << endl;
	cout << "\t\t---------------------------------------------------------------" << endl;
}
//---菜单调度函数

void Menu::menu()
{
	Sort cat;
	while (true)
	{
		ShowMenu();//显示菜单

		string select;
		getline(cin, select);//利用getline函数吸收空格
		while (!cat.ISInt(select))//判断是否为int型数字
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
		case 1:Data_Test1(cat); break;
		case 2:Data_Test2(cat); break;
		case 3:cat.ColorSort(); break;
		case 4:cat.Test2(); break;
		case 5:ShowRecord(); break;
		default:cout << "输入有误！请重新输入！" << endl; 
			system("pause");
			system("cls");
			break;

		}
		
	}
}
//---大数据量排序
void Menu::Data_Test1(Sort cat)
{
	vector<int> v1;
	char select[100];
	cout << "请输入你要测试的层次（level取0到3）：" << endl;
	cout << "level=";
	int level;
	cin >> select;
	if ((level = cat.ISNumber(select)) == -1)
	{
		cout << "输入有误！" << endl;
		while (getchar() != '\n')
		{
			;
		}
		system("pause");
		system("cls");
		return;
	}
	cout << endl;

	//根据选择层次，选择不同的数据量进行排序
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
		cout << "输入有误！" << endl;
		return;
	}
	while (getchar() != '\n')
	{
		;
	}
	system("pause");
	system("cls");
	
}
//---大数据量排序--计时和运行排序函数
void Menu::SpendTime(vector<int>v1, Sort cat)
{
	vector<int> v2 = v1, v3 = v1, v4 = v1, v5 = v1, v6 = v1, v7 = v1, v8 = v1, v9 = v1, v10 = v1;

	double s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0, s10 = 0;//用来保存全部排序的用时

	clock_t begin, end;//begin为开始时间，end为排序后的时间
	srand(time(NULL));//随机数种子


	//下面是进行各种排序并输出用时
	begin = clock();
	cat.Insert_SoarSoft(v2);
	end = clock();
	s2 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "插入排序后的数据：" << endl;
		cat.Print(v2);
	}
	
	cout << "插入排序用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.MergeSort_Recursion(v3, v3, 0, v3.size()-1);
	end = clock();
	s3 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "归并排序后的数据：" << endl;
		cat.Print(v3);
	}
	cout << "归并排序（递归）用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.MergeSort(v4, v4.size());
	end = clock();
	s4 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "归并（非递归）排序后的数据：" << endl;
		cat.Print(v4);
	}
	cout << "归并排序（非递归）用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.QuickSort_Recursion(v5, 0, v5.size()-1);
	end = clock();
	s5 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "快速排序后的数据：" << endl;
		cat.Print(v5);
	}
	cout << "快速排序（递归）用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.QuickSort(v6, 0, v6.size()-1);
	end = clock();
	s6 += (double)(end - begin);
	if (v1.size() ==500)
	{
		cout << "快速（非递归）排序后的数据：" << endl;
		cat.Print(v6);
	}
	cout << "快速排序（非递归）用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.CountSort(v7);
	end = clock();
	s7 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "计数排序后的数据：" << endl;
		cat.Print(v7);
	}
	cout << "计数排序用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.RadixCountSort(v8);
	end = clock();
	s8 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "基数排序后的数据：" << endl;
		cat.Print(v8);
	}
	cout << "基数排序用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.Shell_SoarSort(v9);
	end = clock();
	s9 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "希尔排序后的数据：" << endl;
		cat.Print(v9);
	}
	cout << "希尔排序用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	begin = clock();
	cat.Heap_SoarSort(v10);
	end = clock();
	s10 += (double)(end - begin);
	if (v1.size() == 500)
	{
		cout << "堆排序后的数据：" << endl;
		cat.Print(v10);
		cout << endl;
	}
	cout << "堆排序用时：" << (double)(end - begin) << "ms" << endl;
	cout << endl;

	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件  -- 写文件

	//将数据写入到文件中
	double Spend[] = { s2,s3,s4,s5,s6,s7,s8,s9,s10 };
	ofs << "1" << ",";
	for (int i = 0; i < 9; i++)
	{
		ofs << Spend[i] << ",";
	}
	ofs << endl;


	//关闭文件
	ofs.close();
	this->FileIsEmpty = false;
}
//---大量小数据量排序
void Menu::Data_Test2(Sort cat)
{

	vector<int> v1;
	
	char select[100];
	cout << "请输入你要测试的层次(100^k，k取1到3)：" << endl;
	cout << "k=";
	int k;
	cin >> select;
	if ((k = cat.ISNumber(select)) == -1)
	{
		cout << "输入有误！" << endl;
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
		cout << "输入有误！" << endl;
		return;
	}

	double count=pow(100, k);//pow函数为幂函数，在cmath头文件，参数一为底数，参数二为幂数
	double s2 =0, s3=0, s4=0, s5 =0, s6=0, s7=0, s8=0 , s9=0 , s10=0;//用来保存全部排序的用时
	while (count)
	{
		for (int i = 0; i < 100; i++)
		{
			int num = (rand() % 100001);
			v1.push_back(num);
		}
		vector<int> v2 = v1, v3 = v1, v4 = v1, v5 = v1, v6 = v1, v7 = v1, v8 = v1, v9 = v1, v10 = v1;

		clock_t begin, end;//begin为开始时间，end为排序后的时间
		srand(time(NULL));

		begin = clock();
		cat.Insert_SoarSoft(v2);
		end = clock();
		s2 +=end - begin;
		if (count == 4)
		{
			cout << "插入排序后的数据：" << endl;
			cat.Print(v2);
			cout << endl;
		}

		begin = clock();
		cat.MergeSort_Recursion(v3, v3, 0, v3.size() - 1);
		end = clock();
		s3 += end - begin;
		if (count == 4)
		{
			cout << "归并排序后的数据：" << endl;
			cat.Print(v3);
			cout << endl;
		}

		begin = clock();
		cat.MergeSort(v4, v4.size());
		end = clock();
		s4 += end - begin;
		if (count == 4)
		{
			cout << "归并（非递归）排序后的数据：" << endl;
			cat.Print(v4);
			cout << endl;
		}

		begin = clock();
		cat.QuickSort_Recursion(v5, 0, v5.size() - 1);
		end = clock();
		s5 += end - begin;
		if (count == 4)
		{
			cout << "快速排序后的数据：" << endl;
			cat.Print(v5);
			cout << endl;
		}

		begin = clock();
		cat.QuickSort(v6, 0, v6.size() - 1);
		end = clock(); 
		s6 += end - begin;
		if (count == 4)
		{
			cout << "快速（非递归）排序后的数据：" << endl;
			cat.Print(v6);
			cout << endl;
		}

		begin = clock();
		cat.CountSort(v7);
		end = clock();
		s7 += end - begin;
		if (count == 4)
		{
			cout << "计数排序后的数据：" << endl;
			cat.Print(v7);
			cout << endl;
		}

		begin = clock();
		cat.RadixCountSort(v8);
		end = clock();
		s8 += end - begin;
		if (count == 4)
		{
			cout << "基数排序后的数据：" << endl;
			cat.Print(v8);
			cout << endl;
		}

		begin = clock();
		cat.Shell_SoarSort(v9);
		end = clock();
		s9 += end - begin;
		if (count== 4)
		{
			cout << "希尔排序后的数据：" << endl;
			cat.Print(v9);
			cout << endl;
		}

		begin = clock();
		cat.Heap_SoarSort(v10);
		end = clock();
		s10 += end - begin;
		if (v1.size() == 1000)
		{
			cout << "堆排序后的数据：" << endl;
			cat.Print(v10);
			cout << endl;
		}

		count--;//count为100^k的次数，每次循环后减一次
		v1.resize(0);
	}
	//---输出用时
	cout << "插入排序用时：" << s2<< "ms" << endl;
	cout << endl;

	cout << "归并排序（递归）用时：" << s3 << "ms" << endl;
	cout << endl;

	cout << "归并排序（非递归）用时：" << s4 << "ms" << endl;
	cout << endl;

	cout << "快速排序（递归）用时：" << s5 << "ms" << endl;
	cout << endl;

	cout << "快速排序（非递归）用时：" << s6 << "ms" << endl;
	cout << endl;

	cout << "计数排序用时：" << s7<< "ms" << endl;
	cout << endl;

	cout << "基数排序用时：" << s8 << "ms" << endl;
	cout << endl;

	cout << "希尔排序用时：" << s9 << "ms" << endl;
	cout << endl;

	cout << "堆排序用时：" << s10 << "ms" << endl;
	cout << endl;
	//---输出用时

	//---保存数据到文件
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件  -- 写文件

	//将数据写入到文件中
	double Spend[] = { s2,s3,s4,s5,s6,s7,s8,s9,s10 };
	ofs << "2" << ",";
	for (int i=0;i<9;i++)
	{
		ofs <<Spend[i] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();
	this->FileIsEmpty = false;
	//---保存数据到文件

	while (getchar() != '\n')//吸收还在缓冲区的字符
	{
		;
	}
	system("pause");
	system("cls");
}
//---加载记录（即读取文件）
 void Menu::LoadRecord()
{
	ifstream ifs("speech.csv", ios::in); //输入流对象 读取文件

	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		this->FileIsEmpty = true;
		return ;
	}
	
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		ifs.close();
		this->FileIsEmpty = true;
		return ;
		
	}
	this->FileIsEmpty = false;
	ifs.putback(ch); //读取的单个字符放回去

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string> v1;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start); //从0开始查找 ','
			if (pos == -1)
			{
				break; //找不到break返回
			}
			string temp = data.substr(start, pos - start); //找到了,进行分割 参数1 起始位置，参数2 截取长度
			v1.push_back(temp);
			start = pos + 1;
		}
		Record.insert(make_pair(index, v1));
		index++;
	}
	ifs.close();

}
 //---显示记录
void Menu::ShowRecord()
{
	if (this->FileIsEmpty == true)//如果文件为空，不读取文件
	{
		cout << "文件不存在，或记录为空" << endl;
		return;
	}

	LoadRecord();//文件不为空，读取文件

	//---配合显示记录
	string s1 = { "插入排序用时："};
	string s2 = { "归并排序（递归）用时：" };
	string s3 = {"归并排序（非递归）用时："};
	string s4 = {"快速排序（递归）用时："};
	string s5 = {"快速排序（非递归）用时："};
	string s6 = {"计数排序用时："};
	string s7 = { "基数排序用时："};
	string s8= {"希尔排序用时："};
	string s9 = {"堆排序用时："};
	vector<string> v2={s1,s2,s3,s4,s5,s6,s7,s8,s9};
	//---配合显示记录
	

	int flag1 = 1;//大数据量排序 次数标志
	int flag2 = 1;//大量小数据量 次数标志
	for(int i=0;i<Record.size(); i++)
	{
		if (Record[i][0] == "1")
		{
			cout << "第"<<flag1<<"次不同大数据的测试记录如下：" << endl;
			flag1++;//次数加一
		}
		if (Record[i][0] == "2")
		{
			cout << "第" << flag2 << "次不同小数据的大量测试记录如下：" << endl;
			flag2++;//次数加一
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