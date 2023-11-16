#include<iostream>
#include<vector>
#include<algorithm>
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846

using namespace std;
vector<double>transformedVector1(3);
vector<double>transformedVector2(3);
vector<double>transformedVector3(3);
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	
	glColor3f(1.0, 0.0, 0.0);   //red
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); 
	glVertex3f(transformedVector1[0], transformedVector1[1], transformedVector1[2]); 
	glEnd();
	
	glColor3f(0.0, 1.0, 0.0);   //green
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); 
	glVertex3f(transformedVector2[0], transformedVector2[1], transformedVector2[2]); 
	glEnd();
	
	glColor3f(0.0, 0.0, 1.0);    //blue
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0); 
	glVertex3f(transformedVector3[0], transformedVector3[1], transformedVector3[2]); 
	glEnd();
	
	glFlush();
}


vector<double>matrixVector(vector<vector<double>> matrix, vector<double> A)
{
	vector<double>result(matrix.size(), 0.0);
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix.size(); j++)
		{

			result[i] = result[i] + matrix[i][j] * A[j];
		}
	}
	return result;
}

vector<vector<double>> createScalingMatrix(double scale)
{
	vector<vector<double>> transformationMatrix(3, vector<double>(3, 0.0));
	{
		for (int i = 0; i < 3; i++)
		{
			transformationMatrix[i][i] = scale;
		}
		return transformationMatrix;
	}
}

void printMatrix(const vector<vector<double>>matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void printVectorRangeBased(const vector<double>& vec) {
	for (double element : vec) {
		cout << element << " ";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	vector<double>A = { 10,0,0 };
	vector<vector<double>> matrix =
	{
		{0,0,1},
		{0,1,0},
		{-1,0,0}
	};


	vector<double>transformedVector = matrixVector(matrix, A);

	cout << "Transformed Matrix is:" << endl;
	printVectorRangeBased(transformedVector);

	const double PI = 3.141592653589793238463;
	double angle = PI / 4;
	vector<vector<double>>rotationZ =
	{
		{cos(angle),-sin(angle),0},
		{sin(angle),cos(angle),0},
		{0,0,1}
	};

	cout << endl << "Rotation Matrix after rotating it 45 dgeree the transformation matrix around z axis is:" << endl;
	printMatrix(rotationZ);

	cout << endl << "transformation matrix for uniform scaling of 3" << endl;
	double scale = 3.0;
	vector<vector<double>> transformationMatrix = createScalingMatrix(scale);

	for (auto row : transformationMatrix)
	{
		for (auto element : row)
		{
			cout << element << " ";
		}
		cout << endl;
	}

	vector<vector<double>>rotationY =
	{
		{cos(angle),0,sin(angle)},
		{0,1,0},
		 {-sin(angle),0,cos(angle)}
	};
	cout << endl << "Rotation Matrix after rotating it 45 dgeree the transformation matrix around y axis is:" << endl;
	printMatrix(rotationY);

	vector<vector<double>>rotationX =
	{

		{1,0,0},
		{0,cos(angle),-sin(angle)},
		 {0,sin(angle),cos(angle)}
	};
	cout << endl << "Rotation Matrix after rotating it 45 dgeree the transformation matrix around x axis is:" << endl;
	printMatrix(rotationX);

	transformedVector1 = matrixVector(rotationZ, A);
	cout << endl << "Transformed Matrix with performing rotation around z axis of 45 degree:" << endl;
	printVectorRangeBased(transformedVector1);
	//cout << "transformedVector1[0]:"<<transformedVector1[0] <<endl;

	transformedVector2 = matrixVector(rotationY, A);
	cout << endl << "Transformed Matrix with performing rotation around y axis of 45 degree:" << endl;
	printVectorRangeBased(transformedVector2);

	transformedVector3 = matrixVector(rotationX, A);
	cout << endl << "Transformed Matrix with performing rotation around x axis of 45 degree:" << endl;
	printVectorRangeBased(transformedVector3);
	cout << endl;

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