#include"3_1552704_yanghaocheng.h"
int main()
{
	cout << "�������Թ���������������";
	char element;
	cin >> row >> line;
	cout << "�뻭����ͼ��" << endl;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= line; j++)
		{
			cin >> element;
			maze[i][j] = element;
		}
	}
	cout << "�������Թ������������յ�����(ע����Ҫ����" << "��1,1��" << "������ 1 1��";
	cin >> Brow >> Bline >> Erow >> Eline;
	cout << endl;
	find(Brow, Bline);
	system("pause");
}