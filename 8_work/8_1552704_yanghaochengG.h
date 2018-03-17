#pragma once
#include"8_1552704_yanghaochengT.h"
class Graphmtx {

public:
	const int maxweight = 20000;  
	Graphmtx(int sz = DefaultVertices);
	bool  GraphmtxEmpty();						 //判断图是否为空
	int NumberOfVertices();						 //图中的顶点数
	int NumberOfEdges();						 //图中的边数
	int getWeight(int v1, int v2);				 //得到以v1,v2为顶点的边的权值
	int getFirstNeighbor(int v);				 //找到顶点v的直接邻接点
	int getNextNeighbor(int v, int w);			 //找到顶点v经过顶点w的间接邻接点
	bool insertEdge(int v1, int v2, int cost);	 //插入边
	bool insertVertex(int vertex);				 //插入点
	int getVertexPos(int vertex);				 //找到点的位置
private:
	int *VerticesList;							 //顶点表
	int**Edge;									 //图的邻接矩阵
	int maxVertices;							 //最多可放点个数
	int numEdges;								 //边的个数
	int numVertices;							 //点的个数
};


Graphmtx::Graphmtx(int sz)
{
	maxVertices = sz;
	numVertices = 0; numEdges = 0;
	int i, j;
	VerticesList = new int[maxVertices];
	Edge = (int **)new int*[maxVertices];
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];
	for (i = 0; i < maxVertices; i++)
	{
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? 0 : maxweight;
	}
}

bool Graphmtx::GraphmtxEmpty()
{
	if (numEdges == 0)
		return true;
	else
		return false;
}

int Graphmtx::NumberOfVertices()
{
	return numVertices;
}

int Graphmtx::NumberOfEdges()
{
	return numEdges;
}
int	Graphmtx::getVertexPos(int vertex)
{
	for (int i = 0; i < numVertices; i++)
	{
		if (VerticesList[i] == vertex)
			return i;
	}
	return -1;
}


int Graphmtx::getWeight(int v1, int v2)
{
	return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;// v1,v2 不能为字母 只能为数字 因为二维数组
}

int Graphmtx::getFirstNeighbor(int v)
{
	if (v != -1)
	{
		for (int col = 0; col < numVertices; col++)
		{
			if (Edge[v][col] > 0 && Edge[v][col] < maxweight)
				return col;
		}
	}
	return -1;
}

int Graphmtx::getNextNeighbor(int v, int w)
{
	if (v != -1 && w != -1)
	{
		for (int col = w + 1; col <= numVertices; col++)
		{
			if (Edge[v][col] > 0 && Edge[v][col] < maxweight)
				return col;
		}
		return -1;
	}
}

bool Graphmtx::insertVertex(int vertex)
{
	if (numVertices == maxVertices)return false;
	VerticesList[numVertices] = vertex;
	numVertices++;
	return true;
}

bool Graphmtx::insertEdge(int v1, int v2, int cost)
{
	if (v1 > -1 && v2>-1 && Edge[v1][v2] == maxweight)
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else return false;
}

