#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

string Employee::getDeptName()
{
	return string("员工");
}

string Employee::getDeptDuty()
{
	return string("收到经理的任务，完成任务");
}