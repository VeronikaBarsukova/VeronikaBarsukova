#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void check(int **graph, int vertex, int* buffer, int size, int color);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int size, color;
	color = 0;	scanf("%d", &size);

	int* buffer;
	buffer = (int*)malloc(size * sizeof(int));

	int **graph = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		graph[i] = (int*)malloc(size * sizeof(int));
		for (int j = 0; j < size; j++)
			scanf("%d", &graph[i][j]);
	}
	graph;
	memset(buffer, 0, size * sizeof(int));

	for (int j = 0; j < size; j++)
	{
		if (buffer[j] == 0)
		{
			color++;
			check(graph, j, buffer, size, color);
		}
	}
	printf("%d\n", color);
	for (int j = 0; j < size; j++)
		printf("%d", buffer[j]);

	for (int i = 0; i < size; i++)
		free(graph[i]);
	free(graph);
	free(buffer);

	return 0;
}

void check(int **graph, int vertex, int* buffer, int size, int color)
{
	if (buffer[vertex] != 0)
		return;
	buffer[vertex] = color;
	for (int i = 0; i < size; i++)
	{
		if (graph[vertex][i])
			check(graph, i, buffer, size, color);
	}
}
