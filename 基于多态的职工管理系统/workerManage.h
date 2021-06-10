/*
	头文件中进行声明
*/

#pragma once    //防止头文件重复包含
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h" 
using namespace std;

#define	FILENAME "empFile.txt"


class WorkerManager
{
public:
	// 构造函数
	WorkerManager();

	// 显示菜单
	void Show_Menu();

	//退出功能
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针 
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	// 判断文件是否为空的标志
	bool m_FileIsEmpty;

	// 统计文件中人数
	int get_EmpNum();
	
	// 初始化员工
	void init_Emp();

	// 显示职工
	void Show_Emp();

	// 删除职工
	void Del_Emp();

	// 判断职工是否存在
	int IsExist(int id);

	// 修改职工
	void Mod_Emp();

	// 查找职工
	void Find_Emp();

	// 排序职工    方法是选择排序
	void Sort_Emp();

	// 清空文件
	void Clean_File();

	// 析构函数
	~WorkerManager();

};
