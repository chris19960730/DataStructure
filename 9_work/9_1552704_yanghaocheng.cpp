#include"9_1552704_yanghaocheng.h"
int main()
{
	int number = 0;
	cout << "***      ����������      ***" << endl;
	cout << "=========================== " << endl;
	cout << "**  1----- ����������     ***" << endl;
	cout << "**  2----- ����Ԫ��       ***" << endl;
	cout << "**  3----- ��ѯԪ��       ***" << endl;
	cout << "**  4----- �˳�����       ***" << endl;

	while (number != -1)
	{
		cout << endl;
		cout << "��ѡ��Ҫ���еĲ����� " << endl;
		cin >> number;
		switch (number)
		{
		case 1:
		{
			cout << "���������ݽ�����������(����-1��ʾ�������) " << endl;
			tree.buildTree();
			cout << "�����������ǣ� " << endl;
			tree.show(tree.Return());
			break;
		}
		case 2:
		{
			int input;
			cout << "������Ҫ��������ݣ� ";
			cin >> input;
			tree.insert(input, tree.Return());
			cout << "�����������ǣ� " << endl;
			tree.show(tree.Return());
			break;
		}
		case 3:
		{
			int searchNumber;
			cout << "������Ҫ��ѯ��Ԫ�أ� ";
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