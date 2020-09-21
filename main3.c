#include <stdio.h>

int main() 
{
	char arr[4];
	char *ptr = arr;
	*(ptr + 0) = 'W';
	*(ptr + 1) = 'O';
	*(ptr + 2) = 'R';
	*(ptr + 3) = 'K';
	for (int i = 0; i < 4; ++i)
	{
		printf("%3c", *(ptr + i));
	}
	return 0;
}
