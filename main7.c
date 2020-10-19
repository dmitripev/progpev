#include <stdio.h>
#include <math.h>
enum Style
{
    Classic,
    Pop,
    Rock,
    Rap,
    New_Age,
    Electronic,
};
struct Point
{
    int x;
    int y;
};
struct Circle
{
    struct Point center;
    int radius;
};
struct ADSL
{
    unsigned short DSL : 1;
    unsigned short PPP : 1;
    unsigned short Link : 1;
};
int main()
{
    printf("%d\n", Rock);

    struct Circle N = {{1, 1}, 5};
    float l;
    l = 2 * N.radius * M_PI;
    printf("%f", l);



}
