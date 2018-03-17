#include"9_1552704_yanghaocheng.h"
int main()
{
	int number = 0;
	cout << "***      二叉排序树      ***" << endl;
	cout << "=========================== " << endl;
	cout << "**  1----- 建立二叉树     ***" << endl;
	cout << "**  2----- 插入元素       ***" << endl;
	cout << "**  3----- 查询元素       ***" << endl;
	cout << "**  4----- 退出程序       ***" << endl;

	while (number != -1)
	{
		cout << endl;
		cout << "请选择要进行的操作： " << endl;
		cin >> number;
		switch (number)
		{
		case 1:
		{
			cout << "请输入数据建立二叉树：(输入-1表示输入结束) " << endl;
			tree.buildTree();
			cout << "二叉排序树是： " << endl;
			tree.show(tree.Return());
			break;
		}
		case 2:
		{
			int input;
			cout << "请输入要插入的数据： ";
			cin >> input;
			tree.insert(input, tree.Return());
			cout << "二叉排序树是： " << endl;
			tree.show(tree.Return());
			break;
		}
		case 3:
		{
			int searchNumber;
			cout << "请输入要查询的元素： ";
			cin >> searchNumber;
			tree.find(searchNumber, tree.Return());
			break;
		}
		case 4:
		{
			exit(0);
		}
		}
	}
}