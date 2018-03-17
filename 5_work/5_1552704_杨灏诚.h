#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <ctype.h>  
#include<string>
using namespace std;

struct map {
	string word;     //存的字母
	struct map*next;
};


void createTxt(string name)    
{
	ofstream outfile(name);
	ofstream tempfile("temp.txt");  //临时文件 用于存放去掉符号后的文章 
	cout << "请输入一段英文：(当输入**时输入结束)" << endl;
	string words;
	while (cin >> words)
	{	 
		outfile << words << " ";
		for (int i = 0; i < words.size(); i++)   //去除符号
		{
			if (ispunct(words[i]) && words[i] != '*')
				words[i] = ' ';
			if (words[i] >= 'A'&&words[i] <= 'Z')  //将英文全部转换为小写字母
				words[i] = words[i] + 32;
		}
		tempfile << words << " ";
		if (words == "**")  //输入的终止条件
		{
			cout << "本段文本已保存在文本文件“" << name << "”中" << endl;
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
	cout << "请输入要检索的关键字: " << endl;
	cin >> keywords;
	for (int i = 0; i < keywords.size(); i++)
	{
		if (keywords[i] >= 'A'&&keywords[i] <= 'Z')
			keywords[i] = keywords[i] + 32;
	}
	cout << "显示源文件" << "“" << name << "”" << endl;
	while (infile >> words && (words != "**"))
	{
		cout << words << " ";
	}
	cout << endl;
	map*head = nullptr, *tail;
	while (tempfile >> NSwords&&NSwords != "**")
	{
		
		map*pnew = new map();
		pnew->word = NSwords;  //建立关键字存储链表
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
		if (keywords == p->word)   // 对关键字计数，统计出现次数
			count++;	
		p = p->next;
	}
	cout << "在源文件中共检索到： " << count << " 个关键字 “" << keywords << "”" << endl;
}
