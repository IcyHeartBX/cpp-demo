#include <iostream>
using namespace std;

//求圆的面积
class MyCircle
{
public:
	//半径
	double m_r;
	//面积
	double m_s;
public:
	double getR()
	{
		return m_r;
	}

	void setR(double r)
	{
		m_r = r;
	}
	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
protected:
private:

};


void main()
{
	MyCircle c1,c2;
	c1.setR(10);
	cout<<"c1.s"<<c1.getS()<<endl;
	system("pause");
}