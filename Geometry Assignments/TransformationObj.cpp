#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <GL/glut.h>
#include<sstream>
using namespace std;

float rotation_angle = 0.0f;
float spin_angle = 0.0f;
int previous_x = 0;
int previous_y = 0;
void mouse_callback(int x, int y) {
	// calculate the difference between the current and previous mouse positions
	int delta_x = x - previous_x;
	int delta_y = y - previous_y;
	// update the rotation and spin angles based on the mouse movement
	rotation_angle += delta_x;
	spin_angle += delta_y;
	// update the previous mouse position
	previous_x = x;
	previous_y = y;
	// redraw the scene
	glutPostRedisplay();
}

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

void renderAxis()
{
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
}

void rotateAtY()
{
	float angle = (45 * 3.149) / 180;
	for (int i = 0; i < v.size(); i++)
	{
		Vertex a;
		a.x = v[i].x * cos(angle) + v[i].z * sin(angle);
		a.z = -(v[i].x * sin(angle)) + v[i].z * cos(angle);
		v[i].x = a.x;
		v[i].z = a.z;
	}
	cout << "v1" << v[0].x << " " << v[0].y << " " << v[0].z;
}
void rotateAtZ()
{
	float angle = (45 * 3.149) / 180;
	for (int i = 0; i < v.size(); i++)
	{
		Vertex a;
		a.x = v[i].x * cos(angle) + v[i].y * sin(angle);
		a.y = -(v[i].x * sin(angle)) + v[i].y * cos(angle);
		v[i].x = a.x;
		v[i].y = a.y;
	}
	cout << "v1" << v[0].x << " " << v[0].y << " " << v[0].z;
}
void rotateAtX()
{
	float angle = (45 * 3.149) / 180;
	for (int i = 0; i < v.size(); i++)
	{
		Vertex a;
		a.y = v[i].y * cos(angle) + v[i].z * sin(angle);

		a.z = -(v[i].y * sin(angle)) + v[i].z * cos(angle);
		v[i].y = a.y;
		v[i].z = a.z;
	}
	cout << "v1" << v[0].x << " " << v[0].y << " " << v[0].z;
}
void uniformScaleBy3()
{
	Vertex a;
	for (int i = 0; i < v.size(); i++)
	{
		v[i].x;
		a.x = v[i].x * 0.2;
		a.y = v[i].y * 0.2;
		a.z = v[i].z * 0.2;
		v[i].x = a.x;
		v[i].y = a.y;
		v[i].z = a.z;
	}
}
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
		//cout << line << endl;
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
	T = T + 0.5;
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
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	renderAxis();
	glRotatef(rotation_angle, 0.0f, 1.0f, 0.0f);
	glRotatef(spin_angle, 1.0f, 0.0f, 0.0f);
	obj();

	glutSwapBuffers();
}

int main(int c, char* V[])
{

	parserObj();


	for (int i = 0; i < f.size(); i++)
	{
		cout << i + 1 << " face  v1 coordinate x y z:" << v[(f[i].v1)].x << " " << v[(f[i].v1)].y << " " << v[(f[i].v1)].z << " v2 coordinate x y z:" << v[(f[i].v2)].x << " " << v[(f[i].v2)].y << " " << v[(f[i].v2)].z << " v3 coordinate x y z:" << v[(f[i].v3)].x << " " << v[(f[i].v3)].y << " " << v[(f[i].v3)].z << endl;

	}
	cout << "after rotation";
	rotateAtZ();
	uniformScaleBy3();
	rotateAtY();
	rotateAtX();
	glutInit(&c, V);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("objParser");
	MyInit();
	glutMotionFunc(mouse_callback);
	glutDisplayFunc(draw);
	//glutIdleFunc(spin);
	glutMainLoop();
	return 0;

}
