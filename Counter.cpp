//#include "Counter.h"
#include "MyString.h"
#include <iostream>
//using namespace std;

#define _CRT_SECURE_NO_WARNINGS

MyString::Counter::Counter(const char*str) {
	p_Next = MyString::Counter::Head;
	MyString::Counter::Head = this;
	m_cnt = 1;
	if (str) {
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	else { m_pStr = nullptr; }
}

MyString::Counter::Counter(char*&& str) {
	p_Next = MyString::Counter::Head;
	MyString::Counter::Head = this;
	m_cnt = 1;
	m_pStr = str;
	str = nullptr;
}


MyString::Counter* MyString::Counter::FindSetStr(const char* str) {
	Counter* pointer = MyString::Counter::Head;
	while (pointer) {
		if (!(strcmp(pointer->m_pStr, str))) {
			pointer->m_cnt++;
			return pointer;
		}
		pointer = pointer->p_Next;
	}
	return new Counter(str);
}

MyString::Counter* MyString::Counter::FindMovStr(char* str) {
	Counter* pointer = MyString::Counter::Head;
	while (pointer) {
		if (!(strcmp(pointer->m_pStr, str))) {
			pointer->m_cnt++;
			delete str;           /////////??????
			return pointer;
		}
		pointer = pointer->p_Next;
	}
	return new Counter(std::move(str));
}

//std::ostream& operator<<(std::ostream&, const MyString::Counter &) {
//
//}

void MyString::Counter::ShowAll() {
	Counter* pointer = Head;

	while (pointer) {
		std::cout << pointer;
		pointer = pointer->p_Next;
	}
}

MyString::Counter* MyString::Counter::FindNxtMaxStr(Counter* tmpMax) {
	Counter* tmp = tmpMax->p_Next;
	 //tmpMax = tmpMax->p_Next;
	while (tmp->p_Next) {
		if (strcmp(tmpMax->p_Next->m_pStr, tmp->p_Next->m_pStr) > 0) {
			tmpMax = tmp;
		}
		tmp = tmp->p_Next;
	}
	return tmpMax;
}
void MyString::Counter::Sort() {
	//Counter* RunningHead = Head;
	Counter* NewHead = new Counter();
	Counter* RunningHead = NewHead;

	//
	
	while(RunningHead->p_Next){
		Counter* NextCounterMax= FindNxtMaxStr(RunningHead);
		if(NextCounterMax != RunningHead){
		//if (TmpCounter->p_Next) {
			Counter* tmpMax = NextCounterMax->p_Next;
			NextCounterMax->p_Next = tmpMax->p_Next;
			tmpMax->p_Next = RunningHead->p_Next;
			RunningHead->p_Next = tmpMax;
			


		//NextCounterMax->p_Next = NextCounterMax->p_Next->p_Next;
		//NextCounterMax->p_Next = RunningHead->p_Next->p_Next;
			
			
		}
		RunningHead = RunningHead->p_Next;
	}
	//Head = NewHead->p_Next;
	NewHead->DelStr();
//	delete NewHead;///&/// 
 }

void MyString::Counter::DelStr() {
	if (m_cnt) { m_cnt--; }
	if (!m_cnt) { 
		if (this == Head) { 
			Head = Head->p_Next; 
		}
		else {
			Counter* tmp = Head;
			while (tmp->p_Next != this) {
				tmp = tmp->p_Next;
			}
			tmp->p_Next = this->p_Next;
		}
		delete this; 
	}
}

MyString::Counter::~Counter() {
	if (m_pStr) {
		delete m_pStr;
	}
	
}