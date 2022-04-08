#include"Sort.h"
#include<string>
#define Max_Insert 20;
//===========================��������============================================
//---���뽵������

void Sort::Insert_FallSoft(vector<int>& v1)
{
	int j;
	for (int i = 1; i < v1.size(); i++)
	{
		if (v1[i - 1] < v1[i])
		{
			int temp = v1[i];
			for (j = i - 1; j > -1 && v1[j] < temp; j--)//����
				v1[j + 1] = v1[j];
			v1[j + 1] = temp;//����
		}
	}
}
//---������������

void Sort::Insert_SoarSoft(vector<int>& v1)
{
	int  j;
	for (int i = 1; i < v1.size(); i++)
	{
		if (v1[i - 1] > v1[i])
		{
			int temp = v1[i];
			for (j = i - 1; j > -1 && v1[j] > temp; j--)//����
				v1[j + 1] = v1[j];
			v1[j + 1] = temp;//����
		}
	}
}
//===========================��������============================================

//===========================�鲢���򣨵ݹ飩====================================
// //-------�ϲ�����

void Sort::MergeArray(vector<int>& v1, vector<int>& v2, int i, int mid, int len)
{
	int k, j, l;
	for (k = i, j = mid + 1; j <= len && i <= mid; k++)
	{
		if (v1[i] > v1[j])
			v2[k] = v1[j++];
		else
			v2[k] = v1[i++];
	}
	if (i <= mid)
	{
		for (l = 0; l <= mid - i; l++)
			v2[k + l] = v1[i + l];		
	}
	if (j <= len)
	{
		for (l = 0; l <= len - j; l++)
			v2[k + l] = v1[j + l];		
	}

}
// -------�鲢���򣨵ݹ飩

void Sort::MergeSort_Recursion(vector<int>& v1, vector<int>& v2, int low, int high)
{
	vector<int> v3(v1.begin(), v1.end());
	if (low == high)
		v2[low] = v1[low];
	else
	{
		int mid = (low + high) / 2;//----����
		MergeSort_Recursion(v1, v3, low, mid);//�ݹ�

		MergeSort_Recursion(v1, v3, mid + 1, high);//�ݹ�

		MergeArray(v3, v2, low, mid, high);//�ϲ�
	}
}
//===========================�鲢���򣨵ݹ飩====================================

//===========================�鲢���򣨷ǵݹ飩==================================
//--------�ϲ�����

void Sort::MergePass(vector<int>& v1, vector<int>& v2, int k, int len)
{
	int i = 0, j;
	while (i <= (len - 2 * k))
	{
		MergeArray(v1, v2, i, i + k - 1, i + 2 * k - 1);
		i = i + 2 * k;
	}
	if (i < len - k)
	{
		MergeArray(v1, v2, i, i + k - 1, len - 1);
	}
	else
		for (j = i; j <= len - 1; j++)
			v2[j] = v1[j];
}
//-------�鲢���򣨷ǵݹ飩

void Sort::MergeSort(vector<int>& v1, int len)
{
	vector<int> v2(v1.begin(), v1.end());
	int k = 1;
	while (k < len)
	{
		MergePass(v1, v2, k, len);
		k *= 2;
		MergePass(v2, v1, k, len);
		k *= 2;
	}
}
//===========================�鲢���򣨷ǵݹ飩==================================


//===========================�������򣨵ݹ飩====================================
//------������

int Sort::Partition(vector<int>& v1, int low, int high)
{
	//----����ȡ��
	int m = low + (high - low) / 2;
	if (v1[low] > v1[high])
		swap(v1[low], v1[high]);
	if (v1[m] > v1[high])
		swap(v1[m], v1[high]);
	if (v1[low] > v1[m])
		swap(v1[low], v1[m]);

	int temp = v1[low];
	while (low < high)
	{
		while (low < high && v1[high] >= temp)
			high--;
		swap(v1[low], v1[high]);
		while (low < high && v1[low] <= temp)
			low++;
		swap(v1[low], v1[high]);
		
	}
	return low;
}
//------���ţ��ݹ飩

void Sort::QuickSort_Recursion(vector<int>& v1, int low, int high)
{
	int flag;
	while (low < high)
	{
		flag = Partition(v1, low, high);
		QuickSort_Recursion(v1, low, flag - 1);
		low = flag + 1;//β�ݹ��Ż�
	}

}
//===========================�������򣨵ݹ飩====================================

//===========================�������򣨷ǵݹ飩==================================
//------���ţ��ǵݹ飩

void Sort::QuickSort(vector<int>& v1, int low, int high)
{
	stack<int> s;
	s.push(low);
	s.push(high);//�����high������Ҫ����high
	while (!s.empty())//ջ��Ϊ��
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();

		int index = Partition(v1, left, right);
		if ((index - 1) > left)//��������
		{
			s.push(left);
			s.push(index - 1);
		}
		if ((index + 1) < right)//��������
		{
			s.push(index + 1);
			s.push(right);
		}
	}
}
//===========================�������򣨷ǵݹ飩==================================

//===========================��������============================================

vector<int> Sort::CountSort(vector<int>& v1)
{

	//�������������С��������ȷ���ݴ����������Ĵ�С
	int max = 0;
	for (size_t i = 0; i < v1.size(); i++)
	{
		if (max < v1[i])
			max = v1[i];
	}

	int  min = 0;
	for (size_t i = 0; i < v1.size(); i++)
	{
		if (min > v1[i])
			min = v1[i];
	}

	vector<int> v2(max - min + 1, 0);//�ݴ���������
	vector<int> vOut(v1.size(), 0);//�������

	for (size_t i = 0; i < v1.size(); i++)//1.ͨ��Ͱ���ռ�����
		v2[v1[i]]++;
	for (int i = 1; i < v2.size(); i++)//2.ͳ������
	{
		v2[i] = v2[i] + v2[i - 1];
	}

	for (int i = v1.size() - 1; i >= 0; i--)//3.��������
	{
		vOut[v2[v1[i]] - 1] = v1[i];
		v2[v1[i]]--;
	}
	return vOut;
}
//===========================��������============================================

//===========================��������========================================
//--------�����λ��

int Sort::Max_Digit(vector<int>& v1)
{
	int top = 1; //���λ��

	int flag = 10;//����ͳ��top

	for (int i = 0; i < v1.size(); ++i)
	{
		while (v1[i] >= flag)
		{
			flag *= 10;
			++top;
		}
	}
	return top;
}
//--------��������

void Sort::RadixCountSort(vector<int>& v1) //��������
{
	int top = Max_Digit(v1);//��ȡ�������������ݵ����λ

	vector<int> temp(v1.size(), 0);//��ʱ����

	int  num;
	int radix = 1;
	for (int i = 1; i <= top; i++) //���ΰ��ո�λʮλ��λ�����ƽ�������
	{
		vector<int> count(10, 0); //ͳ������---ÿ�η���ǰ���ͳ������

		for (i = 0; i < v1.size(); i++)//1.�ռ�ÿ��ѭ���е�λ�θ�����Ͱ����--�����ڼ���������ռ�����
		{
			num = (v1[i] / radix) % 10;
			count[num]++;
		}

		for (i = 1; i < count.size(); i++)//2.ͳ��ÿ��ѭ���еĶ�ӦͰ���ۼ�ֵ--�����ڼ��������ͳ������
			count[i] = count[i - 1] + count[i];

		for (i = v1.size() - 1; i >= 0; i--) //3.������Ͱ�м�¼���η��䵽��ʱ����temp��--�����ڼ�������ķ�������
		{
			num = (v1[i] / radix) % 10;
			temp[count[num] - 1] = v1[i];
			count[num]--;
		}

		for (i = 0; i < v1.size(); i++) //4.����ʱ����������ת��ԭ������
			v1[i] = temp[i];

		radix = radix * 10;//5.ÿ��ѭ�����ʮλ
	}
}
//===========================��������========================================

//===========================ϣ������============================================
//--------ϣ��������

void Sort::Shell_FallSort(vector<int>& v1)
{
	int j, incre = v1.size();//increΪ��������
	do
	{
		incre = incre / 3 + 1;
		for (int i = incre; i < v1.size(); i++)
		{
			if (v1[i - incre] < v1[i])
			{
				int temp = v1[i];
				for (j = i - incre; j >= 0 && v1[j] < temp; j -= incre)//�����������к���
					v1[j + incre] = v1[j];
				v1[j + incre] = temp;
			}
		}

	} while (incre > 1);
}
//--------ϣ����������

void Sort::Shell_SoarSort(vector<int>& v1)
{
	int j, incre = v1.size();//increΪ��������
	do
	{
		incre = incre / 3 + 1;
		for (int i = incre; i < v1.size(); i++)
		{
			if (v1[i - incre] > v1[i])
			{
				int temp = v1[i];
				for (j = i - incre; j >= 0 && v1[j] > temp; j -= incre)//�����������к���
					v1[j + incre] = v1[j];
				v1[j + incre] = temp;
			}
		}

	} while (incre > 1);
}
//===========================ϣ������============================================

//===========================������==============================================
//-----������ ����Ķѵ���

void Sort::Heap_FallAdjust(vector<int>& v1, int i, int len)
{
	int j;
	int temp = v1[i];
	for (j = 2 * i; j < len; j *= 2)//---2iΪ��β˫�����ӣ�2i+1Ϊ��β˫���Һ���
	{
		if (j<len && v1[j]>v1[j + 1])
			j++;
		if (temp <= v1[j])
			break;
		v1[i] = v1[j];
		i = j;
	}
	v1[i] = temp;
}
//-----������ ����

void Sort::Heap_FallSort(vector<int>& v1)
{
	int i;
	for (i = v1.size() / 2; i >= 0; i--)//n�����ݣ�n/2Ϊ��β˫��
	{
		Heap_FallAdjust(v1, i, v1.size());//������
	}

	for (i = v1.size() - 1; i > 0; i--)//����������Ѷ���������������
	{
		swap(v1[0], v1[i]);
		Heap_FallAdjust(v1, 0, i - 1);
	}
}

//-----������ ����Ķѵ���

void Sort::Heap_SoarAdjust(vector<int>& v1, int i, int len)
{
	int j;
	int temp = v1[i];
	for (j = 2 * i; j < len; j *= 2)//---2iΪ��β˫�����ӣ�2i+1Ϊ��β˫���Һ���
	{
		if (j < len && v1[j] < v1[j + 1])
			j++;
		if (temp >= v1[j])
			break;
		v1[i] = v1[j];
		i = j;
	}
	v1[i] = temp;
}
//-----������ ����

void Sort::Heap_SoarSort(vector<int>& v1)
{
	int i;
	for (i = v1.size() / 2; i >= 0; i--)//n�����ݣ�n/2Ϊ��β˫��
	{
		Heap_SoarAdjust(v1, i, v1.size());//������
	}

	for (i = v1.size() - 1; i > 0; i--)//����������Ѷ���������������
	{
		swap(v1[0], v1[i]);
		Heap_SoarAdjust(v1, 0, i - 1);
	}
}
//===========================������==============================================

//===========================Ӧ����=============================================
//------��һ���⣺��ɫ����-------

void Sort::ColorSort()
{
	/*cout << "��������ɫ���飺0/1/2��ɵ��������飺(��#�˳�)" << endl;
	vector<int> v1;
	char select[100];
	int num;
	do 
	{	
		cin >> select;

		if (select[0] == '#')
			return ;
		if ((num = ISNumber(select)) == -1)
		{
			cout << "��������" << endl;
			while (getchar() != '\n')
			{
				;
			}
			system("pause");
			system("cls");
			return ;
		}
		if(num==0||num==1||num==2)
			v1.push_back(num);
		else
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

	} while (getchar() != '\n' && num != '-1' );*/

	//---������
	vector<int> v1;
	char select[100];
	cout << "��������Ҫ���ԵĲ�Σ�levelȡ1��3����" << endl;
	cout << "level 1=100������" << endl;
	cout << "level 2=10000������" << endl;
	cout << "level 3=100000������" << endl;
	cout << endl;
	cout << "level=";
	int level;
	cin >> select;
	if ((level = ISNumber(select)) == -1)
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
	//---������

	//���ݲ�Σ�ѡ������len�Ĵ�С
	if (level != 1 && level != 2 && level != 3)
	{
		cout << "��������" << endl;
		return;
	}

	int len;
	if (level == 1)
	{
		len = 100;
	}
	else if (level == 2)
	{
		len = 10000;
	}
	else
	{
		len = 100000;
	}
	
	for (int i = 0; i < len; i++)
	{
		int num = (rand() % 3);  //0~2
		v1.push_back(num);
	}
	//���ݲ�Σ�ѡ������len�Ĵ�С

	//�������ǰ����
	cout << "����ǰ�����ݣ�" << endl;
	Print(v1);
	cout << endl;
	

	int p1 = 0, p2 = v1.size() - 1;
	srand(time(NULL));

	//���򼰼�ʱ
	clock_t begin = clock();
	for (int i = 0; i <= p2; i++)
	{
		if (v1[i] == 0)
		{
			swap(v1[i],v1[p1++]);
		}
		else if (v1[i] == 2)
		{
			swap(v1[i--], v1[p2--]);
		}
	}	
	clock_t end = clock();

	//������ݼ���ʱ
	cout << "���������ݣ�" << endl;
	Print(v1);
	cout << "��ʱ��" << (double)(end -begin ) << "ms" << endl;

	while (getchar() != '\n')
	{
		;
	}
	system("pause");
	system("cls");
}
//------�ڶ����⣺�ҳ���kС/�����

void Sort::Test2()
{
	//-----ѡ����
	vector<int> v1;
	char select[100];
	cout << "��������Ҫ���ԵĲ�Σ�levelȡ1��3����" << endl;
	cout << "level 1=100������" << endl;
	cout << "level 2=1000������" << endl;
	cout << "level 3=10000������" << endl;
	cout << endl;
	cout << "level=";
	int level;
	cin >> select;
	if ((level = ISNumber(select)) == -1)
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
	//-----ѡ����

	//���ݲ�Σ�ѡ������len�Ĵ�С
	if (level != 1 && level != 2 && level != 3)
	{
		cout << "��������" << endl;
		return;
	}

	int len;
	if (level == 1)
	{
		len = 100;
	}
	else if (level == 2)
	{
		len = 1000;
	}
	else
	{
		len = 10000;
	}
	for (int i = 0; i < len; i++)
	{
		int num = (rand() % len);  //0����len-1
		v1.push_back(num);
	}
	
	//����k
	cout << "��������Ҫ�ĵ�kС/���Ԫ�أ�" << endl;
	cout << "k=";
	int k;
	cin >> select;
	if ((k = ISNumber(select)) == -1)
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

	//-----------------1�ҵ�kС
	int high = v1.size() - 1;
	int low = 0;

	//���򼰼�ʱ
	clock_t begin = clock();
	QuickSort_FindK(v1, low, high, k-1);
	clock_t end = clock();

	//������ݼ���ʱ
	cout << "��"<<k << "СԪ��Ϊ:" << v1[k-1] << endl;
	cout << "��ʱ������Ϊ��" << endl;
	Print(v1);
	cout << "��ʱ��" <<(double)(end-begin) << "ms" << endl;
	cout << endl;

	//------------------2�ҵ�k��
	high = v1.size() - 1;
	low = 0;
	cout << "��" << k << "��Ԫ��Ϊ:" ;
	k = v1.size() - k;

	//���򼰼�ʱ
	begin = clock();
	QuickSort_FindK(v1, low, high, k);
	end = clock();

	//������ݼ���ʱ
	cout << v1[k] << endl;
	cout << "��ʱ������Ϊ��" << endl;
	Print(v1);
	cout << "��ʱ��" << (double)((end - begin))  << "ms" << endl;
	cout << endl;

	//------------------3����������������
	//���򼰼�ʱ
	begin = clock();
	QuickSort_Recursion(v1, 0, v1.size() - 1);
	end = clock();
	//������ݼ���ʱ
	cout << "���ź�����ݣ�" << endl;
	Print(v1);
	cout << "��ʱ��" <<(double)((end - begin)) << "ms" << endl;
	

	while (getchar() != '\n')
	{
		;
	}
	system("pause");
	
	system("cls");

}
//===========================Ӧ����=============================================

//=========================����Ƿ����=======================================
//-------�ж��Ƿ�Ϊint�ͣ�����bool����

bool Sort::ISInt(string& str)
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

int Sort::ISNumber(char* s)//------------------------------------------------------�ж������Ƿ�Ϊ����----�����򷵻ض�Ӧ������--------���򷵻�-1----------------------
{
	int p = -1, i = 0, flag= 0;
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
//------��ѯ KС/��Ԫ�� ��λ��

int Sort::QuickSort_FindK(vector<int>& v1, int low, int high, int k)
{
	if (low <= high) //�˲��ָ�parition�������ƣ�����������ֳ�������Ϊ�м���������
	{
		int i = low, j = high, temp = v1[i];
		while (i < j) 
		{
			while (i < j && v1[j] > temp) 
			{
				j--;
			}
			if (i < j)
			{
				v1[i++] = v1[j];
			}
			while (i < j && v1[i] < temp) 
			{
				i++;
			}
			if (i < j) 
			{
				v1[j--] = v1[i];
			}
		}
		v1[i] = temp;
		if (i == k)
		{
			return v1[i];
		}
		else if (k < i) //�����᷵��ֵ������ôѡȡlow��i-1�����������
		{
			return QuickSort_FindK(v1, low, i - 1, k);
		}
		else //�����᷵��ֵ��С����ôѡȡi+1��high�����������
		{
			return QuickSort_FindK(v1, i + 1, high, k);
		}
	}
	else 
	{
		return -1;
	}
}
//=========================����Ƿ����=======================================

//========================��������������===================================

void Sort::Print(const vector<int>& v1)
{
	for (auto x : v1)//��forѭ���������ȫ������
	{
		cout << x << " ";
	}
	cout << endl;
}
//========================��������������===================================
