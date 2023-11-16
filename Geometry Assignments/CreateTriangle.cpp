#include<GL/glut.h>
#include<iostream>

void MyInit()      //to refelct this function we must right glClear(GL_COLOR_BUFFER_BIT); glFlush();
{
	glClearColor(0, 0, 0, 1);    //black bg 
	glColor3f(1, 0, 0);					//red design 
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);    //FOR GROUPING VERTEXES AND THIS IS AN SINGLE OBJECT FROM START TO END
		//glVertex2f(-0.5, 0.5);  
		glVertex2f(0.0, 0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(-0.5, -0.5);
	glEnd();
	glFlush();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitWindowPosition(500,100);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("..Basic OpenGL..");
	MyInit();
	glutDisplayFunc(draw);
	glutMainLoop();     //starting point for window operation
	return 0;
}