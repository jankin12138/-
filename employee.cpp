#pragma once
#include <iostream>
#include <string>
#include"employee.h"

employee::employee(int m_Id, string m_name, int m_DeptId) 
{
	this->m_Id = m_Id;
	this->m_name = m_name;
	this->m_DeptId = m_DeptId;
}

void employee::show()
{
	cout << "ְ�����" << this->m_Id
		<< "\tְ������" << this->m_name
		<< "\tְ����λ" << this->getdeptname()
		<< "\tְ��ְ����ɾ��������" << endl;
	system("pause");
}

string employee::getdeptname()
{
	return "Ա��";
}



manager::manager(int m_Id, string m_name, int m_DeptId)
{
	this->m_Id = m_Id;
	this->m_name = m_name;
	this->m_DeptId = m_DeptId;
}

void manager::show()
{
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ�������� " << this->m_name
		<< "\t���ű��" << this->m_DeptId
		<< "\tְ����λ�� " << this->getdeptname()
		<< "\tְ��ְ������ϰ����񣬷������Ա��" << endl;
	system("pause");
}

string manager::getdeptname()
{
	return "����";
}



boss::boss(int m_Id, string m_name, int m_DeptId)
{
	this->m_Id = m_Id;
	this->m_name = m_name;
	this->m_DeptId = m_DeptId;
}

void boss::show()
{
	cout << "ְ�����" << this->m_Id
		<< "\tְ������" << this->m_name
		<< "\tְ����λ" << this->getdeptname()
		<< "\tְ��ְ��ͳ�����" << endl;
	system("pause");
}

string boss::getdeptname()
{
	return "�ϰ�";
}