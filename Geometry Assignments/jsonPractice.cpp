#include <iostream>
#include <fstream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
	// Create a JSON object
	json data;
	data["name"] = "John Doe";
	data["age"] = 25;
	data["city"] = "New York";

	// Save the JSON object to a file
	ofstream outputFile("data.json");
	if (outputFile.is_open()) {
		outputFile << data.dump(4); // Write the JSON data to the file with indentation
		outputFile.close();
		cout << "JSON file created successfully." << endl;
	}
	else {
		cout << "Unable to create JSON file." << endl;
	}

	// Read the JSON file
	ifstream inputFile("data.json");
	if (inputFile.is_open()) {
		json readData;
		inputFile >> readData;
		inputFile.close();

		// Access and print the data
		cout << "Name: " << readData["name"] << endl;
		cout << "Age: " << readData["age"] << endl;
		cout << "City: " << readData["city"] << endl;
	}
	else {
		cout << "Failed to open JSON file." << endl;
	}

	return 0;
}
