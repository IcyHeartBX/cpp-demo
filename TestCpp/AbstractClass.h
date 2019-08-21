/*
 * AbstractClass.h
 *
 *  Created on: 2017年5月26日
 *      Author: tangpengxiang
 */

#ifndef ABSTRACTCLASS_H_
#define ABSTRACTCLASS_H_
#include <iostream>
using namespace std;
class Figure // 抽象类
{
public:
	virtual ~Figure();
	// 提供统一的接口
	virtual int getArea() = 0; // 纯虚函数
};

class Circle : public Figure {
public :
	Circle(int r) {
		this->m_r = r;
	}
	virtual int getArea() {
		int area = int(3.14 * m_r * m_r);
		cout<<"Circle area is :" << area <<endl;
		return  area;
	}
private :
	int m_r;
};





#endif /* ABSTRACTCLASS_H_ */
