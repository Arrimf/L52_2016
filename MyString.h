#pragma once

//using namespace std;
#include <iostream>
//#define _CRT_SECURE_NO_WARNINGS
typedef unsigned int uint;

class MyString {

	class Counter {
		public:
		size_t m_cnt;
		char* m_pStr;
		Counter* p_Next;
		static Counter* Head;

		Counter(const char* = nullptr);
		Counter(char*&&);

		static Counter* FindSetStr(const char*);
		static Counter* FindMovStr(char*);

		friend std::ostream& operator<<(std::ostream& os, const Counter* Str) {
			if (Str->m_pStr) {
				os << Str->m_pStr << " " << "Owners:" << Str->m_cnt << std::endl;
			}
			return os;
		};

		//static Counter* FindStr(Counter*, void pred(Counter*, Counter*));
		static void ShowAll();
		static Counter* FindNxtMaxStr(Counter*); // принимает начало и идет до конца
		static void Sort();

		void DelStr();
		~Counter();
	};

	Counter* m_counter_p;

	protected:

	public:


	MyString(const char* = nullptr);
	MyString(char*&&);
	MyString(const MyString&);
	MyString(MyString&&);

	inline const char* GetStr() { return m_counter_p->m_pStr; };
	inline const char* GetStr() const { return m_counter_p->m_pStr; };
	inline const uint ShowOnersN() { return static_cast<uint>( m_counter_p->m_cnt); };
	inline const uint ShowOnersN() const { return static_cast<uint>(m_counter_p->m_cnt); };

	MyString& operator=(const MyString&);
	MyString& operator=(MyString&&);

	friend std::ostream& operator<< (std::ostream&, const MyString&);
	//friend std::ostream& operator<< (std::ostream&, std::ostream&);
	static void ShowAll();

	static void Sort();

	~MyString();
};

