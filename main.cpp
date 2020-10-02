#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void merge(int* arr,int left, int middle, int right)
{
    int n1, n2;
    n1 = middle - left + 1;
    n2 = right - middle;
    int* lArr = new int[n1 + 1];
    int* rArr = new int[n2 + 1];
    for (int i = 0; i < n1; ++i)
        lArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rArr[i] = arr[middle + i + 1];
    lArr[n1] = pow(10, 9) + 1;
    rArr[n2] = pow(10, 9) + 1;
    int current1 = 0, current2 = 0;
    for (int i = left; i < right + 1; ++i)
    {
        if (lArr[current1] <= rArr[current2])
        {
            arr[i] = lArr[current1];
            ++current1;
        }
        else
        {
            arr[i] = rArr[current2];
            ++current2;
        }
    }
}
void mergeSort(int* arr, int left, int right)
{
    if (left < right)
    {
        int middle;
        middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
int main()
{
    int n;
    ifstream fin("sort.in");
    fin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        fin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    ofstream fout("sort.out");
    for (int i = 0; i < n; ++i)
    {
        fout << arr[i] << " ";
    }
    fin.close();
    fout.close();

    return 0;
}
