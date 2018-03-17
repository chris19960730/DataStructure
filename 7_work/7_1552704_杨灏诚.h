#pragma once
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Stack {

public:
	Stack();	
	void pop_Stack();				//出栈
	char push_Stack(char data);		//进栈
	char top_Stack();				//获得栈顶元素
	int isp(char ch);				//站内优先级
	int icp(char ch);				//栈外优先级
	bool IsEmpty();					//判断栈是否为空
private:
	char arr[100];
	int top = -1;					//初始栈顶指针为-1

};
struct Tree
{
	string data;					//表达式中的一个元素
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
string posfixEx;    //后缀表达式
void  postfix(string expression)   //将表达式expression转换为后缀表达式
{
	expression.append(1, '#');    //在表达式expression末尾添加‘#’
	char ch = '#', ch1 = '$', op;
	int i = 0;
	Operator.push_Stack(ch);
	ch = expression[i];
	while (Operator.IsEmpty() == false && i < expression.size())  //逐位读取表达式
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
				posfixEx.append(1, '$');  //增添"$"，将表达式数字和符号分隔开
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


void Preorder(Tree*root)   //前序输出表达式树内容
{
	if (root == NULL)
		return;
	cout << root->data << ' ';
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Tree*root) //中序输出表达式树内容
{
	if (root == NULL)
		return;
	Inorder(root->left);
	cout << root->data << ' ';
	Inorder(root->right);
}

void Postorder(Tree*root) //后序输出表达式树内容
{
	if (root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << ' ';

}
Tree*createNode(string ch) //初始化表达式树
{
	Tree*pNode = new Tree();
	pNode->data = ch;
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}
stack<Tree*> treeStack;
Tree*root = NULL;
void buildTree() //将后缀表达式posfixEx建立表达式树
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
	cout << "前缀表达式(波兰表达式): ";
	Preorder(root);
	cout << endl;
	cout << "中缀表达式: ";
	Inorder(root);
	cout << endl;
	cout << "后缀表达式(逆波兰表达式): ";
	Postorder(root);
	cout << endl;
}


