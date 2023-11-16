/*Write a program to calculate distance between two 3D points.

Input:
First Point: Array[3]
Second point: Array[3]
Output:
Distance: decimal

Example:
1) Input:
x1, y1, z1 = (2, -5, 7)
x2, y2, z1 = (3, 4, 5)
Output: 9.2736184955

2) Input:
x1, y1, z1 = (0, 0, 0)
x2, y2, z1 = (1, 1, 1)
Output: 1.73205080757
*/


#include<iostream>
#include<math.h>
using namespace std;
/*
int main()
{
	int x1, x2, y1, y2, z1, z2,T;
	double distance;
	cout << "How many Test cases:";
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cout << "Enter x1 and x2:";
		cin >> x1 >> x2;
		cout << "Enter y1 and y2:";
		cin >> y1 >> y2;
		cout << "Enter x1 and x2:";
		cin >> z1 >> z2;
	}
	cout << "Distance between 3D Point is : ";
	distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) + ((z2 - z1) * (z2 - z1)));
	cout << distance;

}

*/

class Distance
{
private:
	int arr1[3], arr2[3];
	double distance;
public:
	void accept()
	{
		cout << "Enter x1, y1 and z1: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> arr1[i];
		}
		cout << endl;
		cout << "Enter x2, y2 and z2: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> arr2[i];
		}
		cout << endl;
	}

	void CalculateDistance()
	{
		distance = sqrt(((arr2[0] - arr1[0]) * (arr2[0] - arr1[0])) + ((arr2[1] - arr1[1]) * (arr2[1] - arr1[1])) + ((arr2[2] - arr1[2]) * (arr2[2] - arr1[2])));
		cout << distance;
	}
};


int main()
{
	Distance obj1;
	obj1.accept();
	cout << "Distance Between 3D Point is: ";
	obj1.CalculateDistance();
}