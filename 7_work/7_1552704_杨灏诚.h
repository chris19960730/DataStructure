#pragma once
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Stack {

public:
	Stack();	
	void pop_Stack();				//��ջ
	char push_Stack(char data);		//��ջ
	char top_Stack();				//���ջ��Ԫ��
	int isp(char ch);				//վ�����ȼ�
	int icp(char ch);				//ջ�����ȼ�
	bool IsEmpty();					//�ж�ջ�Ƿ�Ϊ��
private:
	char arr[100];
	int top = -1;					//��ʼջ��ָ��Ϊ-1

};
struct Tree
{
	string data;					//���ʽ�е�һ��Ԫ��
	Tree*left;
	Tree*right;
};


Stack::Stack()
{
	/*top = -1;
	arr[100] = { 0 };*/
}

bool Stack::IsEmpty()
{
	if (top == -1)
	{
		return true;
	}
	return false;
}
char  Stack::push_Stack(char data)
{
	top++;
	arr[top] = data;
	return arr[top];
}

void Stack::pop_Stack()
{

	top--;
}

char Stack::top_Stack()
{
	return arr[top];
}

int Stack::isp(char ch)
{
	if (ch == '#') return 0;
	else if (ch == '(')return 1;
	else if (ch == '*' || ch == '/')return 5;
	else if (ch == '+' || ch == '-')return 3;
	else if (ch == ')') return 6;
}

int Stack::icp(char ch)
{
	if (ch == '#') return 0;
	else if (ch == '(')return 6;
	else if (ch == '*' || ch == '/')return 4;
	else if (ch == '+' || ch == '-')return 2;
	else if (ch == ')') return 1;
}

Stack Operator;
Stack number;
string posfixEx;    //��׺���ʽ
void  postfix(string expression)   //�����ʽexpressionת��Ϊ��׺���ʽ
{
	expression.append(1, '#');    //�ڱ��ʽexpressionĩβ��ӡ�#��
	char ch = '#', ch1 = '$', op;
	int i = 0;
	Operator.push_Stack(ch);
	ch = expression[i];
	while (Operator.IsEmpty() == false && i < expression.size())  //��λ��ȡ���ʽ
	{

		if (isdigit(ch))
		{
			posfixEx.append(1, ch); 
			i++;
			ch = expression[i];
		}
		else
		{

			if (Operator.isp(Operator.top_Stack()) < Operator.icp(ch))
			{
				posfixEx.append(1, '$');  //����"$"�������ʽ���ֺͷ��ŷָ���
				Operator.push_Stack(ch);
				i++;
				ch = expression[i];
			}
			else if (Operator.isp(Operator.top_Stack()) > Operator.icp(ch))
			{
				posfixEx.append(1, '$');
				ch1 = Operator.top_Stack();
				Operator.pop_Stack();
				posfixEx.append(1, ch1);

			}
			else
			{
				ch1 = Operator.top_Stack();
				if ('#' == ch&&ch1 == '#')
				{
					posfixEx.append(1, '$');
					break;
				}
				Operator.pop_Stack();
				if (ch1 != '(')
					posfixEx.append(1, ch1);
				if (ch1 == '(')
				{
					i++;
					ch = expression[i];
				}
			}
		}
	}
}


void Preorder(Tree*root)   //ǰ��������ʽ������
{
	if (root == NULL)
		return;
	cout << root->data << ' ';
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Tree*root) //����������ʽ������
{
	if (root == NULL)
		return;
	Inorder(root->left);
	cout << root->data << ' ';
	Inorder(root->right);
}

void Postorder(Tree*root) //����������ʽ������
{
	if (root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << ' ';

}
Tree*createNode(string ch) //��ʼ�����ʽ��
{
	Tree*pNode = new Tree();
	pNode->data = ch;
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}
stack<Tree*> treeStack;
Tree*root = NULL;
void buildTree() //����׺���ʽposfixEx�������ʽ��
{
	string temp;
	int i = 0;
	for (; i < posfixEx.size();)
	{
		temp.clear();
		while (posfixEx[i] != '$')
		{
			temp.append(1, posfixEx[i]);
			i++;
		}
		while (posfixEx[i] == '$')
		{
			i++;
		}
		Tree*pNode = createNode(temp);
		root = pNode;
		if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
		{
			Tree *pRight = treeStack.top();
			treeStack.pop();
			Tree *pLeft = treeStack.top();
			treeStack.pop();

			pNode->right = pRight;
			pNode->left = pLeft;
			treeStack.push(pNode);
		}
		else
		{
			treeStack.push(pNode);
		}
	}
	cout << "ǰ׺���ʽ(�������ʽ): ";
	Preorder(root);
	cout << endl;
	cout << "��׺���ʽ: ";
	Inorder(root);
	cout << endl;
	cout << "��׺���ʽ(�沨�����ʽ): ";
	Postorder(root);
	cout << endl;
}


