#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <GL/glut.h>
#include<sstream>
using namespace std;
class Vertex {
public:
	float x, y, z;
};
class face {
public:
	float v1, v2, v3;
};
vector<Vertex> v;
vector<face> f;


void parserObj()
{
	ifstream file("Obj_file.obj");
	string line;
	while (getline(file, line))
	{
		if (line.empty() || line[0] == '#')
		{
			continue;
		}
		string prefix;
		istringstream iss(line);
		cout << line << endl;
		iss >> prefix;
		if (prefix == "v")
		{
			Vertex tempVertex;
			iss >> tempVertex.x >> tempVertex.y >> tempVertex.z;
			v.push_back(tempVertex);
			// cout<<tempVertex.y;

		}
		else if (prefix == "f")
		{
			face tempFace;
			string vert1, vert2, vert3;
			iss >> vert1 >> vert2 >> vert3;
			tempFace.v1 = (vert1[0] - '0') - 1;
			tempFace.v2 = (vert2[0] - '0') - 1;
			tempFace.v3 = (vert3[0] - '0') - 1;
			//cout << "temp face:v1 " << tempFace.v1 << "   v2 " << tempFace.v2 << "   v3 " << tempFace.v3 << endl;
			f.push_back(tempFace);
		}
	}

}


//opengl code
GLfloat T = 0;
void MyInit() {

	glClearColor(0, 0, 0, 1);
	glColor3f(1, 0, 0);
	glEnable(GL_DEPTH_TEST);
}
void spin()
{
	T = T + 1;
	if (T > 360)
	{
		T = 0;
	}
	glutPostRedisplay();

}
void obj()
{
	for (float i = 0; i < f.size(); i++) {
		glBegin(GL_TRIANGLES);
		glColor3f(1, 1, 0);
		glVertex3f(v[(f[i].v1)].x, v[(f[i].v1)].y, v[(f[i].v1)].z);
		glColor3f(0, 1, 0);
		glVertex3f(v[(f[i].v2)].x, v[(f[i].v2)].y, v[(f[i].v2)].z);
		glColor3f(0, 0, 1);
		glVertex3f(v[(f[i].v3)].x, v[(f[i].v3)].y, v[(f[i].v3)].z);
		glEnd();
	}
}
void axis()
{	//render x y z axis
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1, 0, 0);
	glVertex3f(1, 0, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, -1, 0);
	glVertex3f(0, 1, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, -1);
	glVertex3f(0, 0, 1);
	glEnd();

}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	axis();
	glRotatef(T, 0, 0, 1);
	obj();

	glutSwapBuffers();
}

int main(int argc,char **argv)
{

	parserObj();


	for (int i = 0; i < f.size(); i++)
	{
		cout << i + 1 << " vertex coordinate x y z:" << v[(f[i].v1)].x << " " << v[(f[i].v1)].y << " " << v[(f[i].v1)].z << endl;
		cout << i + 1 << " vertex coordinate x y z:" << v[(f[i].v2)].x << " " << v[(f[i].v2)].y << " " << v[(f[i].v2)].z << endl;
		cout << i + 1 << " vertex coordinate x y z:" << v[(f[i].v3)].x << " " << v[(f[i].v3)].y << " " << v[(f[i].v3)].z << endl;

	}


	glutInit(&argc,argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("objParser");
	MyInit();
	glutDisplayFunc(draw);
	glutIdleFunc(spin);
	glutMainLoop();
	return 0;

}
