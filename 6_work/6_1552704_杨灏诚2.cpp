#include"6_1552704_��尳�.h"
int main()
{
	familyTree tree;
	string name;
	int Childnumber;
	cout << "���Ƚ���һ�����ף�" << endl;
	cout << "���������ȵ�����: " << endl;
	cin >> name;
	tree.createRoot(name);

	char operation;

	operation = getchar();

	while (operation != EOF)
	{
		cout << endl;
		cout << "������Ҫִ�еĲ�����A��������ͥ��B������Ӷ�Ů��C�����ɢ��ͥ��D������ļ�ͥ��Ա������E�����˳����� " << endl;
		cin >> operation;
		switch (operation)
		{
		case 'A':
		{
			cout << "������Ҫ������ͥ���˵����֣� ";
			cin >> name;
			cout << "������" << name << "�Ķ�Ů�������� ";
			cin >> Childnumber;
			tree.addperson(name, Childnumber);
			break;
		}
		case 'B':
		{
			cout << "������Ҫ��Ӷ��ӣ���Ů�������˵������� ";
			cin >> name;
			tree.addperson(name, 1);
			break;
		}

		case 'C':
		{
			cout << "������Ҫ��ɢ�ļ�ͥ���˵����֣� ";
			cin >> name;
			tree.divorce(name);
			break;
		}
		case 'D':
		{
			cout << "������Ҫ�����������˵�Ŀǰ���֣� ";
			cin >> name;
			tree.changeName(name);
			break;
		}
		case 'E':
		{
			cout << "ллʹ�ã��ټ���" << endl;
			exit(0);
		}
		}
	}
}