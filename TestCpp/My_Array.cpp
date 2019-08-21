/*
 * My_Array.cpp
 *
 *  Created on: 2017年2月23日
 *      Author: pixboly
 */
#include "My_Array.h"


Array::Array(int length)
{
	// 构造数组
	if(length <0 )
	{
		m_length = 0;
	}
	m_length = length;
	m_space = new int[length];
}

// 析构数组
Array::~Array()
{
	if(m_space != NULL)
	{
		delete [] m_space;
		m_space = NULL;
		m_length = 0;
	}
}

// 拷贝构造
Array::Array(const Array & obj)
{
		if(obj.m_length <= 0)
		{
			m_length = 0;
		}
		this->m_length = obj.m_length;
		m_space = new int[m_length];
		memcpy(m_space,obj.m_space,sizeof(int)*m_length);
}

int Array::GetData(int index)
{
	if(index <= m_length -1)
	{
		return m_space[index];
	}
	return 0;
}

void Array::SetData(int index ,int value)
{
	if(index <= m_length -1)
	{
		m_space[index] = value;
	}
}

int Array::Length()
{
	return m_length;
}

ostream & operator<<(ostream & out,Array & obj)
{
	out << "[ ";
	for(int i = 0 ;i < obj.m_length - 1;i++)
	{
		out<<obj.GetData(i) << " , ";
	}
	out << obj.GetData(obj.Length() - 1) << " ]";
	return out;
}

Array & Array::operator=(const Array & obj)
{
	// 释放原来的内存
	if(m_space != NULL)
	{
		delete [] m_space;
		m_space = NULL;
		m_length = 0;
	}
	if(obj.m_length <= 0)
			{
				m_length = 0;
			}
			this->m_length = obj.m_length;
			m_space = new int[m_length];
			memcpy(m_space,obj.m_space,sizeof(int)*m_length);
			return *this;
}

int & Array::operator[](int i)
{
		return m_space[i];
}

bool Array::operator==(Array & obj)
{
	if(this->m_length != obj.m_length)
	{
		return false;
	}
	for (int i = 0 ;i < this->m_length ;i++)
	{
		if(this->m_space[i] != obj.m_space[i])
		{
			return false;
		}
	}
	return true;
}

bool Array::operator!=(Array & obj)
{
	return !(*this == obj);
}


void Test_Array(void)
{
	cout<< "FUNC Test_Array(),RUN..."<<endl;
	Array arr(10);
	for(int i = 0;i < arr.Length();i++)
	{
//		arr.SetData(i,i);
		arr[i] = i;
	}
	cout<<"arr:"<< arr<< endl;
	Array arr2 = arr;
	cout<<"arr2:"<<arr2<<endl;
	Array arr3;
	arr3 = arr2;
	cout<<"arr3:"<<arr3<<endl;

	int num = arr[5];
	cout<<"num:"<<num<<endl;

	if(arr == arr2)
	{
		cout << "arr1 == arr2"<<endl;
	}
}


