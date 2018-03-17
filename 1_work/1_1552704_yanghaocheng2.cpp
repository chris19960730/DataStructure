#include"1_1552704_yanghaocheng.h"

int main()
{
	List table;
	int number;
	cout << "请输入考生人数:" << endl;
	cin >> number;
	cout << "请以此输入考生的考号，姓名，性别，年龄和报考类别:" << endl;
	Student temp;
	int id;
	string name;
	string sex;
	int age;
	string position;

	table.createhead();
	for (int i = 1; i <= number; i++)   
	{
		cin >> id >> name >> sex >> age >> position;
		temp.id = id;
		temp.name = name;
		temp.sex = sex;
		temp.age = age;
		temp.position = position;
		table.createlist(temp);				//把输入的信息写入到一个新建的节点中，通过循环构成单向链表
	}

	table.printlist();
	int location;
	int operation;
	operation = getchar();
	while (operation != EOF)
	{
		cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）" << endl;
		cout << "请选择你要进行的操作：";
		cin >> operation;
		switch (operation)
		{
		case 1:
		{
			cout << "请输入你要插入的考生的位置:";
			cin >> location;
			cout << "请依次输入考生的考号，姓名，性别，年龄和报考类别" << endl;
			cout << "考号" << "	 " << "姓名" << " 	 " << "性别" << "		" << "年龄" << "		" << "工作类别" << "		" << endl;
			cin >> id >> name >> sex >> age >> position;
			temp.id = id;
			temp.name = name;
			temp.sex = sex;
			temp.age = age;
			temp.position = position;
			table.insert(temp, location);
			table.printlist();
			break;
		}
		case 2:
		{
			cout << "请输入要删除的考生的考号:";
			cin >> id;
			table.fire(id);
			table.printlist();
			break;
		}
		case 3:
		{
			cout << "请输入要查询的考生的考号:";
			cin >> id;
			table.search(id);
			break;
		}
		case 4:
		{
			cout << "请选择想修改考生的考号：";
			cin >> id;
			table.modify(id);
			table.printlist();
			break;
		}
		case 5:
		{   
			cout << "请输入要统计的报考类别：";
			cin >> position;
			cout<<"报考"<<position<<"的考生有"<<table.statistic(position)<<"个人"<<endl;
			break;
		}
		case 0:
		{
			cout << "thanks for using this system." << endl;
			cout << "Directed by Chris Young "<<endl;
			exit(0);
			
		}
		}
	}

}