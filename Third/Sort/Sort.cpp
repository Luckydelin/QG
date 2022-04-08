#include"Sort.h"
#include<string>
#define Max_Insert 20;
//===========================插入排序============================================
//---插入降序排序

void Sort::Insert_FallSoft(vector<int>& v1)
{
	int j;
	for (int i = 1; i < v1.size(); i++)
	{
		if (v1[i - 1] < v1[i])
		{
			int temp = v1[i];
			for (j = i - 1; j > -1 && v1[j] < temp; j--)//后移
				v1[j + 1] = v1[j];
			v1[j + 1] = temp;//插入
		}
	}
}
//---插入升序排序

void Sort::Insert_SoarSoft(vector<int>& v1)
{
	int  j;
	for (int i = 1; i < v1.size(); i++)
	{
		if (v1[i - 1] > v1[i])
		{
			int temp = v1[i];
			for (j = i - 1; j > -1 && v1[j] > temp; j--)//后移
				v1[j + 1] = v1[j];
			v1[j + 1] = temp;//插入
		}
	}
}
//===========================插入排序============================================

//===========================归并排序（递归）====================================
// //-------合并数组

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
// -------归并排序（递归）

void Sort::MergeSort_Recursion(vector<int>& v1, vector<int>& v2, int low, int high)
{
	vector<int> v3(v1.begin(), v1.end());
	if (low == high)
		v2[low] = v1[low];
	else
	{
		int mid = (low + high) / 2;//----二分
		MergeSort_Recursion(v1, v3, low, mid);//递归

		MergeSort_Recursion(v1, v3, mid + 1, high);//递归

		MergeArray(v3, v2, low, mid, high);//合并
	}
}
//===========================归并排序（递归）====================================

//===========================归并排序（非递归）==================================
//--------合并数组

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
//-------归并排序（非递归）

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
//===========================归并排序（非递归）==================================


//===========================快速排序（递归）====================================
//------驱轴存放

int Sort::Partition(vector<int>& v1, int low, int high)
{
	//----三数取中
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
//------快排（递归）

void Sort::QuickSort_Recursion(vector<int>& v1, int low, int high)
{
	int flag;
	while (low < high)
	{
		flag = Partition(v1, low, high);
		QuickSort_Recursion(v1, low, flag - 1);
		low = flag + 1;//尾递归优化
	}

}
//===========================快速排序（递归）====================================

//===========================快速排序（非递归）==================================
//------快排（非递归）

void Sort::QuickSort(vector<int>& v1, int low, int high)
{
	stack<int> s;
	s.push(low);
	s.push(high);//后入的high，所以要先拿high
	while (!s.empty())//栈不为空
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();

		int index = Partition(v1, left, right);
		if ((index - 1) > left)//左子序列
		{
			s.push(left);
			s.push(index - 1);
		}
		if ((index + 1) < right)//右子序列
		{
			s.push(index + 1);
			s.push(right);
		}
	}
}
//===========================快速排序（非递归）==================================

//===========================计数排序============================================

vector<int> Sort::CountSort(vector<int>& v1)
{

	//找容器中最大最小数，得以确定暂存数据容器的大小
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

	vector<int> v2(max - min + 1, 0);//暂存数据容器
	vector<int> vOut(v1.size(), 0);//输出容器

	for (size_t i = 0; i < v1.size(); i++)//1.通过桶排收集数据
		v2[v1[i]]++;
	for (int i = 1; i < v2.size(); i++)//2.统计数据
	{
		v2[i] = v2[i] + v2[i - 1];
	}

	for (int i = v1.size() - 1; i >= 0; i--)//3.分配数据
	{
		vOut[v2[v1[i]] - 1] = v1[i];
		v2[v1[i]]--;
	}
	return vOut;
}
//===========================计数排序============================================

//===========================基数排序========================================
//--------求最大位数

int Sort::Max_Digit(vector<int>& v1)
{
	int top = 1; //最高位数

	int flag = 10;//用来统计top

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
//--------基数排序

void Sort::RadixCountSort(vector<int>& v1) //基数排序
{
	int top = Max_Digit(v1);//获取容器中所有数据的最高位

	vector<int> temp(v1.size(), 0);//临时容器

	int  num;
	int radix = 1;
	for (int i = 1; i <= top; i++) //依次按照个位十位百位等类推进行排序
	{
		vector<int> count(10, 0); //统计容器---每次分配前清空统计容器

		for (i = 0; i < v1.size(); i++)//1.收集每次循环中的位次个数到桶里面--类似于计数排序的收集数据
		{
			num = (v1[i] / radix) % 10;
			count[num]++;
		}

		for (i = 1; i < count.size(); i++)//2.统计每次循环中的对应桶的累计值--类似于计数排序的统计数据
			count[i] = count[i - 1] + count[i];

		for (i = v1.size() - 1; i >= 0; i--) //3.将所有桶中记录依次分配到临时容器temp中--类似于计数排序的分配数据
		{
			num = (v1[i] / radix) % 10;
			temp[count[num] - 1] = v1[i];
			count[num]--;
		}

		for (i = 0; i < v1.size(); i++) //4.将临时容器的数据转到原容器中
			v1[i] = temp[i];

		radix = radix * 10;//5.每次循环后进十位
	}
}
//===========================基数排序========================================

//===========================希尔排序============================================
//--------希尔排序降序

void Sort::Shell_FallSort(vector<int>& v1)
{
	int j, incre = v1.size();//incre为增量序列
	do
	{
		incre = incre / 3 + 1;
		for (int i = incre; i < v1.size(); i++)
		{
			if (v1[i - incre] < v1[i])
			{
				int temp = v1[i];
				for (j = i - incre; j >= 0 && v1[j] < temp; j -= incre)//根据增量序列后移
					v1[j + incre] = v1[j];
				v1[j + incre] = temp;
			}
		}

	} while (incre > 1);
}
//--------希尔排序升序

void Sort::Shell_SoarSort(vector<int>& v1)
{
	int j, incre = v1.size();//incre为增量序列
	do
	{
		incre = incre / 3 + 1;
		for (int i = incre; i < v1.size(); i++)
		{
			if (v1[i - incre] > v1[i])
			{
				int temp = v1[i];
				for (j = i - incre; j >= 0 && v1[j] > temp; j -= incre)//根据增量序列后移
					v1[j + incre] = v1[j];
				v1[j + incre] = temp;
			}
		}

	} while (incre > 1);
}
//===========================希尔排序============================================

//===========================堆排序==============================================
//-----堆排序 降序的堆调整

void Sort::Heap_FallAdjust(vector<int>& v1, int i, int len)
{
	int j;
	int temp = v1[i];
	for (j = 2 * i; j < len; j *= 2)//---2i为最尾双亲左孩子，2i+1为最尾双亲右孩子
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
//-----堆排序 升序

void Sort::Heap_FallSort(vector<int>& v1)
{
	int i;
	for (i = v1.size() / 2; i >= 0; i--)//n个数据，n/2为最尾双亲
	{
		Heap_FallAdjust(v1, i, v1.size());//调整堆
	}

	for (i = v1.size() - 1; i > 0; i--)//将最大的数与堆顶交换，并调整堆
	{
		swap(v1[0], v1[i]);
		Heap_FallAdjust(v1, 0, i - 1);
	}
}

//-----堆排序 降序的堆调整

void Sort::Heap_SoarAdjust(vector<int>& v1, int i, int len)
{
	int j;
	int temp = v1[i];
	for (j = 2 * i; j < len; j *= 2)//---2i为最尾双亲左孩子，2i+1为最尾双亲右孩子
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
//-----堆排序 升序

void Sort::Heap_SoarSort(vector<int>& v1)
{
	int i;
	for (i = v1.size() / 2; i >= 0; i--)//n个数据，n/2为最尾双亲
	{
		Heap_SoarAdjust(v1, i, v1.size());//调整堆
	}

	for (i = v1.size() - 1; i > 0; i--)//将最大的数与堆顶交换，并调整堆
	{
		swap(v1[0], v1[i]);
		Heap_SoarAdjust(v1, 0, i - 1);
	}
}
//===========================堆排序==============================================

//===========================应用题=============================================
//------第一道题：颜色排序-------

void Sort::ColorSort()
{
	/*cout << "请输入颜色数组：0/1/2组成的无序数组：(按#退出)" << endl;
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
			cout << "输入有误！" << endl;
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
			cout << "输入有误！" << endl;
			while (getchar() != '\n')
			{
				;
			}
			system("pause");
			system("cls");
			return;
		}

	} while (getchar() != '\n' && num != '-1' );*/

	//---输入层次
	vector<int> v1;
	char select[100];
	cout << "请输入你要测试的层次（level取1到3）：" << endl;
	cout << "level 1=100个数据" << endl;
	cout << "level 2=10000个数据" << endl;
	cout << "level 3=100000个数据" << endl;
	cout << endl;
	cout << "level=";
	int level;
	cin >> select;
	if ((level = ISNumber(select)) == -1)
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
	//---输入层次

	//根据层次，选数据量len的大小
	if (level != 1 && level != 2 && level != 3)
	{
		cout << "输入有误！" << endl;
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
	//根据层次，选数据量len的大小

	//输出排序前数据
	cout << "排序前的数据：" << endl;
	Print(v1);
	cout << endl;
	

	int p1 = 0, p2 = v1.size() - 1;
	srand(time(NULL));

	//排序及计时
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

	//输出数据及用时
	cout << "排序后的数据：" << endl;
	Print(v1);
	cout << "用时：" << (double)(end -begin ) << "ms" << endl;

	while (getchar() != '\n')
	{
		;
	}
	system("pause");
	system("cls");
}
//------第二道题：找出第k小/大的数

void Sort::Test2()
{
	//-----选择层次
	vector<int> v1;
	char select[100];
	cout << "请输入你要测试的层次（level取1到3）：" << endl;
	cout << "level 1=100个数据" << endl;
	cout << "level 2=1000个数据" << endl;
	cout << "level 3=10000个数据" << endl;
	cout << endl;
	cout << "level=";
	int level;
	cin >> select;
	if ((level = ISNumber(select)) == -1)
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
	//-----选择层次

	//根据层次，选数据量len的大小
	if (level != 1 && level != 2 && level != 3)
	{
		cout << "输入有误！" << endl;
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
		int num = (rand() % len);  //0——len-1
		v1.push_back(num);
	}
	
	//输入k
	cout << "请输入你要的第k小/大的元素：" << endl;
	cout << "k=";
	int k;
	cin >> select;
	if ((k = ISNumber(select)) == -1)
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

	//-----------------1找第k小
	int high = v1.size() - 1;
	int low = 0;

	//排序及计时
	clock_t begin = clock();
	QuickSort_FindK(v1, low, high, k-1);
	clock_t end = clock();

	//输出数据及计时
	cout << "第"<<k << "小元素为:" << v1[k-1] << endl;
	cout << "此时的数据为：" << endl;
	Print(v1);
	cout << "用时：" <<(double)(end-begin) << "ms" << endl;
	cout << endl;

	//------------------2找第k大
	high = v1.size() - 1;
	low = 0;
	cout << "第" << k << "大元素为:" ;
	k = v1.size() - k;

	//排序及计时
	begin = clock();
	QuickSort_FindK(v1, low, high, k);
	end = clock();

	//输出数据及计时
	cout << v1[k] << endl;
	cout << "此时的数据为：" << endl;
	Print(v1);
	cout << "用时：" << (double)((end - begin))  << "ms" << endl;
	cout << endl;

	//------------------3快速排序所有数据
	//排序及计时
	begin = clock();
	QuickSort_Recursion(v1, 0, v1.size() - 1);
	end = clock();
	//输出数据及计时
	cout << "快排后的数据：" << endl;
	Print(v1);
	cout << "用时：" <<(double)((end - begin)) << "ms" << endl;
	

	while (getchar() != '\n')
	{
		;
	}
	system("pause");
	
	system("cls");

}
//===========================应用题=============================================

//=========================输入非法检测=======================================
//-------判断是否为int型，返回bool类型

bool Sort::ISInt(string& str)
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

int Sort::ISNumber(char* s)//------------------------------------------------------判断输入是否为数字----若是则返回对应的数字--------否则返回-1----------------------
{
	int p = -1, i = 0, flag= 0;
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
//------查询 K小/大元素 的位置

int Sort::QuickSort_FindK(vector<int>& v1, int low, int high, int k)
{
	if (low <= high) //此部分跟parition函数类似，都是以驱轴分成以驱轴为中间数的两边
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
		else if (k < i) //若驱轴返回值过大，那么选取low到i-1的区间继续找
		{
			return QuickSort_FindK(v1, low, i - 1, k);
		}
		else //若驱轴返回值过小，那么选取i+1到high的区间继续找
		{
			return QuickSort_FindK(v1, i + 1, high, k);
		}
	}
	else 
	{
		return -1;
	}
}
//=========================输入非法检测=======================================

//========================输出容器里的数据===================================

void Sort::Print(const vector<int>& v1)
{
	for (auto x : v1)//用for循环输出容器全部数据
	{
		cout << x << " ";
	}
	cout << endl;
}
//========================输出容器里的数据===================================
