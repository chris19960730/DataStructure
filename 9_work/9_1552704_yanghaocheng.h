#pragma once
#pragma once
#include<iostream>
using  namespace std;

struct treeNode {
	int data;									 //������������ĳ��������
	treeNode*left;
	treeNode*right;

};
class BST {

public:
	BST();
	void buildTree();							 //��������������
	bool insert(int data, treeNode*&ptr);		 //������������в�������
	void show(treeNode*ptr);					 //�������������������
	treeNode*find(int data, treeNode*ptr);		 //�ڶ�����������Ѱ������data
	treeNode*& Return();						 //���ض����������ĸ��ڵ�

private:
	treeNode*root;
	int stopValue;								 //�����������ֵֹ,����Ĭ��Ϊ-1
};



BST tree;

BST::BST()
{
	root = NULL;
	stopValue = -1;
}

void BST::buildTree()
{
	int data;
	cin >> data;
	while (data != stopValue)
	{

		insert(data, root);
		cin >> data;

	}
}
treeNode*& BST::Return()
{
	return root;
}
bool BST::insert(int data, treeNode*&ptr)
{
	if (ptr == NULL)					//����������Ϊ����ʱ
	{
		ptr = new treeNode();
		ptr->data = data;
		return true;
	}
	else if (data > ptr->data)			//���ݱȸ��ڵ�����ݴ�ʱ
		insert(data, ptr->right);
	else if (data < ptr->data)			//���ݱȸ��ڵ������Сʱ
		insert(data, ptr->left);
	else
	{
		cout << "���������Ϣ <" << data << ">�Ѿ����ڣ�";
		return  false;
	}
}
treeNode* BST::find(int data, treeNode*ptr)
{

	if (ptr == NULL)
	{
		cout << "û�д����ݣ�" << endl;
		return NULL;
	}

	else if (data < ptr->data) return find(data, ptr->left);   //���ݱȸ��ڵ�����ݴ�ʱ
	else if (data > ptr->data) return find(data, ptr->right);  //���ݱȸ��ڵ������Сʱ
	else
	{
		cout << "�����ɹ���";
		return ptr;
	}
}
void BST::show(treeNode*ptr)
{

	if (ptr != NULL)      
	{
		show(ptr->left);
		cout << ptr->data << "->";
		show(ptr->right);
	}
}
