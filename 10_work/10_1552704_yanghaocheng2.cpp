#include"10_1552704_yanghaocheng.h"
int main()
{
	cout << "**     排序算法比较     **"
		<< endl
		<< "========================="
		<< endl
		<< "**     1---冒泡排序     **"
		<< endl
		<< "**     2---选择排序     **"
		<< endl
		<< "**     3---直接插入排序 **"
		<< endl
		<< "**     4---希尔排序     **"
		<< endl
		<< "**     5---快速排序     **"
		<< endl
		<< "**     6---堆排序       **"
		<< endl
		<< "**     7---归并排序     **"
		<< endl
		<< "**     8---基数排序     **"
		<< endl
		<< "**     9---折半插入排序 **"
		<< endl
		<< "**     10---锦标赛排序  **"
		<< endl
		<< "**     11---退出程序    **"
		<< endl
		<< "========================="
		<< endl;
	int number;

	cout << "请输入要产生的随机数的个数： ";
	cin >> number;
	sort SortAL(number);
	int operation = 0;
	while (operation != EOF)
	{
		cout << "请选择排序算法： ";
		cin >> operation;
		switch (operation)
		{
		case 1:
		{
			SortAL.bubble_Sort(number);
			SortAL.resetArr();
			break;
		}
		case 2:
		{
			SortAL.select_Sort(number);
			SortAL.resetArr();
			break;
		}
		case 3:
		{
			SortAL.directInsert_Sort(number);
			SortAL.resetArr();
			break;

		}
		case 4:
		{
			SortAL.shell_Sort(number);
			SortAL.resetArr();
			break;
		}
		case 5:
		{
			double time = 0;
			LARGE_INTEGER nFreq;
			LARGE_INTEGER nBeginTime;
			LARGE_INTEGER nEndTime;
			QueryPerformanceFrequency(&nFreq);
			QueryPerformanceCounter(&nBeginTime);//开始计时 

			SortAL.quick_Sort(0, number - 1);


			QueryPerformanceCounter(&nEndTime);//停止计时  
			time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
			cout << "程序执行时间：" << time * 1000 << "ms" << endl;
			cout << "快速排序交换次数为： " << SortAL.Count() << "次" << endl;
			cout << endl;
			SortAL.resetArr();
			break;
		}
		case 6:
		{
			SortAL.heap_Sort(number);
			SortAL.resetArr();
			break;
		}
		case 7:
		{
			SortAL.merge_Sort(number);
			SortAL.resetArr();
			break;
		}
		case 8:
		{
			SortAL.radix_Sort(number);
			SortAL.resetArr();
			break;
		}
		case 9:
		{
			SortAL.binaryInsert_Sort(0, number);
			SortAL.resetArr();
			break;
		}
		case 10:
		{
			SortAL.tournament_Sort();
			SortAL.resetArr();
			break;
		}
		case 11:
		{
			cout << "谢谢使用本程序！" << endl;
			exit(0);
		}
		}
	}


}