#include"8_1552704_yanghaochengT.h"
#include"8_1552704_yanghaochengG.h"
#include"8_1552704_yanghaochengH.h"
void Prim(Graphmtx&G, int u0, MiniSpanTree&MST)
{
	MSTEdgeNode ed;
	int i, v, count;
	int n = G.NumberOfVertices();
	int m = G.NumberOfEdges();
	int u = G.getVertexPos(u0);
	miniHeap H(m);
	bool* Vmst = new bool[n];
	for (i = 0; i < n; i++)
	{
		Vmst[i] = false;
	}
	Vmst[u] = true;
	count = 1;
	do
	{
		v = G.getFirstNeighbor(u0);
		while (v != -1)
		{
			if (Vmst[G.getVertexPos(v)] == false)
			{
				ed.tail = u0;
				ed.head = v;
				ed.key = G.getWeight(u0, v);
				H.insert(ed);
			}
			v = G.getNextNeighbor(u0, v);
		}
		while (H.IsEmpty() == false && count < n)
		{
			H.remove(ed);
			if (Vmst[G.getVertexPos(ed.head)] == false)  // ���
			{
				MST.insert(ed);
				u0 = ed.head;
				Vmst[G.getVertexPos(u0)] = true;
				count++;
				break;
			}
		}
	} while (count < n);
}
MiniSpanTree MST;
Graphmtx graphmtx(10);

int main()
{
	cout << "**      �������ģ��ϵͳ     **" << endl;
	cout << "=================================" << endl;
	cout << "**     A---������������      **" << endl;
	cout << "**     B---��ӵ����ı�      **" << endl;
	cout << "**     C---������С������    **" << endl;
	cout << "**     D---��ʾ��С������    **" << endl;
	cout << "**     E---�˳�  ����        **" << endl;
	cout << "=================================" << endl;
	char operation = '$';
	while (operation != EOF)
	{
		cout << endl;
		cout << "��ѡ������� ";
		cin >> operation;
		switch (operation)
		{
		case 'A':
		{
			cout << "�����붥������� ";
			int number;
			char letter;
			cin >> number;
			cout << "���������붥������ƣ� " << endl;
			for (int i = 0; i < number; i++)
			{
				cin >> letter;
				graphmtx.insertVertex(letter - 'a' + 1);
			}
			break;
		}
		case 'B':
		{
			char v1 = '$', v2;
			int key;
			while (v1 != '?')
			{
				cout << "��������������ͱߣ�(���� ��?�� ��?�� 0 ��Ϊ����) ";
				cin >> v1 >> v2 >> key;

				graphmtx.insertEdge((v1 - 'a' + 1), (v2 - 'a' + 1), key);

			}
			break;
		}
		case 'C':
		{
			char start;
			cout << "��������ʼ���㣺 ";
			cin >> start;
			Prim(graphmtx, (start - 'a' + 1), MST);
			cout << "����Prim��С������!" << endl;
			break;
		}
		case 'D':
		{
			MST.show();
			break;
		}
		case 'E':
		{
			cout << "��лʹ�ñ�����" << endl;
			exit(0);
		}
		}
	}
}
