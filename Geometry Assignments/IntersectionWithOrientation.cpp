#include<iostream>
using namespace std;

int orientation(int x1, int y1, int x2,int y2,int x3,int y3)
{
	double orien = (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 * x1);
	if (orien == 0)
	{
		return 2;
	}
	else if (orien < 0)
	{
		return 1;
	}
	else return 0;
}



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

	if ((orientation(x1, y1, x2, y2, x3, y3) == 1 && orientation(x1, y1, x2, y2, x4, y4) == 0) ||
		(orientation(x1, y1, x2, y2, x3, y3) == 0 && orientation(x1, y1, x2, y2, x4, y4) == 1) ||
		orientation(x3, y3, x4, y4, x1, y1) == 1 && orientation(x3, y3, x4, y4, x2, y2) == 0)
	{
		cout << "Lines Intersect..." << endl;
	}
	else
	{
		cout << "Lines are not intersecting..."<<endl;
	}
}