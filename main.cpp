#include <iostream>

#include "workManager.h"
#include"employee.h"
using namespace std;


int main()
{
	workManager wk;
	int control_number = 0;
	while (1) 
	{
		system("cls");
		wk.showmenu();
		cin >>  control_number;
		switch (control_number)
		{		
		case 1://������Ϣ
			wk.Add_massage();
			break;
		case 2://��ʾ��Ϣ
			wk.showmember();
			break;
		case 3://ɾ����ְְ��
			wk.deletemember();
			break;
		case 4://�޸�ְ����Ϣ
			wk.change_member();
			break;
		case 5://����ְ����Ϣ
			wk.search_member();
			break;
		case 6://�������
			wk.sort_member();
			break;
		case 7://����ĵ�
			wk.delete_file();
			break;
		case 0://�˳�
			wk.exitSystem();
		}
	}
	system("pause");
	return 0;
}