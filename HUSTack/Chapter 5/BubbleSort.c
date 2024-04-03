#include <stdio.h>
#define MAX_SIZE 100

void bubbleSort(int a[], int n)
{  
    int i, swapped;
    do{
        swapped = 0;
        for (i = 0;i < n - 1;i++)
        {
            if (a[i] > a[i+1])
            {
                int tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped == 1);
}
int main()
{
    int a[MAX_SIZE] = {0}, i, n;
    scanf("%i", &n);
    for (i = 0;i < n;i++) scanf("%i", &a[i]);
    bubbleSort(a,n);
    for (i = 0;i < n;i++) printf("%i ", a[i]);
}