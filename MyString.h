#pragma once
#include <iostream>
#include <string>
class MyString
{
private:
	 char* str;
	 int length;
public:
	MyString();
	MyString(const char* str);
	
	void Print();
	MyString(const MyString& other);// конструктор копирования
	MyString(MyString&& other);//конструктор перемещения 
	MyString& operator=(const MyString& other);
	MyString operator+(const MyString& other);
	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	char& operator[](int index);
	friend std::ostream& operator<<(std::ostream& out, MyString str);
	friend std::istream& operator>>(std::istream& in, MyString str);
	int Size();
	~MyString();
};

