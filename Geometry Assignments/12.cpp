#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include <vector>
#include<algorithm>
#include <GL/glut.h>
using namespace std;

vector<float>R(3);
vector<float>dott(3);
vector<float> perpendicularVector(3);
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	
	// Set the color of the first line
	glColor3f(1.0, 0.0, 0.0); // Red color

	// Set up the first line segment using glBegin and glEnd
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); // P1(0, 0, 0)
	glVertex3f(10.0, 0.0, 0.0); // P2(10, 0, 0)
	glEnd();

	// Set the color of the second line
	glColor3f(0.0, 1.0, 0.0); // Green color

	// Set up the second line segment using glBegin and glEnd
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); // P3(0, 0, 0)
	glVertex3f(0.0, 10.0, 0.0); // P4(0, 10, 0)
	glEnd();
	
	// Set the color of the third line
	glColor3f(0.0, 0.0, 1.0); // Blue color

	// Set up the third line segment using glBegin and glEnd
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); // P5(0, 0, 0)
	glVertex3f(10.0, 10.0, 0.0); // P6(10, 10, 0)
	glEnd();
	
	
	glColor3f(1.0, 1.0, 0.0);  //yellow

	// Set up the line segment using glBegin and glEnd
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); // Starting point (origin)
	glVertex3f(0.0, 0.0, 10); // Endpoint representing vector R
	
	glEnd();

	
	glColor3f(1.0, 0.0, 1.0);   //cyan

	// Set up the line segment using glBegin and glEnd
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); // Starting point (origin)
	glVertex3f(dott[0], dott[1], dott[2]); // Endpoint representing vector R
	glEnd();
	
	glColor3f(0.0, 1.0, 1.0); // Purple color


	// Set up the perpendicular line segment using glBegin and glEnd
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); // Starting point (origin)
	glVertex3f(perpendicularVector[0], perpendicularVector[1], perpendicularVector[2]); // Endpoint representing the perpendicular vector
	glEnd();
	
	

	// Check if the cross product is the zero vector
	bool coplanar = (R[0] == 0.0 && R[1] == 0.0 && R[2] == 0.0);

	if (coplanar) {
		cout << "Vector A and Vector C are coplanar." << endl;
	}
	else {
		cout << "Vector A and Vector C are not coplanar." << endl;
	}

	if (coplanar) {
		// Calculate the normal vector of the plane using the cross product of vectors A and C
		vector<float> normal(3);
		normal[0] = R[0];
		normal[1] = R[1];
		normal[2] = R[2];

		// Normalize the normal vector
		float magnitude = sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);
		normal[0] /= magnitude;
		normal[1] /= magnitude;
		normal[2] /= magnitude;

		// Define the side length of the square
		float sideLength = 20.0;

		// Define the vertices of the square
		vector<vector<float>> vertices = {
			{ sideLength / 2, 0.0, sideLength / 2 },
			{ -sideLength / 2, 0.0, sideLength / 2 },
			{ -sideLength / 2, 0.0, -sideLength / 2 },
			{ sideLength / 2, 0.0, -sideLength / 2 }
		};

		// Set the color of the square
		glColor3f(0.5, 0.5, 0.5); // Gray color

		// Set up the square using glBegin and glEnd
		glBegin(GL_QUADS);
		for (const auto& vertex : vertices) {
			glVertex3f(vertex[0], vertex[1], vertex[2]);
		}
		glEnd();
	}
	
	
	glFlush();
}

int main(int argc, char** argv)
{
	// Store the points in vectors
	vector<float> P1 = { 0.0, 0.0, 0.0 };       // P1
	vector<float> P2 = { 10.0, 0.0, 0.0 };      // P2
	vector<float> P3 = { 0.0, 0.0, 0.0 };      // P3
	vector<float> P4 = { 0.0, 10.0, 0.0 };      // P5
	vector<float> P5 = { 0.0, 0.0, 0.0 };       // P4
	vector<float> P6 = { 10.0, 10.0, 0.0 };     // P6
	
	vector<float> A(3);
	cout << "Vector of Point P1 and P2 :" <<endl;
	for (int i = 0; i < 3; i++)
	{
		A[i]=P2[i] - P1[i];
		cout << A[i] << "\t";
	}

	vector<float> B(3);
	cout << endl<<"Vector of Point P3 and P4 :" << endl;
	for (int i = 0; i < 3; i++)
	{
		B[i] = P4[i] - P3[i];
		cout << B[i] << "\t";
	}

	vector<float> C(3);
	cout << endl<<"Vector of Point P5 and P6 :" << endl;
	for (int i = 0; i < 3; i++)
	{
		C[i] = P6[i] - P5[i];
		cout << C[i] << "\t";
	}
	
	cout << endl << "Cross Product of Vector A and B is:" << endl;
	
	R[0] = ((A[1] * B[2]) - (A[2] * B[1]));
	R[1] = ((A[0] * B[2]) - (A[2] * B[0]));
	R[2]=((A[0] * B[1]) - (B[0] * A[1]));
	cout <<"(" <<R[0] << "i"<<"," << R[1] << "j" << "," << R[2] << "k"<<")"<<endl;

	
	cout << "\n" << "Dott Product of Vector A and C is:" << endl;
	dott[0] = (A[0] * C[0]) + (A[1] * C[1]) + (A[2] * C[2]);
	cout << "(" << dott[0] << "i" << "," << dott[1] << "j" << "," << dott[2] << "k" << ")" << endl;

	// Calculate the perpendicular vector to C
	vector<float> perpendicular(3);
	perpendicular[0] = -C[1]; // Negate the y-component of vector C
	perpendicular[1] = C[0]; // Swap the x and y components of vector C
	perpendicular[2] = C[2]; // Keep the z-component the same

	cout << "\nPerpendicular Vector to C is:" << endl;
	
	perpendicularVector[0] = -C[1] * dott[0]; // Multiply the y-component of C by the dot product
	perpendicularVector[1] = C[0] * dott[0]; // Multiply the x-component of C by the dot product
	perpendicularVector[2] = C[2] * dott[0]; // Multiply the z-component of C by the dot product

	cout << "(" << perpendicularVector[0] << "i, " << perpendicularVector[1] << "j, " << perpendicularVector[2] << "k)" << endl;

	// Calculate the magnitudes of vectors A and C
	float magnitudeA = sqrt(A[0] * A[0] + A[1] * A[1] + A[2] * A[2]);
	float magnitudeC = sqrt(C[0] * C[0] + C[1] * C[1] + C[2] * C[2]);

	// Calculate the cosine of the angle between vectors A and C
	float cosAngle = dott[0] / (magnitudeA * magnitudeC);

	// Calculate the angle in radians using the inverse cosine function (acos)
	float angleRad = acos(cosAngle);

	// Convert the angle from radians to degrees
	float angleDeg = angleRad * 180 / M_PI;

	cout << "\nAngle between vector A and vector C: " << angleDeg << " degrees" << endl;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Line Segments");

	// Set the display function
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}
