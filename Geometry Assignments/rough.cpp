#include<iostream>
#include<vector>
using namespace std;

double slopeOfLine(double a1, double b1, double a2, double b2)
{
	double slope = (b2 - b1) / (a2 - a1);
	return slope;
}

int main()
{
	vector<pair<int, int>>vec;
	double n, x, y,x1,y1,x2,y2;
	cout << "Enter Points of S:";
	cin >> x1 >> y1;
	cout << "Enter Points of E:";
	cin >> x2 >> y2;
	cout << "Enter Point G:";
	cin >> x >> y;
	vec.push_back(make_pair(x1, y1));
	vec.push_back(make_pair(x2, y2));
	vec.push_back(make_pair(x, y));
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first <<"\t"<< vec[i].second<<endl;
	}


}