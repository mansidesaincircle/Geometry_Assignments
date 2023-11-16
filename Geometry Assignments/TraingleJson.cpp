#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
	// Original triangle vertices
	vector<vector<float>> originalTriangle = { {0.0f, 0.5f}, {-0.5f, -0.5f}, {0.5f, -0.5f} };

	// Scale factor
	float scaleFactor = 5.0f;

	// Scale the original triangle points
	vector<vector<float>> scaledTriangle;
	for (const auto& vertex : originalTriangle) {
		float scaledX = vertex[0] * scaleFactor;
		float scaledY = vertex[1] * scaleFactor;
		scaledTriangle.push_back({ scaledX, scaledY });
	}

	// Create a JSON object containing both original and scaled triangle
	json triangleJson;
	triangleJson["original_triangle"] = originalTriangle;
	triangleJson["scaled_triangle"] = scaledTriangle;

	// Save the JSON object to a file
	ofstream outputFile("triangle.json");
	if (outputFile.is_open()) {
		outputFile << triangleJson.dump(4); // Write the JSON data to the file with indentation
		outputFile.close();
		cout << "JSON file created successfully." << endl;
	}
	else {
		cout << "Unable to create JSON file." << endl;
	}

	// Read the JSON file
	ifstream inputFile("triangle.json");
	if (inputFile.is_open()) {
		json readTriangleJson;
		inputFile >> readTriangleJson;
		inputFile.close();

		// Access and print the original and scaled triangle vertices
		cout << "Original Triangle Vertices:" << endl;
		for (const auto& vertex : readTriangleJson["original_triangle"]) {
			float x = vertex[0];
			float y = vertex[1];
			cout << "(" << x << ", " << y << ")" << endl;
		}

		cout << "Scaled Triangle Vertices:" << endl;
		for (const auto& vertex : readTriangleJson["scaled_triangle"]) {
			float x = vertex[0];
			float y = vertex[1];
			cout << "(" << x << ", " << y << ")" << endl;
		}
	}
	else {
		cout << "Failed to open JSON file." << endl;
	}

	return 0;
}
