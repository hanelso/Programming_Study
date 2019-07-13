#pragma once
#include"main.h"
#include<string.h>

class MyString {
	char* string_content;	// 문자열 데이터를 가리키는 포인터
	int string_length;		// 문자열 길이
	int memory_capacity;	// 현재 할당된 용량

public:
	// 문자 하나로 생성
	MyString(char c);

	// 문자열로 부터 생성
	MyString(const char* str);

	// 복사 생성자
	MyString(const MyString& str);

	~MyString();

	// 문자열의 길이를 제공
	int length() const;
	
	// MyString 객체의 문자열 공간으로 할당 받은 크기를 return 한다.
	int capacity() const;
	// MyString 객체의 문자열 공간을 미리 할당받는다.
	void reserve(int size);

	// 문자열을 세팅하는 함수 ( set 함수 )
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	void print() const;
	void println() const;
};

MyString::MyString(char c) {
	string_content = new char[1];
	memory_capacity = 1;
	string_content[0] = c;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length];
	memory_capacity = string_length;

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	memory_capacity = string_length;

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}

MyString::~MyString() 
{ 
	delete[] string_content; 
}

int MyString::length() const 
{ 
	return string_length; 
}

int MyString::capacity() const
{
	return memory_capacity;
}

void MyString::reserve(int size)
{
	if (size > memory_capacity)
	{
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
		{
			string_content[i] = prev_string_content[i];
		}

		delete[] prev_string_content;
	}

	// 만일 예약하려는 size가 현재 capacity 보다 작다면 
	// 아무것도 하지않는다.
}

MyString& MyString::assign(const MyString& str)
{
	if (str.string_length > memory_capacity)
	{
		// 객체에 할당되어있는 메모리 공간보다 문자열이 길다면 재할당
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}

	for (int i = 0; i != str.string_length; i++)
	{
		string_content[i] = str.string_content[i];
	}

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str)
{
	// str의 길이
	int str_length = strlen(str);

	if (str_length > memory_capacity)
	{
		// 객체에 할당되어있는 메모리 공간보다 문자열이 길다면 재할당
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}

	// 문자열의 내용을 복사한다.
	for (int i = 0; i != str_length; i++)
	{
		string_content[i] = str[i];
	}

	// 문자열의 길이를 얻는다.
	string_length = str_length;

	// 바뀐 문자열 객체를 반환한다. this == &MyString ( 현재 객체의 주소값 )
	return *this;
}

void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}

void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}

	std::cout << std::endl;
}