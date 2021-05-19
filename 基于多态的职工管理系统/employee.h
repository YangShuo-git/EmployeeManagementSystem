#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

// 普通员工类
class Employee : public Worker
{
public:
	//构造函数  初始化信息
	Employee(int id, string name, int dId);

	//获取职工岗位名称
	string getDeptName();

	//获取岗位职责
	string getDeptDuty();


};
