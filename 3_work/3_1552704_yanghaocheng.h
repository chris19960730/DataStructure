#pragma once
#include<iostream>
using namespace std;

int Brow;	//�Թ���������
int Bline;	//�Թ����������
int Erow;	//�Թ��յ������
int Eline;	//�Թ��յ�������
int row;	//����
int line;	//����
char maze[100][100] = { 0 };		//�Թ�Ĭ�ϴ�С100*100
char step[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } }; //����������

char NextisAccess(int row, int line)  //�ж�����Ϊ��row,line����λ���Ƿ�����ߵ�ͨ
{
	if (maze[row][line] == '0')
	{
		return 1;
	}
	return 0;
}
void show() // �������Թ���ӡ����
{
	for (int i = 0; i <= row + 1; i++)
	{
		for (int j = 0; j <= line + 1; j++)
		{
			if (i == 0 || i == row + 1 || j == 0 || j == line + 1)
				maze[i][j] = ' ';
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

void statistic()  //���Թ�ÿһ��������λ�ô�ӡ����
{
	cout << "�Թ�·����";
	for (int i = 0; i <= row + 1; i++)
	{
		for (int j = 0; j <= line + 1; j++)
		{
			if (maze[i][j] == 'X')
			{
				if (!(i == Erow&&j == Eline))
					cout << '<' << i << ',' << j << '>' << "-->" << " ";
				else
					cout << '<' << i << ',' << j << '>';
			}
		}
	}
}
void find(int Brow, int Bline)  //���ݷ�Ѱ��ͨ·
{
	int n;
	if (Brow == Erow&&Bline == Eline)  //���ݵ���ֹ���� ��Ѱ�ҵ�������յ�����һ��ʱ������������Թ�
	{
		maze[Brow][Bline] = 'X';
		show();
		statistic();
		cout << endl;
		maze[Brow][Bline] = '0';
	}
	else
	{
		for (n = 0; n < 4; n++)    //�����������ĸ��������ν�������(�����ҵ�ȫ����ͨ·)
		{
			if (NextisAccess(Brow + step[n][0], Bline + step[n][1]))
			{
				maze[Brow][Bline] = 'X';   //(���߹���λ�ñ��ΪX)
				find(Brow + step[n][0], Bline + step[n][1]);
				maze[Brow][Bline] = '0';//����ǰһ��·�����ã�
			}
		}
	}

}