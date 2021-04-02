#include <bits/stdc++.h>
using namespace std;

class point
{
	public:
		double x, y;
		double* ptr;
	public:
		point(double, double); // TODO: constructor.
		
		point()
		{
			x = 0;
			y = 1;
		};
		
		friend ostream& operator<<(ostream&, point);
		friend double operator+(point, point);
		point add(point); // function.
};

double operator+(point a, point b)
{
	return 10;
}

ostream& operator<<(ostream& os, point src)
{
	os << "[" << src.x << ", " << src.y << "]\n";
	
	return os;
}

point::point(double a, double b)
{
	x = a+b;
	y = a-b;
}

int main()
{
	/*
	class -> object
	type -> variable
	int -> int a = 5;
	
	int a = 5;
	int b = 10;
	
	point a;
	
	*/
	point a(2, 3);
	cout << a.x << ' ' << a.y << endl;
	point b;
	cout << b.x << ' ' << b.y << endl;
	
	// a.add(b);
	cout << a + b;
	cout << a;
}