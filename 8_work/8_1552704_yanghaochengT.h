#pragma once
#include<iostream>
#include<string>
using namespace std;

#define DefaultSize 100
#define DefaultVertices 30
struct MSTEdgeNode {     //��С������
	int tail, head;
	int key;
	MSTEdgeNode() :tail(0), head(0), key(0) {}
	bool operator <=(MSTEdgeNode &R) { return key <= R.key; }
	bool operator > (MSTEdgeNode &R) { return key > R.key; }
};

class MiniSpanTree {
protected:
	MSTEdgeNode*edgeValue;
	int maxSize, n;
public:
	MiniSpanTree(int sz = DefaultSize - 1) :maxSize(sz), n(0)
	{
		edgeValue = new MSTEdgeNode[sz];
	}
	int insert(MSTEdgeNode&item);
	void show();
};

int MiniSpanTree::insert(MSTEdgeNode&item)  //����С�������в���Ԫ��
{
	edgeValue[n] = item;
	n++;
	return n;
}
void MiniSpanTree::show()   //����С���������
{
	int i = 0;
	cout << "��С�������Ķ��㼰��Ϊ�� " << endl;
	while (edgeValue[i].key != 0)
	{
		cout << (char)(edgeValue[i].tail + 96) << "-<" << edgeValue[i].key << ">->" << (char)(edgeValue[i].head + 96) << "      ";
		i++;
	}
	cout << endl;
}



