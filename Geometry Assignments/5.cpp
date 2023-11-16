/*
Write a program to project the point G on given line SE.

Inputs:
• Start End ( S E ) points of line.
• Point ( G )
Output:
• Point ( P )
*/

/*
1.Calculate slope of line SE by using slope=y2-y1/x2-x1.
2.Then To calculate slope of point Perpendicular to line SE will be -ve resiprocal of line SE.
3.Find equation for line SE by using point-slope formula i.e y-y1=m(x-x1). take starting point of line SE as value of x1 and y1.
4.now find equation for point G as well by using same point slop formula
5.Solve these both equation and get the value of x and y.
*/


//#include <iostream>
//using namespace std;
//
//class Point {
//public:
//	double x;
//	double y;
//
//	Point(double xValue, double yValue) {
//		x = xValue;
//		y = yValue;
//	}
//};
//
//double calculateSlope(Point start, Point end) {
//	// Calculate the slope of the line AB
//	return (end.y - start.y) / (end.x - start.x);
//}

//Point projectPointOnLineSegment(Point p, Point start, Point end) {
//	// Step 1: Find the slope of line AB
//	double slopeAB = calculateSlope(start, end);
//	cout << "slopeAB:" << slopeAB<<endl;
//
//	// Step 2: Use point-slope formula to get the equation for line AB
//	double bAB = start.y - slopeAB * start.x;
//	cout << "bAB:" << bAB << endl;
//
//	// Step 3: Take the negative reciprocal of slope AB
//	double negativeReciprocalSlopeAB = -1.0 / slopeAB;
//
//	// Step 4: Use point-slope formula to get the equation for point P
//	double bP = p.y - negativeReciprocalSlopeAB * p.x;
//	cout << "bP:" << bP << endl;
//
//	// Solve the equations to find the coordinates of the projected point
//	double projectedX = (bP - bAB) / (slopeAB - negativeReciprocalSlopeAB);
//	cout << "projectedX:" << projectedX<<endl;
//	double projectedY = slopeAB * projectedX + bAB;
//	cout << "projectedY:" << projectedY <<endl;
//
//	return Point(projectedX, projectedY);
//}

#include <iostream>
#include <cmath>

class Point {
public:
    int x;
    int y;

    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

int main() {
    int startX, startY, endX, endY, pX, pY;

    std::cout << "Enter x-coordinate of the starting point: ";
    std::cin >> startX;
    std::cout << "Enter y-coordinate of the starting point: ";
    std::cin >> startY;

    std::cout << "Enter x-coordinate of the ending point: ";
    std::cin >> endX;
    std::cout << "Enter y-coordinate of the ending point: ";
    std::cin >> endY;

    std::cout << "Enter x-coordinate of point p: ";
    std::cin >> pX;
    std::cout << "Enter y-coordinate of point p: ";
    std::cin >> pY;

    Point start(startX, startY);
    Point end(endX, endY);
    Point p(pX, pY);

    // Calculate the direction vector SE
    int SEx = end.x - start.x;
    int SEy = end.y - start.y;

    // Calculate the magnitude of the SE vector
    double magnitudeSE = sqrt(SEx * SEx + SEy * SEy);

    // Calculate the direction vector SG
    int SGx = p.x - start.x;
    int SGy = p.y - start.y;

    // Calculate the magnitude of the SG vector
    double magnitudeSG = sqrt(SGx * SGx + SGy * SGy);

    // Calculate the dot product of SG and SE
    int dotProduct = SGx * SEx + SGy * SEy;

    // Perform the desired mathematical operations
    double scalar = dotProduct / (magnitudeSG * magnitudeSG);


    // Calculate the final vector
    int resultX = static_cast<int>(scalar * SGx);
    int resultY = static_cast<int>(scalar * SGy);

    // Add the start point to resultX and resultY
    int finalX = start.x + resultX;
    int finalY = start.y + resultY;

    std::cout << "Final Point: (" << finalX << ", " << finalY << ")" << std::endl;



    return 0;
}
