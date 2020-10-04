#include <stdio.h>
#include <math.h>
int main()
{
    float z, a;
    scanf("%f", &a);
    z = 1 - 0.25 * pow((sin(2 * a)), 2) + sin(2 * a);
    printf("%f\n", z);
    z = pow((cos(a)), 2) + pow((cos(a)), 4);
    printf("%f", z);
}
