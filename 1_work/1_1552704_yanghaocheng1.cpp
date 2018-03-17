#include"1_1552704_yanghaocheng.h"
void List::createhead()
{
	first = nullptr;

}

void List::createlist(Student&data)
{

	Student *pnow = new Student();
	pnow->id = data.id;
	pnow->name = data.name;
	pnow->sex = data.sex;
	pnow->age = data.age;
	pnow->position = data.position;
	pnow->next = nullptr;
	if (first == nullptr)
	{
		first = pnow;
	}
	else
		last->next = pnow;
	last = pnow;

}

void List::printlist()
{
	cout << "  ����  "
		<< "  ����    "
		<< "  �Ա�   "
		<< "  ����   "
		<< "  �������  "
		<< endl;
	Student*p = first;
	while (p != nullptr)
	{
		cout << "  " << p->id << "  "
			<< "    " << p->name << "  "
			<< "    " << p->sex << "  "
			<< "    " << p->age << "  "
			<< "    " << p->position << "  "
			<< endl;
		p = p->next;
	}

}

void List::insert(Student&data, int location)
{
	int count = 0;
	Student*pnew = new Student();
	pnew->id = data.id;
	pnew->name = data.name;
	pnew->sex = data.sex;
	pnew->age = data.age;
	pnew->position = data.position;
	Student*pmove = first;
	while (pmove)
	{
		pmove = pmove->next;
		count++;
	}
	pmove = first;
	if (count + 1 < location)  // ����ʱǰ�������п�λʱ����
	{
		cout << "���벻�Ϸ���" << endl;
		exit(0);
	}
	for (int i = 1; i <location - 1; i++) // �ҵ���Ҫ�����λ�ã�����ָ���Ƶ���λ��
	{
		pmove = pmove->next;

	}
	if (location == 1) // ��ͷ��������
	{
		Student *temp = first;
		pnew->next = temp;
		first = pnew;
	}
	else               //�������
	{
		Student*ptemp = pmove->next;
		pmove->next = pnew;
		pnew->next = ptemp;
	}
}

void List::search(int id)
{
	Student*psearch = first;
	while (psearch->id != id)   // ͨ�����ű�����ֱ������id����Ѱ�ҵ�id��ͬ
	{
		psearch = psearch->next;
	}
	cout << "  ����  " << "  ����  " << "  �Ա�  " << "  ����  " << "  �������  " << endl;
	cout << "  " << psearch->id << "  "
		<< "    " << psearch->name << "  "
		<< "    " << psearch->sex << "  "
		<< "    " << psearch->age << "  "
		<< "    " << psearch->position << "  "
		<< endl;
}

void List::fire(int id)
{
	Student*pmove = first;
	if (pmove->id == id)  //ɾ����ͷ�����
	{
		if (first->next)  // 1.����ͷ�� ���������������
		{
			cout << "��ɾ���Ŀ�������Ϣ�ǣ�  " << endl;
			cout << "����" << "    " << "����" << "     " << "�Ա�" << "    " << "����" << "    " << "�������" << "    " << endl;
			cout << first->id
				<< "	  "
				<< first->name
				<< "	  "
				<< first->sex
				<< "	  "
				<< first->age
				<< "  	  "
				<< first->position
				<< endl;
			first = pmove->next;
			delete pmove;
		}
		else // 2.�������
		{
			cout << "��ɾ���Ŀ�������Ϣ�ǣ�  " << endl;
			cout << "����" << "    " << "����" << "     " << "�Ա�" << "    " << "����" << "    " << "�������" << "    " << endl;
			cout << pmove->id
				<< "	  "
				<< pmove->name
				<< "	  "
				<< pmove->sex
				<< "	  "
				<< pmove->age
				<< "  	  "
				<< pmove->position
				<< endl;
			delete pmove;
			first = nullptr;
		}

	}
	else // ���������
	{
		while (pmove->next->id != id)
			pmove = pmove->next;
		cout << "��ɾ���Ŀ�������Ϣ�ǣ�  " << endl;
		cout << "����" << "    " << "����" << "     " << "�Ա�" << "    " << "����" << "    " << "�������" << "    " << endl;
		cout << pmove->next->id
			<< "	  "
			<< pmove->next->name
			<< "	  "
			<< pmove->next->sex
			<< "	  "
			<< pmove->next->age
			<< "  	  "
			<< pmove->next->position
			<< endl;
		Student*ptemp = pmove->next;
		pmove->next = ptemp->next;
		delete ptemp;
	}
}

void List::modify(int id)
{

	Student*pmove = first;
	while (pmove->id != id)
		pmove = pmove->next;
	int judgement;
	int ID;
	string NAME;
	string SEX;
	int AGE;
	string POSITION;
	cout << "��ѡ����Ҫ�޸ĵ���Ϣ��1 �����ţ�2 ����������3 �����Ա�4 �������䣬5 ���������" << endl;
	cin >> judgement;
	switch (judgement)
	{
	case 1:
	{
		cin >> ID;
		pmove->id = ID;
		break;
	}
	case 2:
	{
		cin >> NAME;
		pmove->name = NAME;
		break;
	}
	case 3:
	{
		cin >> SEX;
		pmove->sex = SEX;
		break;
	}
	case 4:
	{
		cin >> AGE;
		pmove->age = AGE;
		break;
	}
	case 5:
	{
		cin >> POSITION;
		pmove->position = POSITION;
		break;
	}
	}


}
int List::statistic(string position)
{
	int total = 0;
	Student*pmove = first;
	while (pmove)  
	{
		if (pmove->position == position)
		{
			total++;				//����ȫ�����ݺ�������ͬ�������+1��ʵ��ͳ�ƵĹ���
		}
		pmove = pmove->next;
	}
	return total;
}