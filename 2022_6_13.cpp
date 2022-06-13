#include<iostream>
#define PI 3.14
using namespace std;
class CShape
{
public:
	virtual void printArea() = 0;
	static void printMe()
	{
		cout << "T am CShape" << endl;
	}
};
class CCircle :public CShape
{
public:
	CCircle(float n)
	{
		this->r = n;
	}
	void printMe()
	{
		cout << "T am CCircle" << endl;
	}
	void printArea()
	{
		cout << this->r*this->r*PI << endl;
	}
private:
	float r;
};
class CRectangle :public CShape
{
public:
	CRectangle(float l, float w)
	{
		this->lenth = l;
		this->width = w;
	}
	void printMe()
	{
		cout << "I an CRectangle" << endl;
	}
	void printArea()
	{
		cout << this->lenth*this->width << endl;
	}
private:
	float lenth;
	float width;
};
int main()
{
	CShape::printMe();
	CCircle c(9.9);
	c.printMe();
	c.printArea();
	CRectangle r(3, 4);
	r.printMe();
	r.printArea();
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int a[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < 10; i++)
	{
		int max_h = a[i][0], y;
		for (int j = 0; j < 10; j++)
			if (max_h < a[i][j])
			{
				max_h = a[i][j];
				y = j;
			}
		cout << "第" << i + 1 << "行最大值是为a[" << i << "][" << y << "]=" << max_h << endl;
	}
	return 0;
}