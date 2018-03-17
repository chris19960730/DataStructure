#include"10_1552704_yanghaocheng.h"
int main()
{
	cout << "**     �����㷨�Ƚ�     **"
		<< endl
		<< "========================="
		<< endl
		<< "**     1---ð������     **"
		<< endl
		<< "**     2---ѡ������     **"
		<< endl
		<< "**     3---ֱ�Ӳ������� **"
		<< endl
		<< "**     4---ϣ������     **"
		<< endl
		<< "**     5---��������     **"
		<< endl
		<< "**     6---������       **"
		<< endl
		<< "**     7---�鲢����     **"
		<< endl
		<< "**     8---��������     **"
		<< endl
		<< "**     9---�۰�������� **"
		<< endl
		<< "**     10---����������  **"
		<< endl
		<< "**     11---�˳�����    **"
		<< endl
		<< "========================="
		<< endl;
	int number;

	cout << "������Ҫ������������ĸ����� ";
	cin >> number;
	sort SortAL(number);
	int operation = 0;
	while (operation != EOF)
	{
		cout << "��ѡ�������㷨�� ";
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
			QueryPerformanceCounter(&nBeginTime);//��ʼ��ʱ 

			SortAL.quick_Sort(0, number - 1);


			QueryPerformanceCounter(&nEndTime);//ֹͣ��ʱ  
			time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//�������ִ��ʱ�䵥λΪs  
			cout << "����ִ��ʱ�䣺" << time * 1000 << "ms" << endl;
			cout << "�������򽻻�����Ϊ�� " << SortAL.Count() << "��" << endl;
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
			cout << "ллʹ�ñ�����" << endl;
			exit(0);
		}
		}
	}


}