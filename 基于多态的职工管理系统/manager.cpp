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
	return string("����");
}

string Manager::getDeptDuty()
{
	return string("�յ��ϰ�����񣬷����滮���·���Ա��");
}