#pragma once
#include<iostream>
#include<windows.h>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

extern int MAX;

class WinnerTree    //锦标赛排序辅助类，胜利树类
{
	friend class Sort;   
public:
	
	WinnerTree(int size)
	{
		maxSize = size;
		n = 0;
		t = new int[maxSize];
	}
	~WinnerTree()
	{
		delete[]t;
	}
	bool Initial(int *a, int size);
	bool RePlay(int i);
	int *t;
	void Update()
	{
		e[t[1]] = MAX;
	}
	int Winner()
	{
		return (n != 0) ? e[t[1]] : 0;
	}
	int Winner(int i)
	{
		return (i < n) ? t[i] : 0;
	}
	int Winner(int a, int b)
	{
		return (e[a] <= e[b]) ? a : b;
	}
private:
	int maxSize;
	int n;
	int lowExt;
	int offset;
	
	int *e;
	void Play(int k, int lc, int rc);
};

class sort {                                      //排序类
public:
	friend class WinnerTree;
	sort(int number1);
	friend class WinnerTree;
	void bubble_Sort(int number);						//冒泡排序
	void select_Sort(int number);						//选择排序
	void directInsert_Sort(int number);					// 直接插入排序
	void shell_Sort(int number);						//希尔排序
	void quick_Sort(int left, int right);				//快速排序
	void heapify(int number, int element);				//堆排序辅助函数
	void heap_Sort(int number);							// 堆排序
	void merge(int a, int b, int length, int number);	//归并排序辅助函数
	void merge_Sort(int number);						//归并排序
	int maxbit(int number);								//基数排序辅助函数（找最大位数）	
	void radix_Sort(int number);						//基数排序
	void binaryInsert_Sort(int left, int right);		//折半插入排序
	void tournament_Sort();								//锦标赛排序
	int Count()											//记录交换次数
	{
		return count;
	}
	void resetArr()										//重置随机数组
	{
		count = 0;
		for (int i = 0; i < number; i++)
		{
			arr[i] = temp[i];
		}
	}
private:
	int count;				//记录交换次数计数器
	int *arr;				//存储随机数的数组
	int *temp;				//记录第一次生成的随机数，并用来为其他算法初始化随机数组使用
	int number;				//随机数的个数

};


