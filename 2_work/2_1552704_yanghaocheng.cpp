#include"2_1552704_yanghaocheng.h"

int main()
{
	int number;
	int start;
	int luckyNum;
	int remains;
	cout << "������������Ϸ��������N��";
	cin >> number;
	cout << "��������Ϸ��ʼ��λ��S: ";
	cin >> start;
	cout << "��������������M: ";
	cin >> luckyNum;
	cout << "������ʣ�����������K: ";
	cin >> remains;
	createList(number, start, luckyNum, remains);
	system("pause");

}