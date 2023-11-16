#define _USE_MATH_DEFINES  // Required for M_PI
#include<iostream>
using namespace std;
#include <GL/glut.h>
#include <cmath>

int windowWidth = 800;    // Width of the window in pixels
int windowHeight = 800;   // Height of the window in pixels
float squareSize = 100.0; // Size of the square in pixels
float circleRadius = 50.0; // Radius of the inscribed circle in pixels
float buttonWidth = 100.0; // Width of the buttons
float buttonHeight = 50.0; // Height of the buttons
float spacing = 50.0;      // Spacing between the buttons

void MyInit()
{
	glClearColor(0, 0, 0, 1);    //black
	glColor3f(1, 1, 1);           //white
}

void DrawSquareAndCircle()
{
	// Calculate the coordinates for the square
	float squareLeft = -squareSize / 2.0;
	float squareRight = squareSize / 2.0;
	float squareBottom = -squareSize / 2.0;
	float squareTop = squareSize / 2.0;

	// Draw the square
	glBegin(GL_LINE_LOOP);
	glVertex2f(squareLeft, squareBottom);
	glVertex2f(squareLeft, squareTop);
	glVertex2f(squareRight, squareTop);
	glVertex2f(squareRight, squareBottom);
	glEnd();

	// Draw the inscribed circle
	int numSegments = 100;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < numSegments; ++i)
	{
		float theta = 2.0 * M_PI * i / numSegments;
		float x = circleRadius * cos(theta);
		float y = circleRadius * sin(theta);
		glVertex2f(x, y);
	}
	glEnd();
}

void DrawButton(float x, float y, const char* label)
{
	// Draw the button outline
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x, y + buttonHeight);
	glVertex2f(x + buttonWidth, y + buttonHeight);
	glVertex2f(x + buttonWidth, y);
	glEnd();

	// Calculate the position for the label
	float labelX = x + buttonWidth / 2 - glutBitmapLength(GLUT_BITMAP_HELVETICA_12, (const unsigned char*)label) / 2;
	float labelY = y + buttonHeight / 2 - 5;

	// Render the label
	glRasterPos2f(labelX, labelY);
	for (int i = 0; label[i] != '\0'; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[i]);
	}
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Calculate the position of the square and circle
	float squarePosX = 0.0;
	float squarePosY = 0.0;

	// Draw the square and circle
	glPushMatrix();
	glTranslatef(squarePosX, squarePosY, 0.0);
	DrawSquareAndCircle();
	glPopMatrix();

	// Calculate the total width of all buttons and spacing
	float totalWidth = 3 * buttonWidth + 2 * spacing;
	float startX = -totalWidth / 2;

	// Draw the buttons
	DrawButton(startX, -windowHeight / 2 + 20, "Start");
	DrawButton(startX + buttonWidth + spacing, -windowHeight / 2 + 20, "Pause");
	DrawButton(startX + 2 * (buttonWidth + spacing), -windowHeight / 2 + 20, "Stop");

	glFlush();
}

void Reshape(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(400, 50);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	MyInit();

	glutCreateWindow("Buttons and Shapes");
	glutDisplayFunc(Draw);
	glutReshapeFunc(Reshape);  // Handle window resizing
	glutMainLoop();
	return 0;
}
