#pragma once

#include<iostream>

using namespace std;
int queenNumber;      //皇后个数
int solutionNumebr = 0;		//解法总数（初始化为0）
char chessboard[100][100] = { 0 };  //棋盘大小，默认为100*100

bool nextOk(int row, int line)		//检查坐标（row,line）位置是否可以放置皇后
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < queenNumber; j++)
		{
			if (chessboard[i][j] == 'X')
			if (j == line || abs(j - line) == abs(i - row)) // 如果前一个皇后的位置和该位置是否同行或同对角线
					return false;
		}
	}
	return true;
}
void print()  //将皇后的排列展示出来，并对总解法数+1
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
	if (rownumber >= queenNumber)  //回溯终止条件，放置完最后一个皇后终止
	{
		print();
	}
	else
	{
		for (int j = 0; j < queenNumber; j++)  //将进行操作的行全部置零
			chessboard[rownumber][j] = '0';
		for (int j = 0; j < queenNumber; j++)
		{
			chessboard[rownumber][j] = 'X';		//放置皇后并进行判断，如果可以便进行递归
			if (nextOk(rownumber, j))    
				createTable(rownumber + 1);
			chessboard[rownumber][j] = '0';     //第一种解法结束后，将棋盘清零
		}
	}
}
