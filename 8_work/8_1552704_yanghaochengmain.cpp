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
			if (Vmst[G.getVertexPos(ed.head)] == false)  // 检查
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
	cout << "**      电网造价模拟系统     **" << endl;
	cout << "=================================" << endl;
	cout << "**     A---创建电网顶点      **" << endl;
	cout << "**     B---添加电网的边      **" << endl;
	cout << "**     C---构造最小生成树    **" << endl;
	cout << "**     D---显示最小生成树    **" << endl;
	cout << "**     E---退出  程序        **" << endl;
	cout << "=================================" << endl;
	char operation = '$';
	while (operation != EOF)
	{
		cout << endl;
		cout << "请选择操作： ";
		cin >> operation;
		switch (operation)
		{
		case 'A':
		{
			cout << "请输入顶点个数： ";
			int number;
			char letter;
			cin >> number;
			cout << "请依次输入顶点的名称： " << endl;
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
				cout << "请输入两个顶点和边：(输入 ‘?’ ‘?’ 0 作为结束) ";
				cin >> v1 >> v2 >> key;

				graphmtx.insertEdge((v1 - 'a' + 1), (v2 - 'a' + 1), key);

			}
			break;
		}
		case 'C':
		{
			char start;
			cout << "请输入起始顶点： ";
			cin >> start;
			Prim(graphmtx, (start - 'a' + 1), MST);
			cout << "生成Prim最小生成树!" << endl;
			break;
		}
		case 'D':
		{
			MST.show();
			break;
		}
		case 'E':
		{
			cout << "感谢使用本程序！" << endl;
			exit(0);
		}
		}
	}
}
