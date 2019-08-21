/*
 * My_String.cpp
 *
 *  Created on: 2017年2月23日
 *      Author: pixboly
 */

#include "My_String.h"

MyString::MyString(const char * string )
{
	// 长度检查
	if(string == NULL || strlen(string) == 0)
	{
		m_length = 0;
	}
	else {
		m_length = strlen(string);
	}
	// 分配内存
	m_Buff = new char[m_length + 1];
	// 拷贝内容
	if(string != NULL)
	{
		strcpy(m_Buff,string);
	}
	else {
		strcpy(m_Buff,"");
	}
}
MyString::MyString(int len)
{
	if(len <0 ) {
		len = 0;
	}
	m_length = len;
	m_Buff = new char[m_length];
}

MyString::~MyString()
{
		if(m_Buff != NULL)
		{
			delete [] m_Buff;
			m_Buff = NULL;
		}
		m_length = 0;
}

// 拷贝构造
MyString::MyString(const MyString & obj)
{
	this->m_length = obj.m_length;
	// 分配内存
	this->m_Buff = new char[this->m_length+ 1];
	// 拷贝内容
	strcpy(this->m_Buff,obj.m_Buff);
}

MyString & MyString::operator=(MyString & obj)
{
	//释放旧的空间
	if(this->m_Buff != NULL)
	{
		delete [] this->m_Buff;
		this->m_Buff = NULL;
		this->m_length = 0;
	}
	this->m_length = obj.m_length;
	// 分配新的内存空间
	this->m_Buff = new char[obj.m_length + 1];
	// 拷贝数据
	strcpy(m_Buff,obj.m_Buff);
	return *this;
}

MyString & MyString::operator=(const char * s)
{
	// 释放之前的内存空间
	if(m_Buff != NULL)
	{
		delete [] m_Buff;
		m_Buff = NULL;
		m_length = 0;
	}
	if(s == NULL || strlen(s) == 0)
	{
		this->m_length = 0;
		m_Buff = new char[m_length + 1];
		strcpy(m_Buff,"");
	}
	else
	{
		this->m_length = strlen(s);
		m_Buff = new char[m_length + 1];
		strcpy(m_Buff,s);
	}
	return *this;
}


bool MyString::operator==(MyString & obj) const
{
	if(this->m_length != obj.m_length)
	{
			return false;
	}
	if(strcmp(this->m_Buff,obj.m_Buff) != 0)
	{
		return false;
	}
	return true;
}

bool MyString::operator==(const char * s) const
{
	if(s == NULL)
	{
		return false;
	}
	if(this->m_length != strlen(s))
	{
		return false;
	}
	if(strcmp(this->m_Buff,s) != 0)
	{
		return false;
	}
	return true;
}


// 重载!=操作
bool MyString::operator!=(MyString & obj) const
{
	return !(*this == obj);
}

bool MyString::operator!=(const char * s) const
{
	return !(*this == s);
}

ostream & operator<<(ostream & out,MyString & s)
{
	out<<s.m_Buff;
	return out;
}

istream & operator>>(istream & in,MyString & s)
{
	in>>s.m_Buff;
	return in;
}

// 重载[]操作
char & MyString::operator[](int index)
{
	if(index >= m_length || index < 0)
	{
		cout<<"Error index >= m_length"<<endl;
		return m_Buff[m_length - 1];
	}
	return m_Buff[index];
}

// 重载<操作
int MyString::operator<(MyString & obj) const
{
	return strcmp(obj.m_Buff,m_Buff);
}
int MyString::operator<(const char * s) const
{
	return strcmp(s,m_Buff);
}
// 重载>操作
int MyString::operator>(MyString & obj) const
{
	return strcmp(m_Buff,obj.m_Buff);
}
int MyString::operator>(const char * s) const
{
	return strcmp(m_Buff,s);
}



void Test_String()
{
		MyString s1;
		MyString s2("abc");
		MyString s3 = s2;
		MyString s4("bcd");
		s1 = s2;
		s4 = "444";

		cout<<"s1:"<<s1<<endl;
		cout<<"s2:"<<s2<<endl;
		cout<<"s3:"<<s3<<endl;
		cout<<"s4:"<<s4<<endl;

		s2[2] = '5';
		cout<<"s2[2]:"<<s2[2]<<endl;

		if(s1 == s2)
		{
			cout<<"s1:"<<s1<< " == " <<"s2:"<<s2<<endl;
		}
		if(s1 != s4)
		{
			cout<<"s1:"<<s1<< " != "<<"s4:"<<s4<<endl;
		}

		if(s1 == "abc")
		{
			cout<<"s1:"<<s1<< " == " <<"abc"<<endl;
		}
		if(s1 != "555")
		{
			cout<<"s1:"<<s1<< " != "<<"555"<<endl;
		}

		MyString s5(100);
		cin>>s5;
		cout<<"s5:"<<s5<<endl;

}

