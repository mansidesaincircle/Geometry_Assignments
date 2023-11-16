#include<iostream>
using namespace std;

int main()
{
	int x1, x2, r, y1, y2;
	double d;
	cout << "Enter Coordinate of Center of Circle: ";
	cin >> x1>>y1;
	cout << "Enter Radius: ";
	cin >> r;
	cout << "Enter Point to Check whether it lies On Circle , Inside Circle or Outside the Circle: ";
	cin >> x2>>y2;
	d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	if (d == r)
	{
		cout << "Point" << "(" << x2 << "," << y2 << ")" << "Lies On Circle... " << endl;
	}
	if (d > r)
	{
		cout << "Point" << "(" << x2 << "," << y2 << ")" << "Lies Outside the Circle... " << endl;
	}
	if (d < r)
	{
		cout << "Point" << "(" << x2 << "," << y2 << ")" << "Lies Inside the Circle... " << endl;
	}
}