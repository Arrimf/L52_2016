//����������� ����� ������
//������� : ��������� ����������� ����� MyString ����� �������, ����� ��� ������ ��������� � ������������ ����������.
//��� ����� ������� ���(����������� ������������ ������) :
//
//
//
//	��������������� ����� Counter
//	�������� "��������" ��� ������ � �������� ��������������� ������, ������� � ��������� �������� �������� 
//																					������������ ������.
//	����������(�������) :
//	�	��������� �� ����������� ����������� ������ � m_pStr
//	�	������� ������������� ������ ������ - m_nOwners
//	�	��������� �� ��������� Counter � pNext
//	������ :
//�	�����������(������������)
//�	����������
//�	�������� ������������
//�	������ ������������(��� ������, ���� ��� ��� ��������� ������������, � ������ ������ ������ �� ����� ? )
//�	�
//
//��� ����, ����� ���������� �������� ������ � ������������ ����������, � ������ Counter ������ ��������� 
//� ������������ ���������� �������� ���� ��������������� �������, (����� �������, � ����� ������ ���������� 
//��������� ����� �������� �������� ���� ������������ �����).������ ����������� ������ :
//static Counter* Head;
//� ����� ������� ���������� :
//static unsigned int m_curCounters;
//������� ������������� ����������� � ������������� ����������� ������.
//�������� ����� MyString
//�������� ������������ ������ � ��������� �� "����" Counter �
//Counter* m_pMyCounter
//������� ����������� �� ��� ������ ������(��������������� ����� ��� �������� ������)..
//
//��� ����������� ����� �������� ������� � ����� ����������� ������ :
//�	����������� ��� ������
//�	�� ���� �������� MyString �������� �������
//�	������� ������ �� ��������
//�	�
//��
#include <string>
#include <tchar.h>
#include <iostream>
#include <conio.h>
#include "MyString.h"


#define _CRT_SECURE_NO_WARNINGS

#define _SP system("pause");

//using namespace std;


//size_t /*MyString::*/ Counter::m_cnt = 0;


MyString::Counter* MyString::Counter::Head = nullptr;

void main() {
	MyString S11("a");
	MyString S12("z");

	std::cout << (S11);
	std::cout << S12;
	MyString S1("Abc");
	MyString S2("Abc");

	MyString S3(S2);
	MyString S4(MyString("abc"));
	
	MyString S5("ku-ku");
	
	//S4 = S5;
	MyString S7;
	S7 = MyString("arc");
	MyString S8("ju-ku");
	//std::cout << S7;

	MyString::ShowAll();

	MyString::Sort();

	std::cout << std::endl;
	MyString::ShowAll();
	_SP


}