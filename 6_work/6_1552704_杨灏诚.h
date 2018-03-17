#pragma once
#pragma once
#include<iostream>
#include<string>

using namespace std;

struct person {

	string name;   //�ó�Ա������
	struct person *firstChild;   //�ó�Ա�ĳ���ָ��
	struct person* nextSibling;	 //�ó�Ա���ٽ��ֵ�ָ��
};

class familyTree {

private:
	person * root, *current, *before;   //���ڵ㣬��ǰ��㣬�ýڵ��ǰһ���ڵ�
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
