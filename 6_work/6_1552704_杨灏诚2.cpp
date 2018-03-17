#include"6_1552704_杨灏诚.h"
int main()
{
	familyTree tree;
	string name;
	int Childnumber;
	cout << "首先建立一个家谱！" << endl;
	cout << "请输入祖先的姓名: " << endl;
	cin >> name;
	tree.createRoot(name);

	char operation;

	operation = getchar();

	while (operation != EOF)
	{
		cout << endl;
		cout << "请输入要执行的操作：A代表建立家庭，B代表添加儿女，C代表解散家庭，D代表更改家庭成员姓名，E代表退出程序 " << endl;
		cin >> operation;
		switch (operation)
		{
		case 'A':
		{
			cout << "请输入要建立家庭的人的名字： ";
			cin >> name;
			cout << "请输入" << name << "的儿女的人数： ";
			cin >> Childnumber;
			tree.addperson(name, Childnumber);
			break;
		}
		case 'B':
		{
			cout << "请输入要添加儿子（或女儿）的人的姓名： ";
			cin >> name;
			tree.addperson(name, 1);
			break;
		}

		case 'C':
		{
			cout << "请输入要解散的家庭的人的名字： ";
			cin >> name;
			tree.divorce(name);
			break;
		}
		case 'D':
		{
			cout << "请输入要更改姓名的人的目前名字： ";
			cin >> name;
			tree.changeName(name);
			break;
		}
		case 'E':
		{
			cout << "谢谢使用！再见！" << endl;
			exit(0);
		}
		}
	}
}