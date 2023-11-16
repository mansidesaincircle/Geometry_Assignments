/*
Problem Statement:
Write a program to calculate intersection point between two lines.

Inputs:
• Start End ( s1 e1 ) points of first line.
• Start End ( s2 e2 ) points of second line.
Output:
• Check line are parallel or not ( true/false ).
• If not then display the intersect point (P).
*/

/*1. Equation in form ax+by+c=0
2. take value of x1, y1, c1 and x2, y2, c2
3. Determinant of x1 y1 and x2 y2 this is value of 'D'
4. if determinant is zero lines are parallel if not they are intercepting
5. wec use cramer's rule to find x and y intercepting co-ordinate
6. now to find x coordinate first we find determinant of c1 y1 and c2 y2 and divide this by 'D'
7. now to find y coordinate first we find determinant of c1 x1 and c2 x2 and divide this by 'D'
*/
#include <iostream>

class LineIntersection {
private:
    int x1, y1, x2, y2, x3, y3, x4, y4;
    double a1, b1, c1, a2, b2, c2;
    double det;

public:
    void getInput() {
        std::cout << "Enter start coordinate point of line L1:";
        std::cin >> x1 >> y1;
        std::cout << "Enter end coordinate point of line L1:";
        std::cin >> x2 >> y2;
        std::cout << "Enter start coordinate point of line L2:";
        std::cin >> x3 >> y3;
        std::cout << "Enter end coordinate point of line L2:";
        std::cin >> x4 >> y4;
    }

    void calculateDeterminant() {
        a1 = y2 - y1;
        a2 = y4 - y3;
        b1 = x1 - x2;
        b2 = x3 - x4;
        c1 = a1 * x1 + b1 * y1;
        c2 = a2 * x3 + b2 * y3;
        det = a1 * b2 - b1 * a2;
    }

    void checkAndComputeIntersection() {
        if (det == 0) {
            std::cout << "Lines are parallel" << std::endl;
        }
        else {
            double x, y;
            x = (b2 * c1 - c2 * b1) / det;
            y = (c2 * a1 - c1 * a2) / det;
            std::cout << "Intersection Point: (" << x << ", " << y << ")" << std::endl;
        }
    }
};

int main() {
    LineIntersection intersection;
    intersection.getInput();
    intersection.calculateDeterminant();
    intersection.checkAndComputeIntersection();
    return 0;
}
