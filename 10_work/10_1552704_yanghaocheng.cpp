#include"10_1552704_yanghaocheng.h"
int MAX = 10000;

bool WinnerTree::Initial(int *a, int size)
{
	if (size < 2 || size>maxSize)
		return false;
	n = size;
	e = a;
	int i, s;
	for (s = 1; 2 * s <= n - 1; s += s);          //计算s=2^log2(n-1)
	lowExt = 2 * (n - s);
	offset = 2 * s - 1;
	for (i = 2; i <= lowExt; i += 2)                    //最远层外部结点的比赛
		Play((offset + i) / 2, i - 1, i);
	if (n % 2 == 0)
		i = lowExt + 2;
	else
	{
		Play(n / 2, t[n - 1], lowExt + 1);
		i = lowExt + 3;
	}
	for (; i <= n; i += 2)
		Play((i - lowExt + n - 1) / 2, i - 1, i);
	return true;
}

void WinnerTree::Play(int k, int lc, int rc)
{
	t[k] = Winner(lc, rc);
	while (k > 1 && k % 2 != 0)
	{
		t[k / 2] = Winner(t[k - 1], t[k]);
		k /= 2;
	}
}

bool WinnerTree::RePlay(int i)
{
	if (i <= 0 || i > n)
		return false;
	int k, lc, rc;
	if (i <= lowExt)
	{
		k = (offset + i) / 2;
		lc = 2 * k - offset;
		rc = lc + 1;
	}
	else
	{
		k = (i - lowExt + n - 1) / 2;
		if (2 * k == n - 1)
		{
			lc == t[2 * k];
			rc = i;
		}
		else
		{
			lc = 2 * k - n + 1 + lowExt;
			rc = lc + 1;
		}
	}
	t[k] = Winner(lc, rc);
	k /= 2;
	for (; k >= 1; k /= 2)
	{
		if (2 * k + 1 > maxSize)
			t[k] = Winner(t[2 * k], rc + 1);
		else
			t[k] = Winner(t[2 * k], t[2 * k + 1]);
	}

}


sort::sort(int number1)
{
	count = 0;
	number = number1;
	arr = new int[number];
	temp = new int[number];
	for (int i = 0; i < number; i++)
	{
		arr[i] = rand();
		temp[i] = arr[i];

	}
}
void sort::bubble_Sort(int number)
{

	double time = 0;

	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	int temp = 0;
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		for (int j = i; j < number; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				count++;
			}
		}
	}
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	cout << "冒泡排序交换次数为： " << count << "次" << endl;
	cout << endl;
}

void sort::select_Sort(int number)
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  

	int min = 0;
	int temp = 0;
	int count = 0;
	int j = 0;
	int i = 0;
	for (i = 0; i < number - 1; i++)
	{
		min = i;
		for (j = i + 1; j < number; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (min != i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
			count++;
		}

	}
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	cout << "选择排序交换次数为： " << count << "次" << endl;
	cout << endl;
}
void sort::directInsert_Sort(int number)
{
	double time = 0;

	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	for (int i = 1; i < number; i++)
	{
		int j = 0;
		int temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
		{
			arr[j + 1] = arr[j];
			count++;
		}
		arr[j + 1] = temp;
	}
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	cout << "直接插入排序交换次数为： " << count << "次" << endl;
	cout << endl;
}

void sort::shell_Sort(int number)

{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	int jump = number;
	//标记本趟检测是否进行了交换，
	// 若进行了 则还有下次从头开始的检测，
	// 否则停止，继续改变jump的值 做另一趟排序
	bool isSwap;
	while (jump != 0)
	{
		//jump每次/2
		jump = jump / 2;
		do {
			int i = 1;
			//初始化表示没有进行交换
			isSwap = false;
			while (i <= number - jump)
			{
				if (arr[i] > arr[i + jump])
				{
					int temp = arr[i];
					arr[i] = arr[i + jump];
					arr[i + jump] = temp;
					count++;
					isSwap = true;
				}
				i++;
			}
		} while (isSwap == true);
	}
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time << "ms" << endl;
	cout << "希尔排序交换次数为： " << count << "次" << endl;
	cout << endl;
}
void sort::quick_Sort(int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int first = left;
	int last = right;
	int key = arr[left];
	if (left < right)
	{
		while (left < right)
		{
			while (left < right&&arr[right] >= key)
			{
				right--;
			}
			if (left < right)
			{
				arr[left++] = arr[right];
				count++;
			}
			while (left < right&&arr[left] < key)
			{
				left++;
			}
			if (left < right)
			{
				arr[right--] = arr[left];
				count++;
			}
		}
		arr[left] = key;

		quick_Sort(first, left - 1);
		quick_Sort(left + 1, last);
	}
}

void sort::heapify(int number, int element)
{
	int lchild = element * 2 + 1, rchild = lchild + 1;
	while (rchild < number)
	{
		if (arr[element] <= arr[lchild] && arr[element] <= arr[rchild])
		{
			return;
		}
		if (arr[lchild] <= arr[rchild])
		{
			int temp = arr[element];
			arr[element] = arr[lchild];
			arr[lchild] = temp;
			count++;
			element = lchild;
		}
		else
		{
			int temp = arr[element];
			arr[element] = arr[rchild];
			arr[rchild] = temp;
			count++;
			element = rchild;
		}
		lchild = element * 2 + 1;
		rchild = lchild + 1;
	}
	if (lchild < number&&arr[lchild] < arr[element])
	{
		int temp = arr[lchild];
		arr[lchild] = arr[element];
		arr[element] = temp;
		count++;
	}
}


void sort::heap_Sort(int number)
{
	double time = 0;

	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	int i;
	int size = number;
	for (i = size - 1; i >= 0; i--)
	{
		heapify(size, i);
	}
	while (size > 0)
	{
		int temp = arr[size - 1];
		arr[size - 1] = arr[0];
		arr[0] = temp;
		size--;
		heapify(size, 0);
	}
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	cout << "堆排序交换次数为： " << count << "次" << endl;
	cout << endl;
}

void sort::merge(int a, int b, int length, int number)
{
	int right;
	if (b + length - 1 >= number - 1)
	{
		right = number - b;
	}
	else
		right = length;
	int *temp = new int[length + right];
	int i = 0, j = 0;
	while (i <= length - 1 && j <= right - 1)
	{
		if (arr[a + i] <= arr[b + j])
		{
			temp[i + j] = arr[a + i];
			count++;
			i++;
		}
		else
		{
			temp[i + j] = arr[b + j];
			count++;
			j++;
		}
	}
	if (j == right)
	{
		memcpy(temp + i + j, arr + a + i, (length - i) * sizeof(int));
	}
	else if (i == length)
	{
		memcpy(temp + i + j, arr + b + j, (right - j) * sizeof(int));
	}
	memcpy(arr + a, temp, (right + length) * sizeof(int));

	delete[] temp;

}

void sort::merge_Sort(int number)
{
	double time = 0;

	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	int step = 1;
	while (step < number)
	{
		for (int i = 0; i <= number - step - 1; i += 2 * step)
		{
			merge(i, i + step, step, number);
		}
		step *= 2;
	}

	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	cout << "归并排序交换次数为： " << count << "次" << endl;
	cout << endl;
}

int  sort::maxbit(int number)
{
	int digit = 1;
	int p = 10;
	for (int i = 0; i < number; i++)
	{
		while (arr[i] >= p)
		{
			p *= 10;
			digit++;
		}
	}
	return digit;
}

void sort::radix_Sort(int number)
{
	double time = 0;

	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  
	int d = maxbit(number);
	int radix = 1;
	int *temp = new int[number];
	int Count[10] = { 0 };
	int i, j, k;
	for (i = 1; i <= d; i++)   //最外层循环 最大位数次排序
	{
		for (j = 0; j < 10; j++)
		{
			Count[j] = 0;
		}
		for (j = 0; j < number; j++)
		{
			k = (arr[j] / radix) % 10;
			Count[k]++;
		}
		for (j = 1; j < 10; j++)
		{
			Count[j] = Count[j - 1] + Count[j];  //将tmp中的位置依次分配给每个桶
		}
		for (j = number - 1; j >= 0; j--)     //将所有桶中记录依次收集到tmp中
		{
			k = (arr[j] / radix) % 10;
			temp[Count[k] - 1] = arr[j];
			Count[k]--;
		}
		for (j = 0; j < number; j++)
		{
			arr[j] = temp[j];
			count++;
		}
		radix *= 10;
	}
	delete[] temp;
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	cout << "基数排序交换次数为： " << count << "次" << endl;
	cout << endl;
}

void sort::binaryInsert_Sort(int left, int right)
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时 
	int temp, i, low, high, middle, k;
	for (i = left + 1; i <= right; i++)
	{
		temp = arr[i];
		low = left;
		high = i - 1;
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (temp < arr[middle])
			{
				high = middle - 1;
			}
			else
			{
				low = middle + 1;
			}
		}
		for (k = i - 1; k >= low; k--)
			arr[k + 1] = arr[k];
		arr[low] = temp;
		count++;
	}
	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	cout << "折半插入排序交换次数为： " << count << "次" << endl;
	cout << endl;

	
}

void sort::tournament_Sort()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时 
	WinnerTree WT(number);
	int *data;
	data = new int[number + 1];
	int i;
	for (i = 1; i <= number; i++)
		data[i] = arr[i - 1];
	WT.Initial(data, number);
	for (i = 1; i <= number; i++)
	{
		arr[i - 1] = WT.Winner();
		count++;
		WT.Update();
		WT.RePlay(WT.t[1]);
		if (WT.Winner() == MAX)
			break;
	}QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	cout << "锦标赛排序交换次数为： " << count << "次" << endl;
	cout << endl;
}

