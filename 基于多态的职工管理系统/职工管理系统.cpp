/*
  ��main����,��ʵ�ǵ��ø��ֽӿ�
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

		cout << "����������ѡ��" << endl;
		cin >> chioce;
		switch (chioce)
		{
		case 0:  //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:  //���Ա��
			wm.Add_Emp();
			break;
		case 2:  //��ʾԱ��
			wm.Show_Emp();
			break;
		case 3:  //ɾ��Ա��
			wm.Del_Emp();
			break;
		case 4:  //�޸�Ա��
			wm.Mod_Emp();
			break;
		case 5:  //����Ա��
			wm.Find_Emp();
			break;
		case 6:  //����Ա��
			wm.Sort_Emp();
			break;
		case 7:  //����ļ�
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
