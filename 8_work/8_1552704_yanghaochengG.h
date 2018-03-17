#pragma once
#include"8_1552704_yanghaochengT.h"
class Graphmtx {

public:
	const int maxweight = 20000;  
	Graphmtx(int sz = DefaultVertices);
	bool  GraphmtxEmpty();						 //�ж�ͼ�Ƿ�Ϊ��
	int NumberOfVertices();						 //ͼ�еĶ�����
	int NumberOfEdges();						 //ͼ�еı���
	int getWeight(int v1, int v2);				 //�õ���v1,v2Ϊ����ıߵ�Ȩֵ
	int getFirstNeighbor(int v);				 //�ҵ�����v��ֱ���ڽӵ�
	int getNextNeighbor(int v, int w);			 //�ҵ�����v��������w�ļ���ڽӵ�
	bool insertEdge(int v1, int v2, int cost);	 //�����
	bool insertVertex(int vertex);				 //�����
	int getVertexPos(int vertex);				 //�ҵ����λ��
private:
	int *VerticesList;							 //�����
	int**Edge;									 //ͼ���ڽӾ���
	int maxVertices;							 //���ɷŵ����
	int numEdges;								 //�ߵĸ���
	int numVertices;							 //��ĸ���
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
	return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;// v1,v2 ����Ϊ��ĸ ֻ��Ϊ���� ��Ϊ��ά����
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

