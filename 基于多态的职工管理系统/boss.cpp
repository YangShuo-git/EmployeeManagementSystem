#include <iostream>
#include <string>
#include "boss.h"
using namespace std;

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

string Boss::getDeptName()
{
	return string("�ϰ�");
}

string Boss::getDeptDuty()
{
	return string("˼����˾��δ�����ַ����������");
}
