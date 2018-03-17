#pragma once
#pragma once
#include<iostream>
using  namespace std;

struct treeNode {
	int data;									 //二叉搜索树中某结点的数据
	treeNode*left;
	treeNode*right;

};
class BST {

public:
	BST();
	void buildTree();							 //建立二叉搜索树
	bool insert(int data, treeNode*&ptr);		 //向二叉搜索树中插入数据
	void show(treeNode*ptr);					 //输出二叉搜索树的内容
	treeNode*find(int data, treeNode*ptr);		 //在二叉搜索树中寻找数据data
	treeNode*& Return();						 //返回二叉搜索树的根节点

private:
	treeNode*root;
	int stopValue;								 //键盘输入的终止值,这里默认为-1
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
	if (ptr == NULL)					//二叉搜索树为空树时
	{
		ptr = new treeNode();
		ptr->data = data;
		return true;
	}
	else if (data > ptr->data)			//数据比根节点的数据大时
		insert(data, ptr->right);
	else if (data < ptr->data)			//数据比根节点的数据小时
		insert(data, ptr->left);
	else
	{
		cout << "您输入的信息 <" << data << ">已经存在！";
		return  false;
	}
}
treeNode* BST::find(int data, treeNode*ptr)
{

	if (ptr == NULL)
	{
		cout << "没有此数据！" << endl;
		return NULL;
	}

	else if (data < ptr->data) return find(data, ptr->left);   //数据比根节点的数据大时
	else if (data > ptr->data) return find(data, ptr->right);  //数据比根节点的数据小时
	else
	{
		cout << "搜索成功！";
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
