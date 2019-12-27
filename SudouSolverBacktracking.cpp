#include <iostream> 
#include <fstream> 
#include <ctime>
#include "Header.h"
using namespace std;

int main() {
	int matrix[N][N];
	int arr[N * N] = {};
	clock_t start;
	double duration = 0;
	cout.precision(6);
	fstream F;
	F.open("D:\\VS Projects\\SudouSolverBacktracking\\SudokuIn3.txt");

	char a;
	int b = 0;
	int ii = 0;
	if (F) {
		while (!F.eof() && ii < N*N) {
			F >> a;
			switch (a) {
			case '*': b = 0; break;
			case '1': b = 1; break;
			case '2': b = 2; break;
			case '3': b = 3; break;
			case '4': b = 4; break;
			case '5': b = 5; break;
			case '6': b = 6; break;
			case '7': b = 7; break;
			case '8': b = 8; break;
			case '9': b = 9; break;
		}
			arr[ii] = b;
			ii++;
		}
}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = arr[N*i+j];
		}
	}
	F.close();

	start = clock();
	if (SudokuSolver(matrix) == true) {
		cout << "Result was found!" << endl;
		duration = (double)clock() - start;
		printToFile(matrix);
	} 
	else {
		cout << "No solutions ";
	}
	cout << "Duration: " << duration << " ms "<< '\n';
	return 0;
}
