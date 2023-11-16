/*
Write a program to calculate the point on given line and at given distance from start point.
Hint: Use Vector direction
Note: Please check the attached image before going for coding.

Inputs:
• Start point of line (S) : Array[3]
• End point of line (E): Array[3]
• Distance from start point (d) : decimal
Output:
• Point (P) :Array[3]

*/
/*
#include<iostream>
using namespace std;

class Distance
{
private:
	float Start[3], End[3], arr3[3], d;
public:
	void accept()
	{
		cout << "Enter the Co-ordinate of Start point(S) x1,y1 and z1: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> Start[i];
		}
		cout << endl;
		cout << "Enter the Co-ordinate of End point(E) x2,y2 and z2: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> End[i];
		}
		cout << endl;
		//value of d will lie between 0 to 1
		cout << "Enter distance from Start Point To Point D on Line:";
		cin >> d;

	}

	void CalculateDistance()
	{
		for (int i = 0; i < 3; i++)
		{
			arr3[i] = End[i] - Start[i];           //find distance between point S and E
			arr3[i] = d * arr3[i];                  //d is the point which is away from the point S and E on same line
			arr3[i] = Start[i] + arr3[i];          //calculating coordinate of point D 
			cout << arr3[i] << "\t";
		}
	}

};

int main()
{
	Distance obj1;
	obj1.accept();
	cout << endl << "The Co-ordinate of point D is: ";
	obj1.CalculateDistance();
}
*/

/*
1.Calculate the SE vector=end-start.
2.take magnitude of SE=sqrt(SE^2).
3.find unit vector of it i.e divide each point by its magnitude respectively.
4.multiply distance with unit vector and add with the start point.

*/



#include<iostream>
using namespace std;

class Distance
{
private:
	double Start[3], End[3], arr3[3], d, magnitude=0;
public:
	void accept()
	{
		cout << "Enter the Co-ordinate of Start point(S) x1,y1 and z1: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> Start[i];
		}
		cout << endl;
		cout << "Enter the Co-ordinate of End point(E) x2,y2 and z2: ";
		for (int i = 0; i < 3; i++)
		{
			cin >> End[i];
		}
		cout << endl;
		//value of d
		cout << "Enter distance from Start Point S To Point D on Line:";
		cin >> d;
	}

	void UnitPoint()
	{
	
		for (int i = 0; i < 3; i++)
		{
			arr3[i] = End[i] - Start[i];           //find distance between point S and E
			cout << "Vector SE is: " << arr3[i] << "\t"<<endl;
			magnitude = magnitude + sqrt(arr3[i]* arr3[i]);
			cout << "magnitude is: " << magnitude << endl;
			arr3[i] = arr3[i] / magnitude;
			cout << "Unit Vector is: " << arr3[i] <<"\t"<< endl;
		}
	}

	void Distant()
	{
		for (int i = 0; i < 3; i++)
		{
			Start[i] = Start[i] + arr3[i] * d;
			cout << Start[i] << "\t"<<endl;
		}
	}
};


int main()
{
	Distance obj1;
	obj1.accept();
	obj1.UnitPoint();
	obj1.Distant();
}