#include<iostream>
using namespace std;


int main()
{
	double x1, y1;
	cout << "Enter the x and y coordinates of starting point of 1st line with spaces : " << endl;
	cin >> x1 >> y1;

	double x2, y2;
	cout << "Enter the x and y coordinates of end point of 1st line with spaces : " << endl;
	cin >> x2 >> y2;

	double x3, y3;
	cout << "Enter the x and y coordinates of starting point of 2nd line with spaces : " << endl;
	cin >> x3 >> y3;

	double x4, y4;
	cout << "Enter the x and y coordinates of end point of 2nd line with spaces : " << endl;
	cin >> x4 >> y4;

	double orien = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 * x1);
	if (orien == 0)
	{
		cout << "Lines are collinear.." << endl;
	}
	else if (orien < 0)
	{
		cout << "Clockwise Orientation..." << endl;
	}
	else
	{
		cout << "AntiClockwise Orientation...." << endl;
	}
}