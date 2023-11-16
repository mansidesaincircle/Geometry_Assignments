#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function to split a string into tokens
vector<string> split_string(const string& s, char delimiter) 
{
	vector<string> tokens;
	stringstream ss(s);
	string token;
	while (getline(ss, token, delimiter)) 
	{
		tokens.push_back(token);
	}
	return tokens;
}

// Function to read and print the vertex positions from the OBJ file
void read_vertex_positions(const string& file_path) {
	ifstream file(file_path);
	if (!file.is_open()) {
		cerr << "Error: Unable to open file " << file_path << endl;
		return;
	}

	string line;
	while (getline(file, line))
	{
		if (line.empty() || line[0] == '#') {
			// Skip empty lines and comments starting with '#'
			continue;
		}

		vector<string> tokens = split_string(line, ' ');
		cout<<"tokens.size():"<< tokens.size()<<endl;
		if (tokens.size() > 0 && tokens[0] == "v" && tokens.size() >= 4) {
			// Print vertex positions (x, y, z)
			cout << "Vertex: (" << tokens[1] << ", " << tokens[2] << ", " << tokens[3] << ")" << endl;
		}
	}

	file.close();
}

int main() {
	// Provide the file path of the "Obj_file.obj" file
	string file_path = "D:\\Geometry Assignmets\\Geometry Assignments\\Geometry Assignments\\Obj_file.obj";

	// Call the function to read and print the vertex positions from the file
	read_vertex_positions(file_path);

	return 0;
}
