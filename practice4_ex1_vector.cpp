#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Vector.h"

vector createVectorByCoord(int x, int y, int z)
{
	vector vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.str = vectorToString(vec);
	return vec;
}

char *vectorToString(vector vec)
{
	char *returned;

	char buffer[50] = "\0";
	char st[2] = "(";
	char delim[2] = ";";
	char en[2] = ")";
	char x[11];
	char y[11];
	char z[11];

	sprintf(x, "%d", vec.x);
	sprintf(y, "%d", vec.y);
	sprintf(z, "%d", vec.z);

	strcat(buffer, st);
	strcat(buffer, x);
	strcat(buffer, delim);
	strcat(buffer, y);
	strcat(buffer, delim);
	strcat(buffer, z);
	strcat(buffer, en);

	returned = (char*)malloc(sizeof(char)*(strlen(buffer)+1));
	returned[strlen(buffer)] = '\0';

	for (int i = 0; i < strlen(buffer); i++)
		returned[i] = buffer[i];

	return returned;
}

vector createZeroVector()
{
	return createVectorByCoord(0, 0, 0);
}

vector createUnitVector()
{
	return createVectorByCoord(1, 1, 1);
}

vector sumOfVectors(vector vec1, vector vec2)
{
	return createVectorByCoord(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
}

vector subOfVectors(vector vec1, vector vec2)
{
	return createVectorByCoord(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

vector multVectorByNumber(vector vec, int number)
{
	return createVectorByCoord(vec.x*number, vec.y*number, vec.z*number);
}

int scalarMultOfVectors(vector vec1, vector vec2)
{
	return vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z;
}

vector vectorMultOfVectors(vector vec1, vector vec2)
{
	int x = vec1.y*vec2.z - vec2.y*vec1.z;
	int y = -1 * (vec1.x*vec2.z - vec2.x*vec1.z);
	int z = vec1.x*vec2.y - vec2.x*vec1.y;
	return createVectorByCoord(x, y, z);
}

int equalVectors(vector vec1, vector vec2)
{
	return vec1.x == vec2.x&&vec1.y == vec2.y&&vec1.z == vec2.z;
}

void desposeVector(vector *vec)
{
	free(vec->str);
}
