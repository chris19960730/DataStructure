#pragma once
#include<iostream>
#include<string>

using namespace std;

struct Student   
{
	int id;				//��������
	string name;		//��������
	string sex;			//�����Ա�	
	int age;			//��������	
	string position;	//�����Ĺ������
	Student*next;
};

class List
{
private:
	Student*first;
	Student*last;

public:
	void createhead();					 //��ʼ������ͷ
	void createlist(Student&data);		 //�½�һ����㣬����data�е�����д�뵽Student�����
	void printlist();					 //��ѧ����Ϣ�������
	void insert(Student&data, int location); // ����
	void search(int id);					 // ����
	void fire(int id);						 // ɾ��
	void modify(int id);					 // �޸�
	int statistic(string position);			 //ͳ��

};