#include <stdio.h>
int main()
{
	int arr[9] = { 99, 88, 77, 66, 55, 44, 33, 22, 11 };
	for (int i = 0; i < 9; ++i)
	{
		printf("%d   ", arr[i]);
		if (i % 3 == 2)
			printf("\n");
	}
}