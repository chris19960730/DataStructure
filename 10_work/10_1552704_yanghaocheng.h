#pragma once
#include<iostream>
#include<windows.h>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

extern int MAX;

class WinnerTree    //�������������࣬ʤ������
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

class sort {                                      //������
public:
	friend class WinnerTree;
	sort(int number1);
	friend class WinnerTree;
	void bubble_Sort(int number);						//ð������
	void select_Sort(int number);						//ѡ������
	void directInsert_Sort(int number);					// ֱ�Ӳ�������
	void shell_Sort(int number);						//ϣ������
	void quick_Sort(int left, int right);				//��������
	void heapify(int number, int element);				//������������
	void heap_Sort(int number);							// ������
	void merge(int a, int b, int length, int number);	//�鲢����������
	void merge_Sort(int number);						//�鲢����
	int maxbit(int number);								//���������������������λ����	
	void radix_Sort(int number);						//��������
	void binaryInsert_Sort(int left, int right);		//�۰��������
	void tournament_Sort();								//����������
	int Count()											//��¼��������
	{
		return count;
	}
	void resetArr()										//�����������
	{
		count = 0;
		for (int i = 0; i < number; i++)
		{
			arr[i] = temp[i];
		}
	}
private:
	int count;				//��¼��������������
	int *arr;				//�洢�����������
	int *temp;				//��¼��һ�����ɵ��������������Ϊ�����㷨��ʼ���������ʹ��
	int number;				//������ĸ���

};


