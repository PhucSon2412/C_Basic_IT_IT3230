#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100001

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int L, int R, int indexPivot)
{   
    int i, pivot = a[indexPivot];
    swap(&a[indexPivot], &a[R]);
    int storeIndex = L;
    for (i = L;i <= R-1;i++)
    {
        if(a[i] < pivot)
        {
            swap(&a[storeIndex], &a[i]);
            storeIndex++;
        }
    }
    swap(&a[storeIndex], &a[R]);
    return storeIndex;
}

void quickSort(int a[], int L, int R)
{
    if(L < R)
    {
        int index = (L + R)/2;
        index = partition(a, L, R, index);
        if(L < index) quickSort(a, L, index - 1);
        if(index < R) quickSort(a, index + 1, R);
    }
}

int main()
{
    int a[MAX_SIZE] = {0}, i, n;
    scanf("%i", &n);
    for (i = 0;i < n;i++) scanf("%i", &a[i]);
    quickSort(a, 0, n-1);
    for (i = 0;i < n;i++) printf("%i ", a[i]);
}