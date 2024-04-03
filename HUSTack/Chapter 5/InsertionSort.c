#include <stdio.h>
#define MAX_SIZE 100

void insertionSort(int a[], int n)
{  
    int i,j;
    for (i = 1;i < n;i++)
    {
        int value = a[i];
        j = i;
        while (j > 0 && a[j-1] > value)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j] = value;
    }
}
int main()
{
    int a[MAX_SIZE] = {0}, i, n;
    scanf("%i", &n);
    for (i = 0;i < n;i++) scanf("%i", &a[i]);
    insertionSort(a,n);
    for (i = 0;i < n;i++) printf("%i ", a[i]);
}