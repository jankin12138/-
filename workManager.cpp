#include <iostream>
#include<fstream>
using namespace std;

#include "workManager.h"
#include"employee.h"


workManager::workManager()
{
	this->total_Num = 0;
	this->total_Array = NULL;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������!" << endl;
		m_Isempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ����ڵ�������" << endl;
		m_Isempty = true;
		ifs.close();
		return;
	}
	ifs.close();
	read_file();
}

workManager::~workManager()
{
	if (this->total_Array != NULL)
	{
		delete[] this->total_Array;
	}
}

void workManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(1);
}
void workManager::showmenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void workManager::input_info(int& id, string& name)
{
	int k = 1;
	cout << "������ְԱ���" << endl;
	while (k)
	{
		cin >> id;
		if (m_Isempty == true)
		{
			k=0;
		}
		else
		{
			k = 0;
			for (int i = 0; i < total_Num; i++)
			{
				if (id == total_Array[i]->m_Id)
				{
					cout << "������������������" << endl;
					k = 1;
				}
			}
		}
	}
	cout << "������ְԱ����" << endl;
	cin >> name;
}

void workManager::Add_massage()//�����Ϣ
{
	int choice;
	int id;
	string name;
	int count=0;
	//ofstream ofs;
	system("cls");
	cout << "��������Ҫ������Ա������" << endl;
	cin >> count;
	if (count > 0)
	{
		int new_Num = this->total_Num + count;
		Worker** newspace = new Worker * [new_Num];
		if (total_Array != NULL)
		{
			for (int i = 0; i < this->total_Num; i++)
			{
				newspace[i] = this->total_Array[i];
			}
		}
		for (int i = 0; i < count; i++)
		{
			cout << "���ڴ�����" << i+1 << "��Ա��" << endl;
			input_info(id, name);
			cout << "��ѡ�񴴽�Ա������" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			while (1)
			{
				cin >> choice;
				if (choice < 4 && choice>0)
				{
					break;
				}
				cout << "������������������" << endl;
			}
			Worker* worker = NULL;
			switch (choice)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			}
			newspace[this->total_Num + i] = worker;
		}
		if (total_Array != NULL)
		{
			delete[] this->total_Array;
		}
		this->total_Array = newspace;
		this->total_Num = new_Num;
		this->m_Isempty = false;
		cout << count << "��ְԱ��ӳɹ�" << endl;
		write_file();
	}
}

void workManager::write_file()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < total_Num; i++)
	{
		ofs << total_Array[i]->m_Id << " "
			<<total_Array[i]->m_name << " "
			<<total_Array[i]->m_DeptId << endl;
	}
	ofs.close();
}

void workManager::read_file()
{
	int count = get_Num();
	int id;
	int i = 0;
	string name;
	int deptid;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	this->total_Array = new Worker * [count];
	cout << this->total_Array << endl;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		Worker* worker = NULL;
		switch (deptid)
		{
		case 1:
			worker = new employee(id, name, 1);
			break;
		case 2:
			worker = new manager(id, name, 2);
			break;
		case 3:
			worker = new boss(id, name, 3);
			break;
		}
		this->total_Array[i] = worker;
		i++;
	}
	this->total_Num = count;
	cout << this->total_Array<<"\t" << this->total_Num << "�ɹ���ȡ" << endl;
	ifs.close();
	m_Isempty = false;
}



int workManager::get_Num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptid;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		i++;
	}
	return i;
}

void workManager::showmember()
{
	if (!m_Isempty)
	{
		for (int i = 0; i < this->total_Num; i++)
		{
			cout << "ְ�����" << total_Array[i]->m_Id
				<< "\tְ������" << total_Array[i]->m_name
				<< "\tְ����λ" << total_Array[i]->getdeptname();
			switch (total_Array[i]->m_DeptId)
			{
			case 1:
				cout << "\tְ��ְ����ɾ��������" << endl;
				break;
			case 2:
				cout << "\tְ��ְ������ϰ����񣬷������Ա��" << endl;
				break;
			case 3:
				cout << "\tְ��ְ��ͳ�����" << endl;
				break;
			}

		}
	}
	else
	{
		system("cls");
		cout << "�ļ������ڻ�Ϊ��!" << endl;
	}
	system("pause");
}

void workManager::deletemember()
{
	if (!m_Isempty)
	{
		int Delete_Number;
		int Isfound = 1;
		cout << "��������Ҫɾ������Ա���" << endl;
		cin >> Delete_Number;
		for (int i = 0; i < this->total_Num; i++)
		{
			if (Delete_Number == total_Array[i]->m_Id)
			{
				for (int j = i; j < this->total_Num - 1; j++)
				{
					total_Array[j] = total_Array[j + 1];
				}
				total_Array[this->total_Num - 1] = NULL;
				this->total_Num--;
				Isfound = 0;
				cout << "ɾ���ɹ�" << endl;
				write_file();
			}
		}
		if (Isfound)
		{
			cout << "δ�ҵ�ɾ����Ա" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "�ļ������ڻ�Ϊ��!" << endl;
	}
	system("pause");
}


void workManager::change_member()
{
	if (!m_Isempty)
	{
		int Change_Number;
		int Isfound = 1;
		int id;
		string name;
		int deptid;
		cout << "��������Ҫ�޸ĵ���Ա���" << endl;
		cin >> Change_Number;
		for (int i = 0; i < this->total_Num; i++)
		{
			if (Change_Number == total_Array[i]->m_Id)
			{
				Isfound = 0;
				cout << "�������޸ĺ�Ա����ţ�" << endl;
				cin >> id;
				//total_Array[i]->m_Id = id;
				cout << "�������޸ĺ�Ա��������" << endl;
				cin >> name;
				//total_Array[i]->m_name = name;
				cout << "�������޸ĺ��ű�ţ�" << endl;
				cin >> deptid;
				//total_Array[i]->m_DeptId = deptid;
				switch (deptid)
				{
				case 1:
					total_Array[i] = new employee(id, name, 1);
					break;
				case 2:
					total_Array[i] = new manager(id, name, 2);
					break;
				case 3:
					total_Array[i] = new boss(id, name, 3);
					break;
				}
				write_file();
			}
		}
		if (Isfound)
		{
			cout << "δ�ҵ��޸���Ա" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "�ļ������ڻ�Ϊ��!" << endl;
	}
	system("pause");
}

void workManager::search_member()
{
	if (!m_Isempty)
	{
		int Search_Number;
		int Isfound = 1;
		cout << "��������Ҫ���ҵ���Ա���" << endl;
		cin >> Search_Number;
		for (int i = 0; i < this->total_Num; i++)
		{
			if (Search_Number == total_Array[i]->m_Id)
			{
				cout << "ְ�����" << total_Array[i]->m_Id
					<< "\tְ������" << total_Array[i]->m_name
					<< "\tְ����λ" << total_Array[i]->getdeptname();
				switch (total_Array[i]->m_DeptId)
				{
				case 1:
					cout << "\tְ��ְ����ɾ��������" << endl;
					break;
				case 2:
					cout << "\tְ��ְ������ϰ����񣬷������Ա��" << endl;
					break;
				case 3:
					cout << "\tְ��ְ��ͳ�����" << endl;
					break;
				}
				Isfound = 0;
			}
		}
		if (Isfound)
		{
			cout << "δ�ҵ���Ҫ���ҵ���Ա" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "�ļ������ڻ�Ϊ��!" << endl;
	}
	system("pause");
}

void workManager::sort_member()
{
	if (!m_Isempty)
	{
		int sort_number;
		cout << "��ѡ����������" << endl;
		cout << "1.��������" << endl;
		cout << "2.��������" << endl;
		cin >> sort_number;
		Worker* temp = NULL;
		if (sort_number == 1)
		{
			for (int j = 0; j < total_Num - 1; j++)
			{
				for (int i = 0; i < total_Num - 1; i++)
				{
					if (total_Array[i]->m_Id > total_Array[i + 1]->m_Id)
					{
						temp = total_Array[i];
						total_Array[i] = total_Array[i + 1];
						total_Array[i + 1] = temp;
					}
				}
			}
			write_file();
		}
		else if (sort_number == 2)
		{
			for (int j = 0; j < total_Num - 1; j++)
			{
				for (int i = 0; i < total_Num - 1; i++)
				{
					if (total_Array[i]->m_Id < total_Array[i + 1]->m_Id)
					{
						temp = total_Array[i];
						total_Array[i] = total_Array[i + 1];
						total_Array[i + 1] = temp;
					}
				}
			}
			write_file();
		}
		cout << "�����ɹ�" << endl;
	}
	else
	{
		system("cls");
		cout << "�ļ������ڻ�Ϊ��!" << endl;
	}
	system("pause");
}

void workManager::delete_file()
{
	if (!m_Isempty)
	{
		ofstream ofs;
		string a;
		cout << "�밴yȷ���Ƿ����" << endl;
		cin >> a;
		if (a == "y")
		{
			ofs.open(FILENAME, ios::trunc);
			ofs.close();
			delete[] total_Array;
			this->total_Array = NULL;
			this->total_Num = 0;
			this->m_Isempty = true;
		}
		else
		{
			cout << "����ȡ��" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "�ļ������ڻ�Ϊ��!" << endl;
	}
	system("pause");
}

