#pragma once
#pragma once
#include<iostream>
#include<string>

using namespace std;

struct person {

	string name;   //该成员的名字
	struct person *firstChild;   //该成员的长子指针
	struct person* nextSibling;	 //该成员的临接兄弟指针
};

class familyTree {

private:
	person * root, *current, *before;   //根节点，当前结点，该节点的前一个节点
	bool Find(person*p, string name);    
	bool FindParent(person*t, person*p);

public:
	familyTree();
	//bool IsEmpty() { return root == NULL; }
	bool Parent();
	void createRoot(string name);
	void addperson(string name, int number);
	void changeName(string name);
	void divorce(string name);
	void realse(person*p);

};
