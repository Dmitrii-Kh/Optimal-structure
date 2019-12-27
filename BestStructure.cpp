#include <iostream>
using namespace std;
const int M = 40;               // Максимальное число слагаемых
int numbers[M];
int N;
double bestResult = -1; 
int* best = new int[M];
double qK;
double qO;
int bestS = 0;

void printArray(int arr[], int from, int to) {
	for (int i = from; i < to; i++) {
		cout << arr[i] << " ";
	}
}

double Pk(double qkz, double qO, int s) {

	double firstPar = 1;
	for (int r = 0; r < s; r++) {
		firstPar *= 1 - pow(qkz, numbers[r]);
	}
	double secondPar = 1;
	for (int r = 0; r < s; r++) {
		secondPar *= (1 - (pow((1 - qO), numbers[r])));
	}
	cout << " S = " << s << " Pk = " << firstPar - secondPar << endl;
	return firstPar - secondPar;
}

double optimalStructure(int n, int k, int i) {
	if (n < 0) return -1;
	if (n == 0) {
		if (N != k) {
			printArray(numbers, 0, i);
			double result = Pk(qK, qO, i);
			if (bestResult < result) {
				bestResult = result;
				bestS = i;
				for (int iter = 0; iter < i; iter++) {
					best[iter] = numbers[iter];
				}
			}
		}
	}

	else {
		if (n - k >= 0) {
			if (i != 0 || n != k)
				numbers[i] = k;
			optimalStructure(n - k, k, i + 1);
		}
		if (k - 1 > 0) {
			optimalStructure(n, k - 1, i);
		}
	}
	return bestResult;
}

int main()
{
	cout << "Enter N : ";
	cin >> N;
	cout << "Enter qO : ";
	cin >> qO;
	cout << "Enter qKz : ";
	cin >> qK;
	cout << "Best result : " << optimalStructure(N, N-1, 0) << endl;
	cout << "Best structure : ";
	printArray(best, 0, bestS);
}