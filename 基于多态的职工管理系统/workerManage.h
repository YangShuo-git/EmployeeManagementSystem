/*
	ͷ�ļ��н�������
*/

#pragma once    //��ֹͷ�ļ��ظ�����
#include <iostream>
#include "worker.h"
using namespace std;

class WorkerManager
{
public:
	// ���캯��
	WorkerManager();

	// ��ʾ�˵�
	void Show_Menu();

	//�˳�����
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ�� 
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	// ��������
	~WorkerManager();

};
