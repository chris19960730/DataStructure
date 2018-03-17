#include"4_1552704_yanghaocheng.h"
int main()
{

	cout << "现有N X N的棋盘，放入N个皇后，要求所有皇后不在同一行，列和同一斜线上！" << endl;
	cout << "请输入皇后的个数： ";
	cin >> queenNumber;
	createTable(0);
	cout << endl;;
	cout << "共有" << solutionNumebr << "种解法!" << endl;
	system("pause");

}