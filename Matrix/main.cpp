#include<iostream>

using namespace std;

#define tab "\t"
#define SUM_MATRIX //сложение матриц
#define SUB_MATRIX //вычитание матриц
#define MUL_MATRIX //умножение матриц
#define DET_SARRUS //определитель матриц по методу Саррюса

void main() {
	setlocale(LC_ALL, "rus");
	const int COLS = 3;
	const int ROWS = 3;
	int arr1[COLS][ROWS] = {};
	int arr2[COLS][ROWS] = {};
	cout << "Первая матрица:" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr1[i][j] = rand() % 10;
			cout << arr1[i][j] << tab;
		}
		cout << endl;
	}
	cout << "Вторая матрица:" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr2[i][j] = rand() % 10;
			cout << arr2[i][j] << tab;
		}
		cout << endl;
	}
#ifdef SUM_MATRIX
	cout << "Сумма матриц:" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << arr1[i][j]+arr2[i][j] << tab;
		}
		cout << endl;
	}
#endif // SUM_MATRIX
#ifdef SUB_MATRIX
	cout << "Вычитание матриц:" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << arr1[i][j] - arr2[i][j] << tab;
		}
		cout << endl;
	}
#endif // SUB_MATRIX
#ifdef MUL_MATRIX
	cout << "Умножение матриц:" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			int sum = 0;
			for (int k = 0; k < COLS; k++) {
				sum += arr1[i][k] * arr2[k][j];
			}
			cout << sum << tab;
		}
		cout << endl;
	}
#endif // MUL_MATRIX
#ifdef DET_SARRUS
	cout << "Определитель первой матрицы по Саррусу" << endl;
	int ext_arr[ROWS][COLS * 2] = {};
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			ext_arr[i][j] = ext_arr[i][j +COLS] = arr1[i][j];
		}
	}
	cout << "Расширенная матрица:" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS*2; j++) {
			cout << ext_arr[i][j] << tab;
		}
		cout << endl;
	}
	int main_sum = 0;
	for (int i = 0; i < ROWS; i++) {
		int product = 1;
		for (int j = 0; j < COLS; j++) {
			product *= ext_arr[j][j + i];
		}
		main_sum += product;
	}
	int aux_sum = 0;
	for (int i = 0; i < ROWS; i++) {
		int prod = 1;
		for (int j = 0; j < COLS; j++) {
			prod *= ext_arr[j][ROWS - 1 - j + i];
		}
		aux_sum += prod;
	}
	cout << "Определитель матрицы: " << main_sum - aux_sum << endl;
#endif // DET_SARRUS
}
