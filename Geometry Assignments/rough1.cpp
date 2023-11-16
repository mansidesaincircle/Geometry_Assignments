#include <iostream>
#include <vector>

using namespace std;

void matrixVector(vector<vector<double>>& matrix1, const vector<vector<double>>& matrix2) 
{
	vector<vector<double>> result(matrix1.size(), vector<double>(matrix2.size(), 0.0));

	for (size_t i = 0; i < matrix1.size(); i++)  
	{
		for (size_t j = 0; j < matrix2.size(); j++) 
		{
			double sum = 0;
			for (size_t k = 0; k < matrix1.size(); k++)
			{
				sum += matrix1[i][k] * matrix2[k][j];
			}
			result[i][j] = sum;
		}
	}

	matrix1 = result;
}

int main() {
	vector<vector<double>> matrix1 = {
		{0, 0, 1},
		{0, 1, 0},
		{1, 0, 0}
	};

	vector<vector<double>> matrix2 = {
		{1, 2, 3},
		{2, 1, 2},
		{1, 3, 1}
	};

	matrixVector(matrix1, matrix2);

	cout << "Resulting Matrix:" << endl;
	for (const auto& row : matrix1) {
		for (const auto& element : row) {
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}
