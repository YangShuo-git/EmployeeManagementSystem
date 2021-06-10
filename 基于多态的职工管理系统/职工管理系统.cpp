/*
  是main函数,其实是调用各种接口
*/
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
			wm.Show_Emp();
			break;
		case 3:  //删除员工
			wm.Del_Emp();
			break;
		case 4:  //修改员工
			wm.Mod_Emp();
			break;
		case 5:  //查找员工
			wm.Find_Emp();
			break;
		case 6:  //排序员工
			wm.Sort_Emp();
			break;
		case 7:  //清空文件
			wm.Clean_File();
			break;

		default:
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}
