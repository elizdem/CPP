#include <iostream>;
#include <iomanip>;
#include <math.h>;
#include <iomanip>;

using namespace std;


//Преобразование: 1D ? 2D.Одномерный массив из 18 целых чисел необходимо
//отсортировать в порядке убывания и разложить по двумерной сетке 9х2 слева направо и
//сверху вниз.
//Инициализация : заполнить массив числами x[i] = i2 + 1 и все элементы с четными
//индексами домножить на - 1.
//Вывод на экран : на каждый элемент массива отвести 5 позиций.

void initialize(int* array, size_t l)
{
	for (size_t i = 0; i < l; i++) 
	{
		array[i] = pow(i, 2) + 1;
		if (i % 2 != 0)
		{
			array[i] *= -1;
		}

	}
	
}

int** make2Darray(int* arr1D, size_t r, size_t c, size_t length)
{

	size_t temp = 0;

	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			if (arr1D[i] < arr1D[j])
			{
				temp = arr1D[i];
				arr1D[i] = arr1D[j];
				arr1D[j] = temp;
			}
		}
		
	}

	int** arr2D = new int* [r];
	for (size_t i = 0; i < r; ++i) 
	{
		*(arr2D + i) = new int[c];
	}

	for (size_t i = 0; i < r; ++i) 
	{
		for (size_t j = 0; j < c; ++j)
		{
			*(*(arr2D + i) + j) = *(arr1D + i * c + j);
		}
	}
	return arr2D;
}


void printArray1D(int* array, size_t m)
{
	for (size_t i = 0; i < m; ++i)
	{
		
		cout << setw(5)<< array[i];
	
	}
	cout << "\n" << endl;
}

void printArray2D(int** arr2D, size_t r, size_t c) 
{
	for (size_t i = 0; i < r; ++i) 
	{
		for (size_t j = 0; j < c; ++j)
		{
			
			cout << setw(5) << *(*(arr2D + i) + j);

		}
		cout << endl;

	}
	
}

void free1Darray(int* array)
{
	delete[] array;
}

void free2Darray(int** arr2D, size_t r)
{
	for (size_t i = 0; i < r; ++i)
	{
		delete[] arr2D[i];
	}
	delete[] arr2D;
}

int main() 
{

	const size_t len = 18;
	const size_t rows = 9;
	const size_t cols = 2;
    int* arr = new int [len];

	initialize(arr, len);
	int** array2D = make2Darray(arr, rows, cols, len);

	
	printArray1D(arr, len);
	printArray2D(array2D, rows, cols);
	free1Darray(arr);
	free2Darray(array2D, rows);



	return 0; 
		
}



