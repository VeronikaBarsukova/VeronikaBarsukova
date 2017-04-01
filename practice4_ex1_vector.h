
#ifndef Vector_h
#define Vector_h

typedef struct vector_struct
{
	int x;
	int y;
	int z;
	char *str;
} vector;

vector createVectorByCoord(int x, int y, int z);

vector createZeroVector();

vector createUnitVector();

vector sumOfVectors(vector vec1, vector vec2);

vector subOfVectors(vector vec1, vector vec2);

vector multVectorByNumber(vector vec, int number);

int scalarMultOfVectors(vector vec1, vector vec2);

vector vectorMultOfVectors(vector vec1, vector vec2);

int equalVectors(vector vec1, vector vec2);

char *vectorToString(vector vec);

void desposeVector(vector *vec);

#endif;
