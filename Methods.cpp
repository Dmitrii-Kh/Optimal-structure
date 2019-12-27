#include <iostream> 
#include <fstream> 
using namespace std;

const int zeroCell = 0;
const int N = 9;

bool UsedInRow(int matrix[N][N], int row, int num) {
	for (int col = 0; col < N; col++)
		if (matrix[row][col] == num)
			return true;
	return false;
}


bool UsedInCol(int matrix[N][N], int col, int num) {
	for (int row = 0; row < N; row++)
		if (matrix[row][col] == num)
			return true;
	return false;
}


bool UsedInBox(int matrix[N][N], int boxStartRow,
	int boxStartCol, int num) {
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (matrix[row + boxStartRow]
				[col + boxStartCol] == num)
				return true;
	return false;
}


bool befit(int matrix[N][N], int row,
	int col, int num) {
	return !UsedInRow(matrix, row, num) &&
		!UsedInCol(matrix, col, num) &&
		!UsedInBox(matrix, row - row % 3,
			col - col % 3, num) &&
		matrix[row][col] == zeroCell;
}

bool FindUnassignedCell(int matrix[N][N],
	int& row, int& col) {
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (matrix[row][col] == zeroCell)
				return true;
	return false;
}


bool SudokuSolver(int matrix[N][N]) {
	int row, col;
	if (!FindUnassignedCell(matrix, row, col))
		return true;

	for (int num = 1; num <= 9; num++) {
		if (befit(matrix, row, col, num)) {
			matrix[row][col] = num;

			if (SudokuSolver(matrix))
				return true;
			matrix[row][col] = zeroCell;
		}
	}
	return false;
}


//void printMatrix(int matrix[N][N])
//{
//	for (int row = 0; row < N; row++)
//	{
//		for (int col = 0; col < N; col++)
//			cout << matrix[row][col] << " ";
//		cout << endl;
//	}
//}

void printToFile(int matrix[N][N]) {
	fstream Fout;
	Fout.open("D:\\VS Projects\\SudouSolverBacktracking\\SudokuOut3.txt");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Fout << matrix[i][j] << " ";
		}
		Fout << "\n";
	}
	Fout.close();
}