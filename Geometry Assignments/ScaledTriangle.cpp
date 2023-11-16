#include <GL/glut.h>  // Include the GLUT library
#include <vector>
#include <fstream>
#include <iostream>
#include "json.hpp"   // Include the JSON library

//nlohmann/json is the library working with json data

using namespace std;
using json = nlohmann::json;            //json is the alias for nlohmann::json

vector<vector<float>> originalTriangle;
vector<vector<float>> scaledTriangle;

void MyInit()
{
	glClearColor(0, 0, 0, 1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the original triangle (green lines)
	glColor3f(0, 1, 0); // Set color to green
	glBegin(GL_LINE_LOOP);
	for (const auto& vertex : originalTriangle) 
	{
		glVertex2f(vertex[0], vertex[1]);
	}
	glEnd();

	// Draw the scaled triangle (red lines)
	glColor3f(1, 0, 0); // Set color to red
	glBegin(GL_LINE_LOOP);
	for (const auto& vertex : scaledTriangle) {
		glVertex2f(vertex[0], vertex[1]);
	}
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	// Create the JSON object for the triangle points
	json triangleJson;
	triangleJson["original_triangle"] = 
	{ 
		{ -0.2f, -0.2f }, 
		{ 0.2f, -0.2f },
		{ 0.0f, 0.2f } 
	};

	// Save the JSON object to a file
	ofstream outputFile("triangle.json");       //create an output file stream object named outputfile
	if (outputFile.is_open()) 
	{
		outputFile << triangleJson.dump(4); // Write the JSON data to the file with indentation
		//dump function is used to convert a json object into string
		//outputFile << is used to write json data into the file
		//4 is indentation resulting in a more human-readable format 
		outputFile.close();
		cout << "JSON file created successfully." << endl;
	}
	else {
		cout << "Unable to create JSON file." << endl;
		return 1;
	}

	// Read the JSON file
	ifstream inputFile("triangle.json");
	if (inputFile.is_open()) {
		json triangleJson;
		inputFile >> triangleJson;
		inputFile.close();

		// Get the original triangle vertices
		originalTriangle = triangleJson["original_triangle"];

		// Scale the triangle vertices by 2 units
		scaledTriangle = originalTriangle;
		for (auto& vertex : scaledTriangle) {
			vertex[0] *= 2.0f;
			vertex[1] *= 2.0f;
		}

		// Print the original and scaled triangle vertices
		cout << "Original Triangle Vertices:" << endl;
		for (const auto& vertex : originalTriangle) {
			float x = vertex[0];
			float y = vertex[1];
			cout << "(" << x << ", " << y << ")" << endl;
		}

		cout << "Scaled Triangle Vertices:" << endl;
		for (const auto& vertex : scaledTriangle) {
			float x = vertex[0];
			float y = vertex[1];
			cout << "(" << x << ", " << y << ")" << endl;
		}

		// Initialize OpenGL and GLUT
		glutInit(&argc, argv);
		glutInitWindowSize(800, 600);
		glutInitWindowPosition(400, 100);
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		glutCreateWindow("Triangle");

		MyInit();

		// Register the display function
		glutDisplayFunc(display);

		// Start the main loop
		glutMainLoop();
	}
	else {
		cout << "Failed to open JSON file." << endl;
		return 1;
	}

	return 0;
}
