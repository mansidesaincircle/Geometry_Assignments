#include<GL/glut.h>
#include<iostream>
GLfloat T = 0;

void Spin()
{
	T = T + 1;
	if (T > 360)
		T = 0;
		glutPostRedisplay();
}

void MyInit()      //to refelct this function we must right glClear(GL_COLOR_BUFFER_BIT); glFlush();
{
	glClearColor(0, 0, 0, 1);    //black bg 
	glColor3f(1, 0, 0);					//red design 
	glEnable(GL_DEPTH_TEST);     //one face is not visible
}

void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[] )
{
	glBegin(GL_TRIANGLES);    //FOR GROUPING VERTEXES AND THIS IS AN SINGLE OBJECT FROM START TO END
	glVertex3fv(A);     //if ur using glVertex3f u need to pass arguements as a points(A[0],A[1],A[2]
 	glVertex3fv(B);
	glVertex3fv(C);
	glVertex3fv(D);
	glEnd();
}

void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{
	//front
	glColor3f(1, 0, 0);
	Face(V0,V1,V2,V3);

	//back
	glColor3f(0, 1, 0);
	Face(V4, V5, V6, V7);
	
	//left
	glColor3f(0, 0, 1);
	Face(V3, V7, V4, V0);
	
	//right
	glColor3f(1, 1, 0);
	Face(V2, V6, V5, V1);
	
	//top
	glColor3f(0, 1, 1);
	Face(V0, V1, V5, V4);
	
	//bottom
	glColor3f(1, 0, 1);
	Face(V3, V2, V6, V7);
	
}



void draw()
{
	GLfloat V[8][3] = {

		{ -0.5 ,  0.5 , 0.5 },
		{  0.5 ,  0.5 , 0.5 },
		{  0.5 , -0.5 , 0.5 },
		{ -0.5 , -0.5 , 0.5 },

		{ -0.5 ,  0.5 , -0.5 },
		{  0.5 ,  0.5 , -0.5 },
		{  0.5 , -0.5 , -0.5 },
		{ -0.5 , -0.5 , -0.5 },

	};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(T, 1, 1, 0);

	Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);

	
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("---3D CUBE---");
	MyInit();
	glutDisplayFunc(draw);
	glutIdleFunc(Spin);
	glutMainLoop();     //starting point for window operation
	return 0;
}