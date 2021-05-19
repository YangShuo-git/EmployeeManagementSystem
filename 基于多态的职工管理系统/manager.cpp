#include <iostream>
#include <string>
#include "manager.h"
using namespace std;

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}


string Manager::getDeptName()
{
	return string("经理");
}

string Manager::getDeptDuty()
{
	return string("收到老板的任务，分析规划后下发给员工");
}