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
	return string("Ա��");
}

string Employee::getDeptDuty()
{
	return string("�յ�����������������");
}