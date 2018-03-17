#pragma once

#include<iostream>

using namespace std;
int queenNumber;      //�ʺ����
int solutionNumebr = 0;		//�ⷨ��������ʼ��Ϊ0��
char chessboard[100][100] = { 0 };  //���̴�С��Ĭ��Ϊ100*100

bool nextOk(int row, int line)		//������꣨row,line��λ���Ƿ���Է��ûʺ�
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < queenNumber; j++)
		{
			if (chessboard[i][j] == 'X')
			if (j == line || abs(j - line) == abs(i - row)) // ���ǰһ���ʺ��λ�ú͸�λ���Ƿ�ͬ�л�ͬ�Խ���
					return false;
		}
	}
	return true;
}
void print()  //���ʺ������չʾ�����������ܽⷨ��+1
{
	solutionNumebr++;

	for (int i = 0; i < queenNumber; i++)
	{
		for (int j = 0; j < queenNumber; j++)
		{
			cout << chessboard[i][j] << " ";
		}
		cout << endl;
	}
	cout << "*********************" << endl;
}
void createTable(int rownumber)
{
	if (rownumber >= queenNumber)  //������ֹ���������������һ���ʺ���ֹ
	{
		print();
	}
	else
	{
		for (int j = 0; j < queenNumber; j++)  //�����в�������ȫ������
			chessboard[rownumber][j] = '0';
		for (int j = 0; j < queenNumber; j++)
		{
			chessboard[rownumber][j] = 'X';		//���ûʺ󲢽����жϣ�������Ա���еݹ�
			if (nextOk(rownumber, j))    
				createTable(rownumber + 1);
			chessboard[rownumber][j] = '0';     //��һ�ֽⷨ�����󣬽���������
		}
	}
}
