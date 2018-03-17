
#include"6_1552704_��尳�.h"
familyTree::familyTree()    //��ʼ�����ڵ�
{
	root = new person();
	current = NULL;
}

bool familyTree::Parent()  //����ǰһ���ڵ�
{
	person*p = current;
	if (current == NULL || current == root)
	{
		current = NULL;
		return false;
	}
	return FindParent(root, p);
}

bool familyTree::FindParent(person *t, person *p)  //�ҵ���t���Ϊ���ڵ��p����ǰһ���ڵ�
{
	if (t->firstChild == p)  //p���ĸ��ڵ��Ǹ��ڵ�����
	{
		current = t;
		return true;
	}
	else      //p���ĸ��ڵ㲻�Ǹ��ڵ�����
	{

		person*q = t->firstChild;
		while (q != NULL && (q->nextSibling != p && q->firstChild != p))
		{
			if (FindParent(q, p))
				return true;
			q = q->nextSibling;
		}
		if (q != NULL && (q->firstChild == p || q->nextSibling == p))
		{
			current = q;
			return true;
		}
		else
		{
			current = NULL;
			return false;
		}
	}
}

bool familyTree::Find(person*p, string name)  //�ҵ���p���Ϊ���ڵ㣬���洢����ϢΪname
{
	bool result = false;
	if (p->name == name)  //���ڵ㼴Ϊ���ҵĽ��
	{
		result = true;
		current = p;
	}
	else 
	{
		person*q = p->firstChild;
		while (q != NULL && !(result = Find(q, name)))
		{
			q = q->nextSibling;
		}
	}
	return result;
}

void familyTree::createRoot(string name)  // ����������������
{
	root->name = name;
	cout << "�˼��׵������ǣ� " << name;
}

void familyTree::addperson(string name, int number) //��������������Ա
{
	string Childname;
	Find(root, name);
	cout << "����������" << name << "�Ķ�Ů�����֣� ";
	for (int i = 1; i <= number; i++)
	{
		cin >> Childname;
		person*pmove = current;
		if (pmove->firstChild == NULL)
		{
			pmove->firstChild = new person();
			pmove->firstChild->name = Childname;
		}
		else {
			pmove = current->firstChild;
			while (pmove->nextSibling)
			{
				pmove = pmove->nextSibling;
			}
			pmove->nextSibling = new person();
			pmove->nextSibling->name = Childname;
		}
	}
	cout << name << "�ĵ�һ�������ǣ� ";
	person*pmove = current->firstChild;
	while (pmove)
	{
		cout << pmove->name << " ";
		pmove = pmove->nextSibling;
	}
}

void familyTree::changeName(string name)//���ĳ�Աname������
{
	string nowName;
	cout << "��������ĺ�����֣� ";
	cin >> nowName;
	cout << name << "�Ѿ�����Ϊ";
	Find(root, name);
	current->name = nowName;
	cout << nowName;

}

void familyTree::realse(person*p) //ɾ��p��㼰�������ӽڵ�
{
	if (p == NULL)
	{
		return;
	}
	else
	{
		realse(p->firstChild);
		realse(p->nextSibling);
		delete p;
	}

}
void familyTree::divorce(string name)	//��ɢ��Աname�ļ�ͥ
{
	cout << "Ҫ��ɢ�ļ�ͥ��: " << name << endl;
	if (name == root->name)
	{
		cout << "���ȱ�ɾ�������׻ٻ���ϵͳ�жϣ�" << endl;
		exit(0);
	}
	else
	{
		Find(root, name);
		person*pmove = current->firstChild;
		if (pmove == NULL)
			cout << "���ź�" << name << "û������";
		else
		{
			cout << name << "�ĵ�һ�������ǣ� ";
			while (pmove)
			{
				cout << pmove->name << " ";
				pmove = pmove->nextSibling;
			}
		}
		person*ptemp = current;
		person*p = ptemp;
		Parent();
		person*before1 = current;
		if (ptemp->nextSibling) // �ֵܣ��ж���û���ֵ�
		{
			if (before1->firstChild == ptemp)
			{
				before1->firstChild = ptemp->nextSibling;
				ptemp->nextSibling = NULL;
				realse(p);
			}
			else
			{
				before1->nextSibling = ptemp->nextSibling;
				ptemp->nextSibling = NULL;
				realse(p);
			}
		}
		else
		{
			realse(ptemp);
		}
	}

}
