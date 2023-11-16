#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include<algorithm>
using namespace std;

/*
inputs:
S(1,1), E(4,5), P1(3,2),P2(1,1),P2(6,8)
*/

double calculateDistance(double x1, double y1, double x2, double y2, double x, double y) {
	double A = y2 - y1;
	double B = x1 - x2;
	double C = (x2 * y1) - (x1 * y2);
	return abs((A * x) + (B * y) + C) / sqrt(pow(A, 2) + pow(B, 2));
}

pair<double, double> findClosestPoint(double x1, double y1, double x2, double y2, const vector<pair<double, double>> & points)
{
	pair<double, double> closestPoint;
	double closestDistance = numeric_limits<double>::max();

	

	for (int i = 0; i < points.size(); ++i)
	{
		cout << "points.size():" << points.size() << endl;
		auto point = points[i];
		double distance;

		if (point.first > min(x1, x2) && point.first < max(x1, x2) && point.second > min(y1, y2) && point.second < max(y1, y2)) 
		{
			cout << "point.first:" << point.first << endl;
			cout << "point.second:" << point.second << endl;
			cout << "min(x1, x2) :"<< min(x1, x2)<<endl;
			cout << "max(x1, x2) :" << max(x1, x2) << endl;
			cout << "min(y1, y2) :" << min(y1, y2) << endl;
			cout << "max(y1, y2) :" << max(y1, y2) << endl;
			
			
			// Point is within the range of the line segment
			distance = calculateDistance(x1, y1, x2, y2, point.first, point.second);
			cout << "distance1:" << distance<<endl;
		}
		else {
			// Point is outside the range of the line segment
			distance = sqrt(pow(point.first - x1, 2) + pow(point.second - y1, 2));
			cout << "distance2:" << distance << endl;
		}

		if (distance < closestDistance) {
			closestDistance = distance;
			closestPoint = point;
		}
	}

	return closestPoint;
}

int main() {
	double x1, y1, x2, y2;
	cout << "Enter Start Point (x1, y1): ";
	cin >> x1 >> y1;
	cout << "Enter End Point (x2, y2): ";
	cin >> x2 >> y2;

	int n;
	cout << "How many Points do you want to check: ";
	cin >> n;

	vector<pair<double, double>> points;
	for (int i = 0; i < n; ++i) {
		double x, y;
		cout << "Enter Point " << i + 1 << ": ";
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	pair<double, double> closestPoint = findClosestPoint(x1, y1, x2, y2, points);

	cout << "Closest Point: (" << closestPoint.first << ", " << closestPoint.second << ")" << endl;

	return 0;
}
