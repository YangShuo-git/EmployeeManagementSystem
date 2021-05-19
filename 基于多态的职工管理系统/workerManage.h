/*
	头文件中进行声明
*/

#pragma once    //防止头文件重复包含
#include <iostream>
using namespace std;

class WorkerManager
{
public:
	// 构造函数
	WorkerManager();

	// 显示菜单
	void Show_Menu();

	//退出功能
	void ExitSystem();

	// 析构函数
	~WorkerManager();

};
