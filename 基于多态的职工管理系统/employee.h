#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

// ��ͨԱ����
class Employee : public Worker
{
public:
	//���캯��  ��ʼ����Ϣ
	Employee(int id, string name, int dId);

	//��ȡְ����λ����
	string getDeptName();

	//��ȡ��λְ��
	string getDeptDuty();


};
