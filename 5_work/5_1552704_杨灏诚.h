#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <ctype.h>  
#include<string>
using namespace std;

struct map {
	string word;     //�����ĸ
	struct map*next;
};


void createTxt(string name)    
{
	ofstream outfile(name);
	ofstream tempfile("temp.txt");  //��ʱ�ļ� ���ڴ��ȥ�����ź������ 
	cout << "������һ��Ӣ�ģ�(������**ʱ�������)" << endl;
	string words;
	while (cin >> words)
	{	 
		outfile << words << " ";
		for (int i = 0; i < words.size(); i++)   //ȥ������
		{
			if (ispunct(words[i]) && words[i] != '*')
				words[i] = ' ';
			if (words[i] >= 'A'&&words[i] <= 'Z')  //��Ӣ��ȫ��ת��ΪСд��ĸ
				words[i] = words[i] + 32;
		}
		tempfile << words << " ";
		if (words == "**")  //�������ֹ����
		{
			cout << "�����ı��ѱ������ı��ļ���" << name << "����" << endl;
			break;
		}

	}
}
void count(string name)
{
	ifstream infile(name);
	ifstream tempfile("temp.txt");   
	string keywords;
	string words;
	string NSwords;
	cout << "������Ҫ�����Ĺؼ���: " << endl;
	cin >> keywords;
	for (int i = 0; i < keywords.size(); i++)
	{
		if (keywords[i] >= 'A'&&keywords[i] <= 'Z')
			keywords[i] = keywords[i] + 32;
	}
	cout << "��ʾԴ�ļ�" << "��" << name << "��" << endl;
	while (infile >> words && (words != "**"))
	{
		cout << words << " ";
	}
	cout << endl;
	map*head = nullptr, *tail;
	while (tempfile >> NSwords&&NSwords != "**")
	{
		
		map*pnew = new map();
		pnew->word = NSwords;  //�����ؼ��ִ洢����
		if (head == nullptr)
			head = pnew;
		else
		{
			tail->next=pnew;
		}
		tail = pnew;
		
	}	
	cout << endl;
	int count = 0;
	map*p = head;
	while (p)
	{
		if (keywords == p->word)   // �Թؼ��ּ�����ͳ�Ƴ��ִ���
			count++;	
		p = p->next;
	}
	cout << "��Դ�ļ��й��������� " << count << " ���ؼ��� ��" << keywords << "��" << endl;
}
