#include"3_1552704_yanghaocheng.h"
int main()
{
	cout << "请输入迷宫的行数和列数：";
	char element;
	cin >> row >> line;
	cout << "请画个地图：" << endl;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= line; j++)
		{
			cin >> element;
			maze[i][j] = element;
		}
	}
	cout << "请输入迷宫的起点坐标和终点坐标(注：若要输入" << "（1,1）" << "则输入 1 1：";
	cin >> Brow >> Bline >> Erow >> Eline;
	cout << endl;
	find(Brow, Bline);
	system("pause");
}