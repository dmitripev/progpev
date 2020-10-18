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

    int arr1[2][2] = { {1, 1}, {1, 4} };
    int arr2[2][2] = { {1, 2}, {4, 1} };
    int arr3[2][2];
    for (int i = 0; i < 2; ++i)
        for (int k = 0; k < 2; ++k)
        {
            arr3[i][k] = arr1[i][0] * arr2[0][k] + arr1[i][1] * arr2[1][k];
            printf("%3d", arr3[i][k]);
            if(k == 1)
                printf("\n");
        }
    return 0;
}
