/*
�����ฺ����������£�
	1�����û��Ĺ�ͨ�˵�����
	2����ְ����ɾ�Ĳ�Ĳ���
	3�����ļ��Ķ�д����

����ʽ���������(�ں���ǰ����Ҫ��������
*/

#include <iostream>
#include "workerManage.h"
using namespace std;

WorkerManager::WorkerManager()
{
	// 1���ļ�������    ����ʼ�������������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  // д�ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
	
		// ��ʼ����¼����
		this->m_EmpNum = 0;
		// ��ʼ������ָ��
		this->m_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())  // Ϊ�棬��˵���ļ�Ϊ��
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		// ��ʼ����¼����
		this->m_EmpNum = 0;
		// ��ʼ������ָ��
		this->m_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 3���ļ����ڣ�����������
	this->m_EmpNum = this->get_EmpNum();
	// ���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// ���ļ��е����ݴ浽������
	this->init_Emp();
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
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ָ�룬���浽������
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

		// ����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		// �������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}

	// ��������� ����
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  // д�ļ�

	// ��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	// �ر��ļ�
	ofs.close();
}

// ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		// ͳ����������
		num++;
	}
	return num;
}

// ��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >>dId)
	{
		Worker* worker = NULL;
		// ���ݲ�ͬ���ŵ�ID������ͬ�Ķ���
		if (dId == 1)  // ��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)  // ����
		{
			worker = new Manager(id, name, dId);
		}
		else  // �ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	// �ر��ļ�
	ifs.close();
}

// ��ʾְ��
void WorkerManager::Show_Emp()
{
	// �ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// ���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

// ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)  // ˵��ְ�����ڣ�����Ҫɾ����
		{
			// ����ǰ��
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; // ���������м�¼��Ա����
			this->save(); // ����ͬ�����µ��ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "δ�ҵ�ְ����ɾ��ʧ�ܣ�" << endl;
		}
	}

	// �����������
	system("pause");
	system("cls");
}

// �ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// �޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڣ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			// ���ҵ��˱�ŵ�ְ��

			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ����Ҫ�޸ģ���������ְ���ţ�" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case2:
				worker = new Manager(newId, newName, dSelect);                                
				break;
			case3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			// �������ݣ���������
			this->m_EmpArray[ret] = worker;

			// cout << "�޸ĳɹ���" << this->m_EmpArray[ret]->m_DeptId << endl;
			cout << "�޸ĳɹ���" << endl;
			// ���浽�ļ���
			this->save();
		}
		else
		{
			cout << "���޴��ˣ��޸�ʧ�ܣ�" << endl;
		}
	}

	// �������������
	system("pause");
	system("cls");
}

// ����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڣ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// ���ձ�Ų���
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			IsExist(id);
			int ret = IsExist(id);
			if (ret != 1)
			{
				// �ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			// ������������
			string name;
			cout << "��������ҵ�ְ��������" << endl;
			cin >> name;

			// �����ж��Ƿ�鵽�ı�־
			bool flag = false; // Ĭ��δ�ҵ�ְ��

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						 << this->m_EmpArray[i]->m_Id
						 << "��ְ����Ϣ���£�" << endl;
					flag = true;

					// ������ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag = false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		} 
	}

	// �������������
	system("pause");
	system("cls");
}

// ����ְ��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ���������" << endl;
		cout << "2����ְ����Ž���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}
}

// ����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// ��ģʽ  ios����trunc ������� ɾ���ļ��������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}