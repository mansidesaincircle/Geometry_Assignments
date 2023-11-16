#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<gl/glut.h>
using namespace std;

class vertex
{
public:
	float  x, y, z;
};
class face
{
public:
	vertex  v1, v2, v3;
};
vector<vertex> v;
vector<face> f;
void stlParser()
{
	ifstream file("stl_file.stl");
	string line;
	while (getline(file, line))
	{
		string word;
		istringstream iss(line);
		iss >> word;

		vertex tempPoint;

		if (word == "vertex")
		{
			iss >> tempPoint.x >> tempPoint.y >> tempPoint.z;

			v.push_back(tempPoint);


		}
		else if (word == "endloop")
		{
			face Face;
			Face.v1 = v[0];
			Face.v2 = v[1];
			Face.v3 = v[2];
			f.push_back(Face);
			v.clear();

		}

	}
}

void rotateAtX()
{
	float angle = (45 * 3.149) / 180;
	for (int i = 0; i < f.size(); i++)
	{
		vertex a;
		//for rotating vertex 1 of respective face 
		a.y = f[i].v1.y * cos(angle) + f[i].v1.z * sin(angle);
		a.z = -(f[i].v1.y * sin(angle)) + f[i].v1.z * cos(angle);
		f[i].v1.y = a.y;
		f[i].v1.z = a.z;
		//for rotating vertex 2 of respective face 
		a.y = f[i].v2.y * cos(angle) + f[i].v2.z * sin(angle);
		a.z = -(f[i].v2.y * sin(angle)) + f[i].v2.z * cos(angle);
		f[i].v2.y = a.y;
		f[i].v2.z = a.z;
		//for rotating vertex 3 of respective face 
		a.y = f[i].v3.y * cos(angle) + f[i].v3.z * sin(angle);
		a.z = -(f[i].v3.y * sin(angle)) + f[i].v3.z * cos(angle);
		f[i].v3.y = a.y;
		f[i].v3.z = a.z;
	}

}
void rotateAtY()
{
	float angle = (45 * 3.149) / 180;
	for (int i = 0; i < f.size(); i++)
	{
		vertex a;
		//for rotating vertex 1 of respective face 
		a.x = f[i].v1.x * cos(angle) + f[i].v1.z * sin(angle);
		a.z = -(f[i].v1.x * sin(angle)) + f[i].v1.z * cos(angle);
		f[i].v1.x = a.x;
		f[i].v1.z = a.z;
		//for rotating vertex 2 of respective face 
		a.x = f[i].v2.x * cos(angle) + f[i].v2.z * sin(angle);
		a.z = -(f[i].v2.x * sin(angle)) + f[i].v2.z * cos(angle);
		f[i].v2.x = a.x;
		f[i].v2.z = a.z;
		//for rotating vertex 3 of respective face 
		a.x = f[i].v3.x * cos(angle) + f[i].v3.z * sin(angle);
		a.z = -(f[i].v3.x * sin(angle)) + f[i].v3.z * cos(angle);
		f[i].v3.x = a.x;
		f[i].v3.z = a.z;
	}

}
void rotateAtZ()
{
	float angle = (45 * 3.149) / 180;
	for (int i = 0; i < f.size(); i++)
	{
		vertex a;
		//for rotating vertex 1 of respective face 
		a.x = f[i].v1.x * cos(angle) + f[i].v1.y * sin(angle);
		a.y = -(f[i].v1.x * sin(angle)) + f[i].v1.y * cos(angle);
		f[i].v1.x = a.x;
		f[i].v1.y = a.y;
		//for rotating vertex 2 of respective face 
		a.x = f[i].v2.x * cos(angle) + f[i].v2.y * sin(angle);
		a.y = -(f[i].v2.x * sin(angle)) + f[i].v2.y * cos(angle);
		f[i].v2.x = a.x;
		f[i].v2.y = a.y;
		//for rotating vertex 3 of respective face 
		a.x = f[i].v3.x * cos(angle) + f[i].v3.y * sin(angle);
		a.y = -(f[i].v3.x * sin(angle)) + f[i].v3.y * cos(angle);
		f[i].v3.x = a.x;
		f[i].v3.y = a.y;
	}

}
void uniformScalingBy3()
{
	float angle = (45 * 3.149) / 180;
	for (int i = 0; i < f.size(); i++)
	{
		vertex a;
		//for vertex 1 of respective face 
		a.x = f[i].v1.x * 0.2;
		a.y = f[i].v1.y * 0.2;
		a.z = f[i].v1.z * 0.2;
		f[i].v1.x = a.x;
		f[i].v1.y = a.y;
		f[i].v1.z = a.z;
		//for vertex 2 of respective face 
		a.x = f[i].v2.x * 0.2;
		a.y = f[i].v2.y * 0.2;
		a.z = f[i].v2.z * 0.2;
		f[i].v2.x = a.x;
		f[i].v2.y = a.y;
		f[i].v2.z = a.z;
		//for vertex 3 of respective face 
		a.x = f[i].v3.x * 0.2;
		a.y = f[i].v3.y * 0.2;
		a.z = f[i].v3.z * 0.2;
		f[i].v3.x = a.x;
		f[i].v3.y = a.y;
		f[i].v3.z = a.z;
	}

}

//glut code
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
void drawObj()
{
	for (float i = 0; i < f.size(); i++) {
		glBegin(GL_TRIANGLES);
		glColor3f(0, 1, 1);
		glVertex3f(f[i].v1.x, f[i].v1.y, f[i].v1.z);
		glColor3f(1, 1, 0);
		glVertex3f(f[i].v2.x, f[i].v2.y, f[i].v2.z);
		glColor3f(0, 1, 0);
		glVertex3f(f[i].v3.x, f[i].v3.y, f[i].v3.z);
		glEnd();
	}
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(T, 0, 0, 0);
	drawObj();

	glutSwapBuffers();
}


int main(int c, char* V[])
{
	//Reading Stl file

	stlParser();

	for (int i = 0; i < f.size(); i++)
	{
		//cout << i + 1 << "face  vertex 1 x coordinate " << f[i].v1.x << " y coordinate:" << f[i].v1.y << " z coordinate" << f[i].v1.z << endl;
	}
	rotateAtZ();
	uniformScalingBy3();
	rotateAtY();
	rotateAtX();


	glutInit(&c, V);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("stlParser");
	MyInit();
	glutDisplayFunc(draw);
	//glutIdleFunc(spin);
	glutMainLoop();

	return 0;
}