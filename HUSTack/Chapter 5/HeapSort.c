#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100001

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int a[], int i, int N)
{
    int L = 2*i;
    int R = 2*i+1;
    int max = i;
    if(L <= N && a[L] > a[i]) max = L;
    if(R <= N && a[R] > a[max]) max = R;
    if(max != i)
    {
        swap(&a[i], &a[max]);
        heapify(a, max, N);
    }
}

void buildHeap(int a[], int N)
{
    int i;
    for(i = (N-1)/2;i >= 0;i--) heapify(a, i, N);
}

void heapSort(int a[], int N)
{
    int i;
    buildHeap(a, N);
    for(i = N-1;i > 0;i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, 0, i-1);
    }
}

int main()
{
    int a[MAX_SIZE] = {0}, i, n;
    scanf("%i", &n);
    for (i = 0;i < n;i++) scanf("%i", &a[i]);
    heapSort(a, n);
    for (i = 0;i < n;i++) printf("%i ", a[i]);
}