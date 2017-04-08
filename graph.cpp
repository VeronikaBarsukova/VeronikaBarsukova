// Graph_practice2_ex3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"

void check(int **graph, int vertex, int* buffer, int size, int color)
{
	if (buffer[vertex] != 0)
		return;
	buffer[vertex] = color;
	for (int i = 0; i < size; i++)
	{
		if (graph[vertex][i])
			check(graph, vertex + 1, buffer, size, color);
	}

}



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int size;
	int color = 0;
	scanf("%d", &size);

	int **graph = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		graph[i] = (int*)malloc(size * sizeof(int));
		for (int j = 0; j < size; j++)
			scanf("%d", &graph[i][j]);
	}
	
	int* buffer;
	buffer = (int*)malloc(size * sizeof(int));
	memset(buffer, 0, size * sizeof(int));

	for (int j = 0; j < size; j++)
	{
		if (buffer[j] == 0)
		{
			check(graph, j, buffer, size, color);
			color++;
		}
		
	}
	printf("%d", color);
	for (int i = 0; i < size; i++)
	{
		printf("%d", buffer[i]);
	}

	for (int i = 0; i < size; i++)
		free(graph[i]);
	free(graph);
    return 0;
}
