#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

// 老板类
class Boss : public Worker
{
public:
	// 构造函数 进行初始化
	Boss(int id, string name, int dId);

	// 获取所在部门的岗位名称
	string getDeptName();

	//获取岗位职责
	string getDeptDuty();

};
