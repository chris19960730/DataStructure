#pragma once
#include<iostream>

using namespace std;

struct Joseph
{
	int location;    //�������ڵ�λ�ã���ţ�
	Joseph*next;
};
void createList(int number, int start, int luckyNum, int remains)   
{
	Joseph*head, *pnew, *plast;
	int count = 0;
	head = nullptr;

	for (int i = 1; i <= number; i++)   // �����������������Լɪ��ѭ������
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
	while (plast->location != start)   //�ҵ�startλ��
	{
		plast = plast->next;
	}
	int nownumber = number;
	for (count = 1; count <= (number - remains); count++)
	{
		Joseph*ptemp;
		if (luckyNum == 1)   //�������������1ʱ��������
		{
			cout << "��" << count << "�������˵�λ���ǣ�" << plast->location << endl;
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
		else  //�������������������
		{
			for (int i = 1; i < luckyNum; i++)
			{
				ptemp = plast;
				plast = plast->next;
			}
			cout << "��" << count << "�������˵�λ���ǣ�" << plast->location << endl;
			ptemp->next = plast->next;
			delete plast;
			plast = ptemp->next;
		}
	}
	Joseph*pmove = plast;
	count = 0;
	cout << "ʣ�������λ��Ϊ��";
	while (count<remains)   //���Ҵ���ȫ�������
	{
		cout << pmove->location << "     ";
		pmove = pmove->next;

		count++;
	}
	cout << endl;
}