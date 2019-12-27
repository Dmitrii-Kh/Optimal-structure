#pragma once
const int zeroCell = 0;
const int N = 9;
bool UsedInRow(int matrix[N][N], int row, int num);
bool UsedInCol(int matrix[N][N], int col, int num);
bool UsedInBox(int matrix[N][N], int boxStartRow, int boxStartCol, int num);
bool befit(int matrix[N][N], int row, int col, int num);
bool FindUnassignedCell(int matrix[N][N], int& row, int& col);
bool SudokuSolver(int matrix[N][N]);
void printToFile(int matrix[N][N]);
