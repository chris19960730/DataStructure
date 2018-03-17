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
	cout << "  考号  "
		<< "  姓名    "
		<< "  性别   "
		<< "  年龄   "
		<< "  工作类别  "
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
	if (count + 1 < location)  // 插入时前方仍留有空位时报错
	{
		cout << "输入不合法！" << endl;
		exit(0);
	}
	for (int i = 1; i <location - 1; i++) // 找到将要插入的位置，并把指针移到该位置
	{
		pmove = pmove->next;

	}
	if (location == 1) // 表头插入的情况
	{
		Student *temp = first;
		pnew->next = temp;
		first = pnew;
	}
	else               //其他情况
	{
		Student*ptemp = pmove->next;
		pmove->next = pnew;
		pnew->next = ptemp;
	}
}

void List::search(int id)
{
	Student*psearch = first;
	while (psearch->id != id)   // 通过考号遍历表，直到表内id和所寻找的id相同
	{
		psearch = psearch->next;
	}
	cout << "  考号  " << "  姓名  " << "  性别  " << "  年龄  " << "  工作类别  " << endl;
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
	if (pmove->id == id)  //删除表头的情况
	{
		if (first->next)  // 1.除表头外 还有其他结点的情况
		{
			cout << "你删除的考生的信息是：  " << endl;
			cout << "考号" << "    " << "姓名" << "     " << "性别" << "    " << "年龄" << "    " << "工作类别" << "    " << endl;
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
		else // 2.其他情况
		{
			cout << "你删除的考生的信息是：  " << endl;
			cout << "考号" << "    " << "姓名" << "     " << "性别" << "    " << "年龄" << "    " << "工作类别" << "    " << endl;
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
	else // 其他的情况
	{
		while (pmove->next->id != id)
			pmove = pmove->next;
		cout << "你删除的考生的信息是：  " << endl;
		cout << "考号" << "    " << "姓名" << "     " << "性别" << "    " << "年龄" << "    " << "工作类别" << "    " << endl;
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
	cout << "请选择你要修改的信息：1 代表考号，2 代表姓名，3 代表性别，4 代表年龄，5 代表报考类别" << endl;
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
			total++;				//遍历全表，数据和所求相同则计数器+1，实现统计的功能
		}
		pmove = pmove->next;
	}
	return total;
}