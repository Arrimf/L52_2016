#include "MyString.h"
//#include "Counter.h"
#include <iostream>
//using namespace std;

MyString::MyString(const char* str){
	if (str) {
		m_counter_p = Counter::FindSetStr(str);
	}
	else {m_counter_p = nullptr;}
}
MyString::MyString(char*&& str) {
	if (str) {
		m_counter_p = Counter::FindMovStr(str);
	}
	else { m_counter_p = nullptr; }
}
MyString::MyString(const MyString& other) {
	m_counter_p = other.m_counter_p;
	other.m_counter_p->m_cnt++;
}
MyString::MyString(MyString&& other) {
	m_counter_p = other.m_counter_p;
	other.m_counter_p = nullptr;
}


MyString& MyString::operator=(const MyString& other) {
	if (this->m_counter_p != other.m_counter_p) {
		this->~MyString();
		m_counter_p = other.m_counter_p;
	}
	m_counter_p->m_cnt++;
	return *this;
}
MyString& MyString::operator=(MyString&& other) {
	if (this->m_counter_p != other.m_counter_p) {
		this->~MyString();
		m_counter_p = other.m_counter_p;
	}
	other.m_counter_p = nullptr;
	return *this;
}

std::ostream& operator<< (std::ostream& os, const MyString& Str) {
	os << Str.GetStr()<<" "<<"Owners:"<< Str.ShowOnersN() << std::endl;
	return os;
}
//std::ostream& operator<< (std::ostream&os1, std::ostream&os2) {
//	os1<<MyString::ShowAll(os2);
//	return os1;
//}

void MyString::ShowAll() {
	Counter::ShowAll();	
}


void MyString::Sort() {
	Counter::Sort();
}


MyString::~MyString() {
	if (m_counter_p) {
		m_counter_p->DelStr();
	}
}

