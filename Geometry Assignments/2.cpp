/*
Write a program to find the midpoint for given two 3D points.

Inputs:
First Point: Array[3]
Second point: Array[3]

Output:
Midpoint: Array[3]

Input : x1 = –1, y1 = 2, z1=1
x2 = 3, y2 = –6, z2=3
Output : 1,–2, 2
*/


#include<iostream>
#include <array>
using namespace std;

class MidPoint
{
private:
	int arr1[3], arr2[3], arr3[3];
public:
	void accept()
	{
		cout << "Enter value for x1, y1 and z1: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> arr1[i];
		}
		cout << endl;
		cout << "Enter value for x2, y2 and z2: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> arr2[i];
		}
		cout << endl;
	}

	void CalculateMidpoint()
	{
		for (int i = 0; i < 3; i++)
		{
			arr3[i] = ((arr1[i] + arr2[i]) / 2);
			cout << arr3[i] << "\t";
		}
		cout << endl;
	}
};


int main()
{
	MidPoint obj1;
	obj1.accept();
	cout << "Midpoint for 3D point is: ";
	obj1.CalculateMidpoint();
}