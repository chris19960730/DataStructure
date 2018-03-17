#pragma once
#include<iostream>
#include<string>

using namespace std;

struct Student   
{
	int id;				//考生考号
	string name;		//考生姓名
	string sex;			//考生性别	
	int age;			//考生年龄	
	string position;	//考生的工作类别
	Student*next;
};

class List
{
private:
	Student*first;
	Student*last;

public:
	void createhead();					 //初始化链表头
	void createlist(Student&data);		 //新建一个结点，并把data中的数据写入到Student结点中
	void printlist();					 //将学生信息依次输出
	void insert(Student&data, int location); // 插入
	void search(int id);					 // 查找
	void fire(int id);						 // 删除
	void modify(int id);					 // 修改
	int statistic(string position);			 //统计

};