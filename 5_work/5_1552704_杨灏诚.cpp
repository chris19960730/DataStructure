#include"5_1552704_杨灏诚.h"
int main()
{
	cout << "关键字检索系统" << endl;
	cout << "请输入文件名:";
	string name;
	cin >> name;
	createTxt(name);
	count(name);
}