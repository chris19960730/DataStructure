
#include"6_1552704_杨灏诚.h"
familyTree::familyTree()    //初始化根节点
{
	root = new person();
	current = NULL;
}

bool familyTree::Parent()  //返回前一个节点
{
	person*p = current;
	if (current == NULL || current == root)
	{
		current = NULL;
		return false;
	}
	return FindParent(root, p);
}

bool familyTree::FindParent(person *t, person *p)  //找到以t结点为根节点的p结点的前一个节点
{
	if (t->firstChild == p)  //p结点的父节点是根节点的情况
	{
		current = t;
		return true;
	}
	else      //p结点的父节点不是根节点的情况
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

bool familyTree::Find(person*p, string name)  //找到以p结点为根节点，结点存储的信息为name
{
	bool result = false;
	if (p->name == name)  //根节点即为所找的结点
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

void familyTree::createRoot(string name)  // 建立家谱树的祖先
{
	root->name = name;
	cout << "此家谱的祖先是： " << name;
}

void familyTree::addperson(string name, int number) //向家谱树中增添成员
{
	string Childname;
	Find(root, name);
	cout << "请依次输入" << name << "的儿女的名字： ";
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
	cout << name << "的第一代子孙是： ";
	person*pmove = current->firstChild;
	while (pmove)
	{
		cout << pmove->name << " ";
		pmove = pmove->nextSibling;
	}
}

void familyTree::changeName(string name)//更改成员name的姓名
{
	string nowName;
	cout << "请输入更改后的名字： ";
	cin >> nowName;
	cout << name << "已经更名为";
	Find(root, name);
	current->name = nowName;
	cout << nowName;

}

void familyTree::realse(person*p) //删除p结点及其所有子节点
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
void familyTree::divorce(string name)	//解散成员name的家庭
{
	cout << "要解散的家庭是: " << name << endl;
	if (name == root->name)
	{
		cout << "祖先被删除，家谱毁坏，系统中断！" << endl;
		exit(0);
	}
	else
	{
		Find(root, name);
		person*pmove = current->firstChild;
		if (pmove == NULL)
			cout << "很遗憾" << name << "没有子孙";
		else
		{
			cout << name << "的第一代子孙是： ";
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
		if (ptemp->nextSibling) // 兄弟，判断有没有兄弟
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
