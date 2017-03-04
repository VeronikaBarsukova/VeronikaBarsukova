// QSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "malloc.h"
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
#include <ctime>
using namespace std;

void RecordArray(int *massiv, int razmer)
{
	for (int i = 0; i < razmer; i++)
	{
		massiv[i] = rand() % 100;
	}
}

int Comparator(void const* first, void const* second)
{
	return *((int*)first) - *((int*)second);
}

void OutputArray(int *massiv, int razmer)
{
	for (int i = 0; i < razmer; i++)
	{
			printf("%d\t", massiv[i]);
	}
	printf("\n");
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int Size;
	printf("Введите размер масива");
	scanf_s("%d", &Size);

	int *Array = (int*)malloc(Size*sizeof(int));

	RecordArray(Array, Size);

	OutputArray(Array, Size);

	qsort(Array, Size, sizeof(int), Comparator);

	OutputArray(Array, Size);

	getchar();
	getchar();
    return 0;
}

