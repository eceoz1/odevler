#include <stdio.h>

/*
Fibonacci Dizisi
Her sayının kendisinden bir önceki sayı ile toplanması ile elde edilen sayılar serisidir.
*/

int fibonacci(int i)
{

	if (i == 0)
	{
		return 0;
	}

	if (i == 1)
	{
		return 1;
	}
	return fibonacci(i - 1) + fibonacci(i - 2);
}

int main()
{
	printf("20180805021 | Ece ÖZ\n");

	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d\t\n", fibonacci(i));
	}

	return 0;
}
