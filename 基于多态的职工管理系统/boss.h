#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

// �ϰ���
class Boss : public Worker
{
public:
	// ���캯�� ���г�ʼ��
	Boss(int id, string name, int dId);

	// ��ȡ���ڲ��ŵĸ�λ����
	string getDeptName();

	//��ȡ��λְ��
	string getDeptDuty();

};
