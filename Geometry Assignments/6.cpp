#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double degree, radian, y2, x2, x, y = 0;
	cout << "Enter x coordinates of E1 assuming that y=0: ";
	cin >> x;
	cout << "Angle of Rotation in degree: ";
	cin >> degree;
	radian = (3.142 / 180) * degree;
	//cout << "Radian: " << radian<<endl;
	x2 = cos(radian)*x;
	//cout << "cos(radian):"<< cos(radian)<<endl;
	y2 = sin(radian)*x;
	//cout << "sin(radian):" << sin(radian) << endl;
	cout <<"Updated Coordinates of Point E2 after rotation is: "<<endl<<"x: " << x2 << endl << "y: " << y2<<endl;
}

