#include <iostream>
#include <Windows.h>

using namespace std;

// Вариант 28
// Дан вещественный массив А[N][M] и целое число 0 < k <N . 
// Сдвинуть в каждом столбце циклически все элементы массива на k позиций вниз.

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, M;

	cout << "Введите количество строк (N) и столбцов (M) матрицы:" << endl;

	cin >> N;
	cin >> M;

	if (N <= 0 || M <= 0)
	{
		cout << "Error";
		return -1;
	}

	float** A = new float* [N];

	for (int i = 0; i < N; i++)
		A[i] = new float[M];


	cout << "Введите матрицу " << N << "x" << M << ":" << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	}

	cout << endl;

	int k;

	cout << "Введите k (0 < k < N): ";
	cin >> k;

	if (0 >= k || k >= N) 
	{
		cout << "Error" << endl;

		for (int i = 0; i < N; i++)
			delete[] A[i];

		delete[] A;
		return -1;
	}

	for (int w = 0; w < k; w++)
	{
		float* tmp = A[N - 1];

		for (int i = N - 1; i > 0; i--)
			A[i] = A[i - 1];

		A[0] = tmp;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << A[i][j] << " ";
		
		cout << endl;
	}

	for (int i = 0; i < N; i++)
		delete[] A[i];

	delete[] A;
	return 0;
}