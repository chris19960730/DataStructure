#pragma once
#include<iostream>

using namespace std;

struct Joseph
{
	int location;    //该人所在的位置（编号）
	Joseph*next;
};
void createList(int number, int start, int luckyNum, int remains)   
{
	Joseph*head, *pnew, *plast;
	int count = 0;
	head = nullptr;

	for (int i = 1; i <= number; i++)   // 根据输入的人数建立约瑟夫循环链表
	{
		pnew = new Joseph();
		pnew->location = i;
		if (head == nullptr)
			head = pnew;
		else
		{
			plast->next = pnew;
		}
		plast = pnew;
	}
	pnew->next = head;
	pnew = head;
	while (plast->location != start)   //找到start位置
	{
		plast = plast->next;
	}
	int nownumber = number;
	for (count = 1; count <= (number - remains); count++)
	{
		Joseph*ptemp;
		if (luckyNum == 1)   //如果死亡数字是1时单独考虑
		{
			cout << "第" << count << "个死的人的位置是：" << plast->location << endl;
			for (int i = 1; i < nownumber; i++)
			{
				plast = plast->next;
			}
			ptemp = plast;
			Joseph* p = ptemp->next;
			plast = ptemp->next->next;
			ptemp->next = plast;
			delete p;
			nownumber--;

		}
		else  //死亡数字是其他的情况
		{
			for (int i = 1; i < luckyNum; i++)
			{
				ptemp = plast;
				plast = plast->next;
			}
			cout << "第" << count << "个死的人的位置是：" << plast->location << endl;
			ptemp->next = plast->next;
			delete plast;
			plast = ptemp->next;
		}
	}
	Joseph*pmove = plast;
	count = 0;
	cout << "剩余的生者位置为：";
	while (count<remains)   //将幸存者全部输出来
	{
		cout << pmove->location << "     ";
		pmove = pmove->next;

		count++;
	}
	cout << endl;
}