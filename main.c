#include <stdio.h>
#include <math.h>
int main()
{
    int x, y, n;
    scanf("%d", &x);
    printf("%x\n", x);
    printf("%o ", x);
    y = x >> 1;
    printf("%o\n", y);
    printf("%o ", x);
    y = ~x;
    printf("%o\n", y);
    scanf("%o", &n);
    y = n ^ x;
    printf("%o\n", y);



}
