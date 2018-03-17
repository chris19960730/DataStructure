#pragma once
#include"8_1552704_yanghaochengT.h"
class miniHeap {       //×îÐ¡¶Ñ
public:
	miniHeap(int sz);
	bool insert(MSTEdgeNode &x);
	bool remove(MSTEdgeNode &x);
	bool IsEmpty();

private:
	MSTEdgeNode*heap;
	int currentSize;
	int maxHeapSize;
	void siftDown(int start, int end);
	void siftUp(int start);
};


miniHeap::miniHeap(int sz)
{
	heap = new MSTEdgeNode[sz];
	maxHeapSize = DefaultSize;
	currentSize = 0;
}

void miniHeap::siftDown(int start, int end)
{
	int i = start, j = 2 * i + 1;
	MSTEdgeNode temp = heap[i];
	while (j <= end)
	{
		if (j<end&&heap[j]>heap[j + 1])
			j++;
		if (temp <= heap[j]) break;
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}

void miniHeap::siftUp(int start)
{
	int j = start, i = (j - 1) / 2;
	MSTEdgeNode temp = heap[j];
	while (j > 0)
	{
		if (heap[i] <= temp) break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;
}

bool miniHeap::insert(MSTEdgeNode &x)    //Ïò¶ÑÖÐ²åÈëÔªËØ
{
	if (currentSize == maxHeapSize)
	{
		cerr << "¶ÑÂú" << endl;
		return false;
	}
	heap[currentSize] = x;
	siftUp(currentSize);
	currentSize++;
	return true;
}

bool miniHeap::remove(MSTEdgeNode&x)   //´Ó¶ÑÖÐÉ¾³ýÔªËØ
{
	if (!currentSize) { cerr << "¶Ñ¿Õ!" << endl; return false; }
	x = heap[0];
	heap[0] = heap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;
}

bool miniHeap::IsEmpty()  //ÅÐ¶Ï¶ÑÊÇ·ñ¿Õ
{
	if (currentSize == 0)
		return true;
	else
		return false;
}
