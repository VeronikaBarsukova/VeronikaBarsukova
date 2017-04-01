#include "stdio.h"
#include "Vector.h"

int main()
{
	vector vec, zeroVec, unitVec, sumVec, subVec, multVec, vectorMultVec;
	int number = 2;
	vec = createVectorByCoord(1, 2, 3);
	zeroVec = createZeroVector();
	unitVec = createUnitVector();
	sumVec = sumOfVectors(vec, unitVec);
	subVec = subOfVectors(vec, unitVec);
	multVec = multVectorByNumber(vec, number);
	vectorMultVec = vectorMultOfVectors(vec, vec);
	printf("vec: %s\n", vectorToString(vec));
	printf("zeroVec: %s\n", vectorToString(zeroVec));
	printf("unitVec: %s\n", vectorToString(unitVec));
	printf("sumVec: %s\n", vectorToString(sumVec));
	printf("subVec: %s\n", vectorToString(subVec));
	printf("multVec: %s\n", vectorToString(multVec));
	printf("scalarMultVec: %d\n", scalarMultOfVectors(vec, vec));
	printf("vectorMultVec: %s\n", vectorToString(vectorMultVec));

	if (equalVectors(vec, unitVec))
		printf("equal\n");
	else
		printf("not equal\n");

	if (equalVectors(vec, vec))
		printf("equal\n");
	else
		printf("not equal\n");


	desposeVector(&vec);
	desposeVector(&zeroVec);
	desposeVector(&unitVec);
	desposeVector(&sumVec);
	desposeVector(&subVec);
	desposeVector(&multVec);
	desposeVector(&vectorMultVec);
	getchar();
	return 0;
}
