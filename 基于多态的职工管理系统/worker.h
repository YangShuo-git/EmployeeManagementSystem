/*

ְ���ķ����У���ͨԱ���������ϰ�
������ְ������һ���ࣨWorker���У����ö�̬����ְͬ������
ְ��������Ϊ��ְ����š�ְ��������ְ�����ڲ��ű��
ְ������Ϊ�У���λְ����Ϣ��������ȡ��λ���ơ� ��ȡ��λְ��

*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

//ְ��������Worker
class Worker
{
public:
	//��ʾ������Ϣ
	void showInfo()
	{
		cout << "ְ����ţ�" << this->m_Id
			<< "\tְ��������" << this->m_Name
			<< "\t��λ��" << this->getDeptName()
			<< "\t��λְ��" << this->getDeptDuty() << endl;
	}

	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//��ȡ��λְ��
	virtual string getDeptDuty() = 0;

	int m_Id;       // ְ�����
	string m_Name;  // ְ������
	int m_DeptId;   // ְ�����ڲ��ű��
};