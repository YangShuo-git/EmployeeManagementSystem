/*
	ͷ�ļ��н�������
*/

#pragma once    //��ֹͷ�ļ��ظ�����
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h" 
using namespace std;

#define	FILENAME "empFile.txt"


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

	//�����ļ�
	void save();

	// �ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;

	// ͳ���ļ�������
	int get_EmpNum();
	
	// ��ʼ��Ա��
	void init_Emp();

	// ��������
	~WorkerManager();

};
