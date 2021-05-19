#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

// 经理类
class Manager : public Worker
{
public:

	// 构造函数 进行初始化
	Manager(int id, string name, int dId);

	// 获取所在部门的岗位名称
	string getDeptName();

	//获取岗位职责
	string getDeptDuty();

};
