#include"2_1552704_yanghaocheng.h"

int main()
{
	int number;
	int start;
	int luckyNum;
	int remains;
	cout << "请输入生死游戏的总人数N：";
	cin >> number;
	cout << "请输入游戏开始的位置S: ";
	cin >> start;
	cout << "请输入死亡数字M: ";
	cin >> luckyNum;
	cout << "请输入剩余的生者人数K: ";
	cin >> remains;
	createList(number, start, luckyNum, remains);
	system("pause");

}