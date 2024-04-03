#include <stdio.h>
#define MAX_SIZE 100

void selectionSort(int a[], int n)
{  
    int i,j;
    for(i = 0;i < n-1;i++)
    {
        int min = i;
        for(j = i+1;j < n;j++)
        {
            if(a[min] > a[j]) min = j;
        }
        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
}
int main()
{
    int a[MAX_SIZE] = {0}, i, n;
    scanf("%i", &n);
    for(i = 0;i < n;i++) scanf("%i", &a[i]);
    selectionSort(a,n);
    for(i = 0;i < n;i++) printf("%i ", a[i]);
}