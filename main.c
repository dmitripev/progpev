#include <stdio.h>
#include <malloc.h>
int main()
{
    char arr[4]; //объявление массива символов
    char *ptr = arr; //создание указателя на массив
    ptr[0] = 'W'; ptr[1] = 'O'; ptr[2] = 'R'; ptr[3] = 'K'; //заполнение массива символов
    for (int i = 0; i < 4; ++i)
    {
        printf("%3c", ptr[i]); //вывод элемента массива символов
    }
    printf("\n");


    char *a; //создание указателя
    a = (char*)malloc(4 * sizeof(char)); //выделение динамической памяти для массива
    a[0] = 'W'; a[1] = 'O'; a[2] = 'R'; a[3] = 'K'; //заполнение массива
    for (int i = 0; i < 4; ++i)
    {
        printf("%3c", a[i]); //вывод элемента массива
    }
    free(a);
    return 0;
}
