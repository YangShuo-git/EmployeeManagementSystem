/*

�����ฺ����������£�
	1�����û��Ĺ�ͨ�˵�����
	2����ְ����ɾ�Ĳ�Ĳ���
	3�����ļ��Ķ�д����

����ʽ���������(�ں���ǰ����Ҫ��������

*/

#include <iostream>
#include "workerManage.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

WorkerManager::WorkerManager()
{
	//��ʼ������
	this->m_EmpNum = 0;
	this->m_EmpArray = 0;
}

// ��ʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "*****************************************************" << endl;
	cout << "**************** ��ӭʹ��ְ������ϵͳ ***************" << endl;
	cout << "****************     0.�˳��������   ***************" << endl;
	cout << "****************     1.����ְ����Ϣ   ***************" << endl;
	cout << "****************     2.��ʾְ����Ϣ   ***************" << endl;
	cout << "****************     3.ɾ����ְְ��   ***************" << endl;
	cout << "****************     4.�޸�ְ����Ϣ   ***************" << endl;
	cout << "****************     5.����ְ����Ϣ   ***************" << endl;
	cout << "****************     6.���ձ������   ***************" << endl;
	cout << "****************     7.��������ĵ�   ***************" << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "��������ӵ�ְ�������� " << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum; // �¿ռ����� = ԭ����¼���� + ��������
	    //�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// �������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i+1 <<" ����ְ����ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
			case 2:
				worker = new Manager(id, name, 2);
			case 3:
				worker = new Boss(id, name, 3);
			default:
				break;
			}
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//��ʾ��ӳɹ�
		cout << "�ɹ���� " << addNum << "����Ա��" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}

	// ��������� ����
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{

}