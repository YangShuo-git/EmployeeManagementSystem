#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

// ������
class Manager : public Worker
{
public:

	// ���캯�� ���г�ʼ��
	Manager(int id, string name, int dId);

	// ��ȡ���ڲ��ŵĸ�λ����
	string getDeptName();

	//��ȡ��λְ��
	string getDeptDuty();

};
