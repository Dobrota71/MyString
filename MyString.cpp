#include "MyString.h"


MyString::MyString()
{
	str = nullptr;
	length = 0;
}
MyString::MyString(const char* str)
{
	length = strlen(str);//подсчет количество символов в строке пока не наткнется на терминирующий ноль
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}

	this->str[length] = '\0';
	
}

MyString::MyString(const MyString& other)
{
	length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';
}

MyString::MyString( MyString&& other)
{
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
}

MyString& MyString::operator=(const MyString& other)// перегруженный конструктор присваивания
{
	if (this->str != nullptr)
		delete[] str;
	length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';
	return *this;

}

MyString MyString::operator+(const MyString& other)
{
	MyString newStr;
	int thisLength = strlen(this->str);
	int otherLength = strlen(other.str);
	newStr.length = thisLength + otherLength;
	newStr.str = new char[thisLength + otherLength+1];
	int i = 0;
	for (; i < thisLength; i++)
	{
		newStr.str[i] = this->str[i];
	}
	for (int j = 0; j < otherLength; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}
	newStr.str[thisLength + otherLength] = '\0';

	return newStr;

}

bool MyString::operator==(const MyString& other)
{
	if (this -> length != other.length)
	return false;
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] != other.str[i])
			return false;
	}
	return true;
}

bool MyString::operator!=(const MyString& other)
{
	return !(this->operator==(other));
}

char& MyString::operator[](int index)
{
	return this->str[index];
}

void MyString::Print()
{
	std::cout << str << '\n';
}

int MyString::Size()
{
	return length;
}

MyString::~MyString()
{
	delete[] this->str;
}


std::ostream& operator<<(std::ostream& out, MyString str)
{
	if (this->str == nullptr)
		std::cout << "Error";
	std::cout << this->str;
	return out;
}

std::istream& operator>>(std::istream& in, MyString str)
{
	std::cin >> this->str;
	return in;
}


