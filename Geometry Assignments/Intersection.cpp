#include<iostream>
#include<cmath>



using namespace std;



int main()
{
	//double s1pt[2];
	double x1, y1;
	cout << "Enter the x and y coordinates of starting point of 1st line with spaces : " << endl;
	//cin >> s1pt[0] >> s1pt[1];     //s1pt[0]:x1   s1pt[1]:y1
	cin >> x1 >> y1;

	//double e1pt[2];
	double x2, y2;
	cout << "Enter the x and y coordinates of end point of 1st line with spaces : " << endl;
	//cin >> e1pt[0] >> e1pt[1];     //e1pt[0]:x2   e1pt[1]:y2
	cin >> x2 >> y2;


	//double s2pt[2];
	double x3, y3;
	cout << "Enter the x and y coordinates of starting point of 2nd line with spaces : " << endl;
	//cin >> s2pt[0] >> s2pt[1];     //s2pt[0]:x3   s2pt[1]:y3
	cin >> x3 >> y3;


	//double e2pt[2];
	double x4, y4;
	cout << "Enter the x and y coordinates of end point of 2nd line with spaces : " << endl;
	//cin >> e2pt[0] >> e2pt[1];        //e2pt[0]:x4   e2pt[1]:y4
	cin >> x4 >> y4;

	//equation of first line is a1x + b1y = c1;
	/*
	double a1 = e1pt[1] - s1pt[1];   //y2-y1
	double b1 = s1pt[0] - e1pt[0];    //x1-x2
	double c1 = a1 * s1pt[0] + b1 * s1pt[1];   //a1*x1+b1*y1
	*/
	double a1 = y2 - y1;
	double b1 = x1 - x2;
	double c1 = a1 * x1 + b1 * y1;
	cout << "a1:" << a1 << "\t" << "b1:" << b1 << "\t" << "c1:" << c1 << endl;

	// //equation of second line is a2x + b2y = c2;
	/*
	double a2 = e2pt[1] - s2pt[1];   //y4-y3
	double b2 = s2pt[0] - e2pt[0];    //x3-x4
	double c2 = a2 * s2pt[0] + b2 * s2pt[1];   //a2*x3+b2*y3
	*/
	double a2 = y4 - y3;
	double b2 = x3 - x4;
	double c2 = a2 * x3 + b2 * y3;
	cout << "a2:" << a2 << "\t" << "b2:" << b2 << "\t" << "c2:" << c2 << endl;

	double determinant = a1 * b2 - b1 * a2;



	if (0 == determinant)
		cout << "The lines are parallel" << endl;
	else
	{
		double pt[2];
		pt[0] = (c1 * b2 - c2 * b1) / determinant;
		pt[1] = (a1 * c2 - a2 * c1) / determinant;
		cout << " The coordinates of intersection point of lines are (" << pt[0] << ", " << pt[1] << ")" << endl;
	}


}