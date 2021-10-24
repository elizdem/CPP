#include <iostream>
#include <iomanip>;
#include <math.h>


//1. ќбъ€вить массив из n=16 целых чисел, проинициализировать единицами. ‘ункци€
//processArray() должна заполнить элементы массива с четными индексами
//степен€ми двойки(1, 2, 4, 8, 16, Е), с нечетными индексами Ц степен€ми тройки(3, 9,
// 27, Е).“акже подсчитать и вернуть count Ц количество двузначных чисел в массиве и
// сформировать выходной массив, содержащий только такие числа.¬ывести на экран
// результирующие массивы.
// ¬ход: [3 2 9 4 27 8 81 16 243 32 729 64 2187 128 6561 256]
// ¬ыход : [27 81 16 32 64] count = 5

int processArray(int array[], size_t n, int result[])
{
	int c = 2;
	int m = 3;
	int stp_C = 1;
	int stp_N = 1;

	for (size_t i = 0; i < n; i++)
	{
		if (i % 2 != 0) {
			array[i] = pow(c, stp_C++);
		}
		else {
			array[i] = pow(m, stp_N++);
		}
	}

	int count = 0 ;
	for (size_t i = 0; i < n; ++i)                     // 
	{
		if (array[i] > 9 && array[i] < 100)
		{
			result[count] = array[i];
			count += 1;
		}

	}

    return count;
}


void printArray(int arr[], std::size_t M)
{
	
	
		for (std::size_t i = 0; i <M ; ++i)
		{
			if (arr[i] != 0) 
			{
				printf("%i ", arr[i]);
			}
			
		}
		printf("\n");
		
	

}


int main()
{
	const size_t N = 16;
	
	int ar[N] = { 1 };

	int l[N] = { 0 };

	int res = processArray(ar, N, l);
	printArray(ar, N);
	printArray(l, N);
	
	printf("Count = %i", processArray(ar, N, l));
	
	
	return 0;
}
	
	

	






