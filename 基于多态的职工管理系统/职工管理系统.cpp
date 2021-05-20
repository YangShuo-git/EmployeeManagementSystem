

#include <iostream>
#include <string>
#include <fstream>
#include "workerManage.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;


int main()
{
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();

	//Worker* manager = new Manager(2, "李四", 2);
	//manager->showInfo();

	//Worker* boss = new Boss(3, "王五", 3);
	//boss->showInfo();

	WorkerManager wm;

	int chioce = 0;
	while (true)
	{
		wm.Show_Menu();

		cout << "请输入您的选择：" << endl;
		cin >> chioce;
		switch (chioce)
		{
		case 0:  //退出系统
			wm.ExitSystem();
			break;
		case 1:  //添加员工
			wm.Add_Emp();
			break;
		case 2:  //显示员工
			break;
		case 3:  //删除员工
			break;
		case 4:  //修改员工
			break;
		case 5:  //查找员工
			break;
		case 6:  //排序员工
			break;
		case 7:  //清空文件
			break;

		default:
			system("cls");
			break;
		}

	}


	system("pause");
	return 0;
}
