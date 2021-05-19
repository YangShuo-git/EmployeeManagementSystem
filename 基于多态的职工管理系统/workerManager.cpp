/*

管理类负责的内容如下：
	1、与用户的沟通菜单界面
	2、对职工增删改查的操作
	3、与文件的读写交互

分离式编译的优势

*/

#include <iostream>
#include "workerManage.h"
using namespace std;

WorkerManager::WorkerManager()
{

}

// 显示菜单
void WorkerManager::Show_Menu()
{
	cout << "*****************************************************" << endl;
	cout << "**************** 欢迎使用职工管理系统 ***************" << endl;
	cout << "****************     0.退出管理程序   ***************" << endl;
	cout << "****************     1.增加职工信息   ***************" << endl;
	cout << "****************     2.显示职工信息   ***************" << endl;
	cout << "****************     3.删除离职职工   ***************" << endl;
	cout << "****************     4.修改职工信息   ***************" << endl;
	cout << "****************     5.查找职工信息   ***************" << endl;
	cout << "****************     6.按照编号排序   ***************" << endl;
	cout << "****************     7.清空所有文档   ***************" << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager()
{

}