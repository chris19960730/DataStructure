#include"1_1552704_yanghaocheng.h"

int main()
{
	List table;
	int number;
	cout << "�����뿼������:" << endl;
	cin >> number;
	cout << "���Դ����뿼���Ŀ��ţ��������Ա�����ͱ������:" << endl;
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
		table.createlist(temp);				//���������Ϣд�뵽һ���½��Ľڵ��У�ͨ��ѭ�����ɵ�������
	}

	table.printlist();
	int location;
	int operation;
	operation = getchar();
	while (operation != EOF)
	{
		cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������" << endl;
		cout << "��ѡ����Ҫ���еĲ�����";
		cin >> operation;
		switch (operation)
		{
		case 1:
		{
			cout << "��������Ҫ����Ŀ�����λ��:";
			cin >> location;
			cout << "���������뿼���Ŀ��ţ��������Ա�����ͱ������" << endl;
			cout << "����" << "	 " << "����" << " 	 " << "�Ա�" << "		" << "����" << "		" << "�������" << "		" << endl;
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
			cout << "������Ҫɾ���Ŀ����Ŀ���:";
			cin >> id;
			table.fire(id);
			table.printlist();
			break;
		}
		case 3:
		{
			cout << "������Ҫ��ѯ�Ŀ����Ŀ���:";
			cin >> id;
			table.search(id);
			break;
		}
		case 4:
		{
			cout << "��ѡ�����޸Ŀ����Ŀ��ţ�";
			cin >> id;
			table.modify(id);
			table.printlist();
			break;
		}
		case 5:
		{   
			cout << "������Ҫͳ�Ƶı������";
			cin >> position;
			cout<<"����"<<position<<"�Ŀ�����"<<table.statistic(position)<<"����"<<endl;
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