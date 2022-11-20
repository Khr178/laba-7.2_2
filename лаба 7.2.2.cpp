// Lab_7_2_2.cpp
// < Копейки Христини >
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 8

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int K, const int N, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < K < N - 1)
		CreateRow(a, rowNo, K, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, K, N, Low, High, 0);
	if (rowNo < K < N - 1)
		CreateRows(a, K, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int K, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < K < N - 1)
		PrintRow(a, rowNo, K, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int K, const int N, int rowNo)
{
	PrintRow(a, rowNo, K, N, 0);
	if (rowNo < K < N - 1)
		PrintRows(a, K, N, rowNo + 1);
	else
		cout << endl;
}
void SearchFirstEven(int** a, const int K, const int N, int i, int& minEven, int& k)
{
	if (a[i][N - 1 - i] % 2 == 0)
	{
		k = i;
		minEven = a[i][N - 1 - i];
	}
	else
		if (i < K < N - 1)
			SearchFirstEven(a, K, N, i + 1, minEven, k);
}
void SearchMinEven(int** a, const int K, const int N, int i, int& minEven)
{
	if (a[i][N - 1 - i] % 2 == 0 && a[i][N - 1 - i] < minEven)
		minEven = a[i][N - 1 - i];
	if (i < K < N - 1)
		SearchMinEven(a, K, N, i + 1, minEven);
}
void SearchMaxEven(int** a, const int K, const int N, int i, int& minEven)
{
	if (a[i][N - 1 - i] % 2 == 0 && a[i][N - 1 - i] < minEven)
		minEven = a[i][N - 1 - i];
	if (i < K < N - 1)
		SearchMinEven(a, K, N, i + 1, minEven);
}
int main()
{
	srand((unsigned)time(NULL));
	int K,N;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << endl;
	int** a = new int* [K];
	for (int i = 0; i < K; i++)
		a[i] = new int[K];
	int** a2 = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[N];
	int Low = -12, High = 37;
	CreateRows(a, K, N, Low, High, 0);
	PrintRows(a, K, N, 0);
	int k = -1;
	int minEven;
	SearchFirstEven(a, K, N, 0, minEven, k);
	if (k > -1)
	{
		SearchMinEven(a, K, N, k + 1, minEven);
		cout << "minEven = " << minEven << endl;
	}
	else
		cout << "there are no even elements" << endl;

	int maxEven;
	SearchFirstEven(a, K, N, 0, minEven, k);
	if (k > -1)
	{
		SearchMaxEven(a, K, N, k + 1, maxEven);
		cout << "maxEven = " << maxEven << endl;
	}
	else
		cout << "there are no even elements" << endl;


	for (int i = 0; i < K; i++)
		delete[] a[i];
	delete[] a;
	return 0;

	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}


