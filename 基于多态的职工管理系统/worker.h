/*

职工的分类有：普通员工、经理、老板
将三种职工抽象到一个类（Worker）中，利用多态管理不同职工种类
职工的属性为：职工编号、职工姓名、职工所在部门编号
职工的行为有：岗位职责信息描述、获取岗位名称、 获取岗位职责

*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

//职工抽象类Worker
class Worker
{
public:
	//显示个人信息
	void showInfo()
	{
		cout << "职工编号：" << this->m_Id
			<< "\t职工姓名：" << this->m_Name
			<< "\t岗位：" << this->getDeptName()
			<< "\t岗位职责：" << this->getDeptDuty() << endl;
	}

	//获取岗位名称
	virtual string getDeptName() = 0;

	//获取岗位职责
	virtual string getDeptDuty() = 0;

	int m_Id;       // 职工编号
	string m_Name;  // 职工姓名
	int m_DeptId;   // 职工所在部门编号
};