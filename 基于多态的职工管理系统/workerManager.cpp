/*
管理类负责的内容如下：
	1、与用户的沟通菜单界面
	2、对职工增删改查的操作
	3、与文件的读写交互

分离式编译的优势(在函数前面需要加作用域）
*/

#include <iostream>
#include "workerManage.h"
using namespace std;

WorkerManager::WorkerManager()
{
	// 1、文件不存在    （初始化的三种情况）
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  // 写文件
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
	
		// 初始化记录人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = NULL;
		// 初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 2、文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())  // 为真，则说明文件为空
	{
		cout << "文件为空！" << endl;
		// 初始化记录人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = NULL;
		// 初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 3、文件存在，并且有数据
	this->m_EmpNum = this->get_EmpNum();
	// 开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// 将文件中的数据存到数组中
	this->init_Emp();
}

// 显示菜单
void WorkerManager::Show_Menu()
{
	cout << "*****************************************************" << endl;
	cout << "**************** 欢迎使用职工管理系统 ***************" << endl;
	cout << "****************     0.退出管理程序   ***************" << endl;
	cout << "****************     1.增加职工信息   ***************" << endl;
	cout << "****************     2.显示职工信息   ***************" << endl;
	cout << "****************     3.删除离职职工   ***************" << endl;
	cout << "****************     4.修改职工信息   ***************" << endl;
	cout << "****************     5.查找职工信息   ***************" << endl;
	cout << "****************     6.按照编号排序   ***************" << endl;
	cout << "****************     7.清空所有文档   ***************" << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加的职工数量： " << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum; // 新空间人数 = 原来记录人数 + 新增人数
	    //开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// 批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i+1 <<" 个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//将创建职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有的空间
		delete[] this->m_EmpArray;

		//更新新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//提示添加成功
		cout << "成功添加 " << addNum << "名新员工" << endl;

		// 更新职工不为空
		this->m_FileIsEmpty = false;

		// 保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入数据有误！" << endl;
	}

	// 按任意键后 清屏
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);  // 写文件

	// 将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	// 关闭文件
	ofs.close();
}

// 统计文件中人数
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
		// 统计人数变量
		num++;
	}
	return num;
}

// 初始化员工
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
		// 根据不同部门的ID创建不同的对象
		if (dId == 1)  // 普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)  // 经理
		{
			worker = new Manager(id, name, dId);
		}
		else  // 老板
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	// 关闭文件
	ifs.close();
}

// 显示职工
void WorkerManager::Show_Emp()
{
	// 判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// 利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

// 删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工的编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)  // 说明职工存在，并且要删除掉
		{
			// 数据前移
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; // 更新数组中记录人员个数
			this->save(); // 数据同步更新到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "未找到职工，删除失败！" << endl;
		}
	}

	// 按任意键清屏
	system("pause");
	system("cls");
}

// 判断职工是否存在
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

// 修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			// 查找到了编号的职工

			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工需要修改，请输入新职工号！" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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

			// 更改数据，到数组中
			this->m_EmpArray[ret] = worker;

			// cout << "修改成功！" << this->m_EmpArray[ret]->m_DeptId << endl;
			cout << "修改成功！" << endl;
			// 保存到文件中
			this->save();
		}
		else
		{
			cout << "查无此人，修改失败！" << endl;
		}
	}

	// 按任意键，清屏
	system("pause");
	system("cls");
}

// 查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// 按照编号查找
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			IsExist(id);
			int ret = IsExist(id);
			if (ret != 1)
			{
				// 找到职工
				cout << "查找成功。该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			// 按照姓名查找
			string name;
			cout << "请输入查找的职工姓名：" << endl;
			cin >> name;

			// 加入判断是否查到的标志
			bool flag = false; // 默认未找到职工

			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为："
						 << this->m_EmpArray[i]->m_Id
						 << "号职工信息如下：" << endl;
					flag = true;

					// 调用显示信息接口
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag = false)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入有误！" << endl;
		} 
	}

	// 按任意键，清屏
	system("pause");
	system("cls");
}

// 排序职工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工编号升序" << endl;
		cout << "2、按职工编号降序" << endl;

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

		cout << "排序成功，排序后的结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}

// 清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// 打开模式  ios：：trunc 如果存在 删除文件，并重新创建
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
		cout << "清空成功！" << endl;
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