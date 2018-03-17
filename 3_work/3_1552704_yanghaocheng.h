#pragma once
#include<iostream>
using namespace std;

int Brow;	//迷宫起点横坐标
int Bline;	//迷宫起点纵坐标
int Erow;	//迷宫终点横坐标
int Eline;	//迷宫终点纵坐标
int row;	//行数
int line;	//列数
char maze[100][100] = { 0 };		//迷宫默认大小100*100
char step[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } }; //辅助方向量

char NextisAccess(int row, int line)  //判断坐标为（row,line）的位置是否可以走得通
{
	if (maze[row][line] == '0')
	{
		return 1;
	}
	return 0;
}
void show() // 将整个迷宫打印出来
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

void statistic()  //将迷宫每一步的坐标位置打印出来
{
	cout << "迷宫路径：";
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
void find(int Brow, int Bline)  //回溯法寻找通路
{
	int n;
	if (Brow == Erow&&Bline == Eline)  //回溯的终止条件 当寻找的坐标和终点坐标一致时，结束并输出迷宫
	{
		maze[Brow][Bline] = 'X';
		show();
		statistic();
		cout << endl;
		maze[Brow][Bline] = '0';
	}
	else
	{
		for (n = 0; n < 4; n++)    //对上下左右四个方向依次进行行走(用于找到全部的通路)
		{
			if (NextisAccess(Brow + step[n][0], Bline + step[n][1]))
			{
				maze[Brow][Bline] = 'X';   //(将走过的位置标记为X)
				find(Brow + step[n][0], Bline + step[n][1]);
				maze[Brow][Bline] = '0';//（将前一条路径重置）
			}
		}
	}

}